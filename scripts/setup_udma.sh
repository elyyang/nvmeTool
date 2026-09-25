#!/usr/bin/env bash

##############################################################################################################
#  _  ___   ____  __    _____         _ _  ___ _   
# | \| \ \ / /  \/  |__|_   _|__  ___| | |/ (_) |_ 
# | .` |\ V /| |\/| / -_)| |/ _ \/ _ \ | ' <| |  _|
# |_|\_| \_/ |_|  |_\___||_|\___/\___/_|_|\_\_|\__|
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

########################################################################################################################

rootdir=$(readlink -f $(dirname $0))/
repoURL=https://github.com/ikwzm/udmabuf.git
cloneDir="$rootdir/../subrepo/udmabuf"
module=u-dma-buf.ko
module_name=u_dma_buf
defaultsBufferSize=0x400000
defineBufferCountKeyWord="DEFAULT_UDMA_BUFFER_COUNT"
definePath="$rootdir../src/drv/include/udma.h"

########################################################################################################################

function get_buffer_size
{
    bufferSize=$defaultsBufferSize
    echo "buffer size: " $bufferSize    
}

function get_buffer_count
{
    bufferCount=$(awk -v key="$defineBufferCountKeyWord" '$1 == "#define" && $2 == key { print $3; exit }' "$definePath")

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
    

elif [ "$mode" == "clean" ]; then

    echo "removing udma module...."
    rmmodCmd="sudo rmmod $module_name"
    echo "running: $rmmodCmd"
    echo $($rmmodCmd 2>&1)
    echo "delete subrepo $cloneDir...."
    sudo rm -rf "$cloneDir"

else

    echo "Invalid argument '$mode'"

fi