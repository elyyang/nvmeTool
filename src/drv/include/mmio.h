
#pragma once

#include "nvmeStructs.h"

//=========================================================================

class mmio_c
{
    private:

        mmio_c();
        ~mmio_c();
        int         pfBar0_fd;        
        void*       pfBar0Addr;
        void*       pfBar0AddrPageTwo;
    
    public:
    
        static mmio_c& getInstance(void);        
        
        int getPfBar0Fd(void);
        void* getPfBar0Address(void);
        void* getPfBar0AddressPageTwo(void);                  

        //==============================================================================
        // Controller Register access API
        //==============================================================================

        cap_t       getControllerCapabilities(void);
        vs_t        getVersion(void);
        intms_t     getInterruptMaskSet(void);
        intmc_t     getInterruptMaskClear(void);
        cc_t        getControllerConfiguration(void);
        csts_t      getControllerStatus(void);
        nssr_t      getNvmSubsystemReset(void);
        aqa_t       getAdminQueueAttributes(void);
        asq_t       getAdminSubmissionQueueBaseAddress(void);
        acq_t       getAdminCompletionQueueBaseAddress(void);
        cmbloc_t    getControllerMemoryBufferLocation(void);
        cmbsz_t     getControllerMemoryBufferSize(void);
        bpinfo_t    getBootParitionInformation(void);
        bprsel_t    getBootParitionReadSelect(void);
        bpmbl_t     getBootParitionMemoryBufferLocation(void);
        cmbmsc_t    getControllerMemoryBufferMemorySpaceControl(void);
        cmbsts_t    getControllerMemoryBufferStatus(void);

        pmrcap_t    getPersistentMemoryCapabilities(void);
        pmrctl_t    getPersistentMemoryRegionControl(void);
        pmrsts_t    getPersistentMemoryRegionStatus(void);
        pmrebs_t    getPersistentMemoryRegionElasticityBufferSize(void);
        pmrswtp_t   getPersistentMemorySustainedWriteThroughput(void);
        pmrmsc_t    getPersistentMemoryRegionControllerMemorySpaceControl(void);

        void setControllerConfiguration(cc_t config);
        void setAdminQueueAttributes(uint16_t asqSize, uint16_t acqSize);
        void setAdminCompletionQueueBaseAddress(uint64_t address);
        void setAdminSubmissionQueueBaseAddress(uint64_t address);

        void setInterruptMaskSet(uint8_t intVector);
        void setInterruptMaskClear(uint8_t intVector);
        
        //==============================================================================
        // SQT/CQH access API
        //==============================================================================

        uint16_t getSqTail(uint32_t queueNumber);
        uint16_t getCqHead(uint32_t queueNumber);

        void setSqTail(uint32_t queueNumber, uint16_t value);
        void setCqHead(uint32_t queueNumber, uint16_t value);

        //==============================================================================
        // MSIX access API
        //==============================================================================
        
        msix_t getMsixEntry(uint32_t entryNumber,  uint32_t msixTableOffset);
        void setMsixEntry(uint32_t entryNumber, msix_t entry, uint32_t msixTableOffset);
};