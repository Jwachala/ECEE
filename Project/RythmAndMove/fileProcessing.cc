#include "fileProcessing.h"
#include "RoboticArm.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <iostream>

float fileProcess::GetFileInfo(){
    fstream inFile;
    inFile.open("BPM.txt");
    float BPM;
    inFile >> BPM;
    infile.close();
    infile.clear();
}

void fileProcess::EnableArm(){
    robotic_arm.MoveServo(0, 90, 20);
    robotic_arm.MoveServo(1, 140, 20);
    robotic_arm.MoveServo(2, 120, 20);
    robotic_arm.MoveServo(3, 100, 20);
    robotic_arm.MoveServo(4, 160, 20);
    sleep(2);
    robotic_arm.MoveServo(5, 0, 20);
}

void fileProcess::DrumA(float length, float BPM){
    robotic_arm.MoveServo(4, 20, 200);
    usleep((70/200)*(1000000))
    robotic_arm.MoveServo(4, 90, 200);
    usleep((70/200)*(1000000))
    //degrees/dps *1000000 = microsecondsto move the arm
    //length/BPM *60 equals seconds

    // 70/200 *1000000
    // 70 degrees of movement from 90 to 20 * 2 because there and back
    usleep((length/BPM)*60000000 - 700000);
}

void fileProcess::DrumB(float length, float BPM){
    robotic_arm.MoveServo(1, 20, 200);
    usleep((70/200)*(1000000))
    robotic_arm.MoveServo(1, 90, 200);
    usleep((70/200)*(1000000))
    //degrees/dps *1000000 = microsecondsto move the arm
    //length/BPM *60 equals seconds

    // 70/200 *1000000
    // 70 degrees of movement from 90 to 20 * 2 because there and back
    usleep((length/BPM)*60000000 - 700000);
}

void fileProcess::PlayRockU(float BPM){
    fileProcess.DrumA(0.5, BPM);
    fileProcess.DrumA(0.5, BPM);
    fileProcess.DrumB(1, BPM);

    //fileProcess.DrumA(0.5, BPM);
    //fileProcess.DrumA(0.5, BPM);
    //fileProcess.DrumB(1, BPM);
}