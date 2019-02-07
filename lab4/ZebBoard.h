#ifndef ZEDBOARD_H
#define ZEDBOARD_H

#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cmath>
#include <unistd.h>

class ZedBoard{
      char *ptr;
      int fd;
public:
       ZedBoard(int *fd,unsigned gpio_size,unsigned gpio_address);

       ~ZedBoard();

       void RegisterWrite(int offset, int value);

       int RegisterRead(int offset);

};
#endif