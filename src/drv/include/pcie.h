
#pragma once

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "pcieStructs.h"
#include "pciDefine.h"

//=========================================================================

class pcie_c
{
    private:

        pcie_c(int id);
        ~pcie_c();
        int uio_config_fd;
        
    public:

        static pcie_c& getInstance(int id);

        pcieConfigurationHeader_t getPcieConfigHeader(void);
        bool isCapabilitiesListPresent(void);                
        void setBusMasterEnable(bool status);
        bool getBusMasterEnable(void);        
        void setInterruptDisable(bool disable);
        bool getInterruptDisable(void);        
        void getPcieCapability(void);
        void getPcieExtendedCapability(void);        
        capability_msix_t getMsixCapability(void);
        void enableMsixCapability(void);
        uint32_t getMsixCapabilityTableSize(void);
};