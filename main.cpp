
#include <stdio.h>
#include <stdint.h>
 #include <stdlib.h> 

#include "mmio.h"
#include "udma.h"
#include "pcie.h"
#include "debugPrint.h"
#include "udmaDefines.h"

int main(int argc, char* argv[])
{
  int uioId = 0;
  if((argc>1)&&(argv[1]!=NULL))
  { 
    uioId = atoi(argv[1]);
  }

  mmio_c& mmioDriver = mmio_c::getInstance(uioId);
  pcie_c& pcieDriver = pcie_c::getInstance(uioId);
  udma_c& udmaDriver = udma_c::getInstance();

  printf("Bar0 Address: 0x%lx \n", mmioDriver.getBar0Address());
  
  udmaDriver.getUdmaBufferInformation();

  pcieConfigurationHeader_t shadow = pcieDriver.getPcieConfigHeader();  
  printf("vendor id: %x device id: %x \n", shadow.dw0.vendorId, shadow.dw0.deviceId);

  printf("NVMe 2.0 Tool All done! \n");
  return 0;
}
