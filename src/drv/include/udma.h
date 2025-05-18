
#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#include "udmaDefines.h"

class udma_c
{
    private:

        udma_c();        
        ~udma_c();

        static const uint32_t UDMA_BUFFER_SIZE = DEFAULT_UDMA_BUFFER_SIZE;
        static const uint32_t UDMA_BUFFER_COUNT = DEFAULT_UDMA_BUFFER_COUNT;        

        int udmaBuffer_fd[UDMA_BUFFER_COUNT];
        int udmaBufferPhysicalAddress_fd[UDMA_BUFFER_COUNT];        
        void* bufferAddress[UDMA_BUFFER_COUNT];
        void* bufferPhysicalAddress[UDMA_BUFFER_COUNT];
        
    public:

        static udma_c& getInstance(void);      

        uint64_t getBufferAddress(uint32_t bufferIndex);
        uint64_t getBufferPhysicalAddress(uint32_t bufferIndex);

        void getUdmaBufferInformation(void);
};

