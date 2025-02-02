#include "Wiimote.h"
Wiimote::Wiimote(){
    // Open Wiimote event file
    fd = open("/dev/input/event2", O_RDONLY);
    if (fd == -1)
    {
        std::cerr << "Error: Could not open event file - forgot sudo?\n";
        exit(1);
    } 
}
Wiimote::~Wiimote(){
    // Close Wiimote event file
    close(fd);
}
void Wiimote::Listen(){
    while (true)
    {
        // Read a packet of 32 bytes from Wiimote
        char buffer[32];
        read(fd, buffer, 32);

        // Extract code (byte 10) and value (byte 12) from packet
        int code = buffer[10];
        int value = buffer[12];
        Wiimote::ButtonEvent(code, value);
    }
}
void Wiimote::ButtonEvent(int code, int value){
    // Print them
    std::cout << "Code = " << code << ", value = " << value << '\n'; 
}