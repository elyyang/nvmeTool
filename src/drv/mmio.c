
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

typedef struct 
{
    int pfBar0_fd;
    void* pfBar0Addr;
    void* pfBar0AddrPageTwo;
}pfvfSettings_t; 

static pfvfSettings_t pfvfSettings_g;

void mmioInit(void)
{    
    pfvfSettings_g.pfBar0_fd = open("/sys/class/uio/uio0/device/resource0", O_RDWR | O_SYNC);    
    pfvfSettings_g.pfBar0Addr = mmap(NULL, 0x4000, PROT_READ | PROT_WRITE, MAP_SHARED, pfvfSettings_g.pfBar0_fd, 0);
    pfvfSettings_g.pfBar0AddrPageTwo = mmap(NULL, 0x1000, PROT_READ | PROT_WRITE, MAP_SHARED, pfvfSettings_g.pfBar0_fd, 0x1000); 
}

void mmioCleanup(void)
{
    close(pfvfSettings_g.pfBar0_fd);    
    munmap(pfvfSettings_g.pfBar0Addr, 0x4000);      
    munmap(pfvfSettings_g.pfBar0AddrPageTwo, 0x1000);      
}
