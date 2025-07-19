
#pragma once

/**************************************************************
NVM-Express-Base-Specification-Revision-2.2-2025.03.11-Ratified
3.1.4 Controller Properties
**************************************************************/

#define NVM_CONTROLLER_MMIO_REG_SIZE                (0x4000)

/**************************************************************
Controller Reigster
**************************************************************/

#define CONTROLLER_REG_OFFSET_CAP                   (0x00)
#define CONTROLLER_REG_OFFSET_CAPL                  (0x00)
#define CONTROLLER_REG_OFFSET_CAPU                  (0x04)
#define CONTROLLER_REG_OFFSET_VS                    (0x08)
#define CONTROLLER_REG_OFFSET_INTMS                 (0x0C)
#define CONTROLLER_REG_OFFSET_INTMC                 (0x10)
#define CONTROLLER_REG_OFFSET_CC                    (0x14)
#define CONTROLLER_REG_OFFSET_CSTS                  (0x1C)
#define CONTROLLER_REG_OFFSET_NSSR                  (0x20)
#define CONTROLLER_REG_OFFSET_AQA                   (0x24)
#define CONTROLLER_REG_OFFSET_ASQ                   (0x28)
#define CONTROLLER_REG_OFFSET_ASQL                  (0x28)
#define CONTROLLER_REG_OFFSET_ASQU                  (0x2C)
#define CONTROLLER_REG_OFFSET_ACQ                   (0x30)
#define CONTROLLER_REG_OFFSET_ACQL                  (0x30)
#define CONTROLLER_REG_OFFSET_ACQU                  (0x34)
#define CONTROLLER_REG_OFFSET_CMBLOC                (0x38)
#define CONTROLLER_REG_OFFSET_CMBSZ                 (0x3C)
#define CONTROLLER_REG_OFFSET_BPINFO                (0x40)
#define CONTROLLER_REG_OFFSET_BPRSEL                (0x44)
#define CONTROLLER_REG_OFFSET_BPMBL                 (0x48)
#define CONTROLLER_REG_OFFSET_CMBMSC                (0x50)
#define CONTROLLER_REG_OFFSET_CMBSTS                (0x58)
#define CONTROLLER_REG_OFFSET_CMBEBS                (0x5C) 
#define CONTROLLER_REG_OFFSET_CMBSWTP               (0x60) 
#define CONTROLLER_REG_OFFSET_NSSD                  (0x64) 
#define CONTROLLER_REG_OFFSET_CRTO                  (0x68)
#define CONTROLLER_REG_OFFSET_PMRCAP                (0xE00)
#define CONTROLLER_REG_OFFSET_PMRCTL                (0xE04)
#define CONTROLLER_REG_OFFSET_PMRSTS                (0xE08)
#define CONTROLLER_REG_OFFSET_PMREBS                (0xE0C)
#define CONTROLLER_REG_OFFSET_PMRSWTP               (0xE10)
#define CONTROLLER_REG_OFFSET_PMRMSCL               (0xE14)
#define CONTROLLER_REG_OFFSET_PMRMSCU               (0xE18)

/**************************************************************
Controller Reigster
SQ Tail & CQ Head doorbell base
**************************************************************/

#define CONTROLLER_REG_OFFSET_SQT_CQH_BASE         (0x1000)

/**************************************************************
NVMe Admin Commands
**************************************************************/

