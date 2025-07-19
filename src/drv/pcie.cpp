#include "pcie.h"
#include "assertLib.h"
#include "debugPrint.h"

//=========================================================================

pcie_c::pcie_c(int id)
{
    #define BYTES_TO_READ 64    
    char fdPath[BYTES_TO_READ];
    char fdIdx[BYTES_TO_READ];    

    int uioId = id;
    sprintf(fdIdx, "%d", uioId);

    NVME_DBG_PRINTF(info, "initialize pcie_c!");

    strcpy(fdPath, "/sys/class/uio/uio");
    strcat(fdPath, fdIdx);
    strcat(fdPath, "/device/config");

    uio_config_fd = open(fdPath, O_RDWR | O_SYNC);
    NVME_DBG_ASSERT((uio_config_fd>0), "uio_config_fd failed to open!")
}

pcie_c::~pcie_c(void)
{    
    NVME_DBG_PRINTF(info, "clean-up pcie_c!");    
    close(uio_config_fd);    
}

//=========================================================================

pcie_c& pcie_c::getInstance(int id)
{
    static pcie_c instance(id);
    return instance;
}

pcieConfigurationHeader_t pcie_c::getPcieConfigHeader(void)
{   
    pcieConfigurationHeader_t configSpace;
    pread(uio_config_fd, &configSpace, sizeof(pcieConfigurationHeader_t), 0x0);
    return configSpace;    
}

bool pcie_c::isCapabilitiesListPresent(void)
{
    pcieConfigurationHeader_t configSpace;    
    pread(uio_config_fd, &configSpace, sizeof(pcieConfigurationHeader_t), 0x0);      
    return configSpace.dw1.status.capabilityList;
}

void pcie_c::setBusMasterEnable(bool bmeStatus)
{
    commandReg_t reg;
    pread(uio_config_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_HEADER_OFFSET_COMMAND);
    reg.busMasterEnable = bmeStatus;
    pwrite(uio_config_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_HEADER_OFFSET_COMMAND);
}

bool pcie_c::getBusMasterEnable(void)
{    
    commandReg_t reg;
    pread(uio_config_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_HEADER_OFFSET_COMMAND);    
    return reg.busMasterEnable;
}

void pcie_c::setInterruptDisable(bool disable)
{
    commandReg_t reg;    
    pread(uio_config_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_HEADER_OFFSET_COMMAND);
    reg.interruptDisable = disable;
    pwrite(uio_config_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_HEADER_OFFSET_COMMAND);
}

bool pcie_c::getInterruptDisable(void)
{    
    commandReg_t reg;
    pread(uio_config_fd, &reg, sizeof(commandReg_t), PCIE_CONFIG_HEADER_OFFSET_COMMAND);    
    return reg.interruptDisable;
}

