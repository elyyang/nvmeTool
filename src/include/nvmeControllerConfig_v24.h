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

#ifndef __cplusplus
    #if !defined(static_assert)
        #define static_assert _Static_assert
    #endif
#endif // __cplusplus

#define NVM_CONTROLLER_MMIO_REG_SIZE                        (0x4000)

#define CONTROLLER_REG_STARTING_OFFSET                      (0x0)
#define CONTROLLER_REG_OFFSET_CAP                           (CONTROLLER_REG_STARTING_OFFSET)
#define CONTROLLER_REG_OFFSET_VS                            (0x8)
#define CONTROLLER_REG_OFFSET_INTMS  	                    (0xC)
#define CONTROLLER_REG_OFFSET_INTMC  	                    (0x10)
#define CONTROLLER_REG_OFFSET_CC		                    (0x14)
#define CONTROLLER_REG_OFFSET_CSTS		                    (0x1C)
#define CONTROLLER_REG_OFFSET_NSSR                          (0x20)
#define CONTROLLER_REG_OFFSET_AQA		                    (0x24) 							
#define CONTROLLER_REG_OFFSET_ASQ                           (0x28) 	
#define CONTROLLER_REG_OFFSET_ACQ                           (0x30)
#define CONTROLLER_REG_OFFSET_CMBLOC                        (0x38)
#define CONTROLLER_REG_OFFSET_CMBSZ                         (0x3C)
#define CONTROLLER_REG_OFFSET_BPINFO                        (0x40)
#define CONTROLLER_REG_OFFSET_BPRSEL                        (0x44)
#define CONTROLLER_REG_OFFSET_BPMBL                         (0x48)
#define CONTROLLER_REG_OFFSET_CMBMSC                        (0x50)
#define CONTROLLER_REG_OFFSET_CMBSTS                        (0x58)
#define CONTROLLER_REG_OFFSET_CMBEBS                        (0x5C)
#define CONTROLLER_REG_OFFSET_CMBSWTP                       (0x60)
#define CONTROLLER_REG_OFFSET_NSSD                          (0x64)
#define CONTROLLER_REG_OFFSET_CRTO                          (0x68)
#define CONTROLLER_REG_OFFSET_PMRCAP                        (0xE00)
#define CONTROLLER_REG_OFFSET_PMRCTL                        (0xE04)
#define CONTROLLER_REG_OFFSET_PMRSTS                        (0xE08)
#define CONTROLLER_REG_OFFSET_PMREBS                        (0xE0C)
#define CONTROLLER_REG_OFFSET_PMRSWTP                       (0xE10)
#define CONTROLLER_REG_OFFSET_PMRMSCL                       (0xE14)
#define CONTROLLER_REG_OFFSET_PMRMSCU                       (0xE18)

#define CONTROLLER_REG_TRANSPORT_SPECIFIC_STARTING_OFFSET   (0x1000)
#define CONTROLLER_REG_SQT_CQH_STARTING_OFFSET              (CONTROLLER_REG_TRANSPORT_SPECIFIC_STARTING_OFFSET)
#define CONTROLLER_REG_VENDOR_SPECIFIC_STARTING_OFFSET      (0x1300)
#define CONTROLLER_REG_SQTAIL_CQHEAD_ENDING_OFFSET          (0x2000)
#define CONTROLLER_REG_ENDING_OFFSET                        (0x4000)

