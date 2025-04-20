
#include "mmio.h"
#include "assertLib.h"
#include "debugPrint.h"

//=========================================================================

mmio_c::mmio_c(void)
{    
    NVME_DBG_PRINTF(info, "initialize mmio_c!");
    uio_resource0_fd = open("/sys/class/uio/uio0/device/resource0", O_RDWR | O_SYNC);    
    NVME_DBG_ASSERT((uio_resource0_fd>0), "uio_resource0_fd failed to open!")
    pfBar0Address = mmap(NULL, MMIO_REG_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, uio_resource0_fd, 0);   
    NVME_DBG_ASSERT((pfBar0Address!=MAP_FAILED), "pfBar0Address map failed!")    
}

mmio_c::~mmio_c(void)
{        
    NVME_DBG_PRINTF(info, "clean-up mmio_c!");
    close(uio_resource0_fd);
    munmap(pfBar0Address, MMIO_REG_SIZE);          
}

//=========================================================================

mmio_c& mmio_c::getInstance(void)
{
    static mmio_c mInstance;
    return mInstance;
}

uint64_t mmio_c::getBar0Address(void)
{
    return (uint64_t)pfBar0Address;
}

//==============================================================================
// Controller Register access API
//==============================================================================

cap_t mmio_c::getControllerCapabilities(void)
{
    cap_t shadow;
    memset(&shadow, 0, sizeof(cap_t)); 
    
    shadow = *(cap_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_CAP_OFFSET); 
    
    return shadow;    
}

vs_t mmio_c::getVersion(void)
{
    vs_t shadow;
    memset(&shadow, 0, sizeof(vs_t)); 
    
    shadow = *(vs_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_VS_OFFSET); 
    
    return shadow;        
}

intms_t mmio_c::getInterruptMaskSet(void)
{
    intms_t shadow;
    memset(&shadow, 0, sizeof(intms_t)); 
    
    shadow = *(intms_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_INTMS_OFFSET); 
    
    return shadow;     
}

intmc_t mmio_c::getInterruptMaskClear(void)
{
    intmc_t shadow;
    memset(&shadow, 0, sizeof(intmc_t)); 
    
    shadow = *(intmc_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_INTMC_OFFSET); 
    
    return shadow;         
}

cc_t mmio_c::getControllerConfiguration(void)
{
    cc_t shadow;
    memset(&shadow, 0, sizeof(cc_t)); 
    
    shadow = *(cc_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_CC_OFFSET); 
    
    return shadow;        
}

csts_t mmio_c::getControllerStatus(void)
{
    csts_t shadow;
    memset(&shadow, 0, sizeof(csts_t)); 
    
    shadow = *(csts_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_CSTS_OFFSET); 
    
    return shadow;          
}

nssr_t mmio_c::getNvmSubsystemReset(void)
{
    nssr_t shadow;
    memset(&shadow, 0, sizeof(nssr_t)); 
    
    shadow = *(nssr_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_NSSR_OFFSET); 
   
    return shadow;
}

aqa_t mmio_c::getAdminQueueAttributes(void)
{
    aqa_t shadow;
    memset(&shadow, 0, sizeof(aqa_t)); 
    
    shadow = *(aqa_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_AQA_OFFSET); 
    
    return shadow;
}

asq_t mmio_c::getAdminSubmissionQueueBaseAddress(void)
{
    asq_t shadow;
    memset(&shadow, 0, sizeof(asq_t)); 

    shadow = *(asq_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_ASQ_OFFSET); 
    
    return shadow;
}

acq_t mmio_c::getAdminCompletionQueueBaseAddress(void)
{
    acq_t shadow;
    memset(&shadow, 0, sizeof(acq_t)); 
    
    shadow = *(acq_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_ACQ_OFFSET); 
    
    return shadow;
}

cmbloc_t mmio_c::getControllerMemoryBufferLocation(void)
{
    cmbloc_t shadow;
    memset(&shadow, 0, sizeof(cmbloc_t)); 
    
    shadow = *(cmbloc_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_CMBLOC_OFFSET); 
    
    return shadow;    
}

cmbsz_t mmio_c::getControllerMemoryBufferSize(void)
{
    cmbsz_t shadow;
    memset(&shadow, 0, sizeof(cmbsz_t)); 
    
    shadow = *(cmbsz_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_CMBSZ_OFFSET); 
    
    return shadow;      
}

bpinfo_t mmio_c::getBootParitionInformation(void)
{
    bpinfo_t shadow;
    memset(&shadow, 0, sizeof(bpinfo_t)); 
    
    shadow = *(bpinfo_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_BPINFO_OFFSET); 
    
    return shadow;     
}

