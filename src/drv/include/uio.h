
#pragma once

#include <stdint.h>

class uio_c
{
    private:

        uio_c();        
        ~uio_c();

    public:

        static uio_c& getInstance();

};