#define CONTROLLER_REG_SIZE_CAP                             (0x8)
#define CONTROLLER_REG_SIZE_VS                              (0x4)
#define CONTROLLER_REG_SIZE_INTMS                           (0x4)
#define CONTROLLER_REG_SIZE_INTMC                           (0x4)
#define CONTROLLER_REG_SIZE_CC                              (0x4)
#define CONTROLLER_REG_SIZE_CSTS                            (0x4)
#define CONTROLLER_REG_SIZE_NSSR                            (0x4)
#define CONTROLLER_REG_SIZE_AQA                             (0x4)
#define CONTROLLER_REG_SIZE_ASQ                             (0x8)
#define CONTROLLER_REG_SIZE_ACQ                             (0x8)
#define CONTROLLER_REG_SIZE_CMBLOC                          (0x4)
#define CONTROLLER_REG_SIZE_CMBSZ                           (0x4)
#define CONTROLLER_REG_SIZE_BPINFO                          (0x4)
#define CONTROLLER_REG_SIZE_BPRSEL                          (0x4)
#define CONTROLLER_REG_SIZE_BPMBL                           (0x8)
#define CONTROLLER_REG_SIZE_CMBMSC                          (0x8)
#define CONTROLLER_REG_SIZE_CMBSTS                          (0x4)
#define CONTROLLER_REG_SIZE_CMBEBS                          (0x4)
#define CONTROLLER_REG_SIZE_CMBSWTP                         (0x4)
#define CONTROLLER_REG_SIZE_NSSD                            (0x4)
#define CONTROLLER_REG_SIZE_CRTO                            (0x4)
#define CONTROLLER_REG_SIZE_PMRCAP                          (0x4)
#define CONTROLLER_REG_SIZE_PMRCTL                          (0x4)
#define CONTROLLER_REG_SIZE_PMRSTS                          (0x4)
#define CONTROLLER_REG_SIZE_PMREBS                          (0x4)
#define CONTROLLER_REG_SIZE_PMRSWTP                         (0x4)
#define CONTROLLER_REG_SIZE_PMRMSCL                         (0x4)
#define CONTROLLER_REG_SIZE_PMRMSCU                         (0x4)

#define CONTROLLER_REG_SQT_ENTRY_SIZE                       (0x4)
#define CONTROLLER_REG_CQH_ENTRY_SIZE                       (0x4)


/**************************************************************
NVM-Express-Base-Specification-Revision-2.4-Ratified-2026.07.31
3.1.4 Controller Properties
**************************************************************/

typedef union __attribute__((packed, aligned (8))) cap_t
{
    struct
    {
        uint64_t    maximumQueueEntriesSupported                :16;
        uint64_t    contiguousQueuesRequired                    :1;
        uint64_t    arbitrationMechanismSupported               :2;
        uint64_t    _reserved0                                  :5;
        uint64_t    timeout                                     :8;
        uint64_t    doorbellStride                              :4;
        uint64_t    nvmSubsystemResetSupported                  :1;
        uint64_t    commandSetsSupported                        :8;
        uint64_t    bootPartitionSupport                        :1;
        uint64_t    controllerPowerScope                        :2;
        uint64_t    memoryPageSizeMinimum                       :4;
        uint64_t    memoryPageSizeMaximum                       :4;
        uint64_t    persistentMemoryRegionSupported             :1;
        uint64_t    controllerMemoryBufferSupported             :1;
        uint64_t    nvmSubsystemShutdownSupported               :1;
        uint64_t    controllerReadyModesSupported               :2;
        uint64_t    nvmSubsystemShutdownEnhancementsSupported   :1;
        uint64_t    _reserved1                                  :2;        
    };

    uint64_t all;
}cap_t;
static_assert(sizeof(cap_t) == CONTROLLER_REG_SIZE_CAP, "cap_t size incorrect");

typedef union __attribute__((packed, aligned (4))) vs_t
{
    struct 
    {    
        uint32_t    tertiaryVersion :16;
        uint32_t    minorVersion    :8;
        uint32_t    majorVersion    :8;
    };

    uint32_t all;
}vs_t;
static_assert(sizeof(vs_t) == CONTROLLER_REG_SIZE_VS, "vs_t size incorrect");

typedef struct __attribute__((packed, aligned (4))) intms_t
{
    uint32_t    interruptVectorMaskSet;
}intms_t;
static_assert(sizeof(intms_t) == CONTROLLER_REG_SIZE_INTMS, "intms_t size incorrect");

typedef struct __attribute__((packed, aligned (4))) intmc_t
{
    uint32_t    interruptVectorMaskClear;
}intmc_t;
static_assert(sizeof(intmc_t) == CONTROLLER_REG_SIZE_INTMC, "intmc_t size incorrect");

typedef union __attribute__((packed, aligned (4))) cc_t
{
    struct
    {
        uint32_t    enable                                  :1;
        uint32_t    _reserved0                              :3;
        uint32_t    ioCommandSetSelected                    :3;
        uint32_t    memoryPageSize                          :4;
        uint32_t    arbitrationMechanismSelected            :3;
        uint32_t    shutdownNotification                    :2;
        uint32_t    ioSubmissionQueueEntrySize              :4;
        uint32_t    ioCompletionQueueEntrySize              :4;
        uint32_t    controllerReadyIndependentofMediaEnable :1;
        uint32_t    _reserved1                              :7;
    };

    uint32_t all;
}cc_t;
static_assert(sizeof(cc_t) == CONTROLLER_REG_SIZE_CC, "cc_t size incorrect");

