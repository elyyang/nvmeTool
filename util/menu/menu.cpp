
#include "menu.h"
#include "assertLib.h"
#include <stdio.h>
#include "example.h"

menu_c::subMenu pcieUtil_subMenu;
menu_c::subMenu nvmeUtil_subMenu;
menu_c::subMenu tests_subMenu;
menu_c::mainMenu nvmeTool_mainMenu;
menu_c nvmeToolMenu;

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
    displayBorder();
    CONSOLE_PRINT("[%s Menu Tree] \n", mProject.getDescription());
    displayInnerBorder();
    for (uint32_t i=0; i<mProject.getItemCount(); i++)
    {
        CONSOLE_PRINT("(%d)-%-40s \n", (i+1), mProject.getItemDescription(i));

        for (uint32_t j=0; j<mProject.getItem(i).getItemCount(); j++)
        {
            CONSOLE_PRINT("|____(%d)-%-40s \n", (j+1), mProject.getItem(i).getItemDescription(j));
        }
    }
    displayBorder();    
    displayPrompt();    
}

void menu_c::displayMainMenuItems()
{
    CONSOLE_PRINT("\n\n")
    displayBorder();
    CONSOLE_PRINT("[Main Menu] (%s) \n", mProject.getDescription());        
    displayInnerBorder();
    mProject.displayItems();
    displayBorder();    
    displayPrompt();
}

void menu_c::displayCurrentSubMenuItems()
{
    CONSOLE_PRINT("\n\n")
    displayBorder();
    CONSOLE_PRINT("[Sub Menu] (%s) \n", mProject.getItem(mCurrentMenuIndex).getDescription());        
    displayInnerBorder();
    mProject.getItem(mCurrentMenuIndex).displayItems();
    displayBorder();
    
    displayPrompt();
}

void menu_c::displayPrompt()
{
    CONSOLE_PRINT("(q)uit, return to (m)ain men, menu (t)ree | selection: ");
}

void menu_c::displayBorder()
{
    CONSOLE_PRINT("==================================================\n");
}

void menu_c::displayInnerBorder()
{
    CONSOLE_PRINT("--------------------------------------------------\n");
}

void menu_c::clearOutput()
{
    CONSOLE_PRINT("\e[1;1H\e[2J");
}

void menu_c::execute()
{
    clearOutput();

    displayBorder();
    CONSOLE_PRINT("[Test Output] (%s) \n", mProject.getItem(mCurrentMenuIndex).getItemDescription(mCurrentSubMenuIndex));
    displayInnerBorder();
    (mCurrentTestFunction_p)(); //execute function
    displayBorder();
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

void nvmeToolMenuBuilder(void)
{
    pcieUtil_subMenu.addDescription("PCIe utilities");
    nvmeUtil_subMenu.addDescription("NVMe utilities");
    tests_subMenu.addDescription("tests");
    tests_subMenu.addItem(demo_uio, "a brief demo on uio_c driver...");

    nvmeTool_mainMenu.addDescription("NVMe tools");
    nvmeTool_mainMenu.addItem(pcieUtil_subMenu, "PCIe utilities");
    nvmeTool_mainMenu.addItem(nvmeUtil_subMenu, "NVMe utilities");
    nvmeTool_mainMenu.addItem(tests_subMenu,    "tests");

    nvmeToolMenu.build(nvmeTool_mainMenu);
    nvmeToolMenu.run();
}