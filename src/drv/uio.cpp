/********************************************************************************************
*                              _              _   ____    ___  
*  _ ____   ___ __ ___   ___  | |_ ___   ___ | | |___ \  / _ \ 
* | '_ \ \ / / '_ ` _ \ / _ \ | __/ _ \ / _ \| |   __) || | | |
* | | | \ V /| | | | | |  __/ | || (_) | (_) | |  / __/ | |_| |
* |_| |_|\_/ |_| |_| |_|\___|  \__\___/ \___/|_| |_____(_)___/ 
*                                                              
* MIT License
* 
* Copyright (c) 2026 Eric L. Yang
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* 
* https://github.com/elyyang
* elyyang@gmail.com
*
*********************************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "uio.h"
#include "assertLib.h"
#include "debugPrint.h"
#include "pcieStructs.h"
#include "nvmeStructs.h"

uio_c::uio_c(int id)
{
    #define BYTES_TO_READ 64    
    char fdPath[BYTES_TO_READ];    
    char fdIdx[BYTES_TO_READ];    

    NVME_DBG_PRINTF(info, "initialize uio_c!");
    
    mUioId = id;
    sprintf(fdIdx, "%d", mUioId);

    //pcie config space
    strcpy(fdPath, "/sys/class/uio/uio");
    strcat(fdPath, fdIdx);
    strcat(fdPath, "/device/config");
    mUioConfig_fd = open(fdPath, O_RDWR | O_SYNC);
    NVME_DBG_ASSERT((mUioConfig_fd>0), "mUioConfig_fd failed to open!")

    //pcie bar0
    strcpy(fdPath, "/sys/class/uio/uio");
    strcat(fdPath, fdIdx);
    strcat(fdPath, "/device/resource0");
    mUioResource0_fd = open(fdPath, O_RDWR | O_SYNC);    
    NVME_DBG_ASSERT((mUioResource0_fd>0), "mUioResource0_fd failed to open!")
    mPfBar0Address = mmap(NULL, NVM_CONTROLLER_MMIO_REG_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mUioResource0_fd, 0);   
    NVME_DBG_ASSERT((mPfBar0Address!=MAP_FAILED), "pfBar0Address map failed!")        
}

uio_c::~uio_c()
{        
    NVME_DBG_PRINTF(info, "clean-up uio_c!");
    close(mUioConfig_fd);    
    close(mUioResource0_fd);
    munmap(mPfBar0Address, NVM_CONTROLLER_MMIO_REG_SIZE);   
}

uio_c& uio_c::getInstance(int id)
{
    static uio_c mInstance(id);
    return mInstance;
}

uintptr_t uio_c::getBar0Address() const
{
    return (uintptr_t)mPfBar0Address;
}

int uio_c::getId() const
{
    return mUioId;
}

void uio_c::dumpNvmeControllerMem(uint32_t itr, uint32_t offset) const
{
    NVME_DBG_ASSERT((offset%0x8)==0, "offset must in multiples of 0x8")
    NVME_DBG_ASSERT_IF_GREATER_THAN((offset+(itr*0x8)), 0x4000, "out of range")

    for(uint32_t i=0; i<itr; i++)
    {
        printf("%.02xh: \t 0x%.16lx \n", (0x8*i)+offset, *(uint64_t*)((uint64_t)mPfBar0Address+(0x8*i)+offset)); 
    }    
}
