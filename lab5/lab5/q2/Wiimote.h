#ifndef WIIMOTE_H
#define WIIMOTE_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
class Wiimote{
    int fd;
public:
    Wiimote();
    ~Wiimote();
    void Listen();
    void ButtonEvent(int code, int value);
};
#endif