#define NVM_ADMIN_CMD_DELETE_IO_SQ                  (0x00)
#define NVM_ADMIN_CMD_CREATE_IO_SQ                  (0x01)
#define NVM_ADMIN_CMD_GET_LOG_PAGE                  (0x02)
#define NVM_ADMIN_CMD_DELETE_IO_CQ                  (0x04)
#define NVM_ADMIN_CMD_CREATE_IO_CQ                  (0x05)
#define NVM_ADMIN_CMD_IDENTIFY                      (0x06)
#define NVM_ADMIN_CMD_ABORT                         (0x08)
#define NVM_ADMIN_CMD_SET_FEATURES                  (0x09)
#define NVM_ADMIN_CMD_GET_FEATURES                  (0x0A)
#define NVM_ADMIN_CMD_ASYNC_EVENT_REQUEST           (0x0C)
#define NVM_ADMIN_CMD_NS_MANAGEMENT                 (0x0D)
#define NVM_ADMIN_CMD_FW_COMMIT                     (0x10)
#define NVM_ADMIN_CMD_FW_IMAGE_DOWNLOAD             (0x11)
#define NVM_ADMIN_CMD_DEVICE_SELF_TEST              (0x14)
#define NVM_ADMIN_CMD_NS_ATTACHMENT                 (0x15)
#define NVM_ADMIN_CMD_KEEP_ALIVE                    (0x18)
#define NVM_ADMIN_CMD_DIRECTIVE_SEND                (0x19)
#define NVM_ADMIN_CMD_DIRECTIVE_RECEIVE             (0x1A)
#define NVM_ADMIN_CMD_VIRTUALIZATION_MANAGEMENT     (0x1C)
#define NVM_ADMIN_CMD_NVME_MI_SEND                  (0x1D) // Refer to the NVM Express Management Interface Specification for details on the NVMe-MI Send command.
#define NVM_ADMIN_CMD_NVME_MI_RECEIVE               (0x1E) // Refer to the NVM Express Management Interface Specification for details on the NVMe-MI Receive command.
#define NVM_ADMIN_CMD_DOORBELL_BUFFER_CONFIG        (0x7C)
#define NVM_ADMIN_CMD_FABRICS                       (0x7F)
#define NVM_ADMIN_CMD_FORMAT_NVM                    (0x80)
#define NVM_ADMIN_CMD_SECURITY_SEND                 (0x81)
#define NVM_ADMIN_CMD_SECURITY_RECEIVE              (0x82)
#define NVM_ADMIN_CMD_SANITIZE                      (0x84)
#define NVM_ADMIN_CMD_LBA_STATUS                    (0x86)

/**************************************************************
Identify Controller or Namespace Structure (CNS)
**************************************************************/

#define CNS_IDENTIFY_NAMESPACE                      (0x00)
#define CNS_IDENTIFY_CONTROLLER                     (0x01)
#define CNS_ACTIVE_NAMESPACE_ID_LIST                (0X02)
#define CNS_NAMESPACE_ID_DESCRIPTOR_LIST            (0X03)
#define CNS_NVME_SET_LIST                           (0x04)

/**************************************************************
Controller and Namespace Management CNS
**************************************************************/

#define CNS_ALLOCATED_NAMESPACE_ID_LIST             (0x10)
#define CNS_IDENTIFY_NAMESPACE_ALLOCATED_NSID       (0x11)
#define CNS_NAMEPACE_ATTACHED_CONTROLLER_LIST       (0x12)
#define CNS_CONTROLLER_LIST                         (0x13)
#define CNS_PRIMARY_CONTROLLER_CAPABILITIES         (0x14)
#define CNS_SECONDARY_CONTROLLER_CAPABILITIES       (0x15)
#define CNS_NAMESPACE_GRANULARITY_LIST              (0x16)
#define CNS_UUID_LIST                               (0x17)

/**************************************************************
Nvme Command Set
**************************************************************/

#define NVM_CMD_FLUSH                               (0x00)
#define NVM_CMD_WRITE                               (0x01)
#define NVM_CMD_READ                                (0x02)
#define NVM_CMD_WRITE_UNCORRECTABLE                 (0x04)
#define NVM_CMD_COMPARE                             (0x05)
#define NVM_CMD_WRITE_ZEROES                        (0x08)
#define NVM_CMD_DATASET_MANAGEMENT                  (0X09)
#define NVM_CMD_VERIFY                              (0x0C)
#define NVM_CMD_RESERVATION_REGISTER                (0x0D)
#define NVM_CMD_RESERVATION_REPORT                  (0x0E)
#define NVM_CMD_RESERVATION_ACQUIRE                 (0x11)
#define NVM_CMD_RESERVATION_RELEASE                 (0x15)

/**************************************************************
Features for set/get features
**************************************************************/

