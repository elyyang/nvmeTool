/********************************************************************************************
*  ________  _____   ____  ____ 
* |_   __  ||_   _| |_  _||_  _|
*   | |_ \_|  | |     \ \  / /  
*   |  _| _   | |   _  \ \/ /   
*  _| |__/ | _| |__/ | _|  |_   
* |________||________||______|        
* 
* NVMe test tool 2.0
* https://github.com/elyyang
* elyyang@gmail.com
*********************************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 

#include "menu.h"

int g_uioId= 0;

int main(int argc, char* argv[])
{  
  if((argc>1)&&(argv[1]!=NULL))
  { 
    g_uioId = atoi(argv[1]);
  }  

  menuBuilder();

  printf("NVMe Tool all done! \n");
  return 0;
}
