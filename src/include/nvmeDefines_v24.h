/* *******************************************
*   _______  ___       ___  ___       
*  /"     "||"  |     |"  \/"  |      
* (: ______)||  |      \   \  /       
*  \/    |  |:  |       \\  \/        
*  // ___)_  \  |___    /   /         
* (:      "|( \_|:  \  /   /          
*  \_______) \_______)|___/           
*
* https://github.com/elyyang
******************************************* */

#pragma once

#define CONTROLLER_REG_STARTING_OFFSET      (0x0)

#define CONTROLLER_REG_OFFSET_CAP           (CONTROLLER_REG_STARTING_OFFSET)
#define CONTROLLER_REG_OFFSET_VS            (0x8)
#define CONTROLLER_REG_OFFSET_INTMS  	    (0xC)
#define CONTROLLER_REG_OFFSET_INTMC  	    (0x10)
#define CONTROLLER_REG_OFFSET_CC		    (0x14)
#define CONTROLLER_REG_OFFSET_CSTS		    (0x1C)
#define CONTROLLER_REG_OFFSET_NSSR          (0x20)
#define CONTROLLER_REG_OFFSET_AQA		    (0x24) 							
#define CONTROLLER_REG_OFFSET_ASQ           (0x28) 	
#define CONTROLLER_REG_OFFSET_ACQ           (0x30)
#define CONTROLLER_REG_OFFSET_CMBLOC        (0x38)
#define CONTROLLER_REG_OFFSET_CMBSZ         (0x3C)
#define CONTROLLER_REG_OFFSET_BPINFO        (0x40)
#define CONTROLLER_REG_OFFSET_BPRSEL        (0x44)
#define CONTROLLER_REG_OFFSET_BPMBL         (0x48)
#define CONTROLLER_REG_OFFSET_CMBMSC        (0x50)
#define CONTROLLER_REG_OFFSET_CMBSTS        (0x58)
#define CONTROLLER_REG_OFFSET_CMBEBS        (0x5C)
#define CONTROLLER_REG_OFFSET_CMBSWTP       (0x60)
#define CONTROLLER_REG_OFFSET_NSSD          (0x64)
#define CONTROLLER_REG_OFFSET_CRTO          (0x68)
#define CONTROLLER_REG_OFFSET_PMRCAP        (0xE00)
#define CONTROLLER_REG_OFFSET_PMRCTL        (0xE04)
#define CONTROLLER_REG_OFFSET_PMRSTS        (0xE08)
#define CONTROLLER_REG_OFFSET_PMREBS        (0xE0C)
#define CONTROLLER_REG_OFFSET_PMRSWTP       (0xE10)
#define CONTROLLER_REG_OFFSET_PMRMSCL       (0xE14)
#define CONTROLLER_REG_OFFSET_PMRMSCU       (0xE18)

#define TRANSPORT_SPECIFIC_STARTING_OFFSET  (0x1000)

#define SQTAIL_CQHEAD_STARTING_OFFSET       (TRANSPORT_SPECIFIC_STARTING_OFFSET)

#define VENDOR_SPECIFIC_STARTING_OFFSET     (0x1300)

#define SQTAIL_CQHEAD_ENDING_OFFSET         (0x2000)

#define CONTROLLER_REG_ENDING_OFFSET        (0x4000)

/**************************************************************
// controller register 0x0
***************************************************************
// sq cq offset        0x1000
**************************************************************/

#define CONTROLLER_REG_SIZE_CAP                 (0x8)
#define CONTROLLER_REG_SIZE_VS                  (0x4)
#define CONTROLLER_REG_SIZE_INTMS               (0x4)
#define CONTROLLER_REG_SIZE_INTMC               (0x4)
#define CONTROLLER_REG_SIZE_CC                  (0x4)
#define CONTROLLER_REG_SIZE_CSTS                (0x4)
#define CONTROLLER_REG_SIZE_NSSR                (0x4)
#define CONTROLLER_REG_SIZE_AQA                 (0x4) 							
#define CONTROLLER_REG_SIZE_ASQ                 (0x8) 	
#define CONTROLLER_REG_SIZE_ACQ                 (0x8)
#define CONTROLLER_REG_SIZE_CMBLOC              (0x4)         
#define CONTROLLER_REG_SIZE_CMBSZ               (0x4)        
#define CONTROLLER_REG_SIZE_BPINFO              (0x4)         
#define CONTROLLER_REG_SIZE_BPRSEL              (0x4)         
#define CONTROLLER_REG_SIZE_BPMBL               (0x8)        
#define CONTROLLER_REG_SIZE_CMBMSC              (0x8)         
#define CONTROLLER_REG_SIZE_CMBSTS              (0x4)         
#define CONTROLLER_REG_SIZE_CMBEBS              (0x4)         
#define CONTROLLER_REG_SIZE_CMBSWTP             (0x4)          
#define CONTROLLER_REG_SIZE_NSSD                (0x4)       
#define CONTROLLER_REG_SIZE_CRTO                (0x4)
#define CONTROLLER_REG_SIZE_PMRCAP              (0x4)         
#define CONTROLLER_REG_SIZE_PMRCTL              (0x4)         
#define CONTROLLER_REG_SIZE_PMRSTS              (0x4)         
#define CONTROLLER_REG_SIZE_PMREBS              (0x4)         
#define CONTROLLER_REG_SIZE_PMRSWTP             (0x4)          
#define CONTROLLER_REG_SIZE_PMRMSCL             (0x4)          
#define CONTROLLER_REG_SIZE_PMRMSCU             (0x4)

#define SQT_ENTRY_SIZE                          (0x4)
#define CQH_ENTRY_SIZE                          (0x4)

#define MSIX_ENTRY_SIZE                         (0x10)

#define NVME_COMMAND_SIZE                       (0x40)
#define NVME_COMMAND_SIZE_IN_DWORDS             (16)

#define NVME_COMPLETION_SIZE                    (0x10)
#define NVME_COMPLETION_SIZE_IN_DWORDS          (4)

#define NVME_IDENTIFY_DATA_SIZE                 (0x1000)
#define NVME_IDENTIFY_DATA_SIZE_IN_DWORDS       (1024)

#define NVME_NAMESPACE_ID_DESCRIPTOR_LIST_SIZE              (20)
#define NVME_NAMESPACE_ID_DESCRIPTOR_LIST_SIZE_IN_DWORDS    (5)

#define NVME_MAX_NSID_LIST                      (1024)
#define NVME_MAX_CONTROLLER                     (2047)
#define NVME_MAX_LBA_FORMAT                     (16)
#define NVME_MAX_POWER_STATE                    (32)

#define NVME_VERSION_1_0                        (0x00010000)
#define NVME_VERSION_1_1                        (0x00010100)
#define NVME_VERSION_1_2                        (0x00010200)
#define NVME_VERSION_1_2_1                      (0x00010201)
#define NVME_VERSION_1_3                        (0x00010300)    
#define NVME_VERSION_1_4                        (0x00010400)
#define NVME_VERSION_2_0                        (0x00020000)


