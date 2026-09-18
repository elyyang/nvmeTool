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