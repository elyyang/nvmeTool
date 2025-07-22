
#include "udma.h"
#include "uio.h"

extern int g_uioId;

void demo_udma()
{
    udma_c& udmaDriver = udma_c::getInstance();

    //example on udma drv
    udmaDriver.getUdmaBufferInformation();
}

void demo_uio()
{
    uio_c& uioDriver = uio_c::getInstance(g_uioId);

    //example on uio drv to mem access 
    printf("Bar0 Address: 0x%lx \n", uioDriver.getBar0Address());    
    printf("BME status: %d \n", uioDriver.getBusMasterEnable());

    capability_msix_t msixShadow = uioDriver.getMsixCapability();
    printf("MSIX table BIR: 0x%x \n", msixShadow.msixTableBir);
    printf("MSIX table offset: 0x%x \n", msixShadow.msixTableOffset*8);
    printf("MSIX pba offset: 0x%x \n", msixShadow.pbaOffset*8);
    
    pcieConfigurationHeader_t pcieHeaderShadow = uioDriver.getPcieConfigHeader();
    printf("pcie vendor id: 0x%x \n", pcieHeaderShadow.dw0.vendorId);
    printf("pcie device id: 0x%x \n", pcieHeaderShadow.dw0.deviceId);    
}

void demo_uio2()
{
    uio_c& uioDriver = uio_c::getInstance(g_uioId);
    uioDriver.dumpNvmeControllerMem(4,0);
    uioDriver.dumpNvmeControllerMem(4,0x1000);
}