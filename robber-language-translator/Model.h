// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA1: Robber Language Translation

#ifndef MODEL_H // header guard
#define MODEL_H
#include <string>

using namespace std;

class Model{
    public:
        Model(); // default constructor
        virtual ~Model(); // default destructor
        string translateSingleConsonant(char ch);
        string translateSingleVowel(char ch);
};

#endif // MODEL_H