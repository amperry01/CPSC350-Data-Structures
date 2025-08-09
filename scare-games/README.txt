// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA5: Scare Games

OVERVIEW
A C++ program that simulates the Scare Games tournament using binary trees to manage single and double-elimination formats, 
determining winners and losers dynamically. The program outputs the tournament structure as a DOT file for visualization, 
showcasing efficient data handling and tournament logic.

SOURCE FILES
main.cpp
Monster.cpp
Monster.h
TournamentNode.h
TournamentTree.h
RunScareGame.h

monsters.txt

ERRORS
There are no known complie or runtime errors.
There is a logic error in builTournamentTree and/or saveTreeAsDotHelper

REFERENCES
https://stackoverflow.com/questions/10575766/comparison-operator-overloading
CHATGPT, PROMPT ASKED: how to read different data types separated by a comma and a space from a string in c++

RUN INSTRUCTIONS
To compile: g++ *.cpp -o A1.exe
To run: ./A1.exe monsters.txt double
        ./A1.exe monsters.txt single
