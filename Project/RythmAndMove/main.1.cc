#include "RoboticArm.h"
#include "fileProcessing.h"
#include <unistd.h>

int main()
{
 RoboticArm robotic_arm;
 fileProcess file_process; 
 file_process.EnableArm();

 while (true)
 {
    float BPM;
    BPM = file_process.GetFileInfo();
    file_process.PlayRockU(BPM);
 }
}
