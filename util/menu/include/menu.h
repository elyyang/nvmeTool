
#pragma once

#include <stdint.h>
#include <stdarg.h>
#include "menuTemplate.hpp"

class menu_c
{
    public:

        #define CONSOLE_PRINT(...)   printf(__VA_ARGS__);
        #define CONSOLE_GET          getchar();

        #define MAX_TESTS_PER_MENU  (15)
        #define MAX_TEST_CATEGORIES (10)

        typedef void(*pTestfunction)(void);
        typedef menuTemplate_c<pTestfunction, MAX_TESTS_PER_MENU> subMenu;   
        typedef menuTemplate_c<subMenu, MAX_TEST_CATEGORIES> mainMenu; 

    private:

        enum states_e
        {
            MAIN_MENU_STATE = 1,
            SUB_MENU_STATE  = 2
        };

        states_e mCurrentState;
        bool mRun;
        uint32_t mCurrentMenuIndex;
        uint32_t mCurrentSubMenuIndex;        
        pTestfunction mCurrentTestFunction_p;

        mainMenu mProject;

        void displayMenuTree();
        void displayMainMenuItems();
        void displayCurrentSubMenuItems();
        void displayPrompt();
        void displayBorder();
        void displayInnerBorder();
        void clearOutput();
        void execute();

    public:
        
        menu_c();
        ~menu_c();       
  
        void build(mainMenu project);
        void run();
};