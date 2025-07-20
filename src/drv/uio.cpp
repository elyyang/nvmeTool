
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

    uioId = id;
    sprintf(fdIdx, "%d", uioId);

    strcpy(fdPath, "/sys/class/uio/uio");
    strcat(fdPath, fdIdx);
    strcat(fdPath, "/device/config");

    uio_config_fd = open(fdPath, O_RDWR | O_SYNC);
    NVME_DBG_ASSERT((uio_config_fd>0), "uio_config_fd failed to open!")

    strcpy(fdPath, "/sys/class/uio/uio");
    strcat(fdPath, fdIdx);
    strcat(fdPath, "/device/resource0");

    uio_resource0_fd = open(fdPath, O_RDWR | O_SYNC);    
    NVME_DBG_ASSERT((uio_resource0_fd>0), "uio_resource0_fd failed to open!")

    mPfBar0 = mmap(NULL, NVM_CONTROLLER_MMIO_REG_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, uio_resource0_fd, 0);   
    NVME_DBG_ASSERT((mPfBar0!=MAP_FAILED), "pfBar0Address map failed!")        
}

uio_c::~uio_c()
{        
    NVME_DBG_PRINTF(info, "clean-up uio_c!");
    close(uio_config_fd);    
    close(uio_resource0_fd);
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