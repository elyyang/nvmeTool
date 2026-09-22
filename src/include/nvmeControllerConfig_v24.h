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

#ifndef __cplusplus
    #if !defined(static_assert)
        #define static_assert _Static_assert
    #endif
#endif // __cplusplus

/**************************************************************
NVM-Express-Base-Specification-Revision-2.4-Ratified-2026.07.31
3.1.4 Controller Properties
**************************************************************/

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

typedef union __attribute__((packed, aligned (4))) cap_t
{
    volatile struct
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

    volatile uint64_t all;
}cap_t;
static_assert(sizeof(cap_t) == CONTROLLER_REG_SIZE_CAP, "cap_t size incorrect");

typedef union __attribute__((packed, aligned (4))) vs_t
{
    volatile struct 
    {    
        uint32_t    TER     :16;
        uint32_t    MNR     :8;
        uint32_t    MJR     :8;
    };

    volatile uint32_t all;
}vs_t;
static_assert(sizeof(vs_t) == CONTROLLER_REG_SIZE_VS, "vs_t size incorrect");

typedef struct __attribute__((packed, aligned (4))) intms_t
{
    volatile uint32_t    IVMS;
}intms_t;
static_assert(sizeof(intms_t) == CONTROLLER_REG_SIZE_INTMS, "intms_t size incorrect");

typedef struct __attribute__((packed, aligned (4))) intmc_t
{
    volatile uint32_t    IVMC;
}intmc_t;
static_assert(sizeof(intmc_t) == CONTROLLER_REG_SIZE_INTMC, "intmc_t size incorrect");

typedef union __attribute__((packed, aligned (4))) cc_t
{
    volatile struct
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

    volatile uint32_t all;
}cc_t;
static_assert(sizeof(cc_t) == CONTROLLER_REG_SIZE_CC, "cc_t size incorrect");

typedef union __attribute__((packed, aligned (4))) csts_t
{
    volatile struct
    {
        uint32_t     RDY     :1;
        uint32_t     CFS     :1;
        uint32_t     SHST    :2;
        uint32_t     NSSRO   :1;
        uint32_t     PP      :1;
        uint32_t     SHN     :25;
    };

    volatile uint32_t all;
}csts_t;
static_assert(sizeof(csts_t) == CONTROLLER_REG_SIZE_CSTS, "csts_t size incorrect");

typedef struct __attribute__((packed, aligned (4))) nssr_t
{
    volatile uint32_t NSSRC;
}nssr_t;
static_assert(sizeof(nssr_t) == CONTROLLER_REG_SIZE_NSSR, "nssr_t size incorrect");

typedef union __attribute__((packed, aligned (4))) aqa_t
{
    volatile struct
    {
        uint32_t    ASQS    :12;
        uint32_t    rsvd0   :4;
        uint32_t    ACQS    :12;
        uint32_t    rsvd1   :4;
    };

    volatile uint32_t all;
}aqa_t;
static_assert(sizeof(aqa_t )== CONTROLLER_REG_SIZE_AQA, "aqa_t size incorrect");

typedef union __attribute__((packed, aligned (4))) asq_t
{
    volatile struct 
    {    
        uint32_t    rsvd0   :12;
        uint64_t    ASQB    :52;
    };

    volatile uint64_t    all;    
}asq_t;
static_assert(sizeof(asq_t) == CONTROLLER_REG_SIZE_ASQ, "asq_t size incorrect");

typedef union __attribute__((packed, aligned (4))) acq_t
{
    volatile struct
    {
        uint32_t    rsvd0   :12;
        uint64_t    ACQB    :52;
    };

    volatile uint64_t all;
}acq_t;
static_assert(sizeof(acq_t) == CONTROLLER_REG_SIZE_ACQ, "acq_t size incorrect");

typedef union __attribute__((packed, aligned (4))) cmbloc_t
{
    volatile struct
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

    volatile uint32_t all;    
}cmbloc_t;
static_assert(sizeof(cmbloc_t) == CONTROLLER_REG_SIZE_CMBLOC, "cmbloc_t size incorrect");

typedef union __attribute__((packed, aligned (4))) cmbsz_t
{    
    volatile struct    
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

    volatile uint32_t all;
}cmbsz_t;
static_assert(sizeof(cmbsz_t) == CONTROLLER_REG_SIZE_CMBSZ, "cmbsz_t size incorrect");

typedef union __attribute__((packed, aligned (4))) bpinfo_t
{
    volatile struct
    {
        uint32_t    BPSZ    :15;
        uint32_t    rsvd0   :5;
        uint32_t    BRS     :2;
        uint32_t    rsvd1   :9;
        uint32_t    ABPID   :1;
    };

    volatile uint32_t all;
}bpinfo_t;
static_assert(sizeof(bpinfo_t) == CONTROLLER_REG_SIZE_BPINFO, "bpinfo_t size incorrect");

typedef union __attribute__((packed, aligned (4))) bprsel_t
{
    volatile struct
    {
        uint32_t    BPRSZ   :10;
        uint32_t    BPROF   :20;
        uint32_t    rsvd0   :1;
        uint32_t    BPID    :1;
    };

    volatile uint32_t all;
}bprsel_t;
static_assert(sizeof(bprsel_t) == CONTROLLER_REG_SIZE_BPRSEL, "bprsel_t size incorrect");

