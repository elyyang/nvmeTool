/********************************************************************************************
*  _  ___   ____  __    _____         _ _  ___ _   
* | \| \ \ / /  \/  |__|_   _|__  ___| | |/ (_) |_ 
* | .` |\ V /| |\/| / -_)| |/ _ \/ _ \ | ' <| |  _|
* |_|\_| \_/ |_|  |_\___||_|\___/\___/_|_|\_\_|\__|
*                                                              
* MIT License
* 
* Copyright (c) 2026 Eric L. Yang
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* 
* https://github.com/elyyang
* elyyang@gmail.com
*
*********************************************************************************************/

#pragma once

#include <stdint.h>
#include "uio.h"
#include "nvmeStructs.h"

class controllerMmio_c
{
    private:

        controllerMmio_c();
        ~controllerMmio_c();

    public:

        static controllerMmio_c& getInstance();
        
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
        cmbebs_t getControllerMemoryBufferElasticityBufferSize() const;
        cmbswtp_t getControllerMemoryBufferSustainedWriteThroughput() const;
        nssd_t getNvmSubsystemShutdown() const;
        crto_t getControllerReadyTimeout() const;        
        pmrcap_t getPersistentMemoryCapabilities() const;
        pmrctl_t getPersistentMemoryRegionControl() const;
        pmrsts_t getPersistentMemoryRegionStatus() const;
        pmrebs_t getPersistentMemoryRegionElasticityBufferSize() const;
        pmrswtp_t getPersistentMemorySustainedWriteThroughput() const;
        pmrmscl_t getPersistentMemoryRegionControllerMemorySpaceControlLower() const;
        pmrmscu_t getPersistentMemoryRegionControllerMemorySpaceControlUpper() const;

        void setControllerCapabilities(cap_t cap) const;
        void setVersion(vs_t vs) const;
        void setInterruptMaskSet(intms_t intms) const;
        void setInterruptMaskClear(intmc_t intmc) const;
        void setControllerConfiguration(cc_t cc) const;
        void setControllerStatus(csts_t csts) const;
        void setNvmSubsystemReset(nssr_t nssr) const;
        void setAdminQueueAttributes(aqa_t aqa) const;
        void setAdminSubmissionQueueBaseAddress(asq_t asq) const;
        void setAdminCompletionQueueBaseAddress(acq_t acq) const;   
        void setControllerMemoryBufferLocation(cmbloc_t cmbloc) const; 
        void setControllerMemoryBufferSize(cmbsz_t cmbsz) const;
        void setBootParitionInformation(bpinfo_t bpinfo) const;
        void setBootParitionReadSelect(bprsel_t bprsel) const;
        void setBootParitionMemoryBufferLocation(bpmbl_t bpmbl) const;
        void setControllerMemoryBufferMemorySpaceControl(cmbmsc_t cmbmsc) const;
        void setControllerMemoryBufferStatus(cmbsts_t cmbsts) const;        
        void setControllerMemoryBufferElasticityBufferSize(cmbebs_t cmbebs) const;
        void setControllerMemoryBufferSustainedWriteThroughput(cmbswtp_t cmbswtp) const;
        void setNvmSubsystemShutdown(nssd_t nssd) const;
        void setControllerReadyTimeout(crto_t crto) const;        
        void setPersistentMemoryCapabilities(pmrcap_t pmrcap) const;
        void setPersistentMemoryRegionControl(pmrctl_t pmrctl) const;
        void setPersistentMemoryRegionStatus(pmrsts_t pmrsts) const;
        void setPersistentMemoryRegionElasticityBufferSize(pmrebs_t pmrebs) const;
        void setPersistentMemorySustainedWriteThroughput(pmrswtp_t pmrswtp) const;
        void setPersistentMemoryRegionControllerMemorySpaceControlLower(pmrmscl_t pmrmscl) const;
        void setPersistentMemoryRegionControllerMemorySpaceControlUpper(pmrmscu_t pmrmscu) const;

        void incrementSqTailDoorbell(uint32_t sqId) const;
        void incrementCqHeadDoorbell(uint32_t cqId) const;
        uint16_t getSqTailDoorbell(uint32_t sqId) const;
        uint16_t getCqHeadDoorbell(uint32_t cqId) const;
        void setSqTailDoorbell(uint32_t sqId, uint16_t value) const;
        void setCqHeadDoorbell(uint32_t cqId, uint16_t value) const;
};