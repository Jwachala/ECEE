#include "GPIO.h"
#include <iostream>
int main() {
    while (true) {
        int servo;
        int servoPort;
        float inAngle = 0;
        float finAngle = 0;
        float dps = 0;
        
        std::cout << "1: Base\n2: Bicep\n3: Elbow\n4: Wrist\n5: Gripper\n";
        std::cout << "Enter the motor port you want:" << '\n';
        std::cin >> servo;
        if (servo < 0 || servo > 5) {
            std::cout << "Error. \n";
            continue;
        }

        // std::cout << servo<<'\n';
        switch (servo) {
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
            servoPort = 12;
            break;
        case 5:
            servoPort = 0;
            break;
        }
    inAnglePrompt:
        std::cout << "Enter the initial angle you want " << servo
                  << " at, between 20 and 160 degrees:";
        std::cin >> inAngle;
        if (inAngle >= 160 || inAngle <= 20) {
            goto inAnglePrompt;
        }
        // Convert angle to milliseconds
        // 20 - 160 converts to .6ms-2.4ms
        float inAngleMs = inAngle/100;
        inAngleMs += .6;
        inAngleMs *= 1000;

    finAnglePrompt:
        std::cout << "Enter the final angle you want " << servo
                  << " at, between 20 and 160 degrees:";
        std::cin >> finAngle;
        if (finAngle >= 160 || finAngle <= 20) {
            goto finAnglePrompt;
        }
        // Convert angle to milliseconds
        // 20 - 160 converts to .6ms-2.4ms
        float finAngleMs = finAngle/100;
        finAngleMs += .6;
        finAngleMs *= 1000;
        //std::cout << finAngle << '\n';
    dpsPrompt:
        std::cout << "Enter the degrees per second you want " << servo
                  << " to move at, between 1 and 180 degrees/s:";
        std::cin >> dps;
        //dps /= 100;
        //dps += .6;
        //dps *= 1000;
        //std::cout << 'DPS: ' << dps << '\n';
        int num_periods = ((finAngle - inAngle) / dps)/.02;
        std::cout << "Number of Periods: " << num_periods << '\n';
        GPIO gpio(servoPort);
        // std::cout<<angle<<'\n';
        // gpio.GeneratePWM(20000, angle, 400);
        gpio.GenerateVariablePWM(20000, inAngleMs, finAngleMs, num_periods);
    }
}