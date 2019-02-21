#include "GPIO.h"
#include <iostream>
int main(){
    while(true){
        int servo;
        int servoPort;
        float angle = 0;
        std::cout << "1: Base\n2: Bicep\n3: Elbow\n4: Wrist\n5: Gripper\n";
        std::cout<<"Enter the motor port you want:" << '\n';
        std::cin>> servo;
        if(servo < 0 || servo > 5){
            std::cout << "Error. \n";
            continue;
        }
        anglePrompt:
            std::cout<<"Enter the angle you want " << servo << " at between 20 and 160 degrees:";
            std::cin>> angle;
        if(angle >= 160 || angle <= 20){
            goto anglePrompt;
        }
        //Convert angle to milliseconds
        // 20 - 160 converts to .6ms-2.4ms
        angle /= 100;
        angle += .6;
        angle *= 1000;
        //std::cout << servo<<'\n';
        switch (servo){
            case 1:
                servoPort = 13;
                break;
            case 2:
                servoPort = 10;
                break;
            case 3:
                servoPort = 11;
                break;
            case 4:
                servoPort =  12;
                break;
            case 5:
                servoPort = 0;  
                break;
        }
        GPIO gpio(servoPort);
        std::cout<<angle<<'\n';
        gpio.GeneratePWM(20000, angle, 400);
    }
}