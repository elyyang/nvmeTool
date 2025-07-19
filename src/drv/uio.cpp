
#include "uio.h"
#include "assertLib.h"
#include "debugPrint.h"

//=========================================================================

uio_c::uio_c()
{
}

uio_c::~uio_c()
{        
}

uio_c& uio_c::getInstance()
{
    static uio_c mInstance;
    return mInstance;
}