// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA5: Scare Games

#ifndef TOURNAMENT_NODE_H
#define TOURNAMENT_NODE_H

#include <cstdlib>

using namespace std;

#include "Monster.h"

template <typename T>
class TournamentNode{
    public:
        TournamentNode(T* winner); // default constructor that takes contains a pointer to winning competitior
        virtual ~TournamentNode(); // default deconstructor
        T* getWinner(); // accessor for winner

        template <typename S>
        friend class TournamentTree;

    private:
        TournamentNode<T>* m_left;
        TournamentNode<T>* m_right;
        T* m_winner;

};

template <typename T>
TournamentNode<T>::TournamentNode(T* winner){
    m_left = NULL;
    m_right = NULL;
    m_winner = winner;
}

template <typename T>
TournamentNode<T>::~TournamentNode(){
    
}

template <typename T>
T* TournamentNode<T>::getWinner(){
    return m_winner;
}

#endif