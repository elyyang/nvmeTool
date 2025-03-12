
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

//=========================================================================

#define UDMA_BUFFER_SIZE    0x400000
#define UDMA_BUFFER_COUNT   8

class udma_c
{
    private:

        udma_c();        
        ~udma_c();
        int udmaBuffer_fd[UDMA_BUFFER_COUNT];
        int udmaBufferPhysicalAddress_fd[UDMA_BUFFER_COUNT];        
        void* bufferAddress[UDMA_BUFFER_COUNT];
        void* bufferPhysicalAddress[UDMA_BUFFER_COUNT];
        
    public:

        static udma_c& getInstance(void);                
        void getUdmaBufferInformation(void);
        uint64_t getBufferAddress(uint32_t bufferIndex);
        uint64_t getBufferPhysicalAddress(uint32_t bufferIndex);
        
};

