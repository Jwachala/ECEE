#include "Wiimote.h"
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
Wiimote::Wiimote() {

    // Open Wiimote event file

    fd = open("/dev/input/event0", O_RDONLY);

    if (fd == -1)

    {

        std::cerr << "Error: Could not open event file - forgot sudo?\n";

        exit(1);
    }
}

Wiimote::~Wiimote() {

    // Close Wiimote event file

    close(fd);
}

void Wiimote::Listen() {
    auto start_check = std::chrono::system_clock::now();
    int lastSinceEpoch = start_check.time_since_epoch().count();
    int count = 0;
    int lastTenBeats[10] = {60, 60, 60, 60, 60, 60, 60, 60, 60, 60};
    double bpm = 60;
    while (true) {

        // Read a packet of 32 bytes from Wiimote

        char buffer[32];

        read(fd, buffer, 32);

        // Extract code (byte 10) and value (byte 12) from packet

        int code = buffer[10];

        short acceleration = *(short *)(buffer + 12);

        int hitDetected = this->AccelerationEvent(code, acceleration);
        if (hitDetected > 470) {
            auto now = std::chrono::system_clock::now();
            int nowSinceEpoch = now.time_since_epoch().count();
            std::chrono::duration<double> elapsed_seconds = now - start_check;
            if (elapsed_seconds.count() > .2) {
                std::cout << "beat!" << '\n';
                start_check = std::chrono::system_clock::now();
                // set bpm here
                int period_microsec = nowSinceEpoch - lastSinceEpoch;
                double period_sec = period_microsec / 1000000.0;
                std::cout << period_sec << '\n';
                bpm = (60 / period_sec) * 4;
                std::cout << bpm << '\n';
                if (count > 0) {
                    std::ofstream myfile;
                    myfile.open("bpm.txt");
                    myfile << bpm;
                    myfile.close();
                }
                lastSinceEpoch = nowSinceEpoch;
                count++;
            }
        }
    }
}

int Wiimote::AccelerationEvent(int code, short value) {

    // Print them

    std::cout << "Code = " << code << ", Acceleration = " << value << '\n';
    return -1;
}
