#include "ZedBoard.h"


       ZedBoard::ZedBoard(){
           fd = open("/dev/mem", O_RDWR);
           ptr = (char *)mmap(NULL, gpio_size, PROT_READ | PROT_WRITE, MAP_SHARED,fd, gpio_address);
           
       }
       ZedBoard::~ZedBoard(){
           munmap(ptr, gpio_size);
           close(fd);
       }
       void ZedBoard::RegisterWrite(int offset, int value){
            *(int *)(ptr + offset) = value;
       }
       int ZedBoard::RegisterRead(int offset){
           return *(int *)(ptr + offset);
       }
