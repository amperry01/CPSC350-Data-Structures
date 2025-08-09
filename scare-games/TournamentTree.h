// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA5: Scare Games

#ifndef TOURNAMENT_TREE_H
#define TOURNAMENT_TREE_H

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#include "TournamentNode.h"

template <typename T>
class TournamentTree{
    public:
        TournamentTree();
        virtual ~TournamentTree();

        void singleElimination(vector<T*>& competitors);
        void doubleElimination(vector<T*>& competitors);

        void saveTreeAsDot(const string& filename, TournamentNode<T>* rootNode);
        void saveTreeAsDotHelper(TournamentNode<T>* node, ofstream& file, int& nodeID);

        TournamentNode<T>* getSingleEliminationWinner();
        TournamentNode<T>* getDoubleEliminationWinner();

    private:
        TournamentNode<T>* m_winRoot; // winners bracket root (winner)
        TournamentNode<T>* m_loseRoot; // losers bracket root (winner), used in double elimination
        TournamentNode<T>* m_doubleEliminationRoot; // overall winner of double elimination tournaments

        bool isDoubleElimination;

        // helper function to recursively build a tree for any tournament type
        TournamentNode<T>* buildTournamentTree(vector<T*>& competitors);
        vector<T*> extractLosers(vector<T*>& competitors);
};

template <typename T>
TournamentTree<T>::TournamentTree(){
    m_winRoot = NULL;
    m_loseRoot = NULL;
    m_doubleEliminationRoot = NULL;
    isDoubleElimination = false;
}

template <typename T>
TournamentTree<T>::~TournamentTree(){
    if (m_winRoot != NULL){
        delete m_winRoot;
    }

    if (m_loseRoot != NULL){
        delete m_loseRoot;
    }

    if (m_doubleEliminationRoot != NULL){
        delete m_doubleEliminationRoot;
    }
}

template <typename T>
void TournamentTree<T>::singleElimination(vector<T*>& competitors){
    isDoubleElimination = false;
    m_winRoot = buildTournamentTree(competitors);
}

template <typename T>
void TournamentTree<T>::doubleElimination(vector<T*>& competitors){
    isDoubleElimination = true;
    // winners bracket
    m_winRoot = buildTournamentTree(competitors);

    // vector holding losers
    // vector<T*> losers;
    // for (int i = 0; i < competitors.size(); i += 2){ // go through each competitor
    //     if (i + 1 < competitors.size()){ // check to make sure not an odd competitor without opponent
    //         if (*competitors[i] > *competitors[i + 1]){
    //             losers.push_back(competitors[i+1])
    //         } else {
    //             losers.push_back(competitors[i])
    //         }
    //     }
    // }

    vector<T*> losers = extractLosers(competitors);
    
    // losers bracket
    m_loseRoot = buildTournamentTree(losers);

    // find overall winner
    T* overallWinner;
    if (m_winRoot->m_winner > m_loseRoot->m_winner){
        overallWinner = m_winRoot->m_winner;
    } else {
        overallWinner = m_loseRoot->m_winner;
    }

    // overall bracket with overall winner as root 
    m_doubleEliminationRoot = new TournamentNode<T>(overallWinner);
    m_doubleEliminationRoot->m_left = m_winRoot;
    m_doubleEliminationRoot->m_right = m_loseRoot;
}

// Recursive helper function for singleElimination and doubleElimination
template <typename T>
TournamentNode<T>* TournamentTree<T>::buildTournamentTree(vector<T*>& competitors){
    // case: there is only one competitor, that competitor wins
    if (competitors.size() == 1){
        return new TournamentNode<T>(competitors[0]);
    }

    // case: > one competitior
    vector<T*> nextRound;
    for (int i = 0; i < competitors.size(); i += 2){ // go through each competitor
        if (i + 1 < competitors.size()){ // check to make sure not an odd competitor without opponent
            // std::cout << "Comparing " << competitors[i]->getName() << " (" << competitors[i]->getScreamPowerLvl() << ") vs " 
                // << competitors[i + 1]->getName() << " (" << competitors[i + 1]->getScreamPowerLvl() << ")\n";
            if (*competitors[i] > *competitors[i + 1]){
                nextRound.push_back(competitors[i]);
                // std::cout << competitors[i]->getName() << " WIN" << endl;
            } else {
                nextRound.push_back(competitors[i + 1]);
                // std::cout << competitors[i + 1]->getName() << " WIN" << endl;
            }
        } else { // if an odd number of competitors, this will be last competitor who automatically advances
            nextRound.push_back(competitors[i]);
        }
    }

    TournamentNode<T>* parent = new TournamentNode<T>(nextRound[0]);
    vector<T*> leftCompetitors;
    vector<T*> rightCompetitors;

    for (int i = 0; i < competitors.size(); i++){
        if (i < competitors.size() / 2){
            leftCompetitors.push_back(competitors[i]);
        } else {
            rightCompetitors.push_back(competitors[i]);
        }
    }

    if (!leftCompetitors.empty()) {
        parent->m_left = buildTournamentTree(leftCompetitors);
    }

    if (!rightCompetitors.empty()) {
        parent->m_right = buildTournamentTree(rightCompetitors);
    }

    return parent;
}

template <typename T>
vector<T*> TournamentTree<T>::extractLosers(vector<T*>& competitors){
    vector<T*> losers;

    for (size_t i = 0; i < competitors.size(); i += 2) {
        if (i + 1 < competitors.size()) { // Ensure there is a pair
            if (*competitors[i] > *competitors[i + 1]) {
                losers.push_back(competitors[i + 1]); // Loser
            } else {
                losers.push_back(competitors[i]); // Loser
            }
        }
    }

    return losers;
}

template <typename T>
TournamentNode<T>* TournamentTree<T>::getSingleEliminationWinner(){
    return m_winRoot;
}

template <typename T>
TournamentNode<T>* TournamentTree<T>::getDoubleEliminationWinner(){
    return m_doubleEliminationRoot;
}

// Function to save the tree as a DOT file
template <typename T>
void TournamentTree<T>::saveTreeAsDot(const string& filename, TournamentNode<T>* rootNode) {
    ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for DOT output: " << filename << "\n";
        return;
    }

    file << "digraph TournamentTree {\n";
    int nodeID = 0;
    saveTreeAsDotHelper(rootNode, file, nodeID);
    file << "}\n";
    file.close();
}

// Recursive helper function for DOT file generation
template <typename T>
void TournamentTree<T>::saveTreeAsDotHelper(TournamentNode<T>* node, ofstream& file, int& nodeID) {
    if (node == NULL) return;

    int currentID = nodeID++;
    file << "    node" << currentID << " [label=\"" << node->m_winner->getName()
         << " (Power: " << node->m_winner->getScreamPowerLvl() << ")\"];\n";

    if (node->m_left) {
        int leftID = nodeID;
        saveTreeAsDotHelper(node->m_left, file, nodeID);
        file << "    node" << currentID << " -> node" << leftID << ";\n";
    }

    if (node->m_right) {
        int rightID = nodeID;
        saveTreeAsDotHelper(node->m_right, file, nodeID);
        file << "    node" << currentID << " -> node" << rightID << ";\n";
    }
}

#endif