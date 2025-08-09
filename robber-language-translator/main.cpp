// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA1: Robber Language Translation

#include <iostream>
#include "FileProcessor.h"

using namespace std;

int main(int argc, char *argv[]){
    
    string inFile = argv[1];
    string outFile = argv[2];
    FileProcessor f;
    f.processFile(inFile, outFile);

    return 0;
}