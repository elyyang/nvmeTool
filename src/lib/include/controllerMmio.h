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
        
        cap_t getControllerCapabilities(uio_c& uioDrv) const;
        vs_t getVersion(uio_c& uioDrv) const;
        intms_t getInterruptMaskSet(uio_c& uioDrv) const;
        intmc_t getInterruptMaskClear(uio_c& uioDrv) const;
        cc_t getControllerConfiguration(uio_c& uioDrv) const;
        csts_t getControllerStatus(uio_c& uioDrv) const;
        nssr_t getNvmSubsystemReset(uio_c& uioDrv) const;
        aqa_t getAdminQueueAttributes(uio_c& uioDrv) const;
        asq_t getAdminSubmissionQueueBaseAddress(uio_c& uioDrv) const;
        acq_t getAdminCompletionQueueBaseAddress(uio_c& uioDrv) const;   
        cmbloc_t getControllerMemoryBufferLocation(uio_c& uioDrv) const; 
        cmbsz_t getControllerMemoryBufferSize(uio_c& uioDrv) const;
        bpinfo_t getBootParitionInformation(uio_c& uioDrv) const;
        bprsel_t getBootParitionReadSelect(uio_c& uioDrv) const;
        bpmbl_t getBootParitionMemoryBufferLocation(uio_c& uioDrv) const;
        cmbmsc_t getControllerMemoryBufferMemorySpaceControl(uio_c& uioDrv) const;
        cmbsts_t getControllerMemoryBufferStatus(uio_c& uioDrv) const;        
        cmbebs_t getControllerMemoryBufferElasticityBufferSize(uio_c& uioDrv) const;
        cmbswtp_t getControllerMemoryBufferSustainedWriteThroughput(uio_c& uioDrv) const;
        nssd_t getNvmSubsystemShutdown(uio_c& uioDrv) const;
        crto_t getControllerReadyTimeout(uio_c& uioDrv) const;        
        pmrcap_t getPersistentMemoryCapabilities(uio_c& uioDrv) const;
        pmrctl_t getPersistentMemoryRegionControl(uio_c& uioDrv) const;
        pmrsts_t getPersistentMemoryRegionStatus(uio_c& uioDrv) const;
        pmrebs_t getPersistentMemoryRegionElasticityBufferSize(uio_c& uioDrv) const;
        pmrswtp_t getPersistentMemorySustainedWriteThroughput(uio_c& uioDrv) const;
        pmrmscl_t getPersistentMemoryRegionControllerMemorySpaceControlLower(uio_c& uioDrv) const;
        pmrmscu_t getPersistentMemoryRegionControllerMemorySpaceControlUpper(uio_c& uioDrv) const;

        void setControllerCapabilities(uio_c& uioDrv, cap_t cap) const;
        void setVersion(uio_c& uioDrv, vs_t vs) const;
        void setInterruptMaskSet(uio_c& uioDrv, intms_t intms) const;
        void setInterruptMaskClear(uio_c& uioDrv, intmc_t intmc) const;
        void setControllerConfiguration(uio_c& uioDrv, cc_t cc) const;
        void setControllerStatus(uio_c& uioDrv, csts_t csts) const;
        void setNvmSubsystemReset(uio_c& uioDrv, nssr_t nssr) const;
        void setAdminQueueAttributes(uio_c& uioDrv, aqa_t aqa) const;
        void setAdminSubmissionQueueBaseAddress(uio_c& uioDrv, asq_t asq) const;
        void setAdminCompletionQueueBaseAddress(uio_c& uioDrv, acq_t acq) const;   
        void setControllerMemoryBufferLocation(uio_c& uioDrv, cmbloc_t cmbloc) const; 
        void setControllerMemoryBufferSize(uio_c& uioDrv, cmbsz_t cmbsz) const;
        void setBootParitionInformation(uio_c& uioDrv, bpinfo_t bpinfo) const;
        void setBootParitionReadSelect(uio_c& uioDrv, bprsel_t bprsel) const;
        void setBootParitionMemoryBufferLocation(uio_c& uioDrv, bpmbl_t bpmbl) const;
        void setControllerMemoryBufferMemorySpaceControl(uio_c& uioDrv, cmbmsc_t cmbmsc) const;
        void setControllerMemoryBufferStatus(uio_c& uioDrv, cmbsts_t cmbsts) const;        
        void setControllerMemoryBufferElasticityBufferSize(uio_c& uioDrv, cmbebs_t cmbebs) const;
        void setControllerMemoryBufferSustainedWriteThroughput(uio_c& uioDrv, cmbswtp_t cmbswtp) const;
        void setNvmSubsystemShutdown(uio_c& uioDrv, nssd_t nssd) const;
        void setControllerReadyTimeout(uio_c& uioDrv, crto_t crto) const;        
        void setPersistentMemoryCapabilities(uio_c& uioDrv, pmrcap_t pmrcap) const;
        void setPersistentMemoryRegionControl(uio_c& uioDrv, pmrctl_t pmrctl) const;
        void setPersistentMemoryRegionStatus(uio_c& uioDrv, pmrsts_t pmrsts) const;
        void setPersistentMemoryRegionElasticityBufferSize(uio_c& uioDrv, pmrebs_t pmrebs) const;
        void setPersistentMemorySustainedWriteThroughput(uio_c& uioDrv, pmrswtp_t pmrswtp) const;
        void setPersistentMemoryRegionControllerMemorySpaceControlLower(uio_c& uioDrv, pmrmscl_t pmrmscl) const;
        void setPersistentMemoryRegionControllerMemorySpaceControlUpper(uio_c& uioDrv, pmrmscu_t pmrmscu) const;
};