
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
