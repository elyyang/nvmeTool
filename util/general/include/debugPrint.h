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

#include <stdio.h>
#include <stdarg.h>

#ifndef ENABLE_DEBUG_MSG
#define ENABLE_DEBUG_MSG    (1)
#endif

#ifndef DEBUG_INFO_LEVELS
#define DEBUG_INFO_LEVELS   (1)
#endif

#ifndef DEBUG_SENSITIVITY
#define DEBUG_SENSITIVITY   (3)
#endif

#ifndef DEBUG_OUTPUT_METHOD
#define DEBUG_OUTPUT_METHOD (1)
#endif

#if ENABLE_DEBUG_MSG
/*
DEBUG_OUTPUT_METHOD
1 - standard printf
2 - convert msg to char array so we can pipe it to UART
default - convert to char array but dont print any message
*/
#if (DEBUG_OUTPUT_METHOD==1)
#define _printMsg(...)                  printf(__VA_ARGS__);
#elif (DEBUG_OUTPUT_METHOD==2)
#define _printMsg(...)                  char argString[256]; sprintf(argString, __VA_ARGS__); printf("%s", argString);
#else
#define _printMsg(...)                  char argString[256]; sprintf(argString, __VA_ARGS__);
#endif

/*
DEBUG_INFO_LEVELS
1 - print tags with message 
2 - print tags with message with function and line number
3 - print tags with message with file name, function and line number
default - print message only
*/
#if (DEBUG_INFO_LEVELS==1) 
#define _formatMsg(tag, msg, ...)       _printTags(tag) _printMsg(msg "\n", ##__VA_ARGS__)
#elif (DEBUG_INFO_LEVELS==2)
#define _formatMsg(tag, msg, ...)       _printTags(tag) _printMsg("[%s](%d) " msg "\n", __func__, __LINE__, ##__VA_ARGS__)
#elif (DEBUG_INFO_LEVELS==3)
#define _formatMsg(tag, msg, ...)       _printTags(tag) _printMsg("[%s::%s](%d) " msg "\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#else
#define _formatMsg(tag, msg, ...)                       _printMsg(msg "\n", ##__VA_ARGS__)
#endif

/*
DEBUG_SENSITIVITY
1 - only print errors
2 - only print warning and error
3 - print all types messages
default - dont print any message
*/
#if (DEBUG_SENSITIVITY==1)
#define NVME_DBG_PRINTF(tag, msg, ...)    if(tag==2)                   {_formatMsg(tag, msg, ##__VA_ARGS__)}
#elif (DEBUG_SENSITIVITY==2)
#define NVME_DBG_PRINTF(tag, msg, ...)    if(tag==1||tag==2)           {_formatMsg(tag, msg, ##__VA_ARGS__)}
#elif (DEBUG_SENSITIVITY==3)
#define NVME_DBG_PRINTF(tag, msg, ...)    if(tag==0||tag==1||tag==2)   {_formatMsg(tag, msg, ##__VA_ARGS__)}
#else
#define NVME_DBG_PRINTF(tag, msg, ...)    
#endif

//Helpers
#define _printTags(x)   if(x==0)     {_printMsg("[info]   ");}  \
                        else if(x==1){_printMsg("[warning]");}  \
                        else if(x==2){_printMsg("[error]  ");}  \
                        else {}                                 \

enum msgTag_e {
    info = 0,
    warning = 1,
    error = 2
};

#else   //ENABLE_DEBUG_MSG

#define NVME_DBG_PRINTF(tag, msg, ...) 

#endif  //ENABLE_DEBUG_MSG