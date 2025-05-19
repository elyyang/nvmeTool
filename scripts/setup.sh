#!/usr/bin/env bash

###########################################################################
# ELY 2022
###########################################################################

rootdir=$(readlink -f $(dirname $0))/

###########################################################################

cache_pci_init() 
{
	local -gA pci_bus_cache
	local -gA pci_ids_vendor
	local -gA pci_ids_device

	[[ -z ${pci_bus_cache[*]} || $CMD == reset ]] || return 1

	pci_bus_cache=()
	pci_bus_ids_vendor=()
	pci_bus_ids_device=()
}

cache_pci() 
{
	local pci=$1 class=$2 vendor=$3 device=$4

	if [[ -n $class ]]; then
		class=0x${class/0x/}
		pci_bus_cache["$class"]="${pci_bus_cache["$class"]:+${pci_bus_cache["$class"]} }$pci"
	fi
	if [[ -n $vendor && -n $device ]]; then
		vendor=0x${vendor/0x/} device=0x${device/0x/}
		pci_bus_cache["$vendor:$device"]="${pci_bus_cache["$vendor:$device"]:+${pci_bus_cache["$vendor:$device"]} }$pci"

		pci_ids_vendor["$pci"]=$vendor
		pci_ids_device["$pci"]=$device
	fi
}

cache_pci_bus_sysfs() 
{
	[[ -e /sys/bus/pci/devices ]] || return 1

	cache_pci_init || return 0

	local pci
	local class vendor device

	for pci in /sys/bus/pci/devices/*; do
		class=$(< "$pci/class") vendor=$(< "$pci/vendor") device=$(< "$pci/device")
		cache_pci "${pci##*/}" "$class" "$vendor" "$device"
	done
}

cache_pci_bus_lspci() 
{
	hash lspci 2> /dev/null || return 1

	cache_pci_init || return 0

	local dev
	while read -ra dev; do
		dev=("${dev[@]//\"/}")
		# lspci splits ls byte of the class (prog. interface) into a separate
		# field if it's != 0. Look for it and normalize the value to fit with
		# what kernel exposes under sysfs.
		if [[ ${dev[*]} =~ -p([0-9]+) ]]; then
			dev[1]+=${BASH_REMATCH[1]}
		else
			dev[1]+=00
		fi
		# pci class vendor device
		cache_pci "${dev[@]::4}"
	done < <(lspci -Dnmm)
}

cache_pci_bus() 
{
	case "$(uname -s)" in
		Linux) cache_pci_bus_lspci || cache_pci_bus_sysfs ;;	
	esac
}

###########################################################################