void pcie_c::getPcieCapability(void)
{
    struct pcieCapListRegister_t
    {            
        uint8_t capId;
        uint8_t nextCapPtr;
    };
    
    pcieCapListRegister_t currentReg;
    uint8_t currentCapPtr;
    
    pcieConfigurationHeader_t  configSpace;
    pread(uio_config_fd, &configSpace, sizeof(pcieConfigurationHeader_t), 0x0);    

    if(configSpace.dw1.status.capabilityList)
    {   
        currentCapPtr = configSpace.dw13.capPtr;            

        while(currentCapPtr != 0x0)
        {            
            pread(uio_config_fd, &currentReg, sizeof(uint16_t), currentCapPtr);    
            
            switch(currentReg.capId)
            {
                case PCIE_CAP_ID_POWER_MANAGEMENT:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_POWER_MANAGEMENT \n", PCIE_CAP_ID_POWER_MANAGEMENT);
                    break;                
                    
                case PCIE_CAP_ID_VPD:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_VPD \n", PCIE_CAP_ID_VPD);
                    break;                

                case PCIE_CAP_ID_AGP:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_AGP \n", PCIE_CAP_ID_AGP);
                    break;                

                case PCIE_CAP_ID_SLOT_ID:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_SLOT_ID \n", PCIE_CAP_ID_SLOT_ID);
                    break;                

                case PCIE_CAP_ID_MSI:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_MSI \n", PCIE_CAP_ID_MSI);
                    break;                
                    
                case PCIE_CAP_ID_COMPACTPCI_HOT_SWAP:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_COMPACTPCI_HOT_SWAP \n", PCIE_CAP_ID_COMPACTPCI_HOT_SWAP);
                    break;                

                case PCIE_CAP_ID_PCIX_DEVICE:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_PCIX_DEVICE \n", PCIE_CAP_ID_PCIX_DEVICE);
                    break;                

                case PCIE_CAP_ID_HYPER_TRANSPORT:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_HYPER_TRANSPORT \n", PCIE_CAP_ID_HYPER_TRANSPORT);
                    break;                
                
                case PCIE_CAP_ID_VENDOR_SPECIFIC:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_VENDOR_SPECIFIC \n", PCIE_CAP_ID_VENDOR_SPECIFIC);
                    break;  
                
                case PCIE_CAP_ID_DEBUG_PORT:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_DEBUG_PORT \n", PCIE_CAP_ID_DEBUG_PORT);
                    break;  
                
                case PCIE_CAP_ID_COMPACTPCI_CENTRAL_RESOURCE_CTRL:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_COMPACTPCI_CENTRAL_RESOURCE_CTRL \n", PCIE_CAP_ID_COMPACTPCI_CENTRAL_RESOURCE_CTRL);
                    break;  

                case PCIE_CAP_ID_PCI_HOT_PLUG:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_PCI_HOT_PLUG \n", PCIE_CAP_ID_PCI_HOT_PLUG);
                    break;  
                
                case PCIE_CAP_ID_PCI_BRIDGE_SUBSYSTEM_VENDOR_ID:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_PCI_BRIDGE_SUBSYSTEM_VENDOR_ID \n", PCIE_CAP_ID_PCI_BRIDGE_SUBSYSTEM_VENDOR_ID);
                    break;                      

                case PCIE_CAP_ID_PCI_EXPRESS:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_PCI_EXPRESS \n", PCIE_CAP_ID_PCI_EXPRESS);
                    break;  
                
                case PCIE_CAP_ID_MSIX:   
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_MSIX \n", PCIE_CAP_ID_MSIX);
                    capability_msix_t shadow;
                    pread(uio_config_fd, &shadow, sizeof(capability_msix_t), currentCapPtr);       
                    printf("\t PCIe MSIX Capability: MESSAGE CONTROL:   0x%X \n", shadow.messageControl);
                    printf("\t PCIe MSIX Capability: MSIX TABLE OFFSET: 0x%X \n", shadow.msixTableOffset);
                    printf("\t PCIe MSIX Capability: PBA OFFSET:        0x%X \n", shadow.pbaOffset);   
                    break;                       

                case PCIE_CAP_ID_SATA_DATA_INDEX:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_SATA_DATA_INDEX \n", PCIE_CAP_ID_SATA_DATA_INDEX);
                    break;  
                
                case PCIE_CAP_ID_ADVANCED_FEATURES:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_ADVANCED_FEATURES \n", PCIE_CAP_ID_ADVANCED_FEATURES);
                    break;  

                case PCIE_CAP_ID_ENHANCED_ALLOCATION_STRUCTURE:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAP_ID_ENHANCED_ALLOCATION_STRUCTURE \n", PCIE_CAP_ID_ENHANCED_ALLOCATION_STRUCTURE);
                    break;  
            }
            
            currentCapPtr = currentReg.nextCapPtr;
        }
    }  
    else
    {
        printf("WARNING: PCIe capability list not present! \n");
    }
}

