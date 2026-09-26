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
        
        cap_t getControllerCapabilities(int uioId) const;
        vs_t getVersion(int uioId) const;
        intms_t getInterruptMaskSet(int uioId) const;
        intmc_t getInterruptMaskClear(int uioId) const;
        cc_t getControllerConfiguration(int uioId) const;
        csts_t getControllerStatus(int uioId) const;
        nssr_t getNvmSubsystemReset(int uioId) const;
        aqa_t getAdminQueueAttributes(int uioId) const;
        asq_t getAdminSubmissionQueueBaseAddress(int uioId) const;
        acq_t getAdminCompletionQueueBaseAddress(int uioId) const;   
        cmbloc_t getControllerMemoryBufferLocation(int uioId) const; 
        cmbsz_t getControllerMemoryBufferSize(int uioId) const;
        bpinfo_t getBootParitionInformation(int uioId) const;
        bprsel_t getBootParitionReadSelect(int uioId) const;
        bpmbl_t getBootParitionMemoryBufferLocation(int uioId) const;
        cmbmsc_t getControllerMemoryBufferMemorySpaceControl(int uioId) const;
        cmbsts_t getControllerMemoryBufferStatus(int uioId) const;        
        cmbebs_t getControllerMemoryBufferElasticityBufferSize(int uioId) const;
        cmbswtp_t getControllerMemoryBufferSustainedWriteThroughput(int uioId) const;
        nssd_t getNvmSubsystemShutdown(int uioId) const;
        crto_t getControllerReadyTimeout(int uioId) const;        
        pmrcap_t getPersistentMemoryCapabilities(int uioId) const;
        pmrctl_t getPersistentMemoryRegionControl(int uioId) const;
        pmrsts_t getPersistentMemoryRegionStatus(int uioId) const;
        pmrebs_t getPersistentMemoryRegionElasticityBufferSize(int uioId) const;
        pmrswtp_t getPersistentMemorySustainedWriteThroughput(int uioId) const;
        pmrmscl_t getPersistentMemoryRegionControllerMemorySpaceControlLower(int uioId) const;
        pmrmscu_t getPersistentMemoryRegionControllerMemorySpaceControlUpper(int uioId) const;

        void setControllerCapabilities(int uioId, cap_t cap) const;
        void setVersion(int uioId, vs_t vs) const;
        void setInterruptMaskSet(int uioId, intms_t intms) const;
        void setInterruptMaskClear(int uioId, intmc_t intmc) const;
        void setControllerConfiguration(int uioId, cc_t cc) const;
        void setControllerStatus(int uioId, csts_t csts) const;
        void setNvmSubsystemReset(int uioId, nssr_t nssr) const;
        void setAdminQueueAttributes(int uioId, aqa_t aqa) const;
        void setAdminSubmissionQueueBaseAddress(int uioId, asq_t asq) const;
        void setAdminCompletionQueueBaseAddress(int uioId, acq_t acq) const;   
        void setControllerMemoryBufferLocation(int uioId, cmbloc_t cmbloc) const; 
        void setControllerMemoryBufferSize(int uioId, cmbsz_t cmbsz) const;
        void setBootParitionInformation(int uioId, bpinfo_t bpinfo) const;
        void setBootParitionReadSelect(int uioId, bprsel_t bprsel) const;
        void setBootParitionMemoryBufferLocation(int uioId, bpmbl_t bpmbl) const;
        void setControllerMemoryBufferMemorySpaceControl(int uioId, cmbmsc_t cmbmsc) const;
        void setControllerMemoryBufferStatus(int uioId, cmbsts_t cmbsts) const;        
        void setControllerMemoryBufferElasticityBufferSize(int uioId, cmbebs_t cmbebs) const;
        void setControllerMemoryBufferSustainedWriteThroughput(int uioId, cmbswtp_t cmbswtp) const;
        void setNvmSubsystemShutdown(int uioId, nssd_t nssd) const;
        void setControllerReadyTimeout(int uioId, crto_t crto) const;        
        void setPersistentMemoryCapabilities(int uioId, pmrcap_t pmrcap) const;
        void setPersistentMemoryRegionControl(int uioId, pmrctl_t pmrctl) const;
        void setPersistentMemoryRegionStatus(int uioId, pmrsts_t pmrsts) const;
        void setPersistentMemoryRegionElasticityBufferSize(int uioId, pmrebs_t pmrebs) const;
        void setPersistentMemorySustainedWriteThroughput(int uioId, pmrswtp_t pmrswtp) const;
        void setPersistentMemoryRegionControllerMemorySpaceControlLower(int uioId, pmrmscl_t pmrmscl) const;
        void setPersistentMemoryRegionControllerMemorySpaceControlUpper(int uioId, pmrmscu_t pmrmscu) const;

        void incrementSqTailDoorbell(int uioId, uint32_t sqId) const;
        void incrementCqHeadDoorbell(int uioId, uint32_t cqId) const;
        uint16_t getSqTailDoorbell(int uioId, uint32_t sqId) const;
        uint16_t getCqHeadDoorbell(int uioId, uint32_t cqId) const;
        void setSqTailDoorbell(int uioId, uint32_t sqId, uint16_t value) const;
        void setCqHeadDoorbell(int uioId, uint32_t cqId, uint16_t value) const;
};