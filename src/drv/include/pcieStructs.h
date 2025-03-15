
#pragma once

#include "pcieDefines.h"

//=========================================================================

//-------------------------------------------------
// PCIe configure header registers
//-------------------------------------------------

typedef struct commandReg_t
{
    uint16_t    ioSpaceEnable       :1;   
    uint16_t    memorySpaceEnable   :1;
    uint16_t    busMasterEnable     :1;
    uint16_t    reserved0           :3;
    uint16_t    parityErrorResponse :1;
    uint16_t    reserved1           :1;
    uint16_t    serrEnable          :1;
    uint16_t    reserved2           :1;
    uint16_t    interruptDisable    :1;
    uint16_t    reserved3           :5;
}commandReg_t;
static_assert(sizeof(commandReg_t) == 2);

typedef struct statusReg_t
{
    uint16_t    immediateReadiness      :1; //bit 0
    uint16_t    reserved0               :2; //bit 1-2
    uint16_t    interruptStatus         :1; //bit 3
    uint16_t    capabilityList          :1; //bit 4
    uint16_t    reserved1               :3; //bit 5-7
    uint16_t    masterDataParityError   :1; //bit 8
    uint16_t    reserved2               :2; //bit 9-10
    uint16_t    signaledTargetAbort     :1; //bit 11
    uint16_t    receivedTargetAbort     :1; //bit 12
    uint16_t    receivedMasterAbort     :1; //bit 13
    uint16_t    signaledSystemError     :1; //bit 14
    uint16_t    detectedParityError     :1; //bit 15
}statusReg_t;
static_assert(sizeof(statusReg_t) == 2);

//-------------------------------------------------
// PCIe configuration headers (Type 0 header for now...)
//-------------------------------------------------

typedef struct pcieConfigurationHeader_t
{
    uint32_t    vendorId                :16;
    uint32_t    deviceId                :16;
    
    union
    {
        commandReg_t    bits;
        uint16_t        rawdata;
    }command;
    
    union
    {
        statusReg_t     bits;
        uint16_t        rawdata;
    }status;
    
    uint32_t    revId                   :8;
    uint32_t    classCode               :24;
    uint32_t    cacheLineSize           :8;  
    uint32_t    latencyTimer            :8;
    uint32_t    headerType              :8;
    uint32_t    bist                    :8;
    uint32_t    bar0;
    uint32_t    bar1;
    uint32_t    bar2;
    uint32_t    bar3;
    uint32_t    bar4;
    uint32_t    bar5;
    uint32_t    cardBusCisPtr;
    uint32_t    subsysVendorId          :16;
    uint32_t    subsysDeviceId          :16;
    uint32_t    expansionRomBaseAddr;
    uint32_t    capPtr                  :8;
    uint32_t    reserved0               :24;
    uint32_t    reserved1;
    uint32_t    interruptLine           :8;
    uint32_t    interruptPin            :8;
    uint32_t    minGnt                  :8;
    uint32_t    maxLat                  :8;
}pcieConfigurationHeader_t;
static_assert(sizeof(pcieConfigurationHeader_t) == PCIE_CONFIG_HEADER_SIZE);

//-------------------------------------------------
// PCIe capability structures
//-------------------------------------------------

typedef struct capability_msix_t
{
    uint32_t    capId                       :8;
    uint32_t    nextCapIdPtr                :8;
    uint32_t    messageControl              :16;
    uint32_t    msixTableOffset;
    uint32_t    pbaOffset;
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