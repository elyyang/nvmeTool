
#include "menu.h"
#include "assertLib.h"
#include <stdio.h>

menu_c::menu_c()
{
    mRun = true;
    mCurrentMenuIndex = 0;
    mCurrentSubMenuIndex = 0;
    mCurrentState = MAIN_MENU_STATE;
}

menu_c::~menu_c()
{
}

void menu_c::build(mainMenu project)
{
    mProject = project;
}

void menu_c::displayMenuTree()
{
    CONSOLE_PRINT("\n\n")
    CONSOLE_PRINT("==================================================\n");
    CONSOLE_PRINT("[%s Menu Tree] \n", mProject.getDescription());
    CONSOLE_PRINT("--------------------------------------------------\n");
    for (uint32_t i=0; i<mProject.getItemCount(); i++)
    {
        CONSOLE_PRINT("(%d)-%-40s \n", (i+1), mProject.getItemDescription(i));

        for (uint32_t j=0; j<mProject.getItem(i).getItemCount(); j++)
        {
            CONSOLE_PRINT("|____(%d)-%-40s \n", (j+1), mProject.getItem(i).getItemDescription(j));
        }
    }
    CONSOLE_PRINT("==================================================\n");
    
    displayPrompt();    
}

void menu_c::displayMainMenuItems()
{
    CONSOLE_PRINT("\n\n")
    CONSOLE_PRINT("==================================================\n");
    CONSOLE_PRINT("[Main Menu] (%s) \n", mProject.getDescription());        
    CONSOLE_PRINT("--------------------------------------------------\n");
    mProject.displayItems();
    CONSOLE_PRINT("==================================================\n");
    
    displayPrompt();
}

void menu_c::displayCurrentSubMenuItems()
{
    CONSOLE_PRINT("\n\n")
    CONSOLE_PRINT("==================================================\n");
    CONSOLE_PRINT("[Sub Menu] (%s) \n", mProject.getItem(mCurrentMenuIndex).getDescription());        
    CONSOLE_PRINT("--------------------------------------------------\n");
    mProject.getItem(mCurrentMenuIndex).displayItems();
    CONSOLE_PRINT("==================================================\n");
    
    displayPrompt();
}

void menu_c::displayPrompt()
{
    CONSOLE_PRINT("(q)uit, return to (m)ain men, menu (t)ree | selection: ");
}

void menu_c::clearOutput()
{
    CONSOLE_PRINT("\e[1;1H\e[2J");
}

void menu_c::execute()
{
    clearOutput();

    CONSOLE_PRINT("==================================================\n");
    CONSOLE_PRINT("[Test Output] (%s) \n", mProject.getItem(mCurrentMenuIndex).getItemDescription(mCurrentSubMenuIndex));
    CONSOLE_PRINT("--------------------------------------------------\n\n");
    (mCurrentTestFunction_p)(); //execute function
    CONSOLE_PRINT("\n==================================================\n");    
}

void menu_c::run()
{    
    displayMainMenuItems();    

    while (mRun)
    {
        char choice = CONSOLE_GET
        
        if (choice == 'q') //note: quit
        {            
            mRun = false;
        }
        else if (choice == 'm') //note: 'm' returns to main menu
        {
            mCurrentState = MAIN_MENU_STATE;             
        }
        else if (choice == 't')
        {
            displayMenuTree();
        }
        else if (choice == '\n') //note: '\n' displays current menu
        {
            if (mCurrentState == MAIN_MENU_STATE)
            {
                displayMainMenuItems();
            }
            else if (mCurrentState == SUB_MENU_STATE)
            {
                displayCurrentSubMenuItems();
            }
            else
            {
                NVME_DBG_ASSERT(0, "incorrect menu state!")
            }
        }
        else if (choice > '0' && choice <= '9')
        {            
            int userInput = (int)(choice - '0'); //convert char to int

            if (mCurrentState == MAIN_MENU_STATE)
            {  
                //execute if valid selection in main menu state
                if((userInput>0) && (userInput<=(int)mProject.getItemCount()))
                {
                    mCurrentMenuIndex = (userInput-1); //user input is 1-based
                    mCurrentState = SUB_MENU_STATE;
                }
            }
            else if (mCurrentState == SUB_MENU_STATE)
            {                
                //execute if valid selection in sub menu state
                if((userInput>0) && (userInput<=(int)mProject.getItem(mCurrentMenuIndex).getItemCount()))
                {
                    mCurrentSubMenuIndex = (userInput-1); //user input is 1-based
                    mCurrentTestFunction_p = mProject.getItem(mCurrentMenuIndex).getItem(mCurrentSubMenuIndex);
                    
                    execute();
                }
            }
            else
            {
                NVME_DBG_ASSERT(0, "incorrect menu state!")
            }
        }
    }
}
