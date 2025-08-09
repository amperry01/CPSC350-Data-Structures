// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA4: Genetic Palindromes

OVERVIEW
A C++ program that takes input from a file of DNA sequences and returns all possible genetic palindromes from the input file.

SOURCE FILES
main.cpp
ListNode.h
DblList.h
DNASeq.h
PalindromeFinder.h

input.txt

ERRORS
There are no known complie or runtime errors.

REFERENCES
Chat GPT Prompts:
- how to throw errors if out of bounds condition is met
- how to throw errors if list is empty condition is met
- this method should only check and print the main string once and then check and print the substring in smallest to largest order
    - then gave it the current code I had for the method

RUN INSTRUCTIONS
To compile: g++ *.cpp -o A4.exe
To run: ./A4.exe input.txt