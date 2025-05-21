
#include <stdio.h>
#include <stdint.h>

#include "mmio.h"
#include "udma.h"
#include "pcie.h"
#include "debugPrint.h"

int main(void)
{
  mmio_c& mmioDriver = mmio_c::getInstance(0);
  udma_c& udmaDriver = udma_c::getInstance();
  pcie_c& pcieDriver = pcie_c::getInstance();

  printf("Bar0 Address: 0x%lx \n", mmioDriver.getBar0Address());
  
  udmaDriver.getUdmaBufferInformation();

  pcieConfigurationHeader_t shadow = pcieDriver.getPcieConfigHeader();  
  printf("vendor id: %x device id: %x \n", shadow.vendorId, shadow.deviceId);

  printf("NVMe 2.0 Tool All done! \n");
  return 0;
}
