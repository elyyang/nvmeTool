
#pragma once

//==============================================================================
// Controller Reigster (BAR 0)
// 64B
//==============================================================================

#define CONTROLLER_REG_CAP_OFFSET                   (0x00)
#define CONTROLLER_REG_VS_OFFSET                    (0x08)
#define CONTROLLER_REG_INTMS_OFFSET                 (0x0C)
#define CONTROLLER_REG_INTMC_OFFSET                 (0x10)
#define CONTROLLER_REG_CC_OFFSET                    (0x14)
#define CONTROLLER_REG_CSTS_OFFSET                  (0x1C)
#define CONTROLLER_REG_NSSR_OFFSET                  (0x20)
#define CONTROLLER_REG_AQA_OFFSET                   (0x24) 						
#define CONTROLLER_REG_ASQ_OFFSET                   (0x28) 	
#define CONTROLLER_REG_ACQ_OFFSET                   (0x30)
#define CONTROLLER_REG_CMBLOC_OFFSET                (0x38)
#define CONTROLLER_REG_CMBSZ_OFFSET                 (0x3C)
#define CONTROLLER_REG_BPINFO_OFFSET                (0x40)
#define CONTROLLER_REG_BPRSEL_OFFSET                (0x44)
#define CONTROLLER_REG_BPMBL_OFFSET                 (0x48)
#define CONTROLLER_REG_CMBMSC_OFFSET                (0x50)
#define CONTROLLER_REG_CMBSTS_OFFSET                (0x58)

#define CONTROLLER_REG_PMRCAP_OFFSET                (0xE00)
#define CONTROLLER_REG_PMRCTL_OFFSET                (0xE04)
#define CONTROLLER_REG_PMRSTS_OFFSET                (0xE08)
#define CONTROLLER_REG_PMREBS_OFFSET                (0xE0C)
#define CONTROLLER_REG_PMRSWTP_OFFSET               (0xE10)
#define CONTROLLER_REG_PMRMSCL_OFFSET               (0xE14)
#define CONTROLLER_REG_PMRMSCU_OFFSET               (0xE18)

//==============================================================================
// SQ Tail & CQ Head doorbell
// 1088B (136 x 8B)
//==============================================================================

#define SQT_CQH_BASE_OFFSET                         (0x1000)

//==============================================================================
// MSIX
//==============================================================================

#define MSIX_BASE_OFFSET                            (0x2000)

//==============================================================================
// NVMe Admin Commands
//==============================================================================

#define ACMD_DELETE_IO_SQ                           0x0
#define ACMD_CREATE_IO_SQ                           0x1
#define ACMD_GET_LOG_PAGE                           0x2
#define ACMD_DELETE_IO_CQ                           0x4
#define ACMD_CREATE_IO_CQ                           0x5
#define ACMD_IDENTIFY                               0x6
#define ACMD_ABORT                                  0x8
#define ACMD_SET_FEATURES                           0x9
#define ACMD_GET_FEATURES                           0xA
#define ACMD_ASYNC_EVENT_REQUEST                    0xC
#define ACMD_NS_MANAGEMENT                          0xD
#define ACMD_FW_COMMIT                              0x10
#define ACMD_FW_IMAGE_DOWNLOAD                      0x11
#define ACMD_DEVICE_SELF_TEST                       0x14
#define ACMD_NS_ATTACHMENT                          0x15
#define ACMD_KEEP_ALIVE                             0x18
#define ACMD_DIRECTIVE_SEND                         0x19
#define ACMD_DIRECTIVE_RECEIVE                      0x1A
#define ACMD_VIRTUALIZATION_MANAGEMENT              0x1C
#define ACMD_NVME_MI_SEND                           0x1D // Refer to the NVM Express Management Interface Specification for details on the NVMe-MI Send command.
#define ACMD_NVME_MI_RECEIVE                        0x1E // Refer to the NVM Express Management Interface Specification for details on the NVMe-MI Receive command.
#define ACMD_DOORBELL_BUFFER_CONFIG                 0x7C
#define ACMD_FABRICS                                0x7F
#define ACMD_FORMAT_NVM                             0x80
#define ACMD_SECURITY_SEND                          0x81
#define ACMD_SECURITY_RECEIVE                       0x82
#define ACMD_SANITIZE                               0x84
#define ACMD_LBA_STATUS                             0x86

//==============================================================================
// Identify Controller or Namespace Structure (CNS)
//==============================================================================

#define CNS_IDENTIFY_NAMESPACE                      0x00
#define CNS_IDENTIFY_CONTROLLER                     0x01
#define CNS_ACTIVE_NAMESPACE_ID_LIST                0X02
#define CNS_NAMESPACE_ID_DESCRIPTOR_LIST            0X03
#define CNS_NVME_SET_LIST                           0x04

//==============================================================================
// Controller and Namespace Management CNS
//==============================================================================

#define CNS_ALLOCATED_NAMESPACE_ID_LIST             0x10
#define CNS_IDENTIFY_NAMESPACE_ALLOCATED_NSID       0x11
#define CNS_NAMEPACE_ATTACHED_CONTROLLER_LIST       0x12
#define CNS_CONTROLLER_LIST                         0x13
#define CNS_PRIMARY_CONTROLLER_CAPABILITIES         0x14
#define CNS_SECONDARY_CONTROLLER_CAPABILITIES       0x15
#define CNS_NAMESPACE_GRANULARITY_LIST              0x16
#define CNS_UUID_LIST                               0x17

