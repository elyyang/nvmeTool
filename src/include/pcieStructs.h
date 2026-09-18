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

#ifndef PCIE_GEN_SUPPORTED
#define PCIE_GEN_SUPPORTED (4)
#endif

#if (PCIE_GEN_SUPPORTED==4)

#include "pcieConfigHeader_g4.h"
#include "pcieCapability_g4.h"

#else 

#error "unsupported pcie generation"

#endif
