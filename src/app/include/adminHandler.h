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
#include "nvmeStructs.h"

class uio_c;

class admin_c
{
    private:

        enum adminStatus_e
        {
            ADMIN_SUCCESS             = 0x00,
            ADMIN_ERROR_INVALID_FD    = 0x01,
            ADMIN_ERROR_MMAP_FAILED   = 0x02,
            ADMIN_ERROR_PREAD_FAILED  = 0x03,
            ADMIN_ERROR_TIMEOUT       = 0x04,
            ADMIN_ERROR_SUBMISSION    = 0x05,
            ADMIN_ERROR_COMPLETION    = 0x06,
            ADMIN_ERROR_GENERIC       = 0xFF
        };

        admin_c();
        ~admin_c();

    public:

        static admin_c& getInstance();

        adminStatus_e submitCommand(uio_c& uioDrv, nvmeCommand_t command);
        adminStatus_e completeCommand(uio_c& uioDrv, nvmeCompletion_t& completion);
        
		adminStatus_e issueAdminIdentify(uio_c& uioDrv, uint32_t cns);
        adminStatus_e issueAdminIdentify(uio_c& uioDrv, uint32_t cns, uint32_t namespaceId);        
        adminStatus_e issueSetFeature_arbitration(uio_c& uioDrv, uint32_t arbitratonBurst, uint32_t lowPriorityWeight, uint32_t medPriorityWeight, uint32_t highPriorityWeight);
        adminStatus_e issueSetFeature_powerMgmt(uio_c& uioDrv, uint32_t powerState, uint32_t workloadHit);
        adminStatus_e issueSetFeature_lbaRange(uio_c& uioDrv, uint32_t numLbaRange);
        adminStatus_e issueSetFeature_numOfQueues(uio_c& uioDrv, uint32_t numSqRequest, uint32_t numCqRequest);
        adminStatus_e issueSetFeature_interruptCoalescing(uio_c& uioDrv, uint32_t aggregationTime, uint32_t aggregationThreshold);
        adminStatus_e issueAdminCreateIOCompletionQueue(uio_c& uioDrv, uint32_t queueId, uint32_t queueSize, bool interruptEn, uint32_t interruptVector, uint64_t prp);
        adminStatus_e issueAdminCreateIOSubmissionQueue(uio_c& uioDrv, uint32_t queueId, uint32_t queueSize, uint32_t priority , uint32_t completionQueueId, uint64_t prp);
        adminStatus_e issueFormatNvm(uio_c& uioDrv, uint32_t lbaf, uint32_t ms, uint32_t pi, uint32_t pil, uint32_t sess);
        adminStatus_e issueGetLogPage(uio_c& uioDrv, uint32_t logPageId);
        adminStatus_e issueAsyncEventRequest(uio_c& uioDrv);

        uint32_t getQueueId(uio_c& uioDrv);
        uint32_t getAsqSize(uio_c& uioDrv);
        uint32_t getAcqSize(uio_c& uioDrv);
        uint64_t getAsqBaseAddress(uio_c& uioDrv);
        uint64_t getAsqBaseAddressPhysical(uio_c& uioDrv);
        uint64_t getAcqBaseAddress(uio_c& uioDrv);
        uint64_t getAcqBaseAddressPhysical(uio_c& uioDrv);
        uint32_t getCommandId(uio_c& uioDrv);
        uint32_t getControllerId(uio_c& uioDrv);
        uint64_t getAdminDataAddress(uio_c& uioDrv);
        uint64_t getAdminDataAddressPhysical(uio_c& uioDrv);
};