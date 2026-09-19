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
PCIe config space header (type 0)
**************************************************************/

#define PCIE_CONFIG_SPACE_HEADER_OFFSET_VENDOR_ID             (0x0)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_DEVICE_ID             (0x2)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_COMMAND               (0x4)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_STATUS                (0x6)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_REV_ID                (0x8)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_CLASS_CODE            (0x9)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_CACHE_LINE_SIZE       (0xC)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_LATENCY_TIMER         (0xD)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_HEADER_TYPE           (0xE)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_BIST                  (0xF)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_BAR0                  (0x10)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_BAR1                  (0x14)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_BAR2                  (0x18)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_BAR3                  (0x1C)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_BAR4                  (0x20)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_BAR5                  (0x24)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_CARDBUS_CIS_PTR       (0x28)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_SUBSYSTEM_VENDOR_ID   (0x2C)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_SUBSYSTEM_ID          (0x2E)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_EXPANSION_ROM         (0x30)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_CAP_PTR               (0x34)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_INT_LINE              (0x3C)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_INT_PIN               (0x3D)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_MIN_GNT               (0x3E)
#define PCIE_CONFIG_SPACE_HEADER_OFFSET_MAX_LAT               (0x3F)

#define PCIE_CONFIG_SPACE_HEADER_SIZE                         (0x40)

/**************************************************************
PCIe header status bit
**************************************************************/

#define PCIE_CONFIG_SPACE_HEADER_STATUS_IMMEDIATE_READINESS          (0x1)
#define PCIE_CONFIG_SPACE_HEADER_STATUS_INTERRUPT_STATUS             (0x8)
#define PCIE_CONFIG_SPACE_HEADER_STATUS_CAPABILITIES_LIST            (0x10)
#define PCIE_CONFIG_SPACE_HEADER_STATUS_MASTER_DATA_PARITY_ERROR     (0x100)
#define PCIE_CONFIG_SPACE_HEADER_STATUS_SIGNALED_TARGET_ABORT        (0x800)
#define PCIE_CONFIG_SPACE_HEADER_STATUS_RECEIVED_TARGET_ABORT        (0x1000)
#define PCIE_CONFIG_SPACE_HEADER_STATUS_RECEIVED_MASTER_ABORT        (0x2000)
#define PCIE_CONFIG_SPACE_HEADER_STATUS_SIGNALED_SYSTEM_ERROR        (0x4000)
#define PCIE_CONFIG_SPACE_HEADER_STATUS_DETECTED_PARITY_ERROR        (0x8000)

/**************************************************************
PCIe header class code
https://pcisig.com/sites/default/files/files/PCI_Code-ID_r_1_11__v24_Jan_2019.pdf
**************************************************************/

#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_MASS_STORAGE_CONTROLLER                          (0x01)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_NETWORK_CONTROLLER                               (0x02)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_DISPLAY_CONTROLLER                               (0x03)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_MULTIMEDIA_DEVICE                                (0x04)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_MEMORY_CONTROLLER                                (0x05)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_BRIDGE_DEVICE                                    (0x06)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_SIMPLE_COMMUNICATION_CONTROLLER                  (0x07)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_BASE_SYSTEM_PERIPHERAL                           (0x08)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_INPUT_DEVICE                                     (0x09)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_DOCKING_STATION                                  (0x0A)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_PROCESSOR                                        (0x0B)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_SERIAL_BUS_CONTROLLER                            (0x0C)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_WIRELESS_CONTROLLER                              (0x0D)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_INTELLIGENT_IO_CONTROLLER                        (0x0E)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_SATELLITE_COMMUNICATION_CONTROLLER               (0x0F)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_ENCRYPTION_DECRYPTION_CONTROLLER                 (0x10)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_DATA_ACQUISITION_SIGNAL_PROCESSING_CONTROLLERS   (0x11)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_PROCESSING_ACCELERATORS                          (0x12)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_NON_ESSENTIAL_INSTRUMENTATION                    (0x13)
#define PCIE_CONFIG_SPACE_HEADER_CLASS_CODE_UNDEFINED                                        (0xFF)

//-------------------------------------------------
// PCIe configure header individual registers
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
}
commandReg_t;

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
}
statusReg_t;

//-------------------------------------------------
// PCIe configuration headers
//-------------------------------------------------

