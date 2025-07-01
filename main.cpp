
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
  (void)uioId;

  demo();

  printf("NVMe 2.0 Tool All done! \n");
  return 0;
}
