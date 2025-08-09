// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA3: Do You See What I See?

#include "SpeakerView.h"

int main(int argc, char *argv[]){
    string inFile = argv[1];
    SpeakerView<float> s;
    s.processFile(inFile);
}