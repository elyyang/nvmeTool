/* *******************************************
*   _______  ___       ___  ___       
*  /"     "||"  |     |"  \/"  |      
* (: ______)||  |      \   \  /       
*  \/    |  |:  |       \\  \/        
*  // ___)_  \  |___    /   /         
* (:      "|( \_|:  \  /   /          
*  \_______) \_______)|___/           
*
* https://github.com/elyyang
******************************************* */

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
