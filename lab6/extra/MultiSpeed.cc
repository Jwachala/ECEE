#include "GPIO.h"
#include <iostream>
#include <thread>
struct servo{
    int servoPort;
    float inAngle;
    float inAngleMs;
    float finAngle;
    float finAngleMs;
    int num_periods;
};

servo getServo(int servonum){
        servo servo;
        int servoType;
        int servoPort;
        float inAngle = 0;
        float finAngle = 0;
        float dps = 0;
        
    servoPrompt:
        std::cout << "1: Base\n2: Bicep\n3: Elbow\n4: Wrist\n5: Gripper\n";
        std::cout << "Enter the motor port you want:" << '\n';
        std::cin >> servoType;
        if (servoType < 0 || servoType > 5) {
            std::cout << "Error. \n";
           goto servoPrompt;
        }

        // std::cout << servo<<'\n';
        switch (servoType) {
        case 1:
            servo.servoPort = 13;
            break;
        case 2:
            servo.servoPort = 10;
            break;
        case 3:
            servo.servoPort = 11;
            break;
        case 4:
            servo.servoPort = 12;
            break;
        case 5:
            servo.servoPort = 0;
            break;
        }
    inAnglePrompt:
        std::cout << "Enter the initial angle you want " << servoType
                  << " at, between 20 and 160 degrees:";
        std::cin >> inAngle;
        if (inAngle >= 160 || inAngle <= 20) {
            goto inAnglePrompt;
        }
        // Convert angle to milliseconds
        // 20 - 160 converts to .6ms-2.4ms
        servo.inAngle = inAngle;
        float inAngleMs = inAngle/100;
        inAngleMs += .6;
        inAngleMs *= 1000;
        servo.inAngleMs = inAngleMs;
    finAnglePrompt:
        std::cout << "Enter the final angle you want " << servoType
                  << " at, between 20 and 160 degrees:";
        std::cin >> finAngle;
        if (finAngle >= 160 || finAngle <= 20) {
            goto finAnglePrompt;
        }
        // Convert angle to milliseconds
        // 20 - 160 converts to .6ms-2.4ms
        servo.finAngle = finAngle;
        float finAngleMs = finAngle/100;
        finAngleMs += .6;
        finAngleMs *= 1000;
        servo.finAngleMs = finAngleMs;
        //std::cout << finAngle << '\n';
    dpsPrompt:
        std::cout << "Enter the degrees per second you want " << servoType
                  << " to move at, between 1 and 180 degrees/s:";
        std::cin >> dps;
        //dps /= 100;
        //dps += .6;
        //dps *= 1000;
        //std::cout << 'DPS: ' << dps << '\n';
        int num_periods = ((finAngle - inAngle) / dps)/.02;
        std::cout << "Number of Periods: " << num_periods << '\n';
        servo.num_periods = num_periods;
        //GPIO gpio(servoPort);
        // std::cout<<angle<<'\n';
        // gpio.GeneratePWM(20000, angle, 400);  
   return servo;     
}

int main() {
    while (true) {
        servo servo1 = getServo(1);
        servo servo2 = getServo(2);
        GPIO gpio1(servo1.servoPort);
        std::thread t1(gpio1.GenerateVariablePWM,20000,servo1.inAngleMs,servo1.finAngleMs,servo1.num_periods);
        GPIO gpio2(servo2.servoPort);
        std::thread t2(gpio2.GenerateVariablePWM,20000,servo2.inAngleMs,servo2.finAngleMs,servo2.num_periods);
        //gpio.GenerateVariablePWM(20000, inAngleMs, finAngleMs, num_periods);
}
}