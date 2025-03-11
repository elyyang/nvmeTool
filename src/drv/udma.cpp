
#include "udma.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

//=========================================================================

#define UDMA_BUFF_DEFAULT_SIZE      0x400000
#define UDMA_BUFFER_COUNT           8

udma_c::udma_c(void)
{    
    printf("udma constructor! \n");

    udmaBuffer0_fd = open("/dev/udmabuf0", O_RDWR);
    udmaBuffer1_fd = open("/dev/udmabuf1", O_RDWR);
    udmaBuffer2_fd = open("/dev/udmabuf2", O_RDWR);
    udmaBuffer3_fd = open("/dev/udmabuf3", O_RDWR);
    udmaBuffer4_fd = open("/dev/udmabuf4", O_RDWR);
    udmaBuffer5_fd = open("/dev/udmabuf5", O_RDWR);
    udmaBuffer6_fd = open("/dev/udmabuf6", O_RDWR);
    udmaBuffer7_fd = open("/dev/udmabuf7", O_RDWR);

    udmaBuffPhysAddr0_fd = open("/sys/class/u-dma-buf/udmabuf0/phys_addr", O_RDONLY);
    udmaBuffPhysAddr1_fd = open("/sys/class/u-dma-buf/udmabuf1/phys_addr", O_RDONLY);
    udmaBuffPhysAddr2_fd = open("/sys/class/u-dma-buf/udmabuf2/phys_addr", O_RDONLY);
    udmaBuffPhysAddr3_fd = open("/sys/class/u-dma-buf/udmabuf3/phys_addr", O_RDONLY);
    udmaBuffPhysAddr4_fd = open("/sys/class/u-dma-buf/udmabuf4/phys_addr", O_RDONLY);
    udmaBuffPhysAddr5_fd = open("/sys/class/u-dma-buf/udmabuf5/phys_addr", O_RDONLY);
    udmaBuffPhysAddr6_fd = open("/sys/class/u-dma-buf/udmabuf6/phys_addr", O_RDONLY);        
    udmaBuffPhysAddr7_fd = open("/sys/class/u-dma-buf/udmabuf7/phys_addr", O_RDONLY);

    udmaBuffSize0_fd = open("/sys/class/u-dma-buf/udmabuf0/size", O_RDONLY);
    udmaBuffSize1_fd = open("/sys/class/u-dma-buf/udmabuf1/size", O_RDONLY);       
    udmaBuffSize2_fd = open("/sys/class/u-dma-buf/udmabuf2/size", O_RDONLY);
    udmaBuffSize3_fd = open("/sys/class/u-dma-buf/udmabuf3/size", O_RDONLY);
    udmaBuffSize4_fd = open("/sys/class/u-dma-buf/udmabuf4/size", O_RDONLY);
    udmaBuffSize5_fd = open("/sys/class/u-dma-buf/udmabuf5/size", O_RDONLY);
    udmaBuffSize6_fd = open("/sys/class/u-dma-buf/udmabuf6/size", O_RDONLY);
    udmaBuffSize7_fd = open("/sys/class/u-dma-buf/udmabuf7/size", O_RDONLY);

    
    
    
    char attr[1024];        
    read(udmaBuffSize0_fd, attr, 1024);
    sscanf(attr, "%p", &size0);

    read(udmaBuffPhysAddr0_fd, attr, 1024);
    sscanf(attr, "%p", &physAddr0); 


    printf("udma 0 buffer size: 0x%lx physical address: 0x%lx \n\n", (uint64_t)size0, (uint64_t)physAddr0);

   #if 0
    read(udmaBuffSize0_fd, &size0, 1024);
    read(udmaBuffSize1_fd, &size1, 1024);
    read(udmaBuffSize2_fd, &size2, 1024);
    read(udmaBuffSize3_fd, &size3, 1024);
    read(udmaBuffSize4_fd, &size4, 1024);
    read(udmaBuffSize5_fd, &size5, 1024);
    read(udmaBuffSize6_fd, &size6, 1024);
    read(udmaBuffSize7_fd, &size7, 1024);

    read(udmaBuffPhysAddr0_fd, &physAddr0, 1024);
    read(udmaBuffPhysAddr1_fd, &physAddr1, 1024);
    read(udmaBuffPhysAddr2_fd, &physAddr2, 1024);
    read(udmaBuffPhysAddr3_fd, &physAddr3, 1024);
    read(udmaBuffPhysAddr4_fd, &physAddr4, 1024);
    read(udmaBuffPhysAddr5_fd, &physAddr5, 1024);
    read(udmaBuffPhysAddr6_fd, &physAddr6, 1024);
    read(udmaBuffPhysAddr7_fd, &physAddr7, 1024);
    #endif
}

udma_c::~udma_c(void)
{   
    printf("udma de-constructor! \n");


}

udma_c& udma_c::getInstance(void)
{
    static udma_c instance;
    return instance;
}

void udma_c::getUdmaBufferInformation(void)
{
    #if 0
    printf("ubuff 0 size: %ld physical address: 0x%lx \n", (uint64_t)size0, (uint64_t)physAddr0);
    printf("ubuff 1 size: %ld physical address: 0x%lx \n", (uint64_t)size1, (uint64_t)physAddr1);
    printf("ubuff 2 size: %ld physical address: 0x%lx \n", (uint64_t)size2, (uint64_t)physAddr2);
    printf("ubuff 3 size: %ld physical address: 0x%lx \n", (uint64_t)size3, (uint64_t)physAddr3);
    printf("ubuff 4 size: %ld physical address: 0x%lx \n", (uint64_t)size4, (uint64_t)physAddr4);
    printf("ubuff 5 size: %ld physical address: 0x%lx \n", (uint64_t)size5, (uint64_t)physAddr5);
    printf("ubuff 6 size: %ld physical address: 0x%lx \n", (uint64_t)size6, (uint64_t)physAddr6);    
    printf("ubuff 7 size: %ld physical address: 0x%lx \n", (uint64_t)size7, (uint64_t)physAddr7); 
    #endif
}