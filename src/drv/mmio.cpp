
#include "mmio.h"
#include "assertLib.h"
#include "debugPrint.h"

//=========================================================================

mmio_c::mmio_c(int id)
{
    #define BYTES_TO_READ 64    
    char fdPath[BYTES_TO_READ];
    char fdIdx[BYTES_TO_READ];    

    uioId = id;
    sprintf(fdIdx, "%d", uioId);

    NVME_DBG_PRINTF(info, "initialize mmio_c!");

    strcpy(fdPath, "/sys/class/uio/uio");
    strcat(fdPath, fdIdx);
    strcat(fdPath, "/device/resource0");

    uio_resource0_fd = open(fdPath, O_RDWR | O_SYNC);    
    NVME_DBG_ASSERT((uio_resource0_fd>0), "uio_resource0_fd failed to open!")
    
    pfBar0Address = mmap(NULL, NVM_CONTROLLER_MMIO_REG_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, uio_resource0_fd, 0);   
    NVME_DBG_ASSERT((pfBar0Address!=MAP_FAILED), "pfBar0Address map failed!")    
}

mmio_c::~mmio_c(void)
{        
    NVME_DBG_PRINTF(info, "clean-up mmio_c!");
    close(uio_resource0_fd);
    munmap(pfBar0Address, NVM_CONTROLLER_MMIO_REG_SIZE);          
}

//=========================================================================

mmio_c& mmio_c::getInstance(int id)
{
    static mmio_c mInstance(id);
    return mInstance;
}

uintptr_t mmio_c::getBar0Address(void)
{
    return (uintptr_t)pfBar0Address;
}

//==============================================================================
// Controller Register access API
//==============================================================================

cap_t mmio_c::getControllerCapabilities(void)
{
    return *(cap_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_CAP); 
}

vs_t mmio_c::getVersion(void)
{
    return *(vs_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_VS); 
}

intms_t mmio_c::getInterruptMaskSet(void)
{
    return *(intms_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_INTMS); 
}

intmc_t mmio_c::getInterruptMaskClear(void)
{
    return *(intmc_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_INTMC);
}

cc_t mmio_c::getControllerConfiguration(void)
{
    return *(cc_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_CC);
}

csts_t mmio_c::getControllerStatus(void)
{
    return *(csts_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_CSTS);
}

nssr_t mmio_c::getNvmSubsystemReset(void)
{
    return *(nssr_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_NSSR); 
}

aqa_t mmio_c::getAdminQueueAttributes(void)
{
    return *(aqa_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_AQA);
}

asq_t mmio_c::getAdminSubmissionQueueBaseAddress(void)
{
    return *(asq_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_ASQ); 
}

acq_t mmio_c::getAdminCompletionQueueBaseAddress(void)
{
    return *(acq_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_ACQ); 
}

cmbloc_t mmio_c::getControllerMemoryBufferLocation(void)
{
    return *(cmbloc_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_CMBLOC); 
}

cmbsz_t mmio_c::getControllerMemoryBufferSize(void)
{
    return *(cmbsz_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_CMBSZ);
}

bpinfo_t mmio_c::getBootParitionInformation(void)
{
    return *(bpinfo_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_BPINFO); 
}

bprsel_t mmio_c::getBootParitionReadSelect(void)
{
    return *(bprsel_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_BPRSEL); 
}

bpmbl_t mmio_c::getBootParitionMemoryBufferLocation(void)
{
    return *(bpmbl_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_BPMBL); 
}

cmbmsc_t mmio_c::getControllerMemoryBufferMemorySpaceControl(void)
{
    return *(cmbmsc_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_CMBMSC); 
}

cmbsts_t mmio_c::getControllerMemoryBufferStatus(void)
{
    return *(cmbsts_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_CMBSTS);  
}

pmrcap_t mmio_c::getPersistentMemoryCapabilities(void)
{
    return *(pmrcap_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_PMRCAP); 
}

pmrctl_t mmio_c::getPersistentMemoryRegionControl(void)
{
    return *(pmrctl_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_PMRCTL);   
}

pmrsts_t mmio_c::getPersistentMemoryRegionStatus(void)
{
    return *(pmrsts_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_PMRSTS); 
}

pmrebs_t mmio_c::getPersistentMemoryRegionElasticityBufferSize(void)
{
    return *(pmrebs_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_PMREBS);
}

pmrswtp_t mmio_c::getPersistentMemorySustainedWriteThroughput(void)
{
    return *(pmrswtp_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_PMRSWTP); 
}

pmrmscl_t mmio_c::getPersistentMemoryRegionControllerMemorySpaceControlLower(void)
{
    return *(pmrmscl_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_PMRMSCL); 
}

pmrmscu_t mmio_c::getPersistentMemoryRegionControllerMemorySpaceControlUpper(void)
{
    return *(pmrmscu_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_PMRMSCU);    
}

void mmio_c::setControllerConfiguration(uint32_t config)
{
    *(volatile uint32_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_CC) = config;
}

void mmio_c::setAdminQueueAttributes(uint16_t asqSize, uint16_t acqSize)
{
    aqa_t adminQueueAttribute = {};
    adminQueueAttribute.ASQS = asqSize;
    adminQueueAttribute.ACQS = acqSize;     

    *(volatile uint32_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_AQA) = adminQueueAttribute.all;
}

void mmio_c::setAdminCompletionQueueBaseAddress(uint64_t address)
{   
    acq_t adminCompletionQueue = {};
    adminCompletionQueue.all = address;
 
    *(volatile uint64_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_ACQ) = adminCompletionQueue.all;    
}

void mmio_c::setAdminSubmissionQueueBaseAddress(uint64_t address)
{   
    asq_t   adminSubmissionQueue = {};    
    adminSubmissionQueue.all = address;
 
    *(volatile uint64_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_ASQ) = adminSubmissionQueue.all;
}

//==============================================================================
// SQT/CQH access API
//==============================================================================

void mmio_c::setSqTail(uint32_t queueNumber, uint16_t value)
{
    sqtdbl_t submissionQueue = {};
    submissionQueue.SQT = value;

    cap_t capShadow = *(cap_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_CAP);
    uint32_t offset = CONTROLLER_REG_OFFSET_SQT_CQH_BASE + ((queueNumber * 2) * (4 << capShadow.DSTRD));    

    *(sqtdbl_t*)((uintptr_t)pfBar0Address+offset) = submissionQueue;
}

void mmio_c::setCqHead(uint32_t queueNumber, uint16_t value)
{
    cqhdbl_t completionQueue = {};    
    completionQueue.CQH = value;

    cap_t capShadow = *(cap_t*)((uintptr_t)pfBar0Address+CONTROLLER_REG_OFFSET_CAP);
    uint32_t offset = CONTROLLER_REG_OFFSET_SQT_CQH_BASE + (((queueNumber * 2) + 1) * (4 << capShadow.DSTRD));

    *(cqhdbl_t*)((uintptr_t)pfBar0Address+offset) = completionQueue;
}
