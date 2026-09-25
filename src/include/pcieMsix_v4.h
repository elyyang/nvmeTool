/********************************************************************************************
*  _  ___   ____  __    _____         _ _  ___ _   
* | \| \ \ / /  \/  |__|_   _|__  ___| | |/ (_) |_ 
* | .` |\ V /| |\/| / -_)| |/ _ \/ _ \ | ' <| |  _|
* |_|\_| \_/ |_|  |_\___||_|\___/\___/_|_|\_\_|\__|
*                                                              
* MIT License
* 
* Copyright (c) 2026 Eric L. Yang
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* 
* https://github.com/elyyang
* elyyang@gmail.com
*
*********************************************************************************************/

#pragma once

#include <stdint.h>

#ifndef __cplusplus
    #if !defined(static_assert)
        #define static_assert _Static_assert
    #endif
#endif // __cplusplus

/********************************************************************
NCB-PCI_Express_Base_4.0r1.0_September-27-2017-c
7.7.2.5 Message Address Register for MSI-X Table Entries
7.7.2.6 Message Upper Address Register for MSI-X Table Entries
7.7.2.7 Message Data Register for MSI-X Table Entries
7.7.2.8 Vector Control Register for MSI-X Table Entries
********************************************************************/

#define MSIX_ENTRY_SIZE                      (0x10)

typedef struct __attribute__((packed, aligned (4))) msix_t
{
    volatile uint32_t MXTMLA;
    volatile uint32_t MXTMUA;
    volatile uint32_t MXTMD;
    
    union
    {
        volatile struct
        {
            uint16_t maskBit     :1;
            uint16_t reserved    :15;
            uint16_t stLower     :8;
            uint16_t stUpper     :8;
        };

        volatile uint32_t all;
    }MXTVC;
}
msix_t;
static_assert(sizeof(msix_t) == MSIX_ENTRY_SIZE, "msix_t size incorrect");
