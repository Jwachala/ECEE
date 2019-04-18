#include "Wiimote.h"

#include "ZedBoard.h"
#include <iostream>
class WiimoteToLed : public Wiimote {

    ZedBoard *ptr;

  public:
    WiimoteToLed(ZedBoard *ptr) : Wiimote() { this->ptr = ptr; }

    int AccelerationEvent(int code, short acceleration) {

        if (code != 3) {

            return -1;
        }

        if (acceleration > 1000) {

            acceleration = 1000;

        } else if (acceleration < -1000) {

            acceleration = -1000;
        }
        short absAccel = abs(acceleration);
        /* return absAccel;
        if(absAccel > 450){
            //std::cout << absAccel << '\n';
            
        } else{
            return 0;
        }
        absAccel *= 8;
        absAccel /= 500;

        for (int i = 0; i < absAccel; i++) {
            ptr->setLed(i, 1);

            // ptr.RegisterWrite(gpio_led1_offset+4*absAccel-4,1);
        }

        for (int i = 8; i > absAccel; i--) {
            ptr->setLed(i, 0);
            // ptr.RegisterWrite(gpio_led1_offset+4*absAccel-4,0);
        } */
    }
};

int main()

{

    // Instantiate ZedBoard object statically

    ZedBoard zed_board;

    // Instantiate WiimoteToLed object statically, passing a pointer to the

    // recently created ZedBoard object.

    WiimoteToLed wiimote_to_led(&zed_board);

    // Enter infinite loop listening to events. The overridden function

    // WiimoteToLed::AccelerationEvent() will be invoked when the user moves

    // the Wiimote.

    wiimote_to_led.Listen();

    // Unreachable code, previous function has an infinite loop

    return 0;
}
