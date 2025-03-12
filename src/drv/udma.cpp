
#include "udma.h"

//=========================================================================

udma_c::udma_c(void)
{    
    printf("initialize udma_c! \n");
    
    #define BYTES_TO_READ 64    
    char fdIdx[BYTES_TO_READ];    
    char fdPath[BYTES_TO_READ];
    
    for(int idx=0; idx<UDMA_BUFFER_COUNT; idx++)
    {
        sprintf(fdIdx, "%d", idx);
     
        strcpy(fdPath, "/dev/udmabuf");
        strcat(fdPath, fdIdx);
        
        udmaBuffer_fd[idx] = open(fdPath, O_RDWR);           
        bufferAddress[idx] = mmap(NULL, UDMA_BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, udmaBuffer_fd[idx], 0);        

        strcpy(fdPath, "/sys/class/u-dma-buf/udmabuf");
        strcat(fdPath, fdIdx);
        strcat(fdPath, "/phys_addr");

        udmaBufferPhysicalAddress_fd[idx] = open(fdPath, O_RDONLY);
        
        char buffer[BYTES_TO_READ];

        read(udmaBufferPhysicalAddress_fd[idx], buffer, 1024);
        sscanf(buffer, "%p", &bufferPhysicalAddress[idx]);
    }

}

udma_c::~udma_c(void)
{   
    printf("clean-up udma_c! \n");

    for(int idx=0; idx<UDMA_BUFFER_COUNT; idx++)
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

void udma_c::getUdmaBufferInformation(void)
{    
    printf("udma buffer 0 address: 0x%lx physical address: 0x%lx \n", (uint64_t)bufferAddress[0], (uint64_t)bufferPhysicalAddress[0]);
    printf("udma buffer 1 address: 0x%lx physical address: 0x%lx \n", (uint64_t)bufferAddress[1], (uint64_t)bufferPhysicalAddress[1]);
    printf("udma buffer 2 address: 0x%lx physical address: 0x%lx \n", (uint64_t)bufferAddress[2], (uint64_t)bufferPhysicalAddress[2]);
    printf("udma buffer 3 address: 0x%lx physical address: 0x%lx \n", (uint64_t)bufferAddress[3], (uint64_t)bufferPhysicalAddress[3]);
    printf("udma buffer 4 address: 0x%lx physical address: 0x%lx \n", (uint64_t)bufferAddress[4], (uint64_t)bufferPhysicalAddress[4]);
    printf("udma buffer 5 address: 0x%lx physical address: 0x%lx \n", (uint64_t)bufferAddress[5], (uint64_t)bufferPhysicalAddress[5]);
    printf("udma buffer 6 address: 0x%lx physical address: 0x%lx \n", (uint64_t)bufferAddress[6], (uint64_t)bufferPhysicalAddress[6]);    
    printf("udma buffer 7 address: 0x%lx physical address: 0x%lx \n", (uint64_t)bufferAddress[7], (uint64_t)bufferPhysicalAddress[7]); 
}

uint64_t udma_c::getBufferAddress(uint32_t bufferIndex)
{
    return (uint64_t)bufferAddress[bufferIndex];
};

uint64_t udma_c::getBufferPhysicalAddress(uint32_t bufferIndex)
{
    return (uint64_t)bufferPhysicalAddress[bufferIndex];
};