void pcie_c::getPcieExtendedCapability(void)
{
    struct pcieExtendCapHeader_t
    {
            uint32_t capId           : 16;
            uint32_t capVersion      : 4;
            uint32_t nextCapOffset   : 12;
    };
    
    pcieExtendCapHeader_t currentHeader;
    uint32_t currentCapOffset = 0x100;
    
    pread(uio_config_fd, &currentHeader, sizeof(uint32_t), currentCapOffset);
    
    while(currentHeader.capId != PCIE_EXT_CAP_ID_NULL)
    {   
        switch(currentHeader.capId)
        {
            case PCIE_EXT_CAP_ID_AER:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_AER \n", PCIE_EXT_CAP_ID_AER);
                break;                
            
            case PCIE_EXT_CAP_ID_VC:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_VC\n", PCIE_EXT_CAP_ID_VC);
                break;                  

            case PCIE_EXT_CAP_ID_DEVICE_SERIAL_NUMBER:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_DEVICE_SERIAL_NUMBER\n", PCIE_EXT_CAP_ID_DEVICE_SERIAL_NUMBER);
                break;                
            
            case PCIE_EXT_CAP_ID_POWER_BUDGETING:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_POWER_BUDGETING\n", PCIE_EXT_CAP_ID_POWER_BUDGETING);
                break;         
                
            case PCIE_EXT_CAP_ID_RC_LINK_DECLARATION:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_RC_LINK_DECLARATION\n", PCIE_EXT_CAP_ID_RC_LINK_DECLARATION);
                break;                
            
            case PCIE_EXT_CAP_ID_PCIE_RC_INTERNAL_LINK_CONTROL:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_PCIE_RC_INTERNAL_LINK_CONTROL\n", PCIE_EXT_CAP_ID_PCIE_RC_INTERNAL_LINK_CONTROL);
                break;                  
            case PCIE_EXT_CAP_ID_RC_EVENT_COLLECTOR:
                printf("[%3X] ", currentCapOffset);;
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_RC_EVENT_COLLECTOR\n", PCIE_EXT_CAP_ID_RC_EVENT_COLLECTOR);
                break;                
            
            case PCIE_EXT_CAP_ID_MFVC:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_MFVC\n", PCIE_EXT_CAP_ID_MFVC);
                break;      
                
            case PCIE_EXT_CAP_ID_VIRTUAL_CHANNEL:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_VIRTUAL_CHANNEL\n", PCIE_EXT_CAP_ID_VIRTUAL_CHANNEL);
                break;                
            
            case PCIE_EXT_CAP_ID_RCRB_HEADER:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_RCRB_HEADER\n", PCIE_EXT_CAP_ID_RCRB_HEADER);
                break;    
                
            case PCIE_EXT_CAP_ID_VENDOR_SPECIFIC:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_VENDOR_SPECIFIC\n", PCIE_EXT_CAP_ID_VENDOR_SPECIFIC );
                break;                
            
            case PCIE_EXT_CAP_ID_ACS:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_ACS\n", PCIE_EXT_CAP_ID_ACS);
                break;                  
            case PCIE_EXT_CAP_ID_ARI:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_ARI\n", PCIE_EXT_CAP_ID_ARI);
                break;                
            
            case PCIE_EXT_CAP_ID_ATS:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_ATS\n", PCIE_EXT_CAP_ID_ATS);
                break;  
                
            case PCIE_EXT_CAP_ID_SRIOV:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_SRIOV\n", PCIE_EXT_CAP_ID_SRIOV);
                break;                
            
            case PCIE_EXT_CAP_ID_MULTICAST:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_MULTICAST\n", PCIE_EXT_CAP_ID_MULTICAST);
                break;   
                
            case PCIE_EXT_CAP_ID_PAGE_REQUEST:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_PAGE_REQUEST\n", PCIE_EXT_CAP_ID_PAGE_REQUEST);
                break;                
            
            case PCIE_EXT_CAP_ID_RESIZABLE_BAR:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_RESIZABLE_BAR\n", PCIE_EXT_CAP_ID_RESIZABLE_BAR );
                break;                 
            case PCIE_EXT_CAP_ID_DYNAMIC_POWER_ALLOCATION:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_DYNAMIC_POWER_ALLOCATION\n", PCIE_EXT_CAP_ID_DYNAMIC_POWER_ALLOCATION);
                break;                
            
            case PCIE_EXT_CAP_ID_TPH:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_TPH\n", PCIE_EXT_CAP_ID_TPH);
                break;  
                
            case PCIE_EXT_CAP_ID_LTR:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_LTR\n", PCIE_EXT_CAP_ID_LTR);
                break;                
            
            case PCIE_EXT_CAP_ID_SECONDARY_PCIE:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_SECONDARY_PCIE\n", PCIE_EXT_CAP_ID_SECONDARY_PCIE);
                break;     
                
            case PCIE_EXT_CAP_ID_PROTOCOL_MULTIPLEXING:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_PROTOCOL_MULTIPLEXING\n", PCIE_EXT_CAP_ID_PROTOCOL_MULTIPLEXING);
                break;                
            
            case PCIE_EXT_CAP_ID_PASID:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_PASID\n", PCIE_EXT_CAP_ID_PASID);
                break;    
                
            case PCIE_EXT_CAP_ID_LNR:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_LNR\n", PCIE_EXT_CAP_ID_LNR);
                break;                
            
            case PCIE_EXT_CAP_ID_DPC:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_DPC\n", PCIE_EXT_CAP_ID_DPC);
                break;                  

            case PCIE_EXT_CAP_ID_L1_PM_SUBSTATES:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_L1_PM_SUBSTATES\n", PCIE_EXT_CAP_ID_L1_PM_SUBSTATES);
                break; 
                
            case PCIE_EXT_CAP_ID_PRECISION_TIME_MEASUREMENT:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_PRECISION_TIME_MEASUREMENT\n", PCIE_EXT_CAP_ID_PRECISION_TIME_MEASUREMENT);
                break; 

            case PCIE_EXT_CAP_ID_MPCIE:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_MPCIE\n", PCIE_EXT_CAP_ID_MPCIE);
                break; 

            case PCIE_EXT_CAP_ID_FUNCTION_READINESS_STATUS:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_FUNCTION_READINESS_STATUS\n", PCIE_EXT_CAP_ID_FUNCTION_READINESS_STATUS);
                break; 

            case PCIE_EXT_CAP_ID_READINESS_TIME_REPORTING:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXT_CAP_ID_READINESS_TIME_REPORTING\n", PCIE_EXT_CAP_ID_READINESS_TIME_REPORTING);
                break; 
        }
        
        currentCapOffset = currentHeader.nextCapOffset;
        pread(uio_config_fd, &currentHeader, sizeof(uint32_t), currentHeader.nextCapOffset);
    } 
}

