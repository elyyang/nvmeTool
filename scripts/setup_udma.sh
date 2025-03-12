#!/usr/bin/env bash

########################################################################################################################

repoURL=https://github.com/ikwzm/udmabuf.git
cloneDir="./submodule/udmabuf"
module=u-dma-buf.ko
module_name=u_dma_buf
defineKeyWord="UDMA_BUFFER_SIZE"
definePath="../src/drv/include/udma.h"

########################################################################################################################

function get_buffer_size
{
    while read -r _ _ VAL; do
        size=$VAL       
    done < <(grep -E $defineKeyWord $definePath)
}

########################################################################################################################

get_buffer_size

if [[ ! -d $cloneDir ]]; then
    echo "cloning..."
    git clone $repoURL $cloneDir 2>&1    
fi

cd $cloneDir

if [[ ! -e $module ]]; then    
    make
fi

if ( lsmod | grep -E "$module_name" > /dev/null 2>&1 ); then    
    echo "udma module available!"
else    
    echo "installing udma module!"

    if [[ -z $size ]]; then
        size=0x400000
    fi

    insmodCmd="sudo insmod $module udmabuf0=$size udmabuf1=$size udmabuf2=$size udmabuf3=$size udmabuf4=$size udmabuf5=$size udmabuf6=$size udmabuf7=$size"
    insmodCmdRun=$($insmodCmd 2>&1)

    echo -n "running: $insmodCmd"
    echo "${insmodCmdRun}"
fi