typedef union __attribute__((packed, aligned (4))) csts_t
{
    volatile struct
    {
        uint32_t     ready                      :1;
        uint32_t     controllerFatalStatus      :1;
        uint32_t     shutdownStatus             :2;
        uint32_t     nvmSubsystemResetOccurred  :1;
        uint32_t     processingPaused           :1;
        uint32_t     shutdownType               :1;
        uint32_t     _reserved0                 :25;
    };

    volatile uint32_t all;
}csts_t;
static_assert(sizeof(csts_t) == CONTROLLER_REG_SIZE_CSTS, "csts_t size incorrect");

typedef struct __attribute__((packed, aligned (4))) nssr_t
{
    uint32_t nvmSubsystemResetControl;
}nssr_t;
static_assert(sizeof(nssr_t) == CONTROLLER_REG_SIZE_NSSR, "nssr_t size incorrect");

typedef union __attribute__((packed, aligned (4))) aqa_t
{
    struct
    {
        uint32_t    adminSubmissionQueueSize    :12;
        uint32_t    rsvd0                       :4;
        uint32_t    adminCompletionQueueSize    :12;
        uint32_t    rsvd1                       :4;
    };

    uint32_t all;
}aqa_t;
static_assert(sizeof(aqa_t )== CONTROLLER_REG_SIZE_AQA, "aqa_t size incorrect");

typedef union __attribute__((packed, aligned (8))) asq_t
{
    struct 
    {    
        uint64_t    _reserved0                  :12;
        uint64_t    adminSubmissionQueueBase    :52;
    };

    uint64_t    all;    
}asq_t;
static_assert(sizeof(asq_t) == CONTROLLER_REG_SIZE_ASQ, "asq_t size incorrect");

typedef union __attribute__((packed, aligned (8))) acq_t
{
    struct
    {
        uint32_t    _reserved0                  :12;
        uint64_t    adminCompletionQueueBase    :52;
    };

    uint64_t all;
}acq_t;
static_assert(sizeof(acq_t) == CONTROLLER_REG_SIZE_ACQ, "acq_t size incorrect");

typedef union __attribute__((packed, aligned (4))) cmbloc_t
{
    struct
    {
        uint32_t    baseIndicatorRegister                               :3;
        uint32_t    cmbQueueMixedMemorySupport                          :1;
        uint32_t    cmbQueuePhysicallyDiscontiguousSupport              :1;
        uint32_t    cmbDataPointerMixedLocationsSupport                 :1;
        uint32_t    cmbDataPointerandCommandIndependentLocationsSupport :1;
        uint32_t    cmbDataMetadataMixedMemorySupport                   :1;
        uint32_t    cmbQueueDwordAlignment                              :1;
        uint32_t    _reserved0                                          :3;
        uint32_t    offset                                              :20;
    };

    uint32_t all;    
}cmbloc_t;
static_assert(sizeof(cmbloc_t) == CONTROLLER_REG_SIZE_CMBLOC, "cmbloc_t size incorrect");

typedef union __attribute__((packed, aligned (4))) cmbsz_t
{    
    struct    
    {
        uint32_t    submissionQueueSupport   :1;
        uint32_t    completionQueueSupport   :1;
        uint32_t    prpSglListSupport        :1;
        uint32_t    readDataSupport          :1;
        uint32_t    writeDataSupport         :1;
        uint32_t    _reserved0               :3;
        uint32_t    sizeUnits                :4;
        uint32_t    size                     :20;
    };

    uint32_t all;
}cmbsz_t;
static_assert(sizeof(cmbsz_t) == CONTROLLER_REG_SIZE_CMBSZ, "cmbsz_t size incorrect");

typedef union __attribute__((packed, aligned (4))) bpinfo_t
{
    struct
    {
        uint32_t    bootPartitionSize       :15;
        uint32_t    _reserved0              :9;
        uint32_t    bootReadStatus          :2;
        uint32_t    _reserved1              :5;
        uint32_t    activeBootPartitionId   :1;
    };

    uint32_t all;
}bpinfo_t;
static_assert(sizeof(bpinfo_t) == CONTROLLER_REG_SIZE_BPINFO, "bpinfo_t size incorrect");

