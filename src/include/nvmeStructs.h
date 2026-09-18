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

#ifndef NVME_VERSION_SUPPORTED
#define NVME_VERSION_SUPPORTED (14)
#endif

#if (NVME_VERSION_SUPPORTED==14)

#include "nvmeStructs_v14.h"

#elif (NVME_VERSION_SUPPORTED==22)

#elif (NVME_VERSION_SUPPORTED==24)

#else 

#error "unsupported nvme version"

#endif
