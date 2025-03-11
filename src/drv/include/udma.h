
#pragma once

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

//=========================================================================

class udma_c
{
    private:

        udma_c();        
        ~udma_c();

        int udmaBuffer0_fd;
        int udmaBuffer1_fd;
        int udmaBuffer2_fd;
        int udmaBuffer3_fd;
        int udmaBuffer4_fd;
        int udmaBuffer5_fd;
        int udmaBuffer6_fd;
        int udmaBuffer7_fd;

        int udmaBuffPhysAddr0_fd;
        int udmaBuffPhysAddr1_fd;
        int udmaBuffPhysAddr2_fd;
        int udmaBuffPhysAddr3_fd;
        int udmaBuffPhysAddr4_fd;
        int udmaBuffPhysAddr5_fd;
        int udmaBuffPhysAddr6_fd;        
        int udmaBuffPhysAddr7_fd;

        int udmaBuffSize0_fd;
        int udmaBuffSize1_fd;       
        int udmaBuffSize2_fd;
        int udmaBuffSize3_fd;
        int udmaBuffSize4_fd;
        int udmaBuffSize5_fd;
        int udmaBuffSize6_fd;
        int udmaBuffSize7_fd;

        void* baseAddr0;
        void* baseAddr1;
        void* baseAddr2;
        void* baseAddr3;
        void* baseAddr4;
        void* baseAddr5;
        void* baseAddr6;
        void* baseAddr7;

        void* physAddr0;
        void* physAddr1;
        void* physAddr2;
        void* physAddr3;
        void* physAddr4;
        void* physAddr5;
        void* physAddr6;
        void* physAddr7;

        void* size0;
        void* size1;
        void* size2;
        void* size3;
        void* size4;        
        void* size5;
        void* size6;
        void* size7;

    public:

        static udma_c& getInstance(void);
                
        void getUdmaBufferInformation(void);        
};