typedef union __attribute__((packed, aligned (4))) bprsel_t
{
    struct
    {
        uint32_t    bootPartitionReadSize      :10;
        uint32_t    bootPartitionReadOffset    :20;
        uint32_t    _reserved0                 :1;
        uint32_t    bootPartitionIdentifier    :1;
    };

    uint32_t all;
}bprsel_t;
static_assert(sizeof(bprsel_t) == CONTROLLER_REG_SIZE_BPRSEL, "bprsel_t size incorrect");

typedef union __attribute__((packed, aligned (8))) bpmbl_t
{
    struct
    {
        uint32_t    _reserved0                              :12;
        uint64_t    bootPartitionMemoryBufferBaseAddress    :52;
    };

    uint64_t all;
}bpmbl_t;
static_assert(sizeof(bpmbl_t) == CONTROLLER_REG_SIZE_BPMBL, "bpmbl_t size incorrect");

typedef union __attribute__((packed, aligned (8))) cmbmsc_t
{
    struct
    {
        uint32_t    capabilitiesRegistersEnabled    :1;
        uint32_t    controllerMemorySpaceEnable     :1;
        uint32_t    _reserved0                      :10;
        uint64_t    controllerBaseAddress           :52;
    };

    uint64_t all;
}cmbmsc_t;
static_assert(sizeof(cmbmsc_t) == CONTROLLER_REG_SIZE_CMBMSC, "cmbmsc_t size incorrect");

typedef union __attribute__((packed, aligned (4))) cmbsts_t
{
    struct
    {
        uint32_t    controllerBaseAddressInvalid    :1;
        uint32_t    _reserved0                      :31;
    };

    uint32_t all;
}cmbsts_t;
static_assert(sizeof(cmbsts_t) == CONTROLLER_REG_SIZE_CMBSTS, "cmbsts_t size incorrect");

typedef union __attribute__((packed, aligned (4))) cmbebs_t
{
    struct
    {
        uint32_t    cmbElasticityBufferSizeUnits    :4;
        uint32_t    cmbReadBypassBehavior           :1;
        uint32_t    _reserved0                      :3;
        uint32_t    cmbElasticityBufferSizeBase     :24;
    };

    uint32_t all;
}cmbebs_t;
static_assert(sizeof(cmbebs_t) == CONTROLLER_REG_SIZE_CMBEBS, "cmbebs_t size incorrect");

typedef union __attribute__((packed, aligned (4))) cmbswtp_t
{
    struct
    {
        uint32_t    cmbSustainedWriteThroughputUnits :4;
        uint32_t    _reserved0                       :4;
        uint32_t    cmbSustainedWriteThroughput      :24;
    };

    uint32_t all;
}cmbswtp_t;
static_assert(sizeof(cmbswtp_t) == CONTROLLER_REG_SIZE_CMBSWTP, "cmbswtp_t size incorrect");

typedef struct __attribute__((packed, aligned (4))) nssd_t
{
    uint32_t    nvmSubsystemShutdownControl;
}nssd_t;
static_assert(sizeof(nssd_t) == CONTROLLER_REG_SIZE_NSSD, "nssd_t size incorrect");

typedef union __attribute__((packed, aligned (4))) crto_t
{
    struct
    {
        uint32_t    controllerReadyWithMediaTimeout          :16;
        uint32_t    controllerReadyIndependentOfMediaTimeout :16;
    };

    uint32_t all;
}crto_t;
static_assert(sizeof(crto_t) == CONTROLLER_REG_SIZE_CRTO, "crto_t size incorrect");

typedef union __attribute__((packed, aligned (4))) pmrcap_t
{
    struct
    {
        uint32_t    _reserved0                                     :3;
        uint32_t    readDataSupport                                :1;
        uint32_t    writeDataSupport                               :1;
        uint32_t    baseIndicatorRegister                          :3;
        uint32_t    persistentMemoryRegionTimeUnits                :2;
        uint32_t    persistentMemoryRegionWriteBarrierMechanisms   :4;
        uint32_t    _reserved1                                     :2;
        uint32_t    persistentMemoryRegionTimeout                  :8;
        uint32_t    controllerMemorySpaceSupported                 :1;
        uint32_t    _reserved2                                     :7;
    };

    uint32_t all;
}pmrcap_t;
static_assert(sizeof(pmrcap_t) == CONTROLLER_REG_SIZE_PMRCAP, "pmrcap_t size incorrect");

