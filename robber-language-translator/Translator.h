// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA1: Robber Language Translation

#ifndef TRANSLATOR_H // header gaurd
#define TRANSLATOR_H
#include <string>

#include "Model.h"

using namespace std;

class Translator{
    public:
        Translator(); // default constructor
        virtual ~Translator(); // default destructor
        string translateEnglishWord(string engWord);
        string translateEnglishSentence(string engSentence);

    private:
        bool isVowel(char ch);
        Model* model;
};

#endif // TRANSLATOR_H