#define FEAT_ARBITATION                             (0x01)
#define FEAT_LBA_RANGE_TYPE                         (0x03)
#define FEAT_TEMPERATURE_TRESHOLD                   (0x04)
#define FEAT_POWER_MANAGAMENT                       (0x02)
#define FEAT_ERROR_RECOVERY                         (0x05)
#define FEAT_VOLATILE_WRITE_CACHE                   (0x06)
#define FEAT_NUMBER_OF_QUEUES                       (0x07)
#define FEAT_INTERRUPT_COALESCING                   (0x08)
#define FEAT_INTERRUPT_VECTOR_CONFIGURATION         (0x09)
#define FEAT_WRITE_ATOMICITY_NORMAL                 (0x0A)
#define FEAT_ASYNC_EVENT_CONFIGURATION              (0x0B)
#define FEAT_AUTONOMOUS_POWER_STATE_TRANSITION      (0x0C)
#define FEAT_HOST_MEMORY_BUFFER                     (0x0D)
#define FEAT_TIMESTAMP                              (0x0E)
#define FEAT_KEEP_ALIVE_TIMER                       (0x0F)
#define FEAT_HOST_CONTROLLED_THERMAL_MANAGMENT      (0x10)
#define FEAT_NON_OPERATIONAL_POWER_STATE_CONFIG     (0x11)
#define FEAT_READ_RECOVERY_LEVEL_CONFIG             (0x12)
#define FEAT_PREDICTABLE_LATENCY_MODE_CONFIG        (0x13)
#define FEAT_PREDICTABLE_LATENCY_MODE_WINDOW        (0x14)
#define FEAT_LBA_STATUS_INFORMATION_REPORT_INTERVAL (0x15)
#define FEAT_HOST_BEHAVIOUR_SUPPORT                 (0x16)
#define FEAT_SANATIZE_CONFIG                        (0x17)
#define FEAT_ENDURANCE_GROUP_EVENT_CONFIG           (0x18)
#define FEAT_SOFTWARE_PROGRESS_MARKER               (0x80)
#define FEAT_HOST_IDENTIFIER                        (0x81)
#define FEAT_RESERVATION_NOTIFICATION_MASK          (0x82)
#define FEAT_RERSERVATION_PERSISTENCE               (0x83)
#define FEAT_NAMESPACE_WRITE_PROTECTION_CONFIG      (0x84)

/**************************************************************
get log page identifier
**************************************************************/

#define LOG_PAGE_ID_ERROR                           (0x1)
#define LOG_PAGE_ID_SMART                           (0x2)
#define LOG_PAGE_ID_FW_SLOT                         (0x3)
#define LOG_PAGE_ID_CHANGED_NS_LIST                 (0x4)
#define LOG_PAGE_ID_CMD_SUPPORTED_AND_EFFECTS       (0x5)
#define LOG_PAGE_ID_DEVICE_SELF_TEST                (0x6)
#define LOG_PAGE_ID_TELEMETRY_HOST_INITIATED        (0x7)            
#define LOG_PAGE_ID_TELEMETRY_CONTROLLER_INITIATED  (0x8)
#define LOG_PAGE_ID_ENDURANCE_GROUP_INFO            (0x9)
#define LOG_PAGE_ID_PERDICTABLE_LATENCY_PER_NVME    (0xA)
#define LOG_PAGE_ID_PERDICTABLE_LATENCY_EVENT_AGGR  (0xB)
#define LOG_PAGE_ID_ASYMMETRIC_NS_ACCESS            (0xC)
#define LOG_PAGE_ID_PERSISTENT_EVENT_LOG            (0xD)
#define LOG_PAGE_ID_LBA_STATUS_INFO                 (0xE)
#define LOG_PAGE_ID_ENDURANCE_GROUP_EVENT_AGGR      (0xF)

/**************************************************************
Misc NVMe 
**************************************************************/

#define MSIX_ENTRY_SIZE                             (0x10)
#define NVME_COMMAND_SIZE                           (0x40)
#define NVME_COMPLETION_SIZE                        (0x10)
#define NVME_SGL_DESCRIPTOR_SIZE                    (0x10)
