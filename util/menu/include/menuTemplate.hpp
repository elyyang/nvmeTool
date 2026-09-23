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
#include <stdio.h>

template <typename ITEM_TYPE, uint32_t MAX_NUM_OF_ITEMS>
class menuTemplate_c 
{
public:

    enum status_e
    {
        SUCCESS = 0,
        FAIL = 1        
    };
    
private:

    uint32_t    mItemCount;
    const char* mMenuDescription;
    ITEM_TYPE   mItems[MAX_NUM_OF_ITEMS];    
    const char* mItemDescription[MAX_NUM_OF_ITEMS]; 

public:

    menuTemplate_c()
    {
        mItemCount = 0;
        mMenuDescription = "(no description)";
    }
    
    ~menuTemplate_c()
    {}

    void addDescription(const char* description)
    {
        mMenuDescription = description;
    }
    
    status_e addItem(ITEM_TYPE item, const char* description)
    {
        if (mItemCount <= MAX_NUM_OF_ITEMS)
        {
            mItems[mItemCount] = item;            
            mItemDescription[mItemCount] = description;            
            mItemCount++;

            return SUCCESS;
        }
        else
        {
            return FAIL;
        }
    }

    void displayItems() const
    {
        for (uint32_t i=0; i<mItemCount; i++)
        {
            printf("(%d)-%-40s \n", (i+1), mItemDescription[i]);
        }
    }

    uint32_t getItemCount() const
    {
        return mItemCount;
    }

    const char* getDescription() const
    {
        return mMenuDescription;
    }

    ITEM_TYPE getItem(uint32_t index) const
    {
        return mItems[index];
    }

    const char* getItemDescription(uint32_t index) const
    {
        return mItemDescription[index];
    }
};
