
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
#include "pciDefine.h"
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
    mPfBar0 = mmap(NULL, NVM_CONTROLLER_MMIO_REG_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mUioResource0_fd, 0);   
    NVME_DBG_ASSERT((mPfBar0!=MAP_FAILED), "pfBar0Address map failed!")        
}

uio_c::~uio_c()
{        
    NVME_DBG_PRINTF(info, "clean-up uio_c!");
    close(mUioConfig_fd);    
    close(mUioResource0_fd);
    munmap(mPfBar0, NVM_CONTROLLER_MMIO_REG_SIZE);   
}

uio_c& uio_c::getInstance(int id)
{
    static uio_c mInstance(id);
    return mInstance;
}

uintptr_t uio_c::getBar0Address() const
{
    return (uintptr_t)mPfBar0;
}

pcieConfigurationHeader_t uio_c::getPcieConfigHeader(void) const
{   
    pcieConfigurationHeader_t configSpace;
    pread(mUioConfig_fd, &configSpace, sizeof(pcieConfigurationHeader_t), 0x0);
    return configSpace;    
}

void uio_c::setBusMasterEnable(bool bmeStatus)
{
    commandReg_t reg;
    pread(mUioConfig_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_HEADER_OFFSET_COMMAND);
    reg.busMasterEnable = bmeStatus;
    pwrite(mUioConfig_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_HEADER_OFFSET_COMMAND);
}

bool uio_c::getBusMasterEnable(void) const
{    
    commandReg_t reg;
    pread(mUioConfig_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_HEADER_OFFSET_COMMAND);    
    return reg.busMasterEnable;
}

capability_msix_t uio_c::getMsixCapability(void) const
{
    uint8_t capPtr;
    uint8_t nextCapPtr;
    uint8_t capId;
    
    capability_msix_t shadow;
    memset(&shadow, 0, sizeof(capability_msix_t)); 
    
    pcieConfigurationHeader_t  configSpace;
    pread(mUioConfig_fd, &configSpace, sizeof(pcieConfigurationHeader_t), 0x0);    
        
    if(configSpace.dw1.status.capabilityList)
    {   
        nextCapPtr = configSpace.dw13.capPtr;            

        while(nextCapPtr != PCIE_EXT_CAP_ID_NULL)
        {
            capPtr = nextCapPtr;
            pread(mUioConfig_fd, &nextCapPtr, 1, (capPtr+0x1));
            pread(mUioConfig_fd, &capId, 1, capPtr);    
            
            if(capId == PCIE_CAP_ID_MSIX)
            {
                pread(mUioConfig_fd, &shadow, sizeof(capability_msix_t), capPtr);                    
            }
        }
    }  
    else
    {
        printf("WARNING: PCIe capability list not present! \n");
    }
 
    return shadow;
}