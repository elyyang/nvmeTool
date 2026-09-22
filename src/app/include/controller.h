/********************************************************************************************
*                              _              _   ____    ___  
*  _ ____   ___ __ ___   ___  | |_ ___   ___ | | |___ \  / _ \ 
* | '_ \ \ / / '_ ` _ \ / _ \ | __/ _ \ / _ \| |   __) || | | |
* | | | \ V /| | | | | |  __/ | || (_) | (_) | |  / __/ | |_| |
* |_| |_|\_/ |_| |_| |_|\___|  \__\___/ \___/|_| |_____(_)___/ 
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
#include "pcieStructs.h"

class controller_c
{
    private:

        controller_c();
        ~controller_c();

    public:

        static controller_c& getInstance();
        
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
        pmrcap_t getPersistentMemoryCapabilities(uio_c& uioDrv) const;
        pmrctl_t getPersistentMemoryRegionControl(uio_c& uioDrv) const;
        pmrsts_t getPersistentMemoryRegionStatus(uio_c& uioDrv) const;
        pmrebs_t getPersistentMemoryRegionElasticityBufferSize(uio_c& uioDrv) const;
        pmrswtp_t getPersistentMemorySustainedWriteThroughput(uio_c& uioDrv) const;
        pmrmscl_t getPersistentMemoryRegionControllerMemorySpaceControlLower(uio_c& uioDrv) const;
        pmrmscu_t getPersistentMemoryRegionControllerMemorySpaceControlUpper(uio_c& uioDrv) const;
};