capability_msix_t pcie_c::getMsixCapability(void)
{
    uint8_t capPtr;
    uint8_t nextCapPtr;
    uint8_t capId;
    
    capability_msix_t shadow;
    memset(&shadow, 0, sizeof(capability_msix_t)); 
    
    pcieConfigurationHeader_t  configSpace;
    pread(uio_config_fd, &configSpace, sizeof(pcieConfigurationHeader_t), 0x0);    
        
    if(configSpace.dw1.status.capabilityList)
    {   
        nextCapPtr = configSpace.dw13.capPtr;            

        while(nextCapPtr != PCIE_EXT_CAP_ID_NULL)
        {
            capPtr = nextCapPtr;
            pread(uio_config_fd, &nextCapPtr, 1, (capPtr+0x1));
            pread(uio_config_fd, &capId, 1, capPtr);    
            
            if(capId == PCIE_CAP_ID_MSIX)
            {
                pread(uio_config_fd, &shadow, sizeof(capability_msix_t), capPtr);                    
            }
        }
    }  
    else
    {
        printf("WARNING: PCIe capability list not present! \n");
    }
 
    return shadow;
}

void pcie_c::enableMsixCapability(void)
{   
    uint8_t capPtr;
    uint8_t nextCapPtr;
    uint8_t capId;
    
    capability_msix_t shadow;
    memset(&shadow, 0, sizeof(capability_msix_t)); 
    
    pcieConfigurationHeader_t  configSpace;
    pread(uio_config_fd, &configSpace, sizeof(pcieConfigurationHeader_t), 0x0);    
        
    if(configSpace.dw1.status.capabilityList)
    {   
        nextCapPtr = configSpace.dw13.capPtr;            

        while(nextCapPtr != PCIE_EXT_CAP_ID_NULL)
        {
            capPtr = nextCapPtr;
            pread(uio_config_fd, &nextCapPtr, 1, (capPtr+0x1));
            pread(uio_config_fd, &capId, 1, capPtr);    
            
            if(capId == PCIE_CAP_ID_MSIX)
            {
                pread(uio_config_fd, &shadow, sizeof(capability_msix_t), capPtr);                    
                shadow.messageControl |= 0x8000; //set bit 15 of message control register (see 7.7.2.2 PCIe specification)
                //shadow.messageControl &= 0xFFFF7FFF; //clear bit 15 of message control register (see 7.7.2.2 PCIe specification)
                pwrite(uio_config_fd, &shadow, sizeof(capability_msix_t), capPtr);
            }
        }
    }  
    else
    {
        printf("WARNING: PCIe capability list not present! \n");
    } 
}

uint32_t pcie_c::getMsixCapabilityTableSize(void)
{   
    uint8_t capPtr;
    uint8_t nextCapPtr;
    uint8_t capId;
    uint32_t tableSize = 0;

    capability_msix_t shadow;
    memset(&shadow, 0, sizeof(capability_msix_t)); 
    
    pcieConfigurationHeader_t  configSpace;
    pread(uio_config_fd, &configSpace, sizeof(pcieConfigurationHeader_t), 0x0);    
        
    if(configSpace.dw1.status.capabilityList)
    {   
        nextCapPtr = configSpace.dw13.capPtr;            

        while(nextCapPtr != PCIE_EXT_CAP_ID_NULL)
        {
            capPtr = nextCapPtr;
            pread(uio_config_fd, &nextCapPtr, 1, (capPtr+0x1));
            pread(uio_config_fd, &capId, 1, capPtr);    
            
            if(capId == PCIE_CAP_ID_MSIX)
            {
                pread(uio_config_fd, &shadow, sizeof(capability_msix_t), capPtr);                    
                tableSize = (shadow.messageControl &= 0x000007FF); // mask bit 0-10 (see 7.7.2.2 PCIe specification)                
            }
        }
    }  
    else
    {
        printf("WARNING: PCIe capability list not present! \n");
    }
    
    return tableSize;
}
