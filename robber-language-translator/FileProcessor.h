// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA1: Robber Language Translation

#ifndef FILE_PROCESSOR_H // header guard
#define FILE_PROCESSOR_H
#include <string>
#include <iostream>
#include <fstream>

#include "Translator.h"

using namespace std;

// declarations
class FileProcessor{
    public:
        FileProcessor(); // default constructor
        virtual ~FileProcessor(); // default destructor
        void processFile(string engFile, string rovFile);

    private:
        Translator* t;
};

#endif // FILE_PROCESSOR_H