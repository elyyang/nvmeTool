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

#ifndef NVME_VERSION_SUPPORTED
#define NVME_VERSION_SUPPORTED (14)
#endif

#if (NVME_VERSION_SUPPORTED==14)

#include "nvmeStructs_v14.h"

#elif (NVME_VERSION_SUPPORTED==22)


#else 

#error "unsupported nvme version"

#endif
