
#pragma once

#include <stdint.h>
#include "nvmeDefines.h"

//=========================================================================

//-------------------------------------------------
// NVME 1.4 - controller register
//-------------------------------------------------

typedef union __attribute__((packed, aligned (4))) cap_t
{
    struct
    {
        uint32_t    MQES    :16;
        uint32_t    CQR     :1;
        uint32_t    AMS     :2;
        uint32_t    rsvd0   :5;
        uint32_t    TO      :8;
        uint32_t    DSTRD   :4;
        uint32_t    NSSRS   :1;
        uint32_t    CSS     :8;
        uint32_t    BSP     :1;
        uint32_t    rsvd1   :2;
        uint32_t    MPSMIN  :4;
        uint32_t    MPSMAX  :4;
        uint32_t    PMRS    :1;
        uint32_t    CMBS    :1;
        uint32_t    rsvd2   :6;
    };

    uint64_t all;
}cap_t;
static_assert(sizeof(cap_t) == 8, "cap_t size is not 8 byte");

typedef union __attribute__((packed, aligned (4))) vs_t
{
    struct 
    {    
        uint32_t    TER     :16;
        uint32_t    MNR     :8;
        uint32_t    MJR     :8;
    };

    uint32_t all;
}vs_t;
static_assert(sizeof(vs_t) == 4, "vs_t size is not 4 byte");

typedef struct __attribute__((packed, aligned (4))) intms_t
{
    uint32_t    IVMS;
}intms_t;
static_assert(sizeof(intms_t) == 4, "intms_t size is not 4 byte");

