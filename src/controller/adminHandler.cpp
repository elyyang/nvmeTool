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

#include "adminHandler.h"

admin_c::admin_c(void)
{
}

admin_c::~admin_c(void)    
{	
}

admin_c& admin_c::getInstance(void)
{
    static admin_c mInstance;
    return mInstance;
}