typedef union __attribute__((packed, aligned (4))) pmrctl_t
{
    struct
    {
        uint32_t    enable      :1;
        uint32_t    _reserved0  :31;
    };

    uint32_t all;
}pmrctl_t;
static_assert(sizeof(pmrctl_t) == CONTROLLER_REG_SIZE_PMRCTL, "pmrctl_t size incorrect");

typedef union __attribute__((packed, aligned (4))) pmrsts_t
{
    struct
    {
        uint32_t    error                         :8;
        uint32_t    notReady                     :1;
        uint32_t    healthStatus                 :3;
        uint32_t    controllerBaseAddressInvalid :1;
        uint32_t    _reserved0                   :19;
    };

    uint32_t all;
}pmrsts_t;
static_assert(sizeof(pmrsts_t) == CONTROLLER_REG_SIZE_PMRSTS, "pmrsts_t size incorrect");

typedef union __attribute__((packed, aligned (4)))  pmrebs_t
{
    struct
    {
        uint32_t    pmrElasticityBufferSizeUnits :4;
        uint32_t    pmrReadBypassBehavior        :1;
        uint32_t    _reserved0                   :3;
        uint32_t    pmrElasticityBufferSizeBase  :24;
    };

    uint32_t all;
}pmrebs_t;
static_assert(sizeof(pmrebs_t) == CONTROLLER_REG_SIZE_PMREBS, "pmrebs_t size incorrect");

typedef union __attribute__((packed, aligned (4)))  pmrswtp_t
{
    struct
    {
        uint32_t    pmrSustainedWriteThroughputUnits :4;
        uint32_t    _reserved0                      :4;
        uint32_t    pmrSustainedWriteThroughput      :24;
    };

    uint32_t all;
}pmrswtp_t;
static_assert(sizeof(pmrswtp_t) == CONTROLLER_REG_SIZE_PMRSWTP, "pmrswtp_t size incorrect");

typedef union __attribute__((packed, aligned (4)))  pmrmscl_t 
{
    struct
    {
        uint32_t    _reserved0                  :1;
        uint32_t    controllerMemorySpaceEnable :1;
        uint32_t    _reserved1                  :10;
        uint32_t    controllerBaseAddress       :20;
    };

    uint32_t all;
}pmrmscl_t;
static_assert(sizeof(pmrmscl_t) == CONTROLLER_REG_SIZE_PMRMSCL, "pmrmscl_t size incorrect");

typedef struct __attribute__((packed, aligned (4)))  pmrmscu_t 
{
    uint32_t controllerBaseAddress;    
}pmrmscu_t;
static_assert(sizeof(pmrmscu_t) == CONTROLLER_REG_SIZE_PMRMSCU, "pmrmscu_t size incorrect");


/*************************************************************************************************
NVM-Express-NVMe-over-PCIe-Transport-Specification-Revision-1.4-Ratified-2026.07.31
3.1.2.1 Offset (1000h + ((2y) * (4 << CAP.DSTRD))): SQyTDBL – Submission Queue y Tail Doorbell
*************************************************************************************************/

typedef union __attribute__((packed, aligned (4))) sqtdbl_t
{
    struct
    {
        uint32_t    submissionQueueTail :16;
        uint32_t    _reserved0          :16;
    };

    uint32_t all;
}sqtdbl_t;
static_assert(sizeof(sqtdbl_t) == CONTROLLER_REG_SQT_ENTRY_SIZE, "sqtdbl_t size incorrect");

/*************************************************************************************************
NVM-Express-NVMe-over-PCIe-Transport-Specification-Revision-1.4-Ratified-2026.07.31
3.1.2.2 Offset (1000h + ((2y + 1) * (4 << CAP.DSTRD))): CQyHDBL – Completion Queue y Head Doorbell
*************************************************************************************************/

typedef union __attribute__((packed, aligned (4))) cqhdbl_t
{
    struct
    {
        uint32_t    completionQueueHead :16;
        uint32_t    _reserved0          :16;
    };
 
    uint32_t all;
}cqhdbl_t;
static_assert(sizeof(cqhdbl_t) == CONTROLLER_REG_CQH_ENTRY_SIZE, "cqhdbl_t size incorrect");
