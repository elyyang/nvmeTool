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

#include <stdint.h>

#ifndef __cplusplus
    #if !defined(static_assert)
        #define static_assert _Static_assert
    #endif
#endif // __cplusplus

/**************************************************************
PCIe capability structure IDs
**************************************************************/

#define PCIE_CAP_ID_RESERVED                            (0x00)
#define PCIE_CAP_ID_POWER_MANAGEMENT                    (0x01)
#define PCIE_CAP_ID_AGP                                 (0x02)
#define PCIE_CAP_ID_VPD                                 (0x03)
#define PCIE_CAP_ID_SLOT_ID                             (0x04)
#define PCIE_CAP_ID_MSI                                 (0x05)
#define PCIE_CAP_ID_COMPACTPCI_HOT_SWAP                 (0x06)
#define PCIE_CAP_ID_PCIX_DEVICE                         (0x07)
#define PCIE_CAP_ID_HYPER_TRANSPORT                     (0x08)
#define PCIE_CAP_ID_VENDOR_SPECIFIC                     (0x09)
#define PCIE_CAP_ID_DEBUG_PORT                          (0x0A)
#define PCIE_CAP_ID_COMPACTPCI_CENTRAL_RESOURCE_CTRL    (0x0B)
#define PCIE_CAP_ID_PCI_HOT_PLUG                        (0x0C)
#define PCIE_CAP_ID_PCI_BRIDGE_SUBSYSTEM_VENDOR_ID      (0x0D)
#define PCIE_CAP_ID_PCI_EXPRESS                         (0x10)
#define PCIE_CAP_ID_MSIX                                (0x11)
#define PCIE_CAP_ID_SATA_DATA_INDEX                     (0x12)
#define PCIE_CAP_ID_ADVANCED_FEATURES                   (0x13)
#define PCIE_CAP_ID_ENHANCED_ALLOCATION_STRUCTURE       (0x14)    
#define PCIE_CAP_ID_FLATTENING_PORTAL_BRIDGE            (0x15)    

/**************************************************************
PCIe extended capability structure IDs
**************************************************************/

#define PCIE_EXT_CAP_ID_NULL                            (0x00)
#define PCIE_EXT_CAP_ID_AER                             (0x01)    
#define PCIE_EXT_CAP_ID_VC                              (0x02)
#define PCIE_EXT_CAP_ID_DEVICE_SERIAL_NUMBER            (0x03)
#define PCIE_EXT_CAP_ID_POWER_BUDGETING                 (0x04)
#define PCIE_EXT_CAP_ID_RC_LINK_DECLARATION             (0x05)
#define PCIE_EXT_CAP_ID_PCIE_RC_INTERNAL_LINK_CONTROL   (0x06)    
#define PCIE_EXT_CAP_ID_RC_EVENT_COLLECTOR              (0x07)
#define PCIE_EXT_CAP_ID_MFVC                            (0x08)    
#define PCIE_EXT_CAP_ID_VIRTUAL_CHANNEL                 (0x09)
#define PCIE_EXT_CAP_ID_RCRB_HEADER                     (0x0A)
#define PCIE_EXT_CAP_ID_VENDOR_SPECIFIC                 (0x0B)
#define PCIE_EXT_CAP_ID_ACS                             (0x0D)
#define PCIE_EXT_CAP_ID_ARI                             (0x0E)
#define PCIE_EXT_CAP_ID_ATS                             (0x0F)
#define PCIE_EXT_CAP_ID_SRIOV                           (0x10)    
#define PCIE_EXT_CAP_ID_MULTICAST                       (0x12)
#define PCIE_EXT_CAP_ID_PAGE_REQUEST                    (0x13)
#define PCIE_EXT_CAP_ID_RESIZABLE_BAR                   (0x15)
#define PCIE_EXT_CAP_ID_DYNAMIC_POWER_ALLOCATION        (0x16)
#define PCIE_EXT_CAP_ID_TPH                             (0x17)
#define PCIE_EXT_CAP_ID_LTR                             (0x18)
#define PCIE_EXT_CAP_ID_SECONDARY_PCIE                  (0x19)
#define PCIE_EXT_CAP_ID_PROTOCOL_MULTIPLEXING           (0x1A)
#define PCIE_EXT_CAP_ID_PASID                           (0x1B)
#define PCIE_EXT_CAP_ID_LNR                             (0x1C)
#define PCIE_EXT_CAP_ID_DPC                             (0x1D)
#define PCIE_EXT_CAP_ID_L1_PM_SUBSTATES                 (0x1E)
#define PCIE_EXT_CAP_ID_PRECISION_TIME_MEASUREMENT      (0x1F)
#define PCIE_EXT_CAP_ID_MPCIE                           (0x20)
#define PCIE_EXT_CAP_ID_FUNCTION_READINESS_STATUS       (0x21)
#define PCIE_EXT_CAP_ID_READINESS_TIME_REPORTING        (0x22)
#define PCIE_EXT_CAP_ID_DVSEC                           (0x23)                    
#define PCIE_EXT_CAP_ID_VF_RESIZEABLE_BAR               (0x24)    
#define PCIE_EXT_CAP_ID_DATA_LINK_FEATURE               (0x25)    
#define PCIE_EXT_CAP_ID_PHYSICAL_LAYER_16GTS            (0x26)        
#define PCIE_EXT_CAP_ID_LANE_MARGINING_AT_RX            (0x27)        
#define PCIE_EXT_CAP_ID_HIERARCHY_ID                    (0x28)
#define PCIE_EXT_CAP_ID_NATIVE_PCIE_ENCLOSURE_MNGMT     (0x29)            
#define PCIE_EXT_CAP_ID_PHYSICAL_LAYER_32GTS            (0x2A)        
#define PCIE_EXT_CAP_ID_ALTERNATE_PROTOCOL              (0x2B)    
#define PCIE_EXT_CAP_ID_SFI                             (0x2C)    

