
#pragma once

#include <stdio.h>
#include <stdarg.h>

#ifndef ENABLE_DEBUG_MSG
#define ENABLE_DEBUG_MSG (1)
#endif

#if ENABLE_DEBUG_MSG

#ifndef DEBUG_INFO_LEVELS
#define DEBUG_INFO_LEVELS   (3)
#endif

#ifndef DEBUG_SENSITIVITY
#define DEBUG_SENSITIVITY   (3)
#endif

#ifndef DEBUG_OUTPUT_METHOD
#define DEBUG_OUTPUT_METHOD (1)
#endif

/*
DEBUG_OUTPUT_METHOD
1 - standard printf
2 - convert msg to char array so we can pipe it to UART
default - convert to char array but dont print any message
*/
#if (DEBUG_OUTPUT_METHOD==1)
#define _printMsg(...)  printf(__VA_ARGS__)
#elif (DEBUG_OUTPUT_METHOD==2)
#define _printMsg(...)  char argString[256]; sprintf(argString, __VA_ARGS__); printf("%s", argString);
#else
#define _printMsg(...)  char argString[256]; sprintf(argString, __VA_ARGS__);
#endif

/*
DEBUG_INFO_LEVELS
1 - print tags with message 
2 - print tags with message with function and line number
3 - print tags with message with file name, function and line number
default - print message only
*/
#define _printTags(x)    if(x==0){_printMsg("[info] ");}          \
                        else if(x==1){_printMsg("[warning] ");}  \
                        else if(x==2){_printMsg("[error] ");}    \
                        else {}                                 \

#if (DEBUG_INFO_LEVELS==1) 
#define _formatMsg(tag, format, ...)       _printTags(tag) _printMsg(format"\n", __VA_ARGS__);
#elif (DEBUG_INFO_LEVELS==2)
#define _formatMsg(tag, format, ...)       _printTags(tag) _printMsg(format" | %s(line:%d)\n", __VA_ARGS__, __func__, __LINE__);
#elif (DEBUG_INFO_LEVELS==3)
#define _formatMsg(tag, format, ...)       _printTags(tag) _printMsg(format" | %s::%s(line:%d) " "\n", __VA_ARGS__, __FILE__, __func__, __LINE__);
#else
#define _formatMsg(tag, format, ...)       _printMsg(format"\n", __VA_ARGS__);
#endif

/*
DEBUG_SENSITIVITY
1 - only print errors
2 - only print warning and error
3 - print all types messages
default - dont print any message
*/
#if (DEBUG_SENSITIVITY==1)
#define DEBUG_PRINTF(tag, format, ...)    if(tag==2){_formatMsg(tag, format,  __VA_ARGS__) }
#elif (DEBUG_SENSITIVITY==2)
#define DEBUG_PRINTF(tag, format, ...)    if(tag==1||tag==2){_formatMsg(tag, format, __VA_ARGS__) }
#elif (DEBUG_SENSITIVITY==3)
#define DEBUG_PRINTF(tag, format, ...)    if(tag==0||tag==1||tag==2) {_formatMsg(tag, format, __VA_ARGS__) }
#else
#define DEBUG_PRINTF(tag, format, ...)    
#endif

#else   //ENABLE_DEBUG_MSG

#define DEBUG_PRINTF(tag, format, ...) 

#endif  //ENABLE_DEBUG_MSG