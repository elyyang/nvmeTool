
#include <stdio.h>
#include <stdint.h>

#include "mmio.h"
#include "udma.h"

int main(void)
{
  mmio_c& mmioDriver = mmio_c::getInstance();

  printf("Pf Bar0 Address: 0x%lx \n", (uint64_t)mmioDriver.getPfBar0Address());
  printf("Pf Bar0 Address page 2: 0x%lx \n", (uint64_t)mmioDriver.getPfBar0AddressPageTwo());

  udma_c& udmaDriver = udma_c::getInstance();

  udmaDriver.getUdmaBufferInformation();

  printf("NVMe 2.0 Tool All done! \n");
  return 0;
}
