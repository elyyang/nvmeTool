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

class controller_c
{
    private:

        controller_c();
        ~controller_c();

    public:

        static controller_c& getInstance();

        

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
};