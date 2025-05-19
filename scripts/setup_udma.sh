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

    if [[ -z $bufferSize ]]; then
        bufferSize=0x100000
    fi

    echo "buffer size: " $bufferSize    
}

function get_buffer_count
{
    #grep udma define header to for buffer count
    while read -r _ _ VAL; do
        bufferCount=$VAL       
    done < <(grep -E $defineBufferCountKeyWord $definePath)

    if [[ -z $bufferCount ]]; then
        bufferCount=1
    fi

    echo "buffer count: " $bufferCount
}

########################################################################################################################

mode=$1

if [ -z "$mode" ]; then
	mode="config"
fi

if [ "$mode" == "config" ]; then	

    get_buffer_size
    get_buffer_count

    if ( lsmod | grep -E "$module_name" > /dev/null 2>&1 ); then    
        echo "udma module available!"
    else    
        echo "installing udma module...."

        if [[ ! -d $cloneDir ]]; then        
            echo "cloning repo...."        
            echo "running: git clone $repoURL $cloneDir"
            echo $(git clone $repoURL $cloneDir 2>&1)        
            cd $cloneDir
            make all
        else
            cd $cloneDir
            if [[ ! -e $module ]]; then    
                make all
            fi
        fi

        insmodCmd="sudo insmod $module "

        for bufferIndex in $(seq 0 $((bufferCount - 1))); do
            insmodCmd+=" udmabuf"${bufferIndex}=$bufferSize" "
        done

        echo "running: $insmodCmd"
        echo $($insmodCmd 2>&1)
    fi

elif [ "$mode" == "reset" ]; then

    echo "removing udma module...."
    rmmodCmd="sudo rmmod $module_name"
    echo "running: $rmmodCmd"
    echo $($rmmodCmd 2>&1)
    
else

    echo "Invalid argument '$mode'"

fi