typedef union __attribute__((packed, aligned (4))) bpmbl_t
{
    volatile struct
    {
        uint32_t    rsvd0   :12;
        uint64_t    BMBBA   :52;
    };

    volatile uint64_t all;
}bpmbl_t;
static_assert(sizeof(bpmbl_t) == CONTROLLER_REG_SIZE_BPMBL, "bpmbl_t size incorrect");

typedef union __attribute__((packed, aligned (4))) cmbmsc_t
{
    volatile struct
    {
        uint32_t    CRE     :1;
        uint32_t    CMSE    :1;
        uint32_t    rsvd0   :10;
        uint64_t    CBA     :52;
    };

    volatile uint64_t all;
}cmbmsc_t;
static_assert(sizeof(cmbmsc_t) == CONTROLLER_REG_SIZE_CMBMSC, "cmbmsc_t size incorrect");

typedef union __attribute__((packed, aligned (4))) cmbsts_t
{
    volatile struct
    {
        uint32_t    CBAI    :1;
        uint32_t    rsvd0   :31;
    };

    volatile uint32_t all;
}cmbsts_t;
static_assert(sizeof(cmbsts_t) == CONTROLLER_REG_SIZE_CMBSTS, "cmbsts_t size incorrect");

typedef union __attribute__((packed, aligned (4))) pmrcap_t
{
    volatile struct
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

    volatile uint32_t all;
}pmrcap_t;
static_assert(sizeof(pmrcap_t) == CONTROLLER_REG_SIZE_PMRCAP, "pmrcap_t size incorrect");

typedef union __attribute__((packed, aligned (4))) pmrctl_t
{
    volatile struct
    {
        uint32_t    EN      :1;
        uint32_t    rsvd0   :31;
    };

    volatile uint32_t all;
}pmrctl_t;
static_assert(sizeof(pmrctl_t) == CONTROLLER_REG_SIZE_PMRCTL, "pmrctl_t size incorrect");

typedef union __attribute__((packed, aligned (4))) pmrsts_t
{
    volatile struct
    {
        uint32_t    ERR     :8;
        uint32_t    NRDY    :1;
        uint32_t    HSTS    :3;
        uint32_t    CBAI    :1;
        uint32_t    rsvd0   :19;
    };

    volatile uint32_t all;
}pmrsts_t;
static_assert(sizeof(pmrsts_t) == CONTROLLER_REG_SIZE_PMRSTS, "pmrsts_t size incorrect");

typedef union __attribute__((packed, aligned (4)))  pmrebs_t
{
    volatile struct
    {
        uint32_t    PMRSZU  :4; 
        uint32_t    RBB     :1;
        uint32_t    rsvd0   :3;
        uint32_t    PMRWBZ  :24;
    };

    volatile uint32_t all;
}pmrebs_t;
static_assert(sizeof(pmrebs_t) == CONTROLLER_REG_SIZE_PMREBS, "pmrebs_t size incorrect");

typedef union __attribute__((packed, aligned (4)))  pmrswtp_t
{
    volatile struct
    {
        uint32_t    PMRSWTU :4;
        uint32_t    rsvd0   :4;
        uint32_t    PMRSWTV :24;
    };

    volatile uint32_t all;
}pmrswtp_t;
static_assert(sizeof(pmrswtp_t) == CONTROLLER_REG_SIZE_PMRSWTP, "pmrswtp_t size incorrect");

typedef union __attribute__((packed, aligned (4)))  pmrmscl_t 
{
    volatile struct
    {
        uint32_t    rsvd0   :1;
        uint32_t    CMSE    :1;
        uint32_t    rsvd1   :10;
        uint32_t    CBA     :20;
    };

    volatile uint32_t all;
}pmrmscl_t;
static_assert(sizeof(pmrmscl_t) == CONTROLLER_REG_SIZE_PMRMSCL, "pmrmscl_t size incorrect");

typedef union __attribute__((packed, aligned (4)))  pmrmscu_t 
{
    volatile uint32_t CBA;
    volatile uint32_t all;
}pmrmscu_t;
static_assert(sizeof(pmrmscu_t) == CONTROLLER_REG_SIZE_PMRMSCU, "pmrmscu_t size incorrect");


/*************************************************************************************************
NVM-Express-NVMe-over-PCIe-Transport-Specification-Revision-1.4-Ratified-2026.07.31
3.1.2.1 Offset (1000h + ((2y) * (4 << CAP.DSTRD))): SQyTDBL – Submission Queue y Tail Doorbell
*************************************************************************************************/

typedef union __attribute__((packed, aligned (4))) sqtdbl_t
{
    volatile struct
    {
        uint32_t    SQT     :16;
        uint32_t    rsvd0   :16;
    };

    volatile uint32_t all;
}
sqtdbl_t;
static_assert(sizeof(sqtdbl_t) == CONTROLLER_REG_SQT_ENTRY_SIZE, "sqtdbl_t size incorrect");

/*************************************************************************************************
NVM-Express-NVMe-over-PCIe-Transport-Specification-Revision-1.4-Ratified-2026.07.31
3.1.2.2 Offset (1000h + ((2y + 1) * (4 << CAP.DSTRD))): CQyHDBL – Completion Queue y Head Doorbell
*************************************************************************************************/

typedef union __attribute__((packed, aligned (4))) cqhdbl_t
{
    volatile struct
    {
        uint32_t    CQH     :16;
        uint32_t    rsvd0   :16;
    };
 
    volatile uint32_t all;
}
cqhdbl_t;
static_assert(sizeof(cqhdbl_t) == CONTROLLER_REG_CQH_ENTRY_SIZE, "cqhdbl_t size incorrect");
