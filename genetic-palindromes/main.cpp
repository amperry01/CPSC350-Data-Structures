// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA4: Genetic Palindromes

#include "PalindromeFinder.h"

#include <string>
using namespace std;

int main(int argc, char *argv[]){

    string inFile = argv[1];
    PalindromeFinder<char> pFinder;
    pFinder.processFile(inFile);

    return 0;
}
