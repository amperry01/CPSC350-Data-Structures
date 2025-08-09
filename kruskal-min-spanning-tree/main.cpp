// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA6: Spanning the Gamut

#include "WGraph.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    std::string inFile = argv[1];

    // getting size here so that I can accurately allocate memory from the constructor
    ifstream file(inFile);
    string line;
    getline(file, line);
    int sz = stoi(line);
    file.close();

    WGraph gamut(sz);
    gamut.processFile(inFile);
    gamut.computeMST();
}