typedef struct __attribute__((packed, aligned (4))) pcieConfigurationHeader_t
{
    //PCIe config header Dword 0 (byte offset 00h)
    union
    {
        struct
        {
            uint32_t vendorId :16;    
            uint32_t deviceId :16;    
        };

        uint32_t all;
    }dw0;

    //PCIe config header Dword 1 (byte offset 04h)
    union
    {
        struct
        {
            commandReg_t command;                           
            statusReg_t status;                         
        };

        uint32_t all;
    }dw1;

    //PCIe config header Dword 2 (byte offset 08h)
    union
    {
        struct
        {
            uint32_t revId     :8;     
            uint32_t classCode :24;    
        };

        uint32_t all;
    }dw2;

    //PCIe config header Dword 3 (byte offset 0Ch)
    union
    {
        struct
        {
            uint32_t cacheLineSize :8;     
            uint32_t latencyTimer  :8;
            uint32_t headerType    :8;
            uint32_t bist          :8;
        };

        uint32_t all;
    }dw3;

    //PCIe config header Dword 4 (byte offset 10h)
    uint32_t bar0;
    
    //PCIe config header Dword 5 (byte offset 14h)
    uint32_t bar1;
    
    //PCIe config header Dword 6 (byte offset 18h)
    union
    {
        //type 1 config space header specific
        struct 
        {
            uint32_t primaryBusNumber       :8;
            uint32_t secondaryBusNumber     :8;
            uint32_t subordinateBusNumber   :8;
            uint32_t secondaryLatencyTimer  :8;
        };

        //type 0 config space header specific
        uint32_t bar2;

        uint32_t all;
    }dw6;
    
    //PCIe config header Dword 7 (byte offset 1Ch)
    union
    {
        //type 1 config space header specific
        struct 
        {
            uint32_t ioBase          :8;
            uint32_t ioLimit         :8;
            uint32_t secondaryStatus :16;
        };

        //type 0 config space header specific
        uint32_t bar3;

        uint32_t all;
    }dw7;

    //PCIe config header Dword 8 (byte offset 20h)
    union
    {
        //type 1 config space header specific
        struct 
        {
            uint32_t memoryBase  :16;
            uint32_t memoryLimit :16;
        };

        //type 0 config space header specific
        uint32_t bar4;

        uint32_t all;
    }dw8;

    //PCIe config header Dword 9 (byte offset 24h)
    union
    {
        //type 1 config space header specific
        struct 
        {
            uint32_t prefetchableMemoryBase  :16;
            uint32_t prefetchableMemoryLimit :16;
        };

        //type 0 config space header specific
        uint32_t bar5;

        uint32_t all;
    }dw9;

    //PCIe config header Dword 10 (byte offset 28h)
    union
    {
        //type 1 config space header specific
        uint32_t prefetchableBaseUpper;

        //type 0 config space header specific
        uint32_t cardBusCisPtr;

        uint32_t all;
    }dw10;

    //PCIe config header Dword 11 (byte offset 2Ch)
    union
    {
        //type 1 config space header specific
        uint32_t prefetchableBaseLower;

        //type 0 config space header specific
        struct
        {
            uint32_t subsysVendorId :16;
            uint32_t subsysDeviceId :16;
        };

        uint32_t all;
    }dw11;
    
    //PCIe config header Dword 12 (byte offset 30h)
    union
    {
        //type 1 config space header specific
        struct
        {
            uint32_t ioBaseUpper  :16;
            uint32_t ioLimitUpper :16;
        };

        //type 0 config space header specific
        uint32_t expansionRomBaseAddr;

        uint32_t all;
    }dw12;

    //PCIe config header Dword 13 (byte offset 34h)
    union
    {
        struct
        {
            uint32_t capPtr    :8;
            uint32_t reserved  :24;
        };

        uint32_t all;
    }dw13;

    //PCIe config header Dword 14 (byte offset 38h)
    union
    {
        //type 1 config space header specific
        uint32_t expansionRomBaseAddr;

        //type 0 config space header specific
        uint32_t reserved;

        uint32_t all;
    }dw14;

    //PCIe config header Dword 15 (byte offset 3Ch)
    union
    {
        struct
        {
            uint32_t interruptLine :8;
            uint32_t interruptPin  :8;
            
            union
            {
                //type 1 config space header specific
                uint16_t bridgeControl;                

                //type 0 config space header specific
                struct
                {
                    uint16_t minGnt :8;
                    uint16_t maxLat :8;                    
                };
            };
        };

        uint32_t all;
    }dw15;
}
pcieConfigurationSpaceHeader_t;
static_assert(sizeof(pcieConfigurationSpaceHeader_t) == PCIE_CONFIG_SPACE_HEADER_SIZE);
