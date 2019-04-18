#include "RoboticArm.h"
#include <unistd.h>




int main()
{
 RoboticArm robotic_arm;
 while (true)
 {
    robotic_arm.MoveServo(0, 90, 20);
    robotic_arm.MoveServo(1, 140, 20);
    robotic_arm.MoveServo(2, 120, 20);
    robotic_arm.MoveServo(3, 100, 20);
    robotic_arm.MoveServo(4, 160, 20);
    sleep(2);
    
    robotic_arm.MoveServo(3, 180, 180);
    robotic_arm.MoveServo(3, 100, 180);
    sleep(2);
robotic_arm.MoveServo(0, 180, 180);
robotic_arm.MoveServo(3, 90, 180);
    sleep(6);
 }
}
