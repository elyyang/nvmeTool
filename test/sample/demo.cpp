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

#include "udma.h"
#include "uio.h"
#include "controller.h"
#include "pcieHandler.h"
#include "menu.h"

#include "demo.h"

extern int g_uioId;

void demo_udma()
{
    udma_c& udmaDriver = udma_c::getInstance();

    //example on udma drv
    udmaDriver.dumpUdmaBufferInformation();
}

void demo_uio()
{
    uio_c& uioDriver = uio_c::getInstance(g_uioId);
    pcieHandler_c& pcieDrv = pcieHandler_c::getInstance();

    //example on uio drv to mem access 
    printf("Bar0 Address: 0x%lx \n", uioDriver.getBar0Address());    
    printf("BME status: %d \n", pcieDrv.getBusMasterEnable(uioDriver));

    capability_msix_t msixShadow = pcieDrv.getMsixCapability(uioDriver);
    printf("MSIX table BIR: 0x%x \n", msixShadow.msixTableBir);
    printf("MSIX table offset: 0x%x \n", msixShadow.msixTableOffset*8);
    printf("MSIX pba offset: 0x%x \n", msixShadow.pbaOffset*8);
    
    pcieConfigurationHeader_t pcieHeaderShadow = pcieDrv.getPcieConfigHeader(uioDriver);
    printf("pcie vendor id: 0x%x \n", pcieHeaderShadow.dw0.vendorId);
    printf("pcie device id: 0x%x \n", pcieHeaderShadow.dw0.deviceId);
}

void demo_uio2()
{
    uio_c& uioDriver = uio_c::getInstance(g_uioId);
    uioDriver.dumpBar0MemorySpace(0, 12);
    uioDriver.dumpBar0MemorySpace(0x1000, 32);
}
