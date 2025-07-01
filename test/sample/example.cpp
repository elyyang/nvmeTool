
#include "mmio.h"
#include "udma.h"
#include "pcie.h"

void demo(void)
{
    int uioId = 0;
    mmio_c& mmioDriver = mmio_c::getInstance(uioId);
    pcie_c& pcieDriver = pcie_c::getInstance(uioId);
    udma_c& udmaDriver = udma_c::getInstance();

    //example on mmio drv to mem access via bar 0
    printf("Bar0 Address: 0x%lx \n", mmioDriver.getBar0Address());
  
    //example on udma drv
    udmaDriver.getUdmaBufferInformation();

    //example on pcie drv
    pcieConfigurationHeader_t shadow = pcieDriver.getPcieConfigHeader();  
    printf("vendor id: %x device id: %x \n", shadow.dw0.vendorId, shadow.dw0.deviceId);

    pcieDriver.getPcieCapability();
    pcieDriver.getPcieExtendedCapability();
}