function check_for_driver() 
{
	if lsmod | grep -q ${1//-/_}; then
		return 1
	fi

	if [[ -d /sys/module/${1} || -d \
		/sys/module/${1//-/_} || -d \
		/sys/bus/pci/drivers/${1} || -d \
		/sys/bus/pci/drivers/${1//-/_} ]]; then
		return 2
	fi
	return 0
}

function pci_dev_echo() 
{
	local bdf="$1"
	shift
	echo "$bdf (${pci_ids_vendor["$bdf"]#0x} ${pci_ids_device["$bdf"]#0x}): $*"
}

function linux_bind_driver() 
{
	bdf="$1"
	driver_name="$2"
	old_driver_name=${drivers_d["$bdf"]:-no driver}
	ven_dev_id="${pci_ids_vendor["$bdf"]#0x} ${pci_ids_device["$bdf"]#0x}"

	if [[ $driver_name == "$old_driver_name" ]]; then
		pci_dev_echo "$bdf" "Already using the $old_driver_name driver"
		return 0
	fi

	if [[ $old_driver_name != "no driver" ]]; then
		echo "$ven_dev_id" > "/sys/bus/pci/devices/$bdf/driver/remove_id" 2> /dev/null || true
		echo "$bdf" > "/sys/bus/pci/devices/$bdf/driver/unbind"
	fi

	pci_dev_echo "$bdf" "$old_driver_name -> $driver_name"

	echo "$ven_dev_id" > "/sys/bus/pci/drivers/$driver_name/new_id" 2> /dev/null || true
	echo "$bdf" > "/sys/bus/pci/drivers/$driver_name/bind" 2> /dev/null || true
}

function linux_unbind_driver() 
{
	local bdf="$1"
	local ven_dev_id
	ven_dev_id="${pci_ids_vendor["$bdf"]#0x} ${pci_ids_device["$bdf"]#0x}"
	local old_driver_name=${drivers_d["$bdf"]:-no driver}

	if [[ -e /sys/bus/pci/drivers/$old_driver_name ]]; then
		echo "$ven_dev_id" > "/sys/bus/pci/drivers/$old_driver_name/remove_id" 2> /dev/null || true
		echo "$bdf" > "/sys/bus/pci/drivers/$old_driver_name/unbind"
	fi

	pci_dev_echo "$bdf" "$old_driver_name -> no driver"
}

function collect_devices() 
{
	# NVMe, IOAT, IDXD, VIRTIO, VMD
	local ids dev_type dev_id bdf bdfs in_use driver

    ids+="PCI_CLASS_NVME"
	ids+="|PCI_DEVICE_ID_INTEL_VMD"    
	ids+="|PCI_DEVICE_ID_INTEL_IDXD"
    
	local -gA nvme_d ioat_d idxd_d virtio_d vmd_d all_devices_d drivers_d

	while read -r _ dev_type dev_id; do
		bdfs=(${pci_bus_cache["0x8086:$dev_id"]})
		[[ $dev_type == *NVME* ]] && bdfs=(${pci_bus_cache["$dev_id"]})
		[[ $dev_type == *VIRT* ]] && bdfs=(${pci_bus_cache["0x1af4:$dev_id"]})
		[[ $dev_type =~ (NVME|IOAT|IDXD|VIRTIO|VMD) ]] && dev_type=${BASH_REMATCH[1],,}
		
        for bdf in "${bdfs[@]}"; do
			in_use=0
            
			eval "${dev_type}_d[$bdf]=$in_use"
			all_devices_d["$bdf"]=$in_use
			if [[ -e /sys/bus/pci/devices/$bdf/driver ]]; then
				driver=$(readlink -f "/sys/bus/pci/devices/$bdf/driver")
				drivers_d["$bdf"]=${driver##*/}
			fi
		done	    
    done < <(grep -E "$ids" "$rootdir/pci_ids.txt")
}

function collect_driver() 
{
	local bdf=$1
	local drivers driver

	[[ -e /sys/bus/pci/devices/$bdf/modalias ]] || return 1
    
	if drivers=($(modprobe -R "$(< "/sys/bus/pci/devices/$bdf/modalias")")); then
		# Pick first entry in case multiple aliases are bound to a driver.
		driver=$(readlink -f "/sys/module/${drivers[0]}/drivers/pci:"*)
		driver=${driver##*/}
	else
		[[ -n ${nvme_d["$bdf"]} ]] && driver=nvme
	fi 2> /dev/null
    
	echo "$driver"
}

function configure_linux_pci() 
{
	local driver_path=""
	driver_name=""

	if modinfo uio_pci_generic > /dev/null 2>&1; then
		driver_name=uio_pci_generic
	else
		echo "uio_pci_generic driver not found!"		
		return 1
	fi

    modprobe $driver_name

	for bdf in "${!all_devices_d[@]}"; do
		if ((all_devices_d["$bdf"] == 0)); then
			if [[ -n ${nvme_d["$bdf"]} ]]; then				                
                linux_bind_driver "$bdf" "$driver_name" &
			else
				linux_bind_driver "$bdf" "$driver_name"
			fi
		fi
	done
    
	wait

	echo "1" > "/sys/bus/pci/rescan"
}

function reset_linux_pci() 
{
	for bdf in "${!all_devices_d[@]}"; do
		((all_devices_d["$bdf"] == 0)) || continue

		driver=$(collect_driver "$bdf")
		if ! check_for_driver "$driver"; then
			linux_bind_driver "$bdf" "$driver"
		else
            #no device
			linux_unbind_driver "$bdf"
		fi
	done

	echo "1" > "/sys/bus/pci/rescan"
}

CMD=reset cache_pci_bus

mode=$1

if [ -z "$mode" ]; then
	mode="config"
fi

collect_devices "$mode"

if [ "$mode" == "config" ]; then	
    configure_linux_pci
elif [ "$mode" == "reset" ]; then
    reset_linux_pci    
else
    echo "Invalid argument '$mode'"
fi
