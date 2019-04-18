#include "RoboticArm.h"
#include <unistd.h>
int main() {
    RoboticArm robotic_arm;

    while (true) {
        robotic_arm.MoveServo(1, 180, 45);
        robotic_arm.MoveServo(2, 90, 45);
        robotic_arm.MoveServo(3, 90, 45);
        robotic_arm.MoveServo(4, 90, 45);
        sleep(3);
        robotic_arm.MoveServo(4, 10, 90);
        sleep(2);
        robotic_arm.MoveServo(1, 80, 72000);
        usleep(350000);
        robotic_arm.MoveServo(4, 90, 1000);
        sleep(2.7);
    }
}