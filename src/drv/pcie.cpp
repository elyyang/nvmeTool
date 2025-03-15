
#include "pcie.h"
#include "assertLib.h"

//=========================================================================

pcie_c::pcie_c(void)
{
    printf("initialize pcie_c! \n");
    uio_config_fd = open("/sys/class/uio/uio0/device/config", O_RDWR | O_SYNC);    
    NVME_DBG_ASSERT((uio_config_fd>0), "uio_config_fd failed to open!")
}

pcie_c::~pcie_c(void)
{    
    printf("clean-up pcie_c! \n");
    close(uio_config_fd);    
}

//=========================================================================

pcie_c& pcie_c::getInstance(void)
{
    static pcie_c instance;
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
    return configSpace.status.bits.capabilityList;
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

    if(configSpace.status.bits.capabilityList)
    {   
        currentCapPtr = configSpace.capPtr;            

        while(currentCapPtr != 0x0)
        {            
            pread(uio_config_fd, &currentReg, sizeof(uint16_t), currentCapPtr);    
            
            switch(currentReg.capId)
            {
                case PCIE_CAPID_POWER_MANAGEMENT:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_POWER_MANAGEMENT \n", PCIE_CAPID_POWER_MANAGEMENT);
                    break;                
                    
                case PCIE_CAPID_VPD:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_VPD \n", PCIE_CAPID_VPD);
                    break;                

                case PCIE_CAPID_AGP:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_AGP \n", PCIE_CAPID_AGP);
                    break;                

                case PCIE_CAPID_SLOT_ID:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_SLOT_ID \n", PCIE_CAPID_SLOT_ID);
                    break;                

                case PCIE_CAPID_MSI:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_MSI \n", PCIE_CAPID_MSI);
                    break;                
                    
                case PCIE_CAPID_COMPACTPCI_HOT_SWAP:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_COMPACTPCI_HOT_SWAP \n", PCIE_CAPID_COMPACTPCI_HOT_SWAP);
                    break;                

                case PCIE_CAPID_PCIX_DEVICE:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_PCIX_DEVICE \n", PCIE_CAPID_PCIX_DEVICE);
                    break;                

                case PCIE_CAPID_HYPER_TRANSPORT:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_HYPER_TRANSPORT \n", PCIE_CAPID_HYPER_TRANSPORT);
                    break;                
                
                case PCIE_CAPID_VENDOR_SPECIFIC:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_VENDOR_SPECIFIC \n", PCIE_CAPID_VENDOR_SPECIFIC);
                    break;  
                
                case PCIE_CAPID_DEBUG_PORT:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_DEBUG_PORT \n", PCIE_CAPID_DEBUG_PORT);
                    break;  
                
                case PCIE_CAPID_COMPACTPCI_CENTRAL_RESOURCE_CTRL:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_COMPACTPCI_CENTRAL_RESOURCE_CTRL \n", PCIE_CAPID_COMPACTPCI_CENTRAL_RESOURCE_CTRL);
                    break;  

                case PCIE_CAPID_PCI_HOT_PLUG:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_PCI_HOT_PLUG \n", PCIE_CAPID_PCI_HOT_PLUG);
                    break;  
                
                case PCIE_CAPID_PCI_BRIDGE_SUBSYSTEM_VENDOR_ID:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_PCI_BRIDGE_SUBSYSTEM_VENDOR_ID \n", PCIE_CAPID_PCI_BRIDGE_SUBSYSTEM_VENDOR_ID);
                    break;                      

                case PCIE_CAPID_PCI_EXPRESS:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_PCI_EXPRESS \n", PCIE_CAPID_PCI_EXPRESS);
                    break;  
                
                case PCIE_CAPID_MSIX:   
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_MSIX \n", PCIE_CAPID_MSIX);
                    capability_msix_t shadow;
                    pread(uio_config_fd, &shadow, sizeof(capability_msix_t), currentCapPtr);       
                    printf("\t PCIe MSIX Capability: MESSAGE CONTROL:   0x%X \n", shadow.messageControl);
                    printf("\t PCIe MSIX Capability: MSIX TABLE OFFSET: 0x%X \n", shadow.msixTableOffset);
                    printf("\t PCIe MSIX Capability: PBA OFFSET:        0x%X \n", shadow.pbaOffset);   
                    break;                       

                case PCIE_CAPID_SATA_DATA_INDEX:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_SATA_DATA_INDEX \n", PCIE_CAPID_SATA_DATA_INDEX);
                    break;  
                
                case PCIE_CAPID_ADVANCED_FEATURES:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_ADVANCED_FEATURES \n", PCIE_CAPID_ADVANCED_FEATURES);
                    break;  

                case PCIE_CAPID_ENHANCED_ALLOCATION_STRUCTURE:
                    printf("[0x%X] ", currentCapPtr);
                    printf("Capability: 0x%X PCIE_CAPID_ENHANCED_ALLOCATION_STRUCTURE \n", PCIE_CAPID_ENHANCED_ALLOCATION_STRUCTURE);
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
    
    while(currentHeader.capId != PCIE_EXTCAPID_NULL)
    {   
        switch(currentHeader.capId)
        {
            case PCIE_EXTCAPID_AER:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_AER \n", PCIE_EXTCAPID_AER);
                break;                
            
            case PCIE_EXTCAPID_VC:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_VC\n", PCIE_EXTCAPID_VC);
                break;                  

            case PCIE_EXTCAPID_DEVICE_SERIAL_NUMBER:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_DEVICE_SERIAL_NUMBER\n", PCIE_EXTCAPID_DEVICE_SERIAL_NUMBER);
                break;                
            
            case PCIE_EXTCAPID_POWER_BUDGETING:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_POWER_BUDGETING\n", PCIE_EXTCAPID_POWER_BUDGETING);
                break;         
                
            case PCIE_EXTCAPID_RC_LINK_DECLARATION:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_RC_LINK_DECLARATION\n", PCIE_EXTCAPID_RC_LINK_DECLARATION);
                break;                
            
            case PCIE_EXTCAPID_PCIE_RC_INTERNAL_LINK_CONTROL:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_PCIE_RC_INTERNAL_LINK_CONTROL\n", PCIE_EXTCAPID_PCIE_RC_INTERNAL_LINK_CONTROL);
                break;                  
            case PCIE_EXTCAPID_RC_EVENT_COLLECTOR:
                printf("[%3X] ", currentCapOffset);;
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_RC_EVENT_COLLECTOR\n", PCIE_EXTCAPID_RC_EVENT_COLLECTOR);
                break;                
            
            case PCIE_EXTCAPID_MFVC:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_MFVC\n", PCIE_EXTCAPID_MFVC);
                break;      
                
            case PCIE_EXTCAPID_VIRTUAL_CHANNEL:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_VIRTUAL_CHANNEL\n", PCIE_EXTCAPID_VIRTUAL_CHANNEL);
                break;                
            
            case PCIE_EXTCAPID_RCRB_HEADER:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_RCRB_HEADER\n", PCIE_EXTCAPID_RCRB_HEADER);
                break;    
                
            case PCIE_EXTCAPID_VENDOR_SPECIFIC:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_VENDOR_SPECIFIC\n", PCIE_EXTCAPID_VENDOR_SPECIFIC );
                break;                
            
            case PCIE_EXTCAPID_ACS:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_ACS\n", PCIE_EXTCAPID_ACS);
                break;                  
            case PCIE_EXTCAPID_ARI:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_ARI\n", PCIE_EXTCAPID_ARI);
                break;                
            
            case PCIE_EXTCAPID_ATS:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_ATS\n", PCIE_EXTCAPID_ATS);
                break;  
                
            case PCIE_EXTCAPID_SRIOV:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_SRIOV\n", PCIE_EXTCAPID_SRIOV);
                break;                
            
            case PCIE_EXTCAPID_MULTICAST:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_MULTICAST\n", PCIE_EXTCAPID_MULTICAST);
                break;   
                
            case PCIE_EXTCAPID_PAGE_REQUEST:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_PAGE_REQUEST\n", PCIE_EXTCAPID_PAGE_REQUEST);
                break;                
            
            case PCIE_EXTCAPID_RESIZABLE_BAR:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_RESIZABLE_BAR\n", PCIE_EXTCAPID_RESIZABLE_BAR );
                break;                 
            case PCIE_EXTCAPID_DYNAMIC_POWER_ALLOCATION:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_DYNAMIC_POWER_ALLOCATION\n", PCIE_EXTCAPID_DYNAMIC_POWER_ALLOCATION);
                break;                
            
            case PCIE_EXTCAPID_TPH:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_TPH\n", PCIE_EXTCAPID_TPH);
                break;  
                
            case PCIE_EXTCAPID_LTR:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_LTR\n", PCIE_EXTCAPID_LTR);
                break;                
            
            case PCIE_EXTCAPID_SECONDARY_PCIE:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_SECONDARY_PCIE\n", PCIE_EXTCAPID_SECONDARY_PCIE);
                break;     
                
            case PCIE_EXTCAPID_PROTOCOL_MULTIPLEXING:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_PROTOCOL_MULTIPLEXING\n", PCIE_EXTCAPID_PROTOCOL_MULTIPLEXING);
                break;                
            
            case PCIE_EXTCAPID_PASID:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_PASID\n", PCIE_EXTCAPID_PASID);
                break;    
                
            case PCIE_EXTCAPID_LNR:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_LNR\n", PCIE_EXTCAPID_LNR);
                break;                
            
            case PCIE_EXTCAPID_DPC:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_DPC\n", PCIE_EXTCAPID_DPC);
                break;                  

            case PCIE_EXTCAPID_L1_PM_SUBSTATES:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_L1_PM_SUBSTATES\n", PCIE_EXTCAPID_L1_PM_SUBSTATES);
                break; 
                
            case PCIE_EXTCAPID_PRECISION_TIME_MEASUREMENT:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_PRECISION_TIME_MEASUREMENT\n", PCIE_EXTCAPID_PRECISION_TIME_MEASUREMENT);
                break; 

            case PCIE_EXTCAPID_MPCIE:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_MPCIE\n", PCIE_EXTCAPID_MPCIE);
                break; 

            case PCIE_EXTCAPID_FUNCTION_READINESS_STATUS:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_FUNCTION_READINESS_STATUS\n", PCIE_EXTCAPID_FUNCTION_READINESS_STATUS);
                break; 

            case PCIE_EXTCAPID_READINESS_TIME_REPORTING:
                printf("[%3X v%x] ", currentCapOffset, currentHeader.capVersion);
                printf("Ext Capability: 0x%X PCIE_EXTCAPID_READINESS_TIME_REPORTING\n", PCIE_EXTCAPID_READINESS_TIME_REPORTING);
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
        
    if(configSpace.status.bits.capabilityList)
    {   
        nextCapPtr = configSpace.capPtr;            

        while(nextCapPtr != PCIE_EXTCAPID_NULL)
        {
            capPtr = nextCapPtr;
            pread(uio_config_fd, &nextCapPtr, 1, (capPtr+0x1));
            pread(uio_config_fd, &capId, 1, capPtr);    
            
            if(capId == PCIE_CAPID_MSIX)
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
        
    if(configSpace.status.bits.capabilityList)
    {   
        nextCapPtr = configSpace.capPtr;            

        while(nextCapPtr != PCIE_EXTCAPID_NULL)
        {
            capPtr = nextCapPtr;
            pread(uio_config_fd, &nextCapPtr, 1, (capPtr+0x1));
            pread(uio_config_fd, &capId, 1, capPtr);    
            
            if(capId == PCIE_CAPID_MSIX)
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
        
    if(configSpace.status.bits.capabilityList)
    {   
        nextCapPtr = configSpace.capPtr;            

        while(nextCapPtr != PCIE_EXTCAPID_NULL)
        {
            capPtr = nextCapPtr;
            pread(uio_config_fd, &nextCapPtr, 1, (capPtr+0x1));
            pread(uio_config_fd, &capId, 1, capPtr);    
            
            if(capId == PCIE_CAPID_MSIX)
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
