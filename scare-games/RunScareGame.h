// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA5: Scare Games

#ifndef RUN_SCARE_GAME_H
#define RUN_SCARE_GAME_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#include "TournamentTree.h"

template <typename T>
class RunScareGame{
    public:
        RunScareGame();
        virtual ~RunScareGame();
        void runTournament(string tournamentFormat, string inFile, string outFile);

    private:
        vector<T*> readFile(string& inFile);

};

template <typename T>
RunScareGame<T>::RunScareGame(){}

template <typename T>
RunScareGame<T>::~RunScareGame(){}

template <typename T>      
void RunScareGame<T>::runTournament(string tournamentFormat, string inFile, string outFile){
    vector<Monster*> monsters = readFile(inFile);
    TournamentTree<T> tournamentTree;

    if (tournamentFormat != "double"){
        tournamentTree.singleElimination(monsters);
        tournamentTree.saveTreeAsDot(outFile, tournamentTree.getSingleEliminationWinner());
    } else {
        tournamentTree.doubleElimination(monsters);
        tournamentTree.saveTreeAsDot(outFile, tournamentTree.getDoubleEliminationWinner());
    }

    for (int i = 0; i < monsters.size(); i++) {
        delete monsters[i];
    }
}

template <typename T>
vector<T*> RunScareGame<T>::readFile(string& inFile){
    vector<Monster*> monsters;
    ifstream file(inFile);
    string line;

    while(getline(file, line)){
        stringstream ss(line);
        string name;
        int screamPwr;

        // ** BEGIN CODE FROM CHATGPT, PROMPT ASKED: how to read different data types separated by a comma and a space from a string in c++ **
        getline(ss, name, ','); // gets name up to comma
        name.erase(name.find_last_not_of(" ") + 1); // trims trailing space

        ss >> screamPwr;
        // ** END CODE FROM CHATGPT **

        monsters.push_back(new Monster(name, screamPwr));
    }

    return monsters;
}

#endif