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

    virtual int AccelerationEvent(int code, short value);

};

#endif
