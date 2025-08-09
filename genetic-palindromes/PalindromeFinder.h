// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA4: Genetic Palindromes

#ifndef PALINDRONE_FINDER_H
#define PALINDRONE_FINDER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "DNASeq.h"

using namespace std;

template <typename T>
class PalindromeFinder{
    public:
        PalindromeFinder(); // default constructor
        virtual ~PalindromeFinder(); // default destructor
        void processFile(string inFile);

    private:
        bool isValidSeq(string& sequence);
        void findPalindromes(string& sequence);
        DNASeq<T>* dnaSeq;

};

template <typename T>
PalindromeFinder<T>::PalindromeFinder(){
    dnaSeq = new DNASeq<T>();
}

template <typename T>
PalindromeFinder<T>::~PalindromeFinder(){
    delete dnaSeq;
}

template <typename T>
bool PalindromeFinder<T>::isValidSeq(string& sequence){
    for(int i = 0; i < sequence.length(); ++i){
        if (sequence[i] != 'A' && sequence[i] != 'C' && sequence[i] != 'T' && sequence[i] != 'G'){ // if not a valid char, invlaid seq
            return false;
        }
    }

    return true;
}

template <typename T>
void PalindromeFinder<T>::findPalindromes(string& sequence){
    DNASeq<T> dnaSeq(sequence);
    
    // check if full sequence is palindrome
    if (dnaSeq.isGeneticPalindrome()){
        cout << dnaSeq.toString() << " - genetic palindrome" << endl;
    } else {
        cout << dnaSeq.toString() << " - not a genetic palindrome" << endl;
    }

    // check substrings for palindromes
    int len = sequence.length();
    // ** BEGIN CODE FROM CHAT GPT, PROMPT ASKED: this method should only check and print the main string once and then check and print the substring in smallest to largest order... **
    // when first running, orignial code printed the orig sequence again and then printed largest to smallest, used chat to help with for loop logic because my brain was overloaded
    for (int subLen = 5; subLen <= len; ++subLen){ // help... is there a way to make this not nested for loops? my big oh is screaming at me
        for (int start = 0; start < len - subLen; ++start){
            int end = start + subLen;
    // ** END CODE FROM CHAT GPT ** 
            DNASeq<T> subSeq = dnaSeq.substring(start, end);
            if (subSeq.isGeneticPalindrome()){
                cout << "     substring " << subSeq.toString() << " - genetic palindrome" << endl;
            }
        }
    }
}

template <typename T>
void PalindromeFinder<T>::processFile(string inFile){
    ifstream file(inFile);
    string sequence;

    while(getline(file, sequence)){
        // checking if end of file
        if (sequence == "END"){
            break;
        }

        // check if valid sequence
        if (!isValidSeq(sequence)){
            cout << sequence << " - INVALID" << endl;
        } else {
            findPalindromes(sequence);
        }
    }
}

#endif
