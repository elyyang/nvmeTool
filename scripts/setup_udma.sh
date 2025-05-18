#!/usr/bin/env bash

########################################################################################################################

rootdir=$(readlink -f $(dirname $0))/
repoURL=https://github.com/ikwzm/udmabuf.git
cloneDir="$rootdir/subrepo/udmabuf"
module=u-dma-buf.ko
module_name=u_dma_buf
defineBufferSizeKeyWord="DEFAULT_UDMA_BUFFER_SIZE"
defineBufferCountKeyWord="DEFAULT_UDMA_BUFFER_COUNT"
definePath="$rootdir../src/drv/include/udmaDefines.h"

########################################################################################################################

function get_buffer_size
{
    #grep udma define header to for buffer size
    while read -r _ _ VAL; do
        bufferSize=$VAL       
    done < <(grep -E $defineBufferSizeKeyWord $definePath)

    echo "buffer size: " $bufferSize    
}

function get_buffer_count
{
    #grep udma define header to for buffer count
    while read -r _ _ VAL; do
        bufferCount=$VAL       
    done < <(grep -E $defineBufferCountKeyWord $definePath)

    echo "buffer count: " $bufferCount    
}

########################################################################################################################

get_buffer_size
get_buffer_count

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
    echo "installing udma module...."

    if [[ -z $bufferSize ]]; then
        bufferSize=0x400000
    fi

    insmodCmd="sudo insmod $module"

    for bufferIndex in $(seq 0 $bufferCount); do
        insmodCmd+=" udmabuf"${bufferIndex}=$bufferSize
    done

    insmodCmdRun=$($insmodCmd 2>&1)

    echo -n "running: $insmodCmd"
    echo "${insmodCmdRun}"
fi
