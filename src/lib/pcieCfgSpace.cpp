/********************************************************************************************
*  _  ___   ____  __    _____         _ _  ___ _   
* | \| \ \ / /  \/  |__|_   _|__  ___| | |/ (_) |_ 
* | .` |\ V /| |\/| / -_)| |/ _ \/ _ \ | ' <| |  _|
* |_|\_| \_/ |_|  |_\___||_|\___/\___/_|_|\_\_|\__|
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

#include "pcieCfgSpace.h"

pcieCfgSpace_c::pcieCfgSpace_c()
{
}

pcieCfgSpace_c::~pcieCfgSpace_c()    
{	
}

pcieCfgSpace_c& pcieCfgSpace_c::getInstance()
{
    static pcieCfgSpace_c mInstance;
    return mInstance;
}


void pcieCfgSpace_c::setBusMasterEnable(int uioId, bool status) const
{
    uio_c& uioDrv = uio_c::getInstance(uioId);
    
    commandReg_t reg;
    pread(uioDrv.mUioConfig_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_SPACE_HEADER_OFFSET_COMMAND);
    reg.busMasterEnable = status;
    pwrite(uioDrv.mUioConfig_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_SPACE_HEADER_OFFSET_COMMAND);
}

pcieConfigurationHeader_t pcieCfgSpace_c::getPcieConfigHeader(int uioId) const
{   
    uio_c& uioDrv = uio_c::getInstance(uioId);
    
    pcieConfigurationHeader_t configSpace;
    pread(uioDrv.mUioConfig_fd, &configSpace, sizeof(pcieConfigurationHeader_t), 0x0);
    return configSpace;    
}

bool pcieCfgSpace_c::getBusMasterEnable(int uioId) const
{    
    uio_c& uioDrv = uio_c::getInstance(uioId);

    commandReg_t reg;
    pread(uioDrv.mUioConfig_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_SPACE_HEADER_OFFSET_COMMAND);    
    return reg.busMasterEnable;
}

capability_msix_t pcieCfgSpace_c::getMsixCapability(int uioId) const
{
    uint8_t capPtr;
    uint8_t nextCapPtr;
    uint8_t capId;
    
    uio_c& uioDrv = uio_c::getInstance(uioId);

    capability_msix_t shadow = {};
    pcieConfigurationHeader_t  configSpace;
    pread(uioDrv.mUioConfig_fd, &configSpace, sizeof(pcieConfigurationHeader_t), 0x0);    
        
    if(configSpace.type0.status.capabilityList)
    {   
        nextCapPtr = configSpace.type0.capPtr;            

        while(nextCapPtr != PCIE_EXT_CAP_ID_NULL)
        {
            capPtr = nextCapPtr;
            pread(uioDrv.mUioConfig_fd, &nextCapPtr, 1, (capPtr+0x1));
            pread(uioDrv.mUioConfig_fd, &capId, 1, capPtr);    
            
            if(capId == PCIE_CAP_ID_MSIX)
            {
                pread(uioDrv.mUioConfig_fd, &shadow, sizeof(capability_msix_t), capPtr);                    
            }
        }
    }  
    else
    {
        printf("WARNING: PCIe capability list not present! \n");
    }
 
    return shadow;
}

