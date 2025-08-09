// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA4: Genetic Palindromes

#ifndef DNA_SEQ_H
#define DNA_SEQ_H

#include "DblList.h"

#include <cstdlib>
#include <string>
using namespace std;

template < typename T>
class DNASeq{
    public:
        DNASeq(); // default constructor
        virtual ~DNASeq(); // deafult destructor
        DNASeq(string &dnaStr); // overloaded constructor that creates a seq from character string
        DNASeq<T> complement(); // returns the complement DNA seq
        DNASeq<T> substring(int s, int e); // returns a DNA seq based on the substring from s (inclusive) to e (exclusive)
        bool isGeneticPalindrome(); // true if seq is palindrome, false otherwise
        string toString();

    private:
        DblList<T>* seqList;

};

template < typename T>
DNASeq<T>::DNASeq(){
    seqList = new DblList<T>();
}

template < typename T>
DNASeq<T>::~DNASeq(){
    delete seqList;
}

template < typename T>
DNASeq<T>::DNASeq(string &dnaStr){
    seqList = new DblList<T>();
    for (int i = 0; i < dnaStr.length(); ++i){
        seqList->addBack(dnaStr[i]);
    }
}

template < typename T>
DNASeq<T> DNASeq<T>::complement(){
    DNASeq<T> complementList;
    ListNode<T>* currNode = seqList->m_front;

    // complement each element
    while (currNode != NULL){
        switch (currNode->m_data){
            case 'A':
                complementList.seqList->addBack('T');
                break;
            case 'T':
                complementList.seqList->addBack('A');
                break;
            case 'C':
                complementList.seqList->addBack('G');
                break;
            case 'G':
                complementList.seqList->addBack('C');
                break;
        }

        currNode = currNode->m_next;
    }

    return complementList;
}

template < typename T>
DNASeq<T> DNASeq<T>::substring(int s, int e){
    // ** BEGIN CODE FROM CHAT GPT, PROMPT ASKED: how to throw errors if out of bounds condition is met **
    if (s < 0 || e > seqList->getSize() || s >= e){
        throw out_of_range("Invalid start or end index for substring");
    }
    // ** END CODE FROM CHAT GPT **

    DNASeq<T> subSeq;
    ListNode<T>* currNode = seqList->m_front;
    int currIdx = 0;

    // go to start idx
    while (currNode != NULL && currIdx < s){
        currNode = currNode->m_next;
        currIdx++;
    }

    // get elements from s (inclusive) to e (exclusive)
    while (currNode != NULL && currIdx < e) {
        subSeq.seqList->addBack(currNode->m_data);
        currNode = currNode->m_next;
        currIdx++;
    }

    return subSeq;
}

template < typename T>
bool DNASeq<T>::isGeneticPalindrome(){
    // get complement
    DNASeq<T> complementSeq = this->complement();

    // reverse complement
    ListNode<T>* ogNode = seqList->m_front;
    ListNode<T>* compNode = complementSeq.seqList->m_back;

    while (ogNode != NULL && compNode != NULL) {
        if (ogNode->m_data != compNode->m_data) {
            return false; // not a palindrome if mismatch
        }
        ogNode = ogNode->m_next;
        compNode = compNode->m_prev;
    }

    return true;
}

template <typename T>
string DNASeq<T>::toString(){
    string s = "";
    ListNode<T>* currNode = seqList->m_front;

    while (currNode != NULL){
        s += currNode->m_data;
        currNode = currNode->m_next;
    }

    return s;
}

#endif