bprsel_t mmio_c::getBootParitionReadSelect(void)
{
    bprsel_t shadow;
    memset(&shadow, 0, sizeof(bprsel_t)); 
    
    shadow = *(bprsel_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_BPRSEL_OFFSET); 
    
    return shadow;      
}

bpmbl_t mmio_c::getBootParitionMemoryBufferLocation(void)
{
    bpmbl_t shadow;
    memset(&shadow, 0, sizeof(bpmbl_t)); 
    
    shadow = *(bpmbl_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_BPMBL_OFFSET); 
    
    return shadow;      
}

cmbmsc_t mmio_c::getControllerMemoryBufferMemorySpaceControl(void)
{
    cmbmsc_t shadow;
    memset(&shadow, 0, sizeof(cmbmsc_t)); 
    
    shadow = *(cmbmsc_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_CMBMSC_OFFSET); 
    
    return shadow;    
}

cmbsts_t mmio_c::getControllerMemoryBufferStatus(void)
{
    cmbsts_t shadow;
    memset(&shadow, 0, sizeof(cmbsts_t)); 
    
    shadow = *(cmbsts_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_CMBSTS_OFFSET); 
    
    return shadow;     
}


pmrcap_t mmio_c::getPersistentMemoryCapabilities(void)
{
    pmrcap_t shadow;
    memset(&shadow, 0, sizeof(pmrcap_t)); 
    
    shadow = *(pmrcap_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_PMRCAP_OFFSET); 
    
    return shadow;     
}

pmrctl_t mmio_c::getPersistentMemoryRegionControl(void)
{
    pmrctl_t shadow;
    memset(&shadow, 0, sizeof(pmrctl_t)); 
    
    shadow = *(pmrctl_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_PMRCTL_OFFSET); 
    
    return shadow;      
}

pmrsts_t mmio_c::getPersistentMemoryRegionStatus(void)
{
    pmrsts_t shadow;
    memset(&shadow, 0, sizeof(pmrsts_t)); 
    
    shadow = *(pmrsts_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_PMRSTS_OFFSET); 
    
    return shadow;     
}

pmrebs_t mmio_c::getPersistentMemoryRegionElasticityBufferSize(void)
{
    pmrebs_t shadow;
    memset(&shadow, 0, sizeof(pmrebs_t)); 
    
    shadow = *(pmrebs_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_PMREBS_OFFSET);
    
    return shadow;      
}

pmrswtp_t mmio_c::getPersistentMemorySustainedWriteThroughput(void)
{
    pmrswtp_t shadow;
    memset(&shadow, 0, sizeof(pmrswtp_t)); 
    
    shadow = *(pmrswtp_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_PMRSWTP_OFFSET); 
    
    return shadow;       
}

pmrmsc_t mmio_c::getPersistentMemoryRegionControllerMemorySpaceControl(void)
{
    pmrmsc_t shadow;
    memset(&shadow, 0, sizeof(pmrmsc_t)); 
    
    shadow = *(pmrmsc_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_PMRMSC_OFFSET); 
    
    return shadow;      
}


void mmio_c::setControllerConfiguration(cc_t config)
{
    *(cc_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_CC_OFFSET) = config;
}

void mmio_c::setAdminQueueAttributes(uint16_t asqSize, uint16_t acqSize)
{
    aqa_t   adminQueueAttribute;    
    memset(&adminQueueAttribute, 0, sizeof(aqa_t));
    
    adminQueueAttribute.ASQS = asqSize;
    adminQueueAttribute.ACQS = acqSize;    
 
    *(aqa_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_AQA_OFFSET) = adminQueueAttribute;
}

void mmio_c::setAdminCompletionQueueBaseAddress(uint64_t address)
{   
    acq_t   adminCompletionQueue;
    memset(&adminCompletionQueue, 0, sizeof(acq_t));
    
    adminCompletionQueue.ACQB = (address>>12);    
 
    *(acq_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_ACQ_OFFSET) = adminCompletionQueue;    
}

void mmio_c::setAdminSubmissionQueueBaseAddress(uint64_t address)
{   
    asq_t   adminSubmissionQueue; 
    memset(&adminSubmissionQueue, 0, sizeof(asq_t));
    
    adminSubmissionQueue.ASQB = (address>>12);
 
    *(asq_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_ASQ_OFFSET) = adminSubmissionQueue;
}


void mmio_c::setInterruptMaskSet(uint8_t intVector)
{
    intms_t shadow;
    
    shadow = *(intms_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_INTMS_OFFSET);
    shadow.IVMS = shadow.IVMS | (0x1 << intVector);    
    *(intms_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_INTMS_OFFSET) = shadow;
    
    *((uint64_t*)pfBar0Address+CONTROLLER_REG_INTMS_OFFSET) = 0x2;
}

