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

static inline void regWrite64Bit(const uintptr_t address, const uint64_t value)
{
    *(volatile uint64_t*)(address) = value;
}

static inline uint64_t regRead64Bit(const uintptr_t address)
{
    return *(volatile uint64_t*)(address);
}

static inline void regWrite32Bit(const uintptr_t address, const uint32_t value)
{
    *(volatile uint32_t*)(address) = value;
}

static inline uint32_t regRead32Bit(const uintptr_t address)
{
    return *(volatile uint32_t*)(address);
}

static inline void regWrite16Bit(const uintptr_t address, const uint16_t value)
{
    *(volatile uint16_t*)(address) = value;
}

static inline uint16_t regRead16Bit(const uintptr_t address)
{
    return *(volatile uint16_t*)(address);
}

static inline void regWrite8Bit(const uintptr_t address, const uint8_t value)
{
    *(volatile uint8_t*)(address) = value;
}

static inline uint8_t regRead8Bit(const uintptr_t address)
{
    return *(volatile uint8_t*)(address);
}
