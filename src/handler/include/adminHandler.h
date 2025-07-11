
#pragma once

#include <stdint.h>
#include "nvmeStructs.h"

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

        adminStatus_e submitCommand(nvmeCommand_t command);
        adminStatus_e completeCommand(nvmeCompletion_t& completion);
        
		adminStatus_e issueAdminIdentify(uint32_t cns);
        adminStatus_e issueAdminIdentify(uint32_t cns, uint32_t namespaceId);        
        adminStatus_e issueSetFeature_arbitration(uint32_t arbitratonBurst, uint32_t lowPriorityWeight, uint32_t medPriorityWeight, uint32_t highPriorityWeight);
        adminStatus_e issueSetFeature_powerMgmt(uint32_t powerState, uint32_t workloadHit);
        adminStatus_e issueSetFeature_lbaRange(uint32_t numLbaRange);
        adminStatus_e issueSetFeature_numOfQueues(uint32_t numSqRequest, uint32_t numCqRequest);
        adminStatus_e issueSetFeature_interruptCoalescing(uint32_t aggregationTime, uint32_t aggregationThreshold);
        adminStatus_e issueAdminCreateIOCompletionQueue(uint32_t queueId, uint32_t queueSize, bool interruptEn, uint32_t interruptVector, uint64_t prp);
        adminStatus_e issueAdminCreateIOSubmissionQueue(uint32_t queueId, uint32_t queueSize, uint32_t priority , uint32_t completionQueueId, uint64_t prp);
        adminStatus_e issueFormatNvm(uint32_t lbaf, uint32_t ms, uint32_t pi, uint32_t pil, uint32_t sess);
        adminStatus_e issueGetLogPage(uint32_t logPageId);
        adminStatus_e issueAsyncEventRequest();

        uint32_t getQueueId();
        uint32_t getAsqSize();
        uint32_t getAcqSize();
        uint64_t getAsqBaseAddress();
        uint64_t getAsqBaseAddressPhysical();
        uint64_t getAcqBaseAddress();
        uint64_t getAcqBaseAddressPhysical();
        uint32_t getCommandId();
        uint32_t getControllerId();
        uint64_t getAdminDataAddress();
        uint64_t getAdminDataAddressPhysical();
};