// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA6: Spanning the Gamut

#ifndef MIN_PQUEUE_H
#define MIN_PQUEUE_H

#include "DblList.h"
#include <cstdlib>
#include <iostream>
#include <tuple>

using namespace std;
typedef unsigned int VertexID;

template <typename T>
class MinPQueue{
    public:
        MinPQueue();
        virtual ~MinPQueue();
        void add(T data);
        T remove();
        T peek();
        int size();
        bool isEmpty();

        void print() const;

    private:
        DblList<T>* m_list;
};

template <typename T>
MinPQueue<T>::MinPQueue(){
    m_list = new DblList<T>();
}

template <typename T>
MinPQueue<T>::~MinPQueue(){
    delete m_list;
}

template <typename T>
void MinPQueue<T>::add(T data){
    if (m_list->isEmpty()){
        m_list->addFront(data);
    } else {
        ListNode<T>* newNode = new ListNode<T>(data);
        ListNode<T>* currNode = m_list->m_front;
        while (currNode != NULL && std::get<2>(currNode->m_data) < std::get<2>(data)){
            currNode = currNode->m_next;
        }
        // found index
        if (currNode == m_list->m_front){ // if adding in front of first item
            newNode->m_next = m_list->m_front;
            m_list->m_front->m_prev = newNode;
            m_list->m_front = newNode;
        } else if (currNode == NULL){ // if adding at end
            m_list->m_back->m_next = newNode;
            newNode->m_prev = m_list->m_back;
            m_list->m_back = newNode;
        } else {
            currNode->m_prev->m_next = newNode;
            newNode->m_prev = currNode->m_prev;
            currNode->m_prev = newNode;
            newNode->m_next = currNode;
        }
        ++m_list->m_size;
    }
}

template <typename T>
T MinPQueue<T>::remove(){
    return m_list->removeFront();
}

template <typename T>
T MinPQueue<T>::peek(){
    return m_list->get(0);
}

template <typename T>
int MinPQueue<T>::size(){
    return m_list->getSize();
}

template <typename T>
bool MinPQueue<T>::isEmpty(){
    return m_list->isEmpty();
}

template <typename T>
void MinPQueue<T>::print() const {
    ListNode<T>* currNode = m_list->m_front; // start at the front of the list
    while (currNode != nullptr) {
        const T& elem = currNode->m_data;

        // assuming T is std::tuple<VertexID, VertexID, double>
        std::cout << "(" << std::get<0>(elem) << ", "
                  << std::get<1>(elem) << ", "
                  << std::get<2>(elem) << ")" << std::endl;

        currNode = currNode->m_next; // move to the next node
    }
}

#endif