typedef struct __attribute__((packed, aligned (4))) intmc_t
{
    uint32_t    IVMC;
}intmc_t;
static_assert(sizeof(intmc_t) == 4, "intmc_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4))) cc_t
{
    struct
    {
        uint32_t    EN      :1;
        uint32_t    rsvd0   :3;
        uint32_t    CSS     :3;
        uint32_t    MPS     :4;
        uint32_t    AMS     :3;
        uint32_t    SHN     :2;
        uint32_t    IOSQES  :4;
        uint32_t    IOCQES  :4;
        uint32_t    rsvd1   :8;
    };

    uint32_t all;
}cc_t;
static_assert(sizeof(cc_t) == 4, "cc_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4))) csts_t
{
    struct
    {
        uint32_t     RDY     :1;
        uint32_t     CFS     :1;
        uint32_t     SHST    :2;
        uint32_t     NSSRO   :1;
        uint32_t     PP      :1;
        uint32_t     SHN     :25;
    };

    uint32_t all;
}csts_t;
static_assert(sizeof(csts_t) == 4, "csts_t size is not 4 byte");

typedef struct __attribute__((packed, aligned (4))) nssr_t
{
    uint32_t NSSRC;
}nssr_t;
static_assert(sizeof(nssr_t) == 4, "nssr_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4))) aqa_t
{
    struct
    {
        uint32_t    ASQS    :12;
        uint32_t    rsvd0   :4;
        uint32_t    ACQS    :12;
        uint32_t    rsvd1   :4;
    };

    uint32_t all;
}aqa_t;
static_assert(sizeof(aqa_t )== 4, "aqa_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4))) asq_t
{
    struct 
    {    
        uint32_t    rsvd0   :12;
        uint64_t    ASQB    :52;
    };

    uint64_t    all;    
}asq_t;
static_assert(sizeof(asq_t) == 8, "asq_t size is not 8 byte");

typedef union __attribute__((packed, aligned (4))) acq_t
{
    struct
    {
        uint32_t    rsvd0   :12;
        uint64_t    ACQB    :52;
    };

    uint64_t all;
}acq_t;
static_assert(sizeof(acq_t) == 8, "acq_t size is not 8 byte");

typedef union __attribute__((packed, aligned (4))) cmbloc_t
{
    struct
    {
        uint32_t    BIR     :3;
        uint32_t    CQMMS   :1;
        uint32_t    CQPDS   :1;
        uint32_t    CDPMLS  :1;
        uint32_t    CDPCILS :1;
        uint32_t    CDMMMS  :1;
        uint32_t    CQDA    :1;
        uint32_t    rsvd0   :3;
        uint32_t    OFST    :20;
    };

    uint32_t all;    
}cmbloc_t;
static_assert(sizeof(cmbloc_t) == 4, "cmbloc_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4))) cmbsz_t
{    
    struct    
    {
        uint32_t    SQS     :1;
        uint32_t    CQS     :1;
        uint32_t    LISTS   :1;
        uint32_t    RDS     :1;
        uint32_t    WDS     :1;
        uint32_t    rsvd0   :3;
        uint32_t    SZU     :4;
        uint32_t    SZ      :20;
    };

    uint32_t all;
}cmbsz_t;
static_assert(sizeof(cmbsz_t) == 4, "cmbsz_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4))) bpinfo_t
{
    struct
    {
        uint32_t    BPSZ    :15;
        uint32_t    rsvd0   :5;
        uint32_t    BRS     :2;
        uint32_t    rsvd1   :9;
        uint32_t    ABPID   :1;
    };

    uint32_t all;
}bpinfo_t;
static_assert(sizeof(bpinfo_t) == 4, "bpinfo_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4))) bprsel_t
{
    struct
    {
        uint32_t    BPRSZ   :10;
        uint32_t    BPROF   :20;
        uint32_t    rsvd0   :1;
        uint32_t    BPID    :1;
    };

    uint32_t all;
}bprsel_t;
static_assert(sizeof(bprsel_t) == 4, "bprsel_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4))) bpmbl_t
{
    struct
    {
        uint32_t    rsvd0   :12;
        uint64_t    BMBBA   :52;
    };

    uint64_t all;
}bpmbl_t;
static_assert(sizeof(bpmbl_t) == 8, "bpmbl_t size is not 8 byte");

typedef union __attribute__((packed, aligned (4))) cmbmsc_t
{
    struct
    {
        uint32_t    CRE     :1;
        uint32_t    CMSE    :1;
        uint32_t    rsvd0   :10;
        uint64_t    CBA     :52;
    };

    uint64_t all;
}cmbmsc_t;
static_assert(sizeof(cmbmsc_t) == 8, "cmbmsc_t size is not 8 byte");

typedef union __attribute__((packed, aligned (4))) cmbsts_t
{
    struct
    {
        uint32_t    CBAI    :1;
        uint32_t    rsvd0   :31;
    };

    uint32_t all;
}cmbsts_t;
static_assert(sizeof(cmbsts_t) == 4, "cmbsts_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4))) pmrcap_t
{
    struct
    {
        uint32_t    rsvd0   :3;
        uint32_t    RDS     :1;
        uint32_t    WDS     :1;
        uint32_t    BIR     :3;
        uint32_t    PMRTU   :2;
        uint32_t    PMRWBM  :4;
        uint32_t    rsvd1   :2;
        uint32_t    PMRTO   :8;
        uint32_t    CMSS    :1;
        uint32_t    rsvd2   :7;
    };

    uint32_t all;
}pmrcap_t;
static_assert(sizeof(pmrcap_t) == 4, "pmrcap_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4))) pmrctl_t
{
    struct
    {
        uint32_t    EN      :1;
        uint32_t    rsvd0   :31;
    };

    uint32_t all;
}pmrctl_t;
static_assert(sizeof(pmrctl_t) == 4, "pmrctl_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4))) pmrsts_t
{
    struct
    {
        uint32_t    ERR     :8;
        uint32_t    NRDY    :1;
        uint32_t    HSTS    :3;
        uint32_t    CBAI    :1;
        uint32_t    rsvd0   :19;
    };

    uint32_t all;
}pmrsts_t;
static_assert(sizeof(pmrsts_t) == 4, "pmrsts_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4)))  pmrebs_t
{
    struct
    {
        uint32_t    PMRSZU  :4; 
        uint32_t    RBB     :1;
        uint32_t    rsvd0   :3;
        uint32_t    PMRWBZ  :24;
    };

    uint32_t all;
}pmrebs_t;
static_assert(sizeof(pmrebs_t) == 4, "pmrebs_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4)))  pmrswtp_t
{
    struct
    {
        uint32_t    PMRSWTU :4;
        uint32_t    rsvd0   :4;
        uint32_t    PMRSWTV :24;
    };

    uint32_t all;
}pmrswtp_t;
static_assert(sizeof(pmrswtp_t) == 4, "pmrswtp_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4)))  pmrmscl_t 
{
    struct
    {
        uint32_t    rsvd0   :1;
        uint32_t    CMSE    :1;
        uint32_t    rsvd1   :10;
        uint32_t    CBA     :20;
    };

    uint32_t all;
}pmrmscl_t;
static_assert(sizeof(pmrmscl_t) == 4, "pmrmscl_t size is not 4 byte");

typedef union __attribute__((packed, aligned (4)))  pmrmscu_t 
{
    uint32_t CBA;
    uint32_t all;
}pmrmscu_t;
static_assert(sizeof(pmrmscu_t) == 4, "pmrmscu_t size is not 4 byte");

//-------------------------------------------------
// NVME 1.4 - sq tail
//-------------------------------------------------

typedef union __attribute__((packed, aligned (4))) sqtdbl_t
{
    struct
    {
        uint32_t    SQT     :16;
        uint32_t    rsvd0   :16;
    };

    uint32_t all;
}sqtdbl_t;
static_assert(sizeof(sqtdbl_t) == 4, "sqtdbl_t size is not 4 byte");

//-------------------------------------------------
// NVME 1.4 - cq head
//-------------------------------------------------

typedef union __attribute__((packed, aligned (4))) cqhdbl_t
{
    struct
    {
        uint32_t    CQH     :16;
        uint32_t    rsvd0   :16;
    };

    uint32_t all;
}cqhdbl_t;
static_assert(sizeof(cqhdbl_t) == 4, "cqhdbl_t size is not 4 byte");

//-------------------------------------------------
// NVME 1.4 - msi-x
//-------------------------------------------------

typedef struct __attribute__((packed, aligned (4))) msix_t
{
    uint32_t MXTMLA;
    uint32_t MXTMUA;
    uint32_t MXTMD;
    
    union
    {
        struct
        {
            uint16_t maskBit     :1;
            uint16_t reserved    :15;
            uint16_t stLower     :8;
            uint16_t stUpper     :8;
        };

        uint32_t all;
    }MXTVC;
}msix_t;
static_assert(sizeof(msix_t) == MSIX_ENTRY_SIZE);

//-------------------------------------------------
// NVME 1.4 - Identify Controller
//-------------------------------------------------
#pragma pack(push, 4)

//Section 1
typedef union cmic_t
{
    struct
    {
        uint8_t     cmicMultiSubsystemPort                      : 1;    //bit  0
        uint8_t     cmicMultiHost                               : 1;    //bit  1
        uint8_t     cmicSriov                                   : 1;    //bit  2
        uint8_t     cmicAsymmetricNamespaceAccess               : 1;    //bit  3
        uint8_t     reserved                                    : 4;    //bits 4-7
    };
    
    uint8_t    all;
 
}cmic_t;
static_assert(sizeof(cmic_t) == 1 , "cmic_t size is not 1 byte");

typedef union oaes_t
{
    struct
    {
        uint32_t    oaesReserved                                : 8;    //bits  0-7     
        uint32_t    namespaceAttributeChanged                   : 1;    //bit   8       
        uint32_t    firmwareActivationNotices                   : 1;    //bit   9       
        uint32_t    oaesReserved1                               : 1;    //bit   10
        uint32_t    asymmetricNamespaceAccess                   : 1;    //bit   11
        uint32_t    predictableLatencyEvent                     : 1;    //bit   12
        uint32_t    lbaStatusInfoNoticEvent                     : 1;    //bit   13
        uint32_t    enduranceGroupEvent                         : 1;    //bit   14    
        uint32_t    reserved                                    :17;    //bits  15-31   
    };
    
    uint32_t    all;    
    
}oaes_t;
static_assert(sizeof(oaes_t) == 4 , "oaes_t size is not 4 bytes");

typedef union ctratt_t
{
    struct 
    {
        uint32_t    support128bitHostIdentifier                 : 1;    //bit   0       
        uint32_t    supportNonOpPowerStatePermissiveMode        : 1;    //bit   1      
        uint32_t    supportNvmeSets                             : 1;    //bit   2
        uint32_t    supportReadRecoveryLevels                   : 1;    //bit   3
        uint32_t    supportEnduranceGroups                      : 1;    //bit   4
        uint32_t    supportPredictableLatencyMode               : 1;    //bit   5
        uint32_t    supportTrafficBasedKeepAliveSupport         : 1;    //bit   6
        uint32_t    supportNamespaceGranularity                 : 1;    //bit   7
        uint32_t    supportSqAssociations                       : 1;    //bit   8
        uint32_t    supportUUIDList                             : 1;    //bit   9    
        uint32_t    reserved                                    :22;    //bits  10-31          
    };

    uint32_t    all;    
}ctratt_t;
static_assert(sizeof(ctratt_t) == 4 , "ctratt_t size is not 4 bytes");

typedef union rrls_t
{
    struct
    {
        uint8_t     readRecoveryLevel0                          : 1;    //bit   0
        uint8_t     readRecoveryLevel1                          : 1;    //bit   1
        uint8_t     readRecoveryLevel2                          : 1;    //bit   2
        uint8_t     readRecoveryLevel3                          : 1;    //bit   3
        uint8_t     readRecoveryLevel4                          : 1;    //bit   4
        uint8_t     readRecoveryLevel5                          : 1;    //bit   5
        uint8_t     readRecoveryLevel6                          : 1;    //bit   6
        uint8_t     readRecoveryLevel7                          : 1;    //bit   7
        uint8_t     readRecoveryLevel8                          : 1;    //bit   8
        uint8_t     readRecoveryLevel9                          : 1;    //bit   9
        uint8_t     readRecoveryLevel10                         : 1;    //bit   10
        uint8_t     readRecoveryLevel11                         : 1;    //bit   11
        uint8_t     readRecoveryLevel12                         : 1;    //bit   12
        uint8_t     readRecoveryLevel13                         : 1;    //bit   13
        uint8_t     readRecoveryLevel14                         : 1;    //bit   14
        uint8_t     readRecoveryLevel15                         : 1;    //bit   15
    };
    
    uint16_t    all;
}rrls_t;
static_assert(sizeof(rrls_t) == 2 , "rrls_t size is not 2 bytes");

//Section 2
typedef union oacs_t
{
    struct
    {
        uint8_t     securitySendReceiveSupported                : 1;    //bit   0
        uint8_t     formatNVMCommandSupported                   : 1;    //bit   1
        uint8_t     fwActivateDownloadSupported                 : 1;    //bit   2
        uint8_t     namespaceManagementSupported                : 1;    //bit   3
        uint8_t     deviceSelfTestSupported                     : 1;    //bit   4
        uint8_t     directivesSupported                         : 1;    //bit   5
        uint8_t     nvmeMiSendRecieveSupported                  : 1;    //bit   6
        uint8_t     virtualizatonManagementSupported            : 1;    //bit   7
        uint8_t     doorbellBufferConfigCmdSupported            : 1;    //bit   8
        uint8_t     getLbaStatusCapability                      : 1;    //bit   9
        uint8_t     reserved                                    : 6;    //bits  10-15    
    };
    
    uint16_t    all;
}oacs_t;
static_assert(sizeof(oacs_t) == 2 , "oacs_t size is not 2 bytes");

typedef union frmw_t
{
    struct
    {
        uint8_t     firmwareUpdateSlot1ReadOnly                 : 1;    //bit   0
        uint8_t     firmwareUpdateSlotCount                     : 3;    //bits  1-3
        uint8_t     firmwareActivationWithoutReset              : 1;    //bit   4
        uint8_t     reserved                                    : 3;    //bits  5-7    
    };
    
    uint8_t    all;
}frmw_t;
static_assert(sizeof(frmw_t) == 1 , "frmw_t size is not 1 byte");

typedef union lpa_t
{
    struct
    {
        uint8_t     logPageAttributes                           : 1;    //bit   0
        uint8_t     logCommandEffects                           : 1;    //bit   1
        uint8_t     logExtendedData                             : 1;    //bit   2
        uint8_t     logTelemetryHostInit                        : 1;    //bit   3
        uint8_t     logPersistentEvent                          : 1;    //bit   4    
        uint8_t     reserved                                    : 3;    //bits 5-7    
    };
    
    uint8_t    all;
}lpa_t;
static_assert(sizeof(lpa_t) == 1 , "lpa_t size is not 1 byte");

typedef union avscc_t
{
    struct
    {
        uint8_t     adminVendorSpecificCommandConfig            : 1;    //bit  0
        uint8_t     reserved                                    : 7;    //bits 1-7
    };
    
    uint8_t    all;
}avscc_t;
static_assert(sizeof(avscc_t) == 1 , "avscc_t size is not 1 byte");

typedef union apsta_t
{
    struct
    {
        uint8_t     autonomousPowerStateTransitionAttributes    : 1;    //bit  0
        uint8_t     reserved                                    : 7;    //bits 1-7   
    };
    
    uint8_t    all;
}apsta_t;
static_assert(sizeof(apsta_t) == 1 , "apsta_t size is not 1 byte");

typedef union rpmbs_t
{
    struct
    {
        uint32_t    numberOfRpmbUnits                           : 3;    //bits 0-2
        uint32_t    authenticationMethod                        : 3;    //bits 3-5
        uint32_t    reserved                                    : 10;   //bits 6-15
        uint32_t    totalSize                                   : 8;    //bits 16-23
        uint32_t    accessSize                                  : 8;    //bits 24-31
    };
    
    uint32_t    all;
}rpmbs_t;
static_assert(sizeof(rpmbs_t) == 4 , "rpmbs_t size is not 4 bytes");

typedef union sanicap_t
{
    struct
    {
        uint32_t    cryptoEraseSupport                          : 1;    //bit 0
        uint32_t    blockEraseSupport                           : 1;    //bit 1
        uint32_t    overWriteSupport                            : 1;    //bit 2
        uint32_t    reserved                                    : 26;   //bits 3-28
        uint32_t    noDeallocateInhibited                       : 1;    //bit 29
        uint32_t    noDeallocateModifiesMediaAfterSanitize      : 2;    //bits 30-31
    };
    
    uint32_t    all;
}sanicap_t;
static_assert(sizeof(sanicap_t) == 4 , "sanicap_t size is not 4 bytes");

//Section 3
typedef union sqes_t
{
    struct
    {
        uint8_t     submissionQueueEntrySizeMinimum             : 4;    //bits 0-3
        uint8_t     submissionQueueEntrySizeMaximum             : 4;    //bits 4-7    
    };

    uint8_t    all;
}sqes_t;
static_assert(sizeof(sqes_t) == 1 , "sqes_t size is not 1 byte");

typedef union cqes_t
{
    struct    
    {
        uint8_t     completionQueueEntrySizeMinimum             : 4;    //bits 0-3
        uint8_t     completionQueueEntrySizeMaximum             : 4;    //bits 4-7  
    };
    
    uint8_t    all;    
}cqes_t;
static_assert(sizeof(cqes_t) == 1 , "cqes_t size is not 1 byte");

typedef union oncs_t
{
    struct
    {
        uint16_t    compareCommandSupported                     : 1;    //bit 0
        uint16_t    writeUncorrectableCommandSupported          : 1;    //bit 1
        uint16_t    datasetManagementCommandSupported           : 1;    //bit 2
        uint16_t    writeZeroesCommandSupported                 : 1;    //bit 3
        uint16_t    saveSelectInSetGetFeaturesSupported         : 1;    //bit 4
        uint16_t    reservationsSupported                       : 1;    //bit 5
        uint16_t    timeStampFeatureSupported                   : 1;    //bit 6
        uint16_t    verifyCommandSupported                      : 1;    //bit 7    
        uint16_t    reserved                                    : 8;    //bits 8-15    
    };

    uint16_t    all;    
}oncs_t;
static_assert(sizeof(oncs_t) == 2 , "oncs_t size is not 2 bytes");

typedef union fuses_t
{
    struct
    {
        uint16_t    compareAndWriteFusedOperationSupport        : 1;    //bit  0
        uint16_t    reserved                                    :15;    //bits 1-15
    };
    
    uint16_t    all;
}fuses_t;
static_assert(sizeof(fuses_t) == 2 , "fuses_t size is not 2 bytes");

typedef union fna_t
{        
    struct
    {
        uint8_t     formatAppliesToAllNamespaces                : 1;    //bit  0   
        uint8_t     secureEraseAppliesToAllNamespaces           : 1;    //bit  1   
        uint8_t     cryptographicEraseSupported                 : 1;    //bit  2   
        uint8_t     reserved                                    : 5;    //bits 3-7 
    };
    
    uint8_t    all;
}fna_t;
static_assert(sizeof(fna_t) == 1 , "fna_t size is not 1 byte");

typedef union vwc_t
{
    struct
    {
        uint8_t     volatileWriteCache                          : 1;    //bit  0
        uint8_t     flushCommandBehavior                        : 2;    //bits 1-2
        uint8_t     reserved                                    : 5;    //bits 3-7
    };
    
    uint8_t    all;    
}vwc_t;
static_assert(sizeof(vwc_t) == 1 , "vwc_t size is not 1 byte");

typedef union nvscc_t
{
    struct
    {
        uint8_t     nvmVendorSpecificCommand                    : 1;    //bit  0
        uint8_t     reserved                                    : 7;    //bits 1-7        
    };

    uint8_t    all;    
}nvscc_t;
static_assert(sizeof(nvscc_t) == 1 , "nvscc_t size is not 1 byte");

typedef union nwpc_t
{
    struct
    {
        uint8_t     supportNoWriteProtect                       : 1;    //bit 0
        uint8_t     supportWriteProtectUntilPowerCycleState     : 1;    //bit 1
        uint8_t     supportPermanentWriteProtectState           : 1;    //bit 2
        uint8_t     reserved                                    : 5;    //bits 3-7
    };

    uint8_t    all;    
}nwpc_t;
static_assert(sizeof(nwpc_t) == 1 , "nwpc_t size is not 1 byte");

typedef union sgls_t
{    
    struct
    {
        uint32_t    sglNvmCmdSet                                :2;     //bit 0-1
        uint32_t    supportKeyedDataBlockDesc                   :1;     //bit 2
        uint32_t    reserved                                    :13;    //bit 3-15
        uint32_t    supportBitBucketDesc                        :1;     //bit 16
        uint32_t    supportByteAlignedContiguousPhysicalBuffer  :1;     //bit 17
        uint32_t    supportCmdDataLongerThanTransferData        :1;     //bit 18
        uint32_t    supportMptrContainSglDesc                   :1;     //bit 19
        uint32_t    supportAddressFieldInDataBlock              :1;     //bit 20
        uint32_t    supportTransportSglDataBlockDesc            :1;     //bit 21
        uint32_t    reserved1                                   :10;    //bit 22-31
    };

    uint32_t    all;    
}sgls_t;
static_assert(sizeof(sgls_t) == 4 , "sgls_t size is not 4 bytes");

//Section 4
typedef union psd_t
{    
    struct
    {
        uint16_t    MP;                     //bits 00-15    bytes 0-1
        uint8_t     psdReserved0;           //bits 16-23    bytes 2-3
        uint8_t     MXPS            : 1;    //bit  24       byte  4
        uint8_t     NOPS            : 1;    //bit  25       byte  4
        uint8_t     psdReserved1    : 6;    //bits 26-31    byte  4
        uint32_t    ENLAT;                  //bits 32-63    bytes 5-8
        uint32_t    EXLAT;                  //bits 64-95    bytes 9-12    
        uint8_t     RRT             : 5;    //bits 96-100   byte  13
        uint8_t     psdReserved2    : 3;    //bits 101-103  byte  13        
        uint8_t     RRL             : 5;    //bits 104-108  byte  14
        uint8_t     psdReserved3    : 3;    //bits 109-111  byte  14        
        uint8_t     RWT             : 5;    //bits 112-116  byte  15
        uint8_t     psdReserved4    : 3;    //bits 117-119  byte  15        
        uint8_t     RWL             : 5;    //bits 120-124  byte  16
        uint8_t     psdReserved5    : 3;    //bits 125-127  byte  16      
        uint16_t    IDLP;                   //bits 128-143  bytes 17-18      
        uint8_t     psdReserved6    : 6;    //bits 144-149  byte  19
        uint8_t     IPS             : 2;    //bits 150-151  byte  19
        uint8_t     psdReserved7;           //bits 152-159  byte  20
        uint16_t    ACTP;                   //bits 160-175  bytes 21-22
        uint8_t     APW             : 3;    //bits 176-178  byte  23      
        uint8_t     psdReserved8    : 3;    //bits 179-181  byte  23
        uint8_t     APS             : 2;    //bits 182-183  byte  23
        uint8_t     psdReserved9[9];        //bits 184-255  bytes 24-32
    };
    
    uint32_t all[8];
        
}psd_t;
static_assert(sizeof(psd_t) == 32, "psd_t size is not 32 bytes");

#pragma pack(pop)

typedef union __attribute__((packed, aligned (4))) identifyController_t
{
    uint32_t dword[1024];
    
    struct
    {
        //-------------------------------------------------------------------------------------------------------------------
        //Section 1 - Controller Capabilities and Features
        //bytes 0-255 (256 bytes)
        //-------------------------------------------------------------------------------------------------------------------

        uint32_t    VID                     :16;    //pciVendorID;                                          //byte(s) 0-1
        uint32_t    SSVID                   :16;    //pciSubsystemVendorID;                                 //byte(s) 2-3
        uint8_t     SN[20];                         //serialNumber[20];                                     //byte(s) 4-23
        uint8_t     MN[40];                         //modelNumber[40];                                      //byte(s) 24-63
        uint8_t     FR[8];                          //firmwareRevision[8];                                  //byte(s) 64-71
        uint32_t    RAB                     :8;     //recommendedArbitrationBurst;                          //byte(s) 72        
        uint32_t    IEEE                    :24;    //ieeeOuiIdentifier:24;                                 //byte(s) 73-75        
        cmic_t      CMIC;                           //controllerMultipathIoNamespaceSharingCapabilities;    //byte(s) 76        
        uint32_t    MDTS                    :8;     //maximumDataTransferSize;                              //byte(s) 77    
        uint32_t    CNTLID                  :16;    //controllerId;                                         //byte(s) 78-79        
        uint32_t    VER;                            //nvmeVersion;                                          //byte(s) 80-83    
        uint32_t    RTD3R;                          //rtd3ResumeLatency;                                    //byte(s) 84-87
        uint32_t    RTD3E;                          //rtd3EntryLatency;                                     //byte(s) 88-91    
        oaes_t      OAES;                           //optionalAysnchronouseEventsSupported;                 //byte(s) 92-95    
        ctratt_t    CTRATT;                         //controllerAttributes;                                 //byte(s) 96-99
        rrls_t      RRLS;                           //readRecoveryLevelsSupported;                          //byte(s) 100-101
        uint8_t     section1Reserved0[9];           //reserved                                              //byte(s) 110-102
        uint8_t     CNTRLTYPE               :8;     //controllerType;                                       //byte(s) 111
        uint8_t     FGUID[16];                      //fruGloballyUniqueId[16];                              //byte(s) 112-127
        uint32_t    CRDT1                   :16;    //commandRetryDelayTimer1;                              //byte(s) 128-129
        uint32_t    CRDT2                   :16;    //commandRetryDelayTimer2;                              //byte(s) 130-131
        uint32_t    CRDT3                   :16;    //commandRetryDelayTimer3;                              //byte(s) 132-133
        uint8_t     section1Reserved1[106];         //reserved                                              //byte(s) 134-239
        uint8_t     managementInterface[16];        //managementInterface[16];                              //byte(s) 240-255

        //-------------------------------------------------------------------------------------------------------------------
        //Section 2 - Admin Command Set Attributes & Optional Controller Capabilities
        //bytes 256-511 (256 bytes)
        //-------------------------------------------------------------------------------------------------------------------

        oacs_t      OACS;                           //optionalAdminCommandSupport;                          //byte(s) 256-257     
        uint32_t    ACL                     :8;     //abortCommandLimit;                                    //byte(s) 258    
        uint32_t    AERL                    :8;     //asynchronousEventRequestLimit;                        //byte(s) 259    
        frmw_t      FRMW;                           //firmwareUpdates;                                      //byte(s) 260
        lpa_t       LPA;                            //logPageAttributes;                                    //byte(s) 261
        uint32_t    ELPE                    :8;     //errorLogPageEntries;                                  //byte(s) 262    
        uint32_t    NPSS                    :8;     //numberOfPowerStatesSupported;                         //byte(s) 263
        avscc_t     AVSCC;                          //adminVendorSpecificCommandConfig;                     //byte(s) 264
        apsta_t     APSTA;                          //autonomousPowerStateTransitionAttributes;             //byte(s) 265
        uint32_t    WCTEMP                  :16;    //warningCompositeTemperatureThreshold;                 //byte(s) 266-267
        uint32_t    CCTEMP                  :16;    //criticalCompositeTemperatureThreshold;                //byte(s) 268-269    
        uint32_t    MTFA                    :16;    //maximumTimeForFirmwareActivation;                     //byte(s) 270-271
        uint32_t    HMPRE;                          //hostMemoryBufferPreferredSize;                        //byte(s) 272-275
        uint32_t    HMMIN;                          //hostMemoryBufferMinimumSize;                          //byte(s) 276-279
        uint8_t     TNVMCAP[16];                    //totalNVMCapacity[16];                                 //byte(s) 280-295
        uint8_t     UNVMCAP[16];                    //unallocatedNvmCapacity[16];                           //byte(s) 296-311
        rpmbs_t     RPMBS;                          //replayProtectedMemoryBlockSupport;                    //byte(s) 312-315
        uint32_t    EDSTT                   :16;    //extendedDeviceSelfTestMinutes;                        //byte(s) 316-317
        uint32_t    DSTO                    :8;     //deviceSelfTestOptions;                                //byte(s) 318
        uint32_t    FWUG                    :8;     //firmwareUpdateGranularity;                            //byte(s) 319    
        uint32_t    KAS                     :16;    //keepAliveSupport;                                     //byte(s) 320-321    
        uint32_t    HCTMA                   :16;    //hostControlledThermalManagementAttributes;            //byte(s) 322-323
        uint32_t    MNTMT                   :16;    //minThermalManagementTemperature;                      //byte(s) 324-325
        uint32_t    MXTMT                   :16;    //maxThermalManagementTemperature;                      //byte(s) 326-327    
        sanicap_t   SANICAP;                        //sanitizeCapabilities;                                 //byte(s) 328-331    
        uint32_t    HMMINDS;                        //hostMemoryBufferMinimumDescriptorEntrySize;           //byte(s) 332-335
        uint32_t    HMMAXD                  :16;    //hostMemoryMaximumDescriptorsEntries;                  //byte(s) 336-337
        uint32_t    NSETIDMAX               :16;    //nvmSetidentifierMaximum;                              //byte(s) 338-339
        uint32_t    ENDGIDMAX               :16;    //enduranceGroupIdentifierMaximum;                      //byte(s) 340-341
        uint32_t    ANATT                   :8;     //anaTransitionTime;                                    //byte(s) 342
        uint32_t    ANACAP                  :8;     //asymmetricNamespaceAccessCapabilities;                //byte(s) 343
        uint32_t    ANAGRPMAX;                      //anaGroupIdentifierMaximum;                            //byte(s) 344-347
        uint32_t    NANAGRPID;                      //numberOfAnaGroupIdentifiers;                          //byte(s) 348-351
        uint32_t    PELS;                           //persistentEventLogSize;                               //byte(s) 352-355
        uint8_t     section2Reserved0[156];         //reserved                                              //byte(s) 356-511

        //-------------------------------------------------------------------------------------------------------------------
        //Section 3 - NVM Command Set Attributes
        //bytes 512-703 (192 bytes)
        //-------------------------------------------------------------------------------------------------------------------

        sqes_t      SQES;                           //submissionQueueEntrySize;                             //byte(s) 512
        cqes_t      CQES;                           //completionQueueEntrySize;                             //byte(s) 513    
        uint32_t    MAXCMD                  :16;    //maximumOutstandingCommands;                           //byte(s) 514-515
        uint32_t    NN;                             //numberOfNamespaces;                                   //byte(s) 516-519    
        oncs_t      ONCS;                           //optionalNvmCommandSupport;                            //byte(s) 520-521
        fuses_t     FUSES;                          //fusedOperationSupport;                                //byte(s) 522-523
        fna_t       FNA;                            //formatNvmAttributes;                                  //byte(s) 524
        vwc_t       VWC;                            //volatileWriteCache;                                   //byte(s) 525    
        uint32_t    AWUN                    :16;    //atomicWriteUnitNormal;                                //byte(s) 526-527
        uint32_t    AWUPF                   :16;    //atomicWriteUnitPowerFail;                             //byte(s) 528-529
        nvscc_t     NVSCC;                          //nvmVendorSpecificCommandConfiguartion;                //byte(s) 530    
        nwpc_t      NWPC;                           //namespaceWriteProtectionCapabilities;                 //byte(s) 531    
        uint32_t    ACWU                    :16;    //atomicCompareAndWriteUnit;                            //byte(s) 532-533    
        uint32_t    section3Reserved0       :16;    //reserved                                              //byte(s) 534-535    
        sgls_t      SGLS;                           //sglSupport;                                           //byte(s) 536-539
        uint32_t    MNAN;                           //maximumNumberOfAllowedNamespaces;                     //byte(s) 540-543    
        uint8_t     section3Reserved1[224];         //reserved                                              //byte(s) 544-767
        uint8_t     SUBNQN[256];                    //nvmSubsystemNvmeQualifiedName[256];                   //byte(s) 768-1023
        uint8_t     section3Reserved2[768];         //reserved                                              //byte(s) 1024-1791
        uint8_t     section3Reserved3[256];         //nvmeOverFabricsReserved[256];                         //byte(s) 1792-2047

        //-------------------------------------------------------------------------------------------------------------------
        //Section 4 - Power State Descriptors
        //bytes 2048-3071 (1024 bytes)
        //bytes 2048-2079 power state 0 descriptor is mandatory with up to 31 additional optional power state descriptors at 32 bytes each for a total of 1024 bytes
        //bytes 2080-3071 power state 1-31 descriptors are optional
        //-------------------------------------------------------------------------------------------------------------------
        
        psd_t       PSD[32];                        //powerStateDescriptor[32];                             //byte(s) 2048-3071
        
        //-------------------------------------------------------------------------------------------------------------------
        //Section 5 - Vendor specific
        //bytes 3072-4095 (1024 bytes)
        //-------------------------------------------------------------------------------------------------------------------
        
        uint8_t     vendorSpecific[1024];                                                                   //byte(s) 3072-4095    
    };
        
}identifyController_t;
static_assert(sizeof(identifyController_t) == 4096, "identifyController_t size is not 4096 bytes");

//-------------------------------------------------
// NVME 1.4 - Identify Namespace
//-------------------------------------------------
#pragma pack(push, 4)

typedef union nsfeat_t
{
    struct
    {
        uint8_t     thinProvisioningSupported                   : 1;    //bit  0
        uint8_t     namespaceAtomicSupported                    : 1;    //bit  1
        uint8_t     deallocatedSupported                        : 1;    //bit  2        
        uint8_t     reuseId                                     : 1;    //bit  3
        uint8_t     optperf                                     : 1;    //bit  4
        uint8_t     reserved                                    : 3;    //bits 5-7    
    };
    
    uint8_t     all;
}nsfeat_t;
static_assert(sizeof(nsfeat_t) == 1, "nsfeat_t size is not 1 byte");

typedef union flbas_t
{
    struct
    {
        uint8_t currentLbaFormat                : 4; //bits 0-3
        uint8_t metaDataSetting                 : 1; //bit 4
        uint8_t reserved                        : 3; //bit 5-7
    };
    
    uint8_t     all;
}flbas_t;    
static_assert(sizeof(flbas_t) == 1, "flbas_t size is not 1 byte");

typedef union mc_t
{
    struct
    {
        uint8_t     metadataInExtendedLBA                       : 1;    //bit  0
        uint8_t     metadataInSeparateBuffer                    : 1;    //bit  1
        uint8_t     reserved                                    : 6;    //bits 2-7    
    };
    
    uint8_t     all;
}mc_t;
static_assert(sizeof(mc_t) == 1, "mc_t size is not 1 byte");

typedef union dpc_t
{
    struct
    {
        uint8_t     protectionInformationType1                  : 1;    //bit  0
        uint8_t     protectionInformationType2                  : 1;    //bit  1
        uint8_t     protectionInformationType3                  : 1;    //bit  2
        uint8_t     protectionInformationFirst8Metadata         : 1;    //bit  3
        uint8_t     protectionInformationLast8Metadata          : 1;    //bit  4
        uint8_t     reserved                                    : 3;    //bits 5-7     
    };
    
    uint8_t     all;
}dpc_t;
static_assert(sizeof(dpc_t) == 1, "dpc_t size is not 1 byte");

typedef union dps_t
{        
    struct
    {
        uint8_t     protectionInformation                       : 2;    //bits 0-2
        uint8_t     protectionInformationLocatio                : 1;    //bit  3
        uint8_t     reserved                                    : 4;    //bits 4-7
    };
    uint8_t     all;
}dps_t;
static_assert(sizeof(dps_t) == 1, "dps_t size is not 1 byte");

typedef union nmic_t
{
    struct
    {    
        uint8_t     sharedNamespace                             : 1;    //bit  0
        uint8_t     reserved                                    : 7;    //bits 1-7
    };
    
    uint8_t     all;
}nmic_t;
static_assert(sizeof(nmic_t) == 1, "nmic_t size is not 1 byte");

typedef union rescap_t
{
    struct
    {    
        uint8_t     persistThroughPowerLoss                     : 1;    //bit 0
        uint8_t     writeExclusiveReservationType               : 1;    //bit 1
        uint8_t     exclusiveAccessReservationType              : 1;    //bit 2
        uint8_t     writeExclusiveRegistrantsOnly               : 1;    //bit 3
        uint8_t     exclusiveAccessRegistrantsOnly              : 1;    //bit 4
        uint8_t     writeExclusiveAllRegistrants                : 1;    //bit 5
        uint8_t     exclusiveAccessAllRegistrants               : 1;    //bit 6
        uint8_t     ignoreExistingKey                           : 1;    //bit 7    
    };

    uint8_t     all;
}rescap_t;
static_assert(sizeof(rescap_t) == 1, "rescap_t size is not 1 byte");

typedef union fpi_t
{
    struct
    {    
        uint8_t     formatProgressIndicator                     : 7;    //bits 0-6
        uint8_t     formatProgressIndicatorSupport              : 1;    //bit 7   
    };

    uint8_t     all;
}fpi_t;
static_assert(sizeof(fpi_t) == 1, "fpi_t size is not 1 byte");

typedef union dlfeat_t
{
    struct
    {    
        uint8_t     deallocatedLogicalBlockReadBehavior         : 2;    //bits 0-2
        uint8_t     supportDeallocateWriteZero                  : 1;    //bit  3
        uint8_t     deallocatedPiGuardCrc                       : 1;    //bit  4
        uint8_t     reserved                                    : 3;    //bits 5-7     
    };

    uint8_t     all;
}dlfeat_t;
static_assert(sizeof(dlfeat_t) == 1, "dlfeat_t size is not 1 byte");

typedef union nsattr_t
{
    struct
    {    
        uint8_t     writeProtected                              : 1;    //bit  0
        uint8_t     reserved                                    : 7;    //bits 1-7
    };
   
    uint8_t     all;
}nsattr_t;
static_assert(sizeof(nsattr_t) == 1, "nsattr_t size is not 1 byte");

typedef union nguid_t    
{
    struct
    {
        uint32_t nsId;                 //byte 104-107 NGUID vendor specific extension id
        uint32_t nsidCount;            //byte 108-111 NGUID vendor specific extension id
        uint32_t companyId_OUI : 24;   //byte 112-114 NGUID OUI
        uint64_t extendedId    : 40;   //byte 115-119 NGUID Extension id 
    };
    
    uint32_t all[4];
}nguid_t;    
static_assert(sizeof(nguid_t) == 16, "nguid_t size is not 16 bytes");

typedef union lbaFormat_t
{
    struct
    {
        uint32_t metaDataSize        : 16;  //bit 15:00 
        uint32_t lbaDataSize         : 8;   //bit 23:16
        uint32_t relativePerformance : 2;   //bit 25:24 
        uint32_t reserved            : 6;   //bit 32:26
    };
    
    uint32_t all;
}lbaFormat_t;
static_assert(sizeof(lbaFormat_t) == 4, "lbaFormat_t size is not 4 bytes");
    
#pragma pack(pop)

typedef union __attribute__((packed, aligned (4))) identifyNamespace_t
{
    uint32_t dword[1024];
    struct
    {    
        uint64_t    NSZE;                           //namespaceSize;                                //byte(s) 0-7     (host specified)
        uint64_t    NCAP;                           //namespaceCapacity;                            //byte(s) 8-15    (host specified)
        uint64_t    NUSE;                           //namespaceUtilization;                         //byte(s) 16-23
        nsfeat_t    NSFEAT;                         //namespaceFeatures;                            //byte(s) 24    
        uint32_t    NLBAF                   :8;     //numberOfLBAFormats;                           //byte(s) 25
        flbas_t     FLBAS;                          //formattedLbaSize;                             //byte(s) 26      (host specified)
        mc_t        MC;                             //metadataCapabilities;                         //byte(s) 27 
        dpc_t       DPC;                            //endToendProtectionCapabilities;               //byte(s) 28 
        dps_t       DPS;                            //dataProtectionTypeSettings;                   //byte(s) 29      (host specified)        
        nmic_t      NMIC;                           //namespaceMultipathIoSharingCapabilities;      //byte(s) 30      (host specified)        
        rescap_t    RESCAP;                         //reservationCapabilities;                      //byte(s) 31
        fpi_t       FPI;                            //formatProgressIndicator;                      //byte(s) 32
        dlfeat_t    DLFEAT;                         //deallocateLogicalBlockFeatures;               //byte(s) 33
        uint32_t    NAWUN                   :16;    //namespaceAtomicWriteUnitNormal;               //byte(s) 34-35
        uint32_t    NAWUPF                  :16;    //namespaceAtomicWriteUnitPowerFail;            //byte(s) 36-37
        uint32_t    NACWU                   :16;    //namespaceAtomicCompareAndWriteUnit;           //byte(s) 38-39
        uint32_t    NABSN                   :16;    //namespaceAtomicBoundarySizeNormal;            //byte(s) 40-41
        uint32_t    NABO                    :16;    //namespaceAtomicBoundaryOffset;                //byte(s) 42-43
        uint32_t    NABSPF                  :16;    //namespaceAtomicBoundarySizePowerFail;         //byte(s) 44-45  
        uint32_t    NOIOB                   :16;    //namespaceOptimalIoBoundary;                   //byte(s) 46-47
        uint8_t     NVMCAP[16];                     //nvmCapacity[16];                              //byte(s) 48-63    
        uint32_t    NPWG                    :16;    //namespacePreferredWriteGranularity;           //Byte(s) 64-65    
        uint32_t    NPWA                    :16;    //namespacePreferredWriteAlignment;             //Byte(s) 66-67
        uint32_t    NPDG                    :16;    //namespacePreferredDeallocatedGranularity;     //Byte(s) 68-69
        uint32_t    NPDA                    :16;    //namespacePreferredDeallocatedAlignment;       //Byte(s) 70-71
        uint32_t    NOWS                    :16;    //namespaceOptimalWriteSize;                    //Byte(s) 72-73
        uint8_t     reserved0[18];                  //reserved                                      //Byte(s) 74-91
        uint32_t    ANAGRPID;                       //anaGroupId;                                   //Byte(s) 92-95
        uint8_t     reserved1[3];                   //reserved                                      //Byte(s) 96-98    
        nsattr_t    NSATTR;                         //namespaceAttributes;                          //Byte(s) 99
        uint32_t    NVMSETID                :16;    //nvmSetIdentifier;                             //Byte(s) 100-101
        uint32_t    ENGID                   :16;    //enduranceGroupIdentifier;                     //Byte(s) 102-103    
        nguid_t     NGUID;                          //namespaceGloballyUniqueId;                    //byte(s) 104-119
        uint64_t    EUI64;                          //ieeeExtendedUniqueIdentifier;                 //byte(s) 120-127    
        lbaFormat_t LBAF[16];                       //lbaFormat[16];                                //byte(s) 128-191        
        uint8_t     reserved2[192];                 //reserved                                      //byte(s) 192-383
        uint8_t     vendorSpecific[3712];                                                           //byte(s) 384-4095
    };
        
}identifyNamespace_t;
static_assert(sizeof(identifyNamespace_t) == 4096, "identifyNamespace_t size is not 4096 bytes");

//-------------------------------------------------
// NVME 1.4 - Identify Namespace List
//-------------------------------------------------

typedef struct __attribute__((packed, aligned (4))) identifyNamespaceList_t
{    
    uint32_t    identifier[1024];
}identifyNamespaceList_t;
static_assert(sizeof(identifyNamespaceList_t) == 4096, "identifyNamespaceList_t size is not 4096 bytes");

//-------------------------------------------------
// NVME 1.4 - NVMe data structure - Meta Data
//-------------------------------------------------

typedef union __attribute__((packed, aligned (4))) metaData_t
{
    uint8_t  byte[8];
    uint64_t all;

    struct
    {
        uint16_t guard;
        uint16_t app;
        uint32_t ref;
    };
}metaData_t;
static_assert(sizeof(metaData_t) == 8);

//-------------------------------------------------
// NVME 1.4 - NVMe data structure - PRP Entry
//-------------------------------------------------

typedef struct __attribute__((packed, aligned (4))) prpEntry_t
{
    uint64_t pageAddress;
}prpEntry_t;
static_assert(sizeof(prpEntry_t) == 8);

//-------------------------------------------------
// NVME 1.4 - NVMe data structure - SGL
//-------------------------------------------------

typedef struct __attribute__((packed, aligned (4))) datablock_t 
{
    uint64_t address;
    uint32_t length;
    uint32_t reserved0      :24;
    uint32_t sglSubType     :4;
    uint32_t sglType        :4;
}datablock_t;
static_assert(sizeof(datablock_t) == SGL_DESCRIPTOR_SIZE);

typedef struct __attribute__((packed, aligned (4))) bitbucket_t
{
    uint64_t reserved0;
    uint32_t length;
    uint32_t reserved1      :24;
    uint32_t sglSubType     :4;
    uint32_t sglType        :4;
}bitbucket_t;
static_assert(sizeof(bitbucket_t) == SGL_DESCRIPTOR_SIZE);

typedef struct __attribute__((packed, aligned (4))) segment_t
{
    uint64_t address;
    uint32_t length;
    uint32_t reserved0      :24;
    uint32_t sglSubType     :4;
    uint32_t sglType        :4;
}segment_t;
static_assert(sizeof(segment_t) == SGL_DESCRIPTOR_SIZE);

typedef struct __attribute__((packed, aligned (4))) lastSegment_t
{
    uint64_t address;
    uint32_t length;
    uint32_t reserved0      :24;
    uint32_t sglSubType     :4;
    uint32_t sglType        :4;
}lastSegment_t;
static_assert(sizeof(lastSegment_t) == SGL_DESCRIPTOR_SIZE);

typedef struct __attribute__((packed, aligned (4))) keyedDatablock_t 
{
    uint64_t address;
    uint64_t length         :24;
    uint64_t key            :32;        
    uint64_t sglSubType     :4;
    uint64_t sglType        :4;
}keyedDatablock_t;
static_assert(sizeof(keyedDatablock_t) == SGL_DESCRIPTOR_SIZE);

typedef struct __attribute__((packed, aligned (4))) transportDatablock_t
{
    uint64_t reserved0;    
    uint32_t length;
    uint32_t reserved1      :24;    
    uint32_t sglSubType     :4;
    uint32_t sglType        :4;
}transportDatablock_t;
static_assert(sizeof(transportDatablock_t) == SGL_DESCRIPTOR_SIZE);

typedef union __attribute__((packed, aligned (4))) sglDescriptor_t
{
    uint64_t all[2];    
    
    datablock_t             datablock;    
    
    bitbucket_t             bitbucket;    
    
    segment_t               segment;    
    
    lastSegment_t           lastSegment;    
    
    keyedDatablock_t        keyedDatablock;    
    
    transportDatablock_t    transportDatablock;        
}sglDescriptor_t;
static_assert(sizeof(sglDescriptor_t) == SGL_DESCRIPTOR_SIZE);

typedef union __attribute__((packed, aligned (4))) dptr_t
{
    uint64_t all[2];

    struct
    {
        uint64_t PRP1;
        uint64_t PRP2;
    }prp;
    
    sglDescriptor_t sgl;
}dptr_t;
static_assert(sizeof(dptr_t) == SGL_DESCRIPTOR_SIZE);

//-------------------------------------------------
// NVME 1.4 - NVMe Command
//-------------------------------------------------

typedef union __attribute__((packed, aligned (4))) nvmeCommand_t
{
    uint32_t dword[16];

    struct
    {
        //dw0 bytes 0-3
        union
        {
            struct
            {
                uint32_t opcode         :8;     //bits 0:7
                uint32_t fusedOperation :2;     //bits 8:9
                uint32_t reserved       :4;     //bits 10:13
                uint32_t psdt           :2;     //bits 14:15
                uint32_t commandId      :16;    //bits 16:31
            };
        }dw0;

        //dw1 bytes 4-7
        uint32_t namespaceId;

        //dw2 bytes 8-11
        union
        {
            uint32_t reserved;   
        }dw2;

        //dw3 bytes 12-15
        union
        {
            uint32_t reserved;   
        }dw3;

        //dw4 bytes 16-19
        union
        {
            uint32_t metadataPointer;
        }dw4;
        
        //dw5 bytes 20-23
        union
        {
            uint32_t metadataPointer;
        }dw5;
  
        //dw6-9 bytes 24-39
        union
        {
            struct
            {
                uint64_t PRP1;
                uint64_t PRP2;
            }prp;
          
            struct
            {                
                uint64_t address;
                uint32_t length;
                uint32_t reserved0      :24;
                uint32_t sglSubType     :4;
                uint32_t sglType        :4;                
            }
            datablock;    
              
            struct
            {
                uint64_t reserved0;
                uint32_t length;
                uint32_t reserved1      :24;
                uint32_t sglSubType     :4;
                uint32_t sglType        :4;
            }bitbucket;

            struct
            {
                uint64_t address;
                uint32_t length;
                uint32_t reserved0      :24;
                uint32_t sglSubType     :4;
                uint32_t sglType        :4;
            }segment;

            struct
            {
                uint64_t address;
                uint32_t length;
                uint32_t reserved0      :24;
                uint32_t sglSubType     :4;
                uint32_t sglType        :4;
            }lastSegment;

            struct
            {
                uint64_t address        :64;
                uint64_t length         :24;
                uint64_t key            :32;
                uint64_t sglSubType     :4;
                uint64_t sglType        :4;
            }keyedDatablock;
       
            struct
            {
                uint64_t reserved0;                
                uint32_t length;
                uint32_t reserved1      :24;                
                uint32_t sglSubType     :4;
                uint32_t sglType        :4;
            }transportDatablock;

        }dptr;

        //dw10 bytes 40-43
        union
        {
            uint32_t all;

            struct createCompletionQueue
            {
                uint32_t QID            :16; 
                uint32_t QSIZE          :16; 
            }createCompletionQueue;

            struct createSubmissionQueue
            {
                uint32_t QID            :16; 
                uint32_t QSIZE          :16;
            }createSubmissionQueue;

            struct abort
            {
                uint32_t SQID           :16;
                uint32_t CID            :16;
            }abort;

            struct deleteCompletionQueue
            {
                uint32_t QID            :16;
                uint32_t reserved       :16;
            }deleteCompletionQueue;

            struct deleteSubmissionQueue
            {
                uint32_t QID            :16;
                uint32_t reserved       :16;
            }deleteSubmissionQueue;

            struct deviceSelfTest
            {
                uint32_t STC            :4;
                uint32_t reserved       :28;
            }deviceSelfTest;

            struct directiveReceive
            {
                uint32_t NUMD; 
            }directiveReceive;

            struct directiveSend
            {
                uint32_t NUMD; 
            }directiveSend;

            struct firmwareCommit
            {
                uint32_t FS             :3; 
                uint32_t CA             :3; 
                uint32_t reserved       :25;
                uint32_t BPID           :1; 
            }firmwareCommit;

            struct firwareImageDownload
            {
                uint32_t NUMD; 
            }firwareImageDownload;

            struct getFeatures
            {
                uint32_t FID            :8;
                uint32_t SEL            :3;
                uint32_t reserved       :21;
            }getFeatures;

            struct getLogPage
            {
                uint32_t LID            :8; 
                uint32_t LSP            :4;
                uint32_t reserved       :3;
                uint32_t RAE            :1;
                uint32_t NUMDL          :16;
            }getLogPage;

            struct identify
            {
                uint32_t CNS            :8;
                uint32_t reserved       :8;
                uint32_t CNTID          :16;
            }identify;
            
            struct namespaceAttachment
            {
                uint32_t SEL            :4;
                uint32_t reserved       :28;
            }namespaceAttachment;

            struct namespaceManagment
            {
                uint32_t SEL            :4;
                uint32_t reserved       :28;
            }namespaceManagment;

            struct setFeatures
            {
                uint32_t FID            :8; 
                uint32_t reserved       :23;
                uint32_t SV             :1; 
            }setFeatures;

            struct virtualizationManagement
            {
                uint32_t ACT            :4; 
                uint32_t reserved       :4;
                uint32_t RT             :3; 
                uint32_t reserved1      :5;
                uint32_t CNTLID         :16; 
            }virtualizationManagement;

            struct formatNvm
            {
                uint32_t LBAF           :4; 
                uint32_t MSET           :1; 
                uint32_t PI             :3; 
                uint32_t PIL            :1; 
                uint32_t SES            :3; 
                uint32_t reserved       :20;
            }formatNvm;

            struct sanitize
            {
                uint32_t SANACT         :3; 
                uint32_t AUSE           :1; 
                uint32_t OWPASS         :4; 
                uint32_t OIPBP          :1; 
                uint32_t NDAS           :1; 
                uint32_t reserved       :22;
            }sanitize;

            struct securityReceive
            {
                uint32_t NSSF           :8; 
                uint32_t SPSP0          :8;
                uint32_t SPSP1          :8;
                uint32_t SECP           :8; 
            }securityReceive;

            struct securitySend
            {
                uint32_t NSSF           :8; 
                uint32_t SPSP0          :8;
                uint32_t SPSP1          :8;
                uint32_t SECP           :8; 
            }securitySend;

            struct getLbaStatus
            {
                uint32_t SLBA; 
            }getLbaStatus;

            struct compare
            {
                uint32_t SLBA; 
            }compare;

            struct datasetManagement
            {
                uint32_t NR             :8; 
                uint32_t reserved       :24;
            }datasetManagement;

            struct read
            {
                uint32_t SLBA;
            }read;

            struct reservationAcquire
            {
                uint32_t RACQA          :3; 
                uint32_t IEKEY          :1; 
                uint32_t reserved       :4;
                uint32_t RTYPE          :8; 
                uint32_t reserved1      :16;
            }reservationAcquire;

            struct reservationRegister
            {
                uint32_t RREGA          :3; 
                uint32_t IEKEY          :1; 
                uint32_t reserved       :26;
                uint32_t CPTPL          :2; 
            }reservationRegister;

            struct reservationRelease
            {
                uint32_t RRELA          :3; 
                uint32_t IEKEY          :1; 
                uint32_t reserved       :4;
                uint32_t RTYPE          :8; 
                uint32_t reserved1      :16;
            }reservationRelease;

            struct reservationReport
            {
                uint32_t NUMD; 
            }reservationReport;

            struct verify
            {
                uint32_t SLBA; 
            }verify;

            struct write
            {
                uint32_t SLBA; 
            }write;

            struct writeUncorrectable
            {
                uint32_t SLBA; 
            }writeUncorrectable;

            struct writeZeroes
            {
                uint32_t SLBA; 
            }writeZeroes;
        }dw10;

        //dw11 bytes 44-47
        union 
        {
            uint32_t all;
            
            struct createCompletionQueue
            {
                uint32_t PC             :1; 
                uint32_t IEN            :1;
                uint32_t reserved       :6;
                uint32_t reserved1      :8;
                uint32_t IV             :16; 
            }createCompletionQueue;

            struct createSubmissionQueue
            {
                uint32_t PC             :1; 
                uint32_t QPRIO          :2;
                uint32_t reserved       :5;
                uint32_t reserved1      :8;
                uint32_t CQID           :16; 
            }createSubmissionQueue;

            struct directiveReceive
            {
                uint32_t DOPER          :8; 
                uint32_t DTYPE          :8; 
                uint32_t DSPEC          :16; 
            }directiveReceive;

            struct directiveSend
            {
                uint32_t DOPER          :8; 
                uint32_t DTYPE          :8; 
                uint32_t DSPEC          :16; 
            }directiveSend;

            struct firwareImageDownload
            {
                uint32_t OFST; 
            }firwareImageDownload;

            struct getLogPage
            {
                uint32_t NUMDU          :16; 
                uint32_t LSI            :16; 
            }getLogPage;

            struct identify
            {
                uint32_t NVMSETID       :16;
                uint32_t reserved       :16;
            }identify;

            union 
            {
                uint32_t all;
                
                struct arbitration
                {
                    uint32_t AB         :3; 
                    uint32_t reserved   :5;
                    uint32_t LPW        :8; 
                    uint32_t MPW        :8; 
                    uint32_t HPW        :8; 
                }arbitration;

                struct powerManagment
                {
                    uint32_t PS         :5; 
                    uint32_t WH         :3; 
                    uint32_t reserved   :24;
                }powerManagment;

                struct lbaRangeType
                {
                    uint32_t NUM        :6;
                    uint32_t reserved   :26;
                }lbaRangeType;

                struct temperatureThreshold
                {
                    uint32_t TMPTH      :16; 
                    uint32_t TMPSEL     :4; 
                    uint32_t THSEL      :2; 
                    uint32_t reserved   :10;
                }temperatureThreshold;

                struct errorRecovery
                {
                    uint32_t TLER       :16; 
                    uint32_t DULBE      :1; 
                    uint32_t reserved   :15;
                }errorRecovery;

                struct volatileWriteCache
                {
                    uint32_t WCE        :1; 
                    uint32_t reserved   :31;
                }volatileWriteCache;

                struct numberOfQueues
                {
                    uint32_t NSQR       :16; 
                    uint32_t NCQR       :16; 
                }numberOfQueues;

                struct interruptCoalescing
                {
                    uint32_t THR        :8;
                    uint32_t TIME       :8;
                    uint32_t reserved   :16;
                }interruptCoalescing;

                struct interruptVectorConfiguration
                {
                    uint32_t IV         :16; 
                    uint32_t CD         :1; 
                    uint32_t reserved   :15;
                }interruptVectorConfiguration;

                struct writeAtomicityNormal
                {
                    uint32_t DN         :1; 
                    uint32_t reserved   :31;
                }writeAtomicityNormal;

                struct asyncEventConfiguration
                {  
                    uint32_t SMART      :8; 
                    uint32_t NAN        :1; 
                    uint32_t FAN        :1; 
                    uint32_t TLN        :1; 
                    uint32_t ANACN      :1; 
                    uint32_t PLEALCN    :1;
                    uint32_t LBASIN     :1; 
                    uint32_t EGEALCN    :1;
                    uint32_t reserved   :1; 
                    uint32_t reserved1  :12;
                    uint32_t fabrics    :4;
                }asyncEventConfiguration;

                struct autonomousPowerStateTransition
                {
                    uint32_t APSTE      :1;
                    uint32_t reserved   :31;
                }autonomousPowerStateTransition;

                struct hostMemoryBuffer
                {
                    uint32_t EHM        :1;
                    uint32_t MR         :1; 
                    uint32_t reserved      :30;
                }hostMemoryBuffer;

                struct keepAliveTimer
                {
                    uint32_t KATO; 
                }keepAliveTimer;

                struct hostControlleredThermalManagement
                {
                    uint32_t TMT2       :16;
                    uint32_t TMT1       :16;
                }hostControlleredThermalManagement;

                struct nonOperationalPowerStateConfig
                {
                    uint32_t NOPPME     :1;
                    uint32_t reserved      :31;
                }nonOperationalPowerStateConfig;

                struct readRecoveryLevelConfig
                {
                    uint32_t NVMESETID  :16;
                    uint32_t reserved      :16;
                }readRecoveryLevelConfig;

                struct predictableLatencyModeConfig
                {
                    uint32_t NVM_Set_Identifier :16;
                    uint32_t reserved      :16;
                }predictableLatencyModeConfig;

                struct predictableLatencyModeWindow
                {
                    uint32_t NVM_Set_Identifier:16;
                    uint32_t reserved      :16;
                }predictableLatencyModeWindow;

                struct lbaStatusInformationAttributes
                {
                    uint32_t LSIRI      :16;
                    uint32_t LSIPI      :16;
                }lbaStatusInformationAttributes;

                struct sanitizeConfig
                {
                    uint32_t NODRM      :1;
                    uint32_t reserved   :31;
                }sanitizeConfig;

                struct asyncConfiguration
                {
                    uint32_t ENDGID     :16;
                    uint32_t EGCW       :8; 
                    uint32_t reserved   :8;
                }asyncConfiguration;

                struct softwareProgessMarker
                {
                    uint32_t PBSLC      :8;
                    uint32_t reserved   :24;
                }softwareProgessMarker;

                struct hostIdentifier
                {
                    uint32_t EXHID      :1; 
                    uint32_t reserved      :31;
                }hostIdentifier;

                struct reservationNotificationMask
                {
                    uint32_t reserved   :1;
                    uint32_t REGPRE     :1; 
                    uint32_t RESREL     :1; 
                    uint32_t RESPRE     :1; 
                    uint32_t reserved1  :28;
                }reservationNotificationMask;

                struct reservationPersistanceConfiguration
                {
                    uint32_t PTPL       :1;
                    uint32_t reserved   :31;
                }reservationPersistanceConfiguration;

                struct namespaceWriteProtectionConfig
                {
                    uint32_t WPS        :3; 
                    uint32_t reserved   :29;
                }namespaceWriteProtectionConfig;

            }setFeatures;

            struct virtualizationManagement
            {
                uint32_t NR             :16;
                uint32_t reserved       :16;
            }virtualizationManagement;

            struct sanitize
            {
                uint32_t OVRPAT; 
            }sanitize;

            struct securityReceive
            {
                uint32_t AL; 
            }securityReceive;

            struct securitySend
            {
                uint32_t TL; 
            }securitySend;
         
            struct getLbaStatus
            {
                uint32_t SLBA; 
            }getLbaStatus;

            struct compare
            {
                uint32_t SLBA; 
            }compare;

            struct datasetManagement
            {
                uint32_t IDR            :1; 
                uint32_t IDW            :1; 
                uint32_t AD             :1; 
                uint32_t reserved       :29;
            }datasetManagement;

            struct read
            {
                uint32_t SLBA; 
            }read;

            struct reservationReport
            {
                uint32_t EDS            :1; 
                uint32_t reserved       :31;
            }reservationReport;

            struct verify
            {
                uint32_t SLBA; 
            }verify;

            struct write
            {
                uint32_t SLBA; 
            }write;

            struct writeUncorrectable
            {
                uint32_t SLBA; 
            }writeUncorrectable;

            struct writeZeroes
            {
                uint32_t SLBA; 
            }writeZeroes;
        }dw11;

        //dw12 bytes 48-51
        union 
        {
            uint32_t all;
            
            struct createSubmissionQueue
            {
                uint32_t NVMSETID       :16;
                uint32_t reserved       :16;
            }createSubmissionQueue;

            struct getLogPage
            {
                uint32_t LPOL; 
            }getLogPage;

            union 
            {
                struct hostMemoryBuffer
                {
                    uint32_t HSIZE; 
                }hostMemoryBuffer;

                struct readRecoveryLevelConfig
                {
                    uint32_t RRL        :4; 
                    uint32_t reserved   :28;
                }readRecoveryLevelConfig;

                struct predictableLatencyModeConfig
                {
                    uint32_t PLE        :1; 
                    uint32_t reserved   :31;
                }predictableLatencyModeConfig;

                struct predictableLatencyModeWindow
                {
                    uint32_t WS         :3; 
                    uint32_t reserved   :29;
                }predictableLatencyModeWindow;

            }setFeatures;

            struct getLbaStatus
            {
                uint32_t MNDW; 
            }getLbaStatus;

            struct compare
            {
                uint32_t NLB            :16; 
                uint32_t reserved       :8;
                uint32_t reserved1      :2;
                uint32_t PRINFO         :4; 
                uint32_t FUA            :1; 
                uint32_t LR             :1; 
            }compare;

            struct read
            {
                uint32_t NLB            :16; 
                uint32_t reserved       :8;
                uint32_t reserved1      :2;
                uint32_t PRINFO         :4; 
                uint32_t FUA            :1; 
                uint32_t LR             :1; 
            }read;

            struct verify
            {
                uint32_t NLB            :16; 
                uint32_t reserved       :8;
                uint32_t reserved1      :2;
                uint32_t PRINFO         :4; 
                uint32_t FUA            :1; 
                uint32_t LR             :1; 
            }verify;

            struct write
            {
                uint32_t NLB            :16; 
                uint32_t reserved       :4;
                uint32_t DTYPE          :4; 
                uint32_t reserved1      :2;
                uint32_t PRINFO         :4; 
                uint32_t FUA            :1; 
                uint32_t LR             :1; 
            }write;

            struct writeUncorrectable
            {
                uint32_t NLB            :16; 
                uint32_t reserved       :16;
            }writeUncorrectable;

            struct writeZeroes
            {
                uint32_t NLB            :16; 
                uint32_t reserved       :8;
                uint32_t reserved1      :1;
                uint32_t DEAC           :1; 
                uint32_t PRINFO         :4; 
                uint32_t FUA            :1; 
                uint32_t LR             :1; 
            }writeZeroes;
        }dw12;

        //dw13 bytes 52-55
        union 
        {
            uint32_t all;
            
            struct getLogPage
            {
                uint32_t LPOU; 
            }getLogPage;

            union 
            {
                struct hostMemoryBuffer
                {
                    uint32_t HMDLLA; 
                }hostMemoryBuffer;
            }setFeatures;

            struct getLbaStatus
            {
                uint32_t RL             :16; 
                uint32_t reserved       :8;
                uint32_t ATYPE          :8; 
            }getLbaStatus;

            struct read
            {
                struct
                {
                    uint8_t AF          :4; 
                    uint8_t AL          :2; 
                    uint8_t SR          :1; 
                    uint8_t IC          :1; 
                }DSM;
                
                uint32_t reserved       :24;
            }read;

            struct write
            {
                struct
                {
                    uint8_t AF          :4; 
                    uint8_t AL          :2; 
                    uint8_t SR          :1; 
                    uint8_t IC          :1; 
                }DSM;
                
                uint32_t reserved       :8;
                uint32_t DSPEC          :16; 
                
            }write;
        }dw13;

        //dw14 bytes 56-59
        union 
        {
            uint32_t all;

            struct getFeatures
            {
                uint32_t UUID_Index     :7;
                uint32_t reserved       :25;
            }getFeatures;

            struct getLogPage
            {
                uint32_t UUID_Index     :7;
                uint32_t reserved       :25;
            }getLogPage;

            struct identify
            {
                uint32_t UUID_Index     :7;
                uint32_t reserved       :25;
            }identify;

            union 
            {
                struct
                {
                    uint32_t UUID_Index :7;
                    uint32_t reserved   :25;
                };

                struct hostMemoryBuffer
                {
                    uint32_t HMDLUA; 
                }hostMemoryBuffer;
            }setFeatures;

            struct compare
            {
                uint32_t EILBRT;
            }compare;

            struct read
            {
                uint32_t EILBRT;
            }read;

            struct verify
            {
                uint32_t EILBRT;
            }verify;

            struct write
            {
                uint32_t ILBRT; 
            }write;

            struct writeZeroes
            {
                uint32_t ILBRT; 
            }writeZeroes;
        }dw14;

        //dw15 bytes 60-63
        union 
        {
            uint32_t all;

            union 
            {
                struct hostMemoryBuffer
                {
                    uint32_t HMDLEC;
                }hostMemoryBuffer;
            }setFeatures;

            struct compare
            {
                uint32_t ELBAT          :16; 
                uint32_t ELBATM         :16;
            }compare;

            struct read
            {
                uint32_t ELBAT          :16; 
                uint32_t ELBATM         :16;
            }read;

            struct verify
            {
                uint32_t ELBAT          :16; 
                uint32_t ELBATM         :16;
            }verify;

            struct write
            {
                uint32_t LBAT           :16; 
                uint32_t LBATM          :16;
            }write;

            struct writeZeroes
            {
                uint32_t LBAT           :16; 
                uint32_t LBATM          :16; 
            }writeZeroes;
        
        }dw15;
    };    
   
}nvmeCommand_t;
static_assert(sizeof(nvmeCommand_t) == NVME_COMMAND_SIZE, "NVMe command is not 16 dwords (64 Byte)");

//-------------------------------------------------
// NVME 1.4 - NVMe Completion 
//-------------------------------------------------

typedef union __attribute__((packed, aligned (4))) nvmeCompletion_t 
{    
    uint32_t all[4];
    
    struct
    {
        union  
        {     
            
            struct
            {
                uint32_t NUM       :6;
                uint32_t RESERVED  :26;
            }lbaRangeType; 

            struct
            {
                uint32_t NSQA       :16;
                uint32_t NCQA       :16;
            }numOfQueues;   

            uint32_t commandSpecific;            
        }dw0;    

        union
        {
            uint32_t reserved;
        }dw1;

        union
        {
            struct
            {
                uint32_t SQHD       :16;    //sq head pointer
                uint32_t SQID       :16;    //sq identifier
            };
            
            uint32_t all;
        }dw2;

        union 
        {
            struct 
            {         
                uint32_t CID        :16;    //command identifier
                uint32_t P          :1;     //phase tag
                uint32_t SC         :8;     //status code  
                uint32_t SCT        :3;     //status code type
                uint32_t reserved   :2;     //reserved
                uint32_t M          :1;     //more
                uint32_t DNR        :1;     //do not retry
            };
            
            uint32_t all;
        }dw3;
    };
    
}nvmeCompletion_t;
static_assert(sizeof(nvmeCompletion_t) == NVME_COMPLETION_SIZE, "nvmeCompletion_t 4x dword (16 Byte)");