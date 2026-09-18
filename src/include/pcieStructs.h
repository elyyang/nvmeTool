/********************************************************************************************
*  ________  _____   ____  ____ 
* |_   __  ||_   _| |_  _||_  _|
*   | |_ \_|  | |     \ \  / /  
*   |  _| _   | |   _  \ \/ /   
*  _| |__/ | _| |__/ | _|  |_   
* |________||________||______|        
* 
* NVMe test tool 2.0
* https://github.com/elyyang
* elyyang@gmail.com
*********************************************************************************************/

#pragma once

#ifndef PCIE_GEN_SUPPORTED
#define PCIE_GEN_SUPPORTED (4)
#endif

#if (PCIE_GEN_SUPPORTED==4)

#include "pcieConfigHeader_g4.h"
#include "pcieCapability_g4.h"

#else 

#error "unsupported pcie generation"

#endif