//-------------------------------------------------
// PCIe capability structures
//-------------------------------------------------

typedef struct capability_msix_t
{
    //dw0
    uint32_t    capId           :8;
    uint32_t    nextCapIdPtr    :8;
    uint32_t    messageControl  :16;
    //dw1
    uint32_t    msixTableBir    :3;
    uint32_t    msixTableOffset :29;    
    //dw2
    uint32_t    pbaBir          :3;
    uint32_t    pbaOffset       :29;
}capability_msix_t;
static_assert(sizeof(capability_msix_t) == 12);

typedef struct capability_sriov_t
{
    uint32_t    extCapId                    :16;
    uint32_t    capVersion                  :4;
    uint32_t    nextExtCapIdPtr             :12;
    uint32_t    sriovCapabilities;
    uint32_t    sriovControl                :16;
    uint32_t    sriovStatus                 :16;
    uint32_t    initialVf                   :16;
    uint32_t    totalVf                     :16;
    uint32_t    numVf                       :16;
    uint32_t    functionDependencyLink      :8;
    uint32_t    reserved0                   :8;
    uint32_t    firstVfOffset               :16;
    uint32_t    vfStride                    :16;
    uint32_t    reserved1                   :16;
    uint32_t    vfDeviceId                  :16;
    uint32_t    supportedPageSize;
    uint32_t    systemPageSize;
    uint32_t    vfBar0;
    uint32_t    vfBar1;
    uint32_t    vfBar2;
    uint32_t    vfBar3;
    uint32_t    vfBar4;
    uint32_t    vfBar5;
    uint32_t    vfMigrationStateArrayOffset;
}capability_sriov_t;  
static_assert(sizeof(capability_sriov_t) == 64);

typedef struct capability_pasid_t
{
    uint32_t    extCapId                    :16;
    uint32_t    capVersion                  :4;
    uint32_t    nextExtCapIdPtr             :12;
    uint32_t    pasidCapabilityReigster     :16;
    uint32_t    pasidControlReigster        :16;
}capability_pasid_t;
static_assert(sizeof(capability_pasid_t) == 8);

typedef struct capability_pcipm_t
{
    uint32_t    capId                       :8;
    uint32_t    nextCapIdPtr                :8;
    uint32_t    pmc                         :16;
    uint32_t    pmcsr                       :16;
    uint32_t    pmcsrBse                    :8;
    uint32_t    dataRegister                :8;
}capability_pcipm_t;
static_assert(sizeof(capability_pcipm_t) == 8);