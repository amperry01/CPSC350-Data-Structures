// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA5: Scare Games

#include "RunScareGame.h"
#include "Monster.h"

int main(int argc, char* argv[]){
    string inFile = argv[1];
    string tournamentFormat = argv[2];
    string outFile = "tournament_bracket.dot";

    RunScareGame<Monster> game;
    game.runTournament(tournamentFormat, inFile, outFile);

    return 0;
}