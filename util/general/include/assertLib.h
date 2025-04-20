
#pragma once

#include <stdio.h>
#include <stdarg.h>

// user defined assert options

#ifndef ENABLE_NVME_DBG_ASSERT
#define ENABLE_NVME_DBG_ASSERT              (1)
#endif

#ifndef NVME_DBG_ASSERT_NOTIFICATION_OPTION
#define NVME_DBG_ASSERT_NOTIFICATION_OPTION (1)
#endif

#ifndef NVME_DBG_ASSERT_ACTION_OPTION
#define NVME_DBG_ASSERT_ACTION_OPTION       (2)
#endif

#if ENABLE_NVME_DBG_ASSERT

#define NVME_DBG_ASSERT(condition, message)                              _assert_condition((!condition), message)
#define NVME_DBG_ASSERT_IF_TRUE(condition, message)                      _assert_condition((condition), message)
#define NVME_DBG_ASSERT_IF_EQUAL(actual, expected, message)              _assert_condition((actual==expected), message)
#define NVME_DBG_ASSERT_IF_NOT_EQUAL(actual, expected, message)          _assert_condition((actual!=expected), message)
#define NVME_DBG_ASSERT_IF_GREATER_THAN(actual, threshold, message)      _assert_condition((actual>threshold), message)
#define NVME_DBG_ASSERT_IF_LESSER_THAN(actual, threshold, message)       _assert_condition((actual<threshold), message)
#define NVME_DBG_ASSERT_IF_GREATER_OR_EQUAL(actual, threshold, message)  _assert_condition((actual>=threshold), message)
#define NVME_DBG_ASSERT_IF_LESSER_OR_EQUAL(actual, threshold, message)   _assert_condition((actual<=threshold), message)

// assert condition
#define _assert_condition(condition, message) \
do{                                           \
    if (condition)                            \
    {                                         \
        _assert_notification(message)         \
        _assert_action                        \
    }                                         \
}while(0);

/*
options for assert notification
1. printf message
2. uart message 
default no message 
*/

// assert notification
#define _assert_msg_format                  ("[NVM DBG ASSERT] [%s:%s:(%.3d)]: (%s) \n")

#if (NVME_DBG_ASSERT_NOTIFICATION_OPTION==1)
#define _assert_notification(message)       printf(_assert_msg_format, __FILE__, __FUNCTION__, __LINE__, message);
#elif (NVME_DBG_ASSERT_NOTIFICATION_OPTION==2)
#define _assert_notification(message)       char argString[256]; sprintf(argString, _assert_msg_format, __FILE__, __FUNCTION__, __LINE__, message); printf("%s", argString);
#else
#define _assert_notification(message)
#endif

/*
option for assert action 
1. hang (while 1)
2. exit program (with stdlib) 
default no action
*/

// assert action
#if(NVME_DBG_ASSERT_ACTION_OPTION==1)
#define _assert_action                      while(1);
#elif(NVME_DBG_ASSERT_ACTION_OPTION==2)
#define _assert_action                      _exit(1);
#else
#define _assert_action                      
#endif

#else   //ENABLE_NVME_DBG_ASSERT

#define NVME_DBG_ASSERT(condition, message)                              
#define NVME_DBG_ASSERT_IF_TRUE(condition, message)                      
#define NVME_DBG_ASSERT_IF_EQUAL(actual, expected, message)              
#define NVME_DBG_ASSERT_IF_NOT_EQUAL(actual, expected, message)          
#define NVME_DBG_ASSERT_IF_GREATER_THAN(actual, threshold, message)      
#define NVME_DBG_ASSERT_IF_LESSER_THAN(actual, threshold, message)       
#define NVME_DBG_ASSERT_IF_GREATER_OR_EQUAL(actual, threshold, message)  
#define NVME_DBG_ASSERT_IF_LESSER_OR_EQUAL(actual, threshold, message)   

#endif  //ENABLE_NVME_DBG_ASSERT