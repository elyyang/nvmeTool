
#include "mmio.h"
#include "pcie.h"
#include "udma.h"
#include "uio.h"

void demo(int uioId)
{
    mmio_c& mmioDriver = mmio_c::getInstance(uioId);
    pcie_c& pcieDriver = pcie_c::getInstance(uioId);

    uio_c& uioDriver = uio_c::getInstance(uioId);
    udma_c& udmaDriver = udma_c::getInstance();

    //example on uio drv to mem access 
    printf("Bar0 Address: 0x%lx (uio drv)\n", uioDriver.getBar0Address());

    //example on mmio drv to mem access via bar 0
    printf("Bar0 Address: 0x%lx (mmio drv)\n", mmioDriver.getBar0Address());
  
    //example on udma drv
    udmaDriver.getUdmaBufferInformation();

    //example on pcie drv
    pcieConfigurationHeader_t shadow = pcieDriver.getPcieConfigHeader();  
    printf("vendor id: 0x%x device id: 0x%x \n", shadow.dw0.vendorId, shadow.dw0.deviceId);

    pcieDriver.getPcieCapability();
    pcieDriver.getPcieExtendedCapability();
}