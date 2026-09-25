# NVMe Tool Kit #

_  ___   ____  __    _____         _ _  ___ _   
| \| \ \ / /  \/  |__|_   _|__  ___| | |/ (_) |_ 
| .` |\ V /| |\/| / -_)| |/ _ \/ _ \ | ' <| |  _|
|_|\_| \_/ |_|  |_\___||_|\___/\___/_|_|\_\_|\__|


-------------------------------------------------

## Getting started

### bind uio driver to nvme device

  $ sudo ./scripts/setup.sh 
  or
  $ sudo ./scripts/setup.sh config

### setup udma driver

  $ sudo ./scripts/setup_udma.sh 

### build

  $ sudo make

### run

  $ sudo ./build/nvmeTool

### reset

  $ sudo ./scripts/setup.sh reset
  $ sudo ./scripts/setup_udma.sh reset

--------------------------------------------------

## Troubleshoot

### module fail to build

error message: 
* "ERROR: Kernel configuration is invalid. include/generated/autoconf.h or include/config/auto.conf are missing. Run 'make oldconfig && make prepare' on kernel src to fix it."

solution:
* re-install linux-headers:
* shell$ sudo apt install --reinstall linux-headers-$(uname -r)

### device fail to bind

error message:
* uio_resource0_fd failed to open!

solution:
* run binary as superuser
* shell$ sudo ./build/nvmeTool



ELY 2026
