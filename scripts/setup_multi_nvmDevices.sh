##############################################################################################################
#                              _              _   ____    ___  
#  _ ____   ___ __ ___   ___  | |_ ___   ___ | | |___ \  / _ \ 
# | '_ \ \ / / '_ ` _ \ / _ \ | __/ _ \ / _ \| |   __) || | | |
# | | | \ V /| | | | | |  __/ | || (_) | (_) | |  / __/ | |_| |
# |_| |_|\_/ |_| |_| |_|\___|  \__\___/ \___/|_| |_____(_)___/ 
#                                                              
# MIT License
# 
# Copyright (c) 2026 Eric L. Yang
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# 
# https://github.com/elyyang
# elyyang@gmail.com
#
##############################################################################################################

#!/usr/bin/env bash

PCI_CLASS_STORAGE_NVME=0x010802

########################################################################################################################

cache_pci() 
{
	[[ -e /sys/bus/pci/devices ]] || return 1
	
	local -gA pci_device pci_driver

	pci_device=()	
	pci_driver=()

	local pci driver
	
	for pci in /sys/bus/pci/devices/*; do		
		
		pci_device["${pci##*/}"]=pci
				
		if [[ -e $pci/driver ]]; then
			driver=$(readlink -f "$pci/driver")
		else
			driver='no driver'
		fi

		pci_driver["${pci##*/}"]=${driver##*/}
	done
}

########################################################################################################################

function unbind
{
    echo "$VENDOR $DEVICE" > "/sys/bus/pci/devices/$BDF/driver/remove_id" 2> /dev/null || true
    echo "$BDF" > "/sys/bus/pci/devices/$BDF/driver/unbind"
}

function bind_driver
{   
	driver_name=$1

	if [ -e "/sys/bus/pci/drivers/$driver_name/" ];	then
		echo "$driver_name driver available!"
	else
		if modinfo $driver_name > /dev/null 2>&1; then
			modprobe $driver_name	
		else
			echo "$driver_name driver not found!"
			return 1
		fi    		
	fi

	local old_driver 
	old_driver=${pci_driver[$BDF]}
	if [[ $old_driver != 'no driver' ]]; then
		unbind		
	fi

    echo "$VENDOR $DEVICE" > "/sys/bus/pci/drivers/$driver_name/new_id" 2> /dev/null || true
    echo "$BDF" > "/sys/bus/pci/drivers/$driver_name/bind" 2> /dev/null || true

	local new_driver
	new_driver=$(readlink -f "/sys/bus/pci/devices/$BDF/driver")
	echo "$old_driver -> ${new_driver##*/}"

	echo "1" > "/sys/bus/pci/rescan"
}

########################################################################################################################

function list_compatible_devices
{		
	tabs -2
	index=0
	for pci in /sys/bus/pci/devices/*; do

		class=$(< "$pci/class")
		driver=$(readlink -f "$pci/driver")

		if [[ $PCI_CLASS_STORAGE_NVME = $class ]]; then
			echo -e -n 'pci device: '$index '\t' ${pci##*/}

			if [[ -e $pci/driver ]]; then
				echo  -e '\t' ${driver##*/}			
			else
				echo  -e '\t' "(no driver)"
			fi
		fi
		
		((index++))
	done
}

function show_assigned_bdf
{	
	VENDOR=$(setpci -s $BDF VENDOR_ID) 
	DEVICE=$(setpci -s $BDF DEVICE_ID)
	echo "target pci device: $BDF (vendor: 0x$VENDOR device: 0x$DEVICE)"
}

function assign_bdf
{
	local -gA BDF
	local index=0

	for i in /sys/bus/pci/devices/*; do			
		if [[ $1 -eq $index ]]; then
			BDF=${i##*/}
			show_assigned_bdf
		fi
		((index++))
	done
}

########################################################################################################################
# menu
########################################################################################################################

cache_pci all

PS3="Enter selection: "
options=("list nvme devices" "bind uio driver" "unbind uio driver" "quit")

select opt in "${options[@]}"
do
    case $opt in
		"list nvme devices")
			echo -e "\n=================================================="
			list_compatible_devices
			echo -e "==================================================\n"
			;;
        "bind uio driver")			
			echo -e "\n=================================================="
			list_compatible_devices
			echo -e "==================================================\n"
			echo -n "Select pci device: "			
			read sel			
			if [[ ! -z $sel ]]; then
				assign_bdf $sel
		    	bind_driver uio_pci_generic
				cache_pci all
			fi
			;;
		"unbind uio driver")			
			echo -e "\n=================================================="
			list_compatible_devices
			echo -e "==================================================\n"			
			echo -n "Select pci device: "
			read sel
			if [[ ! -z $sel ]]; then
				assign_bdf $sel			
				bind_driver nvme
				cache_pci all
			fi						
			;;        
		"quit")			
            break
            ;;
        *)
            echo "invalid option: $REPLY"
			echo -e "\n"			
            ;;
    esac
done