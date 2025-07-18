
#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "nvmeStructs.h"

//=========================================================================

class mmio_c
{
    private:

        mmio_c(int uioId);
        ~mmio_c();
        int uioId;
        int uio_resource0_fd;        
        void* pfBar0Address;

    public:
    
        static mmio_c& getInstance(int id);     
        uintptr_t getBar0Address(void);
        
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
        pmrmscl_t   getPersistentMemoryRegionControllerMemorySpaceControlLower(void);
        pmrmscu_t   getPersistentMemoryRegionControllerMemorySpaceControlUpper(void);

        void setControllerConfiguration(uint32_t config);
        void setAdminQueueAttributes(uint16_t asqSize, uint16_t acqSize);
        void setAdminCompletionQueueBaseAddress(uint64_t address);
        void setAdminSubmissionQueueBaseAddress(uint64_t address);
        
        //==============================================================================
        // SQT/CQH access API
        //==============================================================================
        void setSqTail(uint32_t queueNumber, uint16_t value);
        void setCqHead(uint32_t queueNumber, uint16_t value);        
};