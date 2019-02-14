#include "Wiimote.h"
#include "ZedBoard.h"
class WiimoteToLed : public Wiimote{
    ZedBoard *ptr;
public:
    WiimoteToLed(ZedBoard *ptr) : Wiimote{
        this->ptr = ptr;
    }
    void AccelerationEvent(int code, short acceleration){
        if(code != 3){
            return;
        }
        if(acceleration > 100){
            acceleration = 100;
        }else if(acceleration < -100){
            acceleration = -100;
        }
        short absAccel = abs(acceleration);
        absAccel /= 100;
        absAccel *= 8;
        for(int i = 0; i < absAccel; i++){
            ptr.RegisterWrite(gpio_led1_offset+4*absAccel-4,1);
        }
        for(int i = 8; i > absAccel; i--){
            ptr.RegisterWrite(gpio_led1_offset+4*absAccel-4,0);
        }
    }
}

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