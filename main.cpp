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

#include "example.h"

int main(int argc, char* argv[])
{
  int uioId = 0;
  if((argc>1)&&(argv[1]!=NULL))
  { 
    uioId = atoi(argv[1]);
  }  

  demo(uioId);

  printf("NVMe Tool all done! \n");
  return 0;
}
