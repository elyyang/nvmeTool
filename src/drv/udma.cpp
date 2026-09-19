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

#include "udma.h"
#include "assertLib.h"
#include "debugPrint.h"

udma_c::udma_c(void)
{    
    NVME_DBG_PRINTF(info, "initialize udma_c!");
    
    #define BYTES_TO_READ 64    
    char fdIdx[BYTES_TO_READ];    
    char fdPath[BYTES_TO_READ];
    
    for(uint32_t idx=0; idx<UDMA_BUFFER_COUNT; idx++)
    {
        sprintf(fdIdx, "%d", idx);
     
        strcpy(fdPath, "/dev/udmabuf");
        strcat(fdPath, fdIdx);
        
        udmaBuffer_fd[idx] = open(fdPath, O_RDWR | O_SYNC);       
        NVME_DBG_ASSERT((udmaBuffer_fd[idx]>0), "udmaBuffer_fd failed to open!")

        bufferAddress[idx] = mmap(NULL, UDMA_BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, udmaBuffer_fd[idx], 0);        
        NVME_DBG_ASSERT((bufferAddress[idx]!=MAP_FAILED), "bufferAddress map failed!")    

        strcpy(fdPath, "/sys/class/u-dma-buf/udmabuf");
        strcat(fdPath, fdIdx);
        strcat(fdPath, "/phys_addr");

        udmaBufferPhysicalAddress_fd[idx] = open(fdPath, O_RDONLY);
        NVME_DBG_ASSERT((udmaBufferPhysicalAddress_fd[idx]>0), "udmaBufferPhysicalAddress_fd failed to open!")

        char buffer[BYTES_TO_READ];

        read(udmaBufferPhysicalAddress_fd[idx], buffer, 64);
        sscanf(buffer, "%p", &bufferPhysicalAddress[idx]);
    }

}

udma_c::~udma_c(void)
{   
    NVME_DBG_PRINTF(info, "clean-up udma_c!");    

    for(uint32_t idx=0; idx<UDMA_BUFFER_COUNT; idx++)
    {
        close(udmaBuffer_fd[idx]);
        close(udmaBufferPhysicalAddress_fd[idx]);        
        munmap(bufferAddress[idx], UDMA_BUFFER_SIZE);
    } 
}

udma_c& udma_c::getInstance(void)
{
    static udma_c instance;
    return instance;
}

uint64_t udma_c::getBufferAddress(uint32_t bufferIndex)
{
    return (uint64_t)bufferAddress[bufferIndex];
};

uint64_t udma_c::getBufferPhysicalAddress(uint32_t bufferIndex)
{
    return (uint64_t)bufferPhysicalAddress[bufferIndex];
};

void udma_c::getUdmaBufferInformation(void)
{   
    for(uint32_t i=0; i<UDMA_BUFFER_COUNT; i++)
    {
        printf("udma buffer %d address: 0x%lx physical address: 0x%lx \n", i, (uint64_t)bufferAddress[i], (uint64_t)bufferPhysicalAddress[i]);    
    }
}