//==============================================================================
// Nvme Command Set
//==============================================================================

#define NVM_FLUSH                                   0x0
#define NVM_WRITE                                   0x1
#define NVM_READ                                    0x2
#define NVM_WRITE_UNCORRECTABLE                     0x4
#define NVM_COMPARE                                 0x5
#define NVM_WRITE_ZEROES                            0x8
#define NVM_DATASET_MANAGEMENT                      0X9
#define NVM_VERIFY                                  0xC
#define NVM_RESERVATION_REGISTER                    0xD
#define NVM_RESERVATION_REPORT                      0xE
#define NVM_RESERVATION_ACQUIRE                     0x11
#define NVM_RESERVATION_RELEASE                     0x15

//==============================================================================
// Features for set/get features
//==============================================================================

#define FEAT_ARBITATION                             0x1
#define FEAT_LBA_RANGE_TYPE                         0x3
#define FEAT_TEMPERATURE_TRESHOLD                   0x4
#define FEAT_POWER_MANAGAMENT                       0x2
#define FEAT_ERROR_RECOVERY                         0x5
#define FEAT_VOLATILE_WRITE_CACHE                   0x6
#define FEAT_NUMBER_OF_QUEUES                       0x7
#define FEAT_INTERRUPT_COALESCING                   0x8
#define FEAT_INTERRUPT_VECTOR_CONFIGURATION         0x9
#define FEAT_WRITE_ATOMICITY_NORMAL                 0xA
#define FEAT_ASYNC_EVENT_CONFIGURATION              0xB
#define FEAT_AUTONOMOUS_POWER_STATE_TRANSITION      0xC
#define FEAT_HOST_MEMORY_BUFFER                     0xD
#define FEAT_TIMESTAMP                              0xE
#define FEAT_KEEP_ALIVE_TIMER                       0xF
#define FEAT_HOST_CONTROLLED_THERMAL_MANAGMENT      0x10
#define FEAT_NON_OPERATIONAL_POWER_STATE_CONFIG     0x11
#define FEAT_READ_RECOVERY_LEVEL_CONFIG             0x12
#define FEAT_PREDICTABLE_LATENCY_MODE_CONFIG        0x13
#define FEAT_PREDICTABLE_LATENCY_MODE_WINDOW        0x14
#define FEAT_LBA_STATUS_INFORMATION_REPORT_INTERVAL 0x15
#define FEAT_HOST_BEHAVIOUR_SUPPORT                 0x16
#define FEAT_SANATIZE_CONFIG                        0x17
#define FEAT_ENDURANCE_GROUP_EVENT_CONFIG           0x18
#define FEAT_SOFTWARE_PROGRESS_MARKER               0x80
#define FEAT_HOST_IDENTIFIER                        0x81
#define FEAT_RESERVATION_NOTIFICATION_MASK          0x82
#define FEAT_RERSERVATION_PERSISTENCE               0x83
#define FEAT_NAMESPACE_WRITE_PROTECTION_CONFIG      0x84

//==============================================================================
// get log page identifier
//==============================================================================

#define LOG_PAGE_ID_ERROR                           0x1
#define LOG_PAGE_ID_SMART                           0x2
#define LOG_PAGE_ID_FW_SLOT                         0x3
#define LOG_PAGE_ID_CHANGED_NS_LIST                 0x4
#define LOG_PAGE_ID_CMD_SUPPORTED_AND_EFFECTS       0x5
#define LOG_PAGE_ID_DEVICE_SELF_TEST                0x6
#define LOG_PAGE_ID_TELEMETRY_HOST_INITIATED        0x7            
#define LOG_PAGE_ID_TELEMETRY_CONTROLLER_INITIATED  0x8
#define LOG_PAGE_ID_ENDURANCE_GROUP_INFO            0x9
#define LOG_PAGE_ID_PERDICTABLE_LATENCY_PER_NVME    0xA
#define LOG_PAGE_ID_PERDICTABLE_LATENCY_EVENT_AGGR  0xB
#define LOG_PAGE_ID_ASYMMETRIC_NS_ACCESS            0xC
#define LOG_PAGE_ID_PERSISTENT_EVENT_LOG            0xD
#define LOG_PAGE_ID_LBA_STATUS_INFO                 0xE
#define LOG_PAGE_ID_ENDURANCE_GROUP_EVENT_AGGR      0xF

//==============================================================================
// Misc NVMe 
//==============================================================================

#define MMIO_REG_SIZE                               0x4000

#define MSIX_ENTRY_SIZE                             0x10
#define SGL_DESCRIPTOR_SIZE                         0x10
#define NVME_COMMAND_SIZE                           0x40
#define NVME_COMPLETION_SIZE                        0x10

#define IOSQ_ENTRY_SIZE                             0x6
#define IOCQ_ENTRY_SIZE                             0x4

#define MAX_QUEUE_COUNT                             256
#define MAX_NAMESPACE_COUNT                         1024

#define AMS_RR                                      0x0
#define AMS_WRRUPC                                  0x1
#define AMS_VENDOR_SPECIFIC                         0x7

#define CSS_NVM_CMD_SET                             0x0
#define CSS_ADMIN_CMD_SET_ONLY                      0x7