void mmio_c::setInterruptMaskClear(uint8_t intVector)
{
    intmc_t shadow;
    
    shadow = *(intmc_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_INTMC_OFFSET);
    shadow.IVMC = shadow.IVMC | (0x1 << intVector);
    *(intmc_t*)((uint64_t)pfBar0Address+CONTROLLER_REG_INTMC_OFFSET) = shadow;
    
    *((uint64_t*)pfBar0Address+CONTROLLER_REG_INTMC_OFFSET) = 0x2;
}


//==============================================================================
// SQT/CQH access API
//==============================================================================

void mmio_c::setSqTail(uint32_t queueNumber, uint16_t value)
{
    sqtdbl_t submissionQueue;    
    memset(&submissionQueue, 0, sizeof(sqtdbl_t)); 
    
    cap_t capShadow;    
    memcpy(&capShadow, (void*)((uint64_t)pfBar0Address+CONTROLLER_REG_CAP_OFFSET), sizeof(cap_t));
    uint16_t doorbellStride = capShadow.DSTRD;

    submissionQueue.SQT = value;
    uint32_t offset = SQT_CQH_BASE_OFFSET + ((queueNumber * 2) * (4 << doorbellStride));    
    
    //memcpy( (void*)((uint64_t)pfBar0Address+offset), &submissionQueue, sizeof(sqtdbl_t));    
    *(sqtdbl_t*)((uint64_t)pfBar0Address+offset) = submissionQueue;
}

void mmio_c::setCqHead(uint32_t queueNumber, uint16_t value)
{
    cqhdbl_t completionQueue;
    memset(&completionQueue, 0, sizeof(cqhdbl_t));
    
    cap_t capShadow;    
    memcpy(&capShadow, (void*)((uint64_t)pfBar0Address+CONTROLLER_REG_CAP_OFFSET), sizeof(cap_t));
    uint16_t doorbellStride = capShadow.DSTRD;

    completionQueue.CQH = value;
    uint32_t offset = SQT_CQH_BASE_OFFSET + (((queueNumber * 2) + 1) * (4 << doorbellStride));
    
    //memcpy( (void*)((uint64_t)pfBar0Address+offset), &completionQueue, sizeof(cqhdbl_t));
    *(cqhdbl_t*)((uint64_t)pfBar0Address+offset) = completionQueue;
}

//Note: the host should NOT be reading SQTDBL - this API is implemented for testing purposes
uint16_t mmio_c::getSqTail(uint32_t queueNumber)
{
    cap_t capShadow;    
    memcpy(&capShadow, (void*)((uint64_t)pfBar0Address+CONTROLLER_REG_CAP_OFFSET), sizeof(cap_t));
    uint16_t doorbellStride = capShadow.DSTRD;

    sqtdbl_t submissionQueue;
    uint32_t offset = SQT_CQH_BASE_OFFSET + ((queueNumber * 2) * (4 << doorbellStride));

    memcpy(&submissionQueue, (void*)((uint64_t)pfBar0Address+offset), sizeof(sqtdbl_t));    
    
    return submissionQueue.SQT;        
}
//Note: the host should NOT be reading CQHDBL - this API is implemented for testing purposes
uint16_t mmio_c::getCqHead(uint32_t queueNumber)
{
    cap_t capShadow;    
    memcpy(&capShadow, (void*)((uint64_t)pfBar0Address+CONTROLLER_REG_CAP_OFFSET), sizeof(cap_t));
    uint16_t doorbellStride = capShadow.DSTRD;

    cqhdbl_t completionQueue;        
    uint32_t offset = SQT_CQH_BASE_OFFSET + (((queueNumber * 2) + 1) * (4 << doorbellStride));
    
    memcpy(&completionQueue, (void*)((uint64_t)pfBar0Address+offset), sizeof(cqhdbl_t));    
    
    return completionQueue.CQH;          
}

//==============================================================================
// MSIX access API
//==============================================================================

msix_t mmio_c::getMsixEntry(uint32_t entryNumber,  uint32_t msixTableOffset)
{
    msix_t entry;        
    uint64_t offset = (uint64_t)pfBar0Address + msixTableOffset + (entryNumber * MSIX_ENTRY_SIZE);            
    memcpy(&entry, (void*)offset, sizeof(msix_t));        
    return entry;
}

void mmio_c::setMsixEntry(uint32_t entryNumber, msix_t entry, uint32_t msixTableOffset)
{    
    uint64_t offset = (uint64_t)pfBar0Address + msixTableOffset + (entryNumber * MSIX_ENTRY_SIZE);        
    memcpy((void*)offset, &entry, sizeof(msix_t));    
}