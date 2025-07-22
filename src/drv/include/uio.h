
#pragma once

#include "nvmeStructs.h"
#include "pcieStructs.h"

class uio_c
{
    private:

        uio_c(int id);        
        ~uio_c();

        int mUioResource0_fd;
        int mUioConfig_fd;
        int mUioId;
        void* mPfBar0Address;

    public:

        static uio_c& getInstance(int id);

        uintptr_t getBar0Address() const;
        int getId() const;

        void dumpNvmeControllerMem(uint32_t itr, uint32_t offset) const;

        cap_t getControllerCapabilities() const;
        vs_t getVersion() const;
        intms_t getInterruptMaskSet() const;
        intmc_t getInterruptMaskClear() const;
        cc_t getControllerConfiguration() const;
        csts_t getControllerStatus() const;
        nssr_t getNvmSubsystemReset() const;
        aqa_t getAdminQueueAttributes() const;
        asq_t getAdminSubmissionQueueBaseAddress() const;
        acq_t getAdminCompletionQueueBaseAddress() const;
        cmbloc_t getControllerMemoryBufferLocation() const;
        cmbsz_t getControllerMemoryBufferSize() const;
        bpinfo_t getBootParitionInformation() const;
        bprsel_t getBootParitionReadSelect() const;
        bpmbl_t getBootParitionMemoryBufferLocation() const;
        cmbmsc_t getControllerMemoryBufferMemorySpaceControl() const;
        cmbsts_t getControllerMemoryBufferStatus() const;
        pmrcap_t getPersistentMemoryCapabilities() const;
        pmrctl_t getPersistentMemoryRegionControl() const;
        pmrsts_t getPersistentMemoryRegionStatus() const;
        pmrebs_t getPersistentMemoryRegionElasticityBufferSize() const;
        pmrswtp_t getPersistentMemorySustainedWriteThroughput() const;
        pmrmscl_t getPersistentMemoryRegionControllerMemorySpaceControlLower() const;
        pmrmscu_t getPersistentMemoryRegionControllerMemorySpaceControlUpper() const;

        void setControllerConfiguration(uint32_t config);
        void setAdminQueueAttributes(uint16_t asqSize, uint16_t acqSize);
        void setAdminCompletionQueueBaseAddress(uint64_t address);
        void setAdminSubmissionQueueBaseAddress(uint64_t address);

        void setSqTail(uint32_t queueNumber, uint16_t value);
        void setCqHead(uint32_t queueNumber, uint16_t value);

        pcieConfigurationHeader_t getPcieConfigHeader() const;
        void setBusMasterEnable(bool status);
        bool getBusMasterEnable() const;
        capability_msix_t getMsixCapability() const;
};
