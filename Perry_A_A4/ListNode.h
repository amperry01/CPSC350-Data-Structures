// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA4: Genetic Palindromes

#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <cstdlib>
using namespace std;

template <typename T>
class ListNode{
    public:
        ListNode(T data);
        virtual ~ListNode();

        template <typename S>
        friend class DblList;

        template <typename R>
        friend class DNASeq;

    private:
        T m_data;
        ListNode<T>* m_next;
        ListNode<T>* m_prev;
};

template <typename T>
ListNode<T>::ListNode(T data){
    m_next = NULL;
    m_prev = NULL;
    m_data = data;
}

template <typename T>
ListNode<T>::~ListNode(){
    m_next = NULL;
    m_prev = NULL;
}


#endif
