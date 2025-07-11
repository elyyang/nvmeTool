
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