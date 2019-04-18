#ifndef FILEPROCESSING_H
#define FILEPROCESSING_H

#include <iostream>
#include <fstream>

class fileProcess{
    public:
        float GetFileInfo();
        void EnableArm();
        void DrumA(float length, float BPM);
        void DrumB(float length, float BPM);
        void PlayRockU(float BPM);

};

#endif