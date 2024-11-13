// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA4: Genetic Palindromes

#ifndef DBL_LIST_H
#define DBL_LIST_H

#include "ListNode.h"

template <typename T>
class DblList{
    public:
        DblList();
        virtual ~DblList();
        bool isEmpty();
        int getSize();

        // add
        void addFront(T data);
        void addBack(T data);
        void add(int pos, T data);

        // remove
        T removeFront();
        T removeBack();
        T remove(int pos);

        // get random
        T get(int pos);
        bool contains(T data);

        template <typename S>
        friend class DNASeq;
    
    private:
        ListNode<T>* m_front;
        ListNode<T>* m_back;
        int m_size;
};

template <typename T>
DblList<T>::DblList(){
    m_size = 0;
    m_front = NULL;
    m_back = NULL;
}

template <typename T>
DblList<T>::~DblList(){
    ListNode<T>* currNode = m_front;
    while (currNode != NULL) {
        ListNode<T>* nextNode = currNode->m_next;
        delete currNode;
        currNode = nextNode;
    }
    m_size = 0;
    m_front = NULL;
    m_back = NULL;
}

template <typename T>
bool DblList<T>::isEmpty(){
    return (m_size == 0);
}

template <typename T>
int DblList<T>::getSize(){
    return m_size;
}

// add
template <typename T>
void DblList<T>::addFront(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty()){
        m_front->m_prev = newNode;
        newNode->m_next = m_front;
    } else { // empty
        m_back = newNode;
    }
    m_front = newNode;
    ++m_size;
}

template <typename T>
void DblList<T>::addBack(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty()){
        m_back->m_next = newNode;
        newNode->m_prev = m_back;
    } else { // empty
        m_front = newNode;
    }
    m_back = newNode;
    ++m_size;
}

template <typename T>
void DblList<T>::add(int pos, T data){
    if(isEmpty() || pos <= 0){
        addFront(data);
    } else if(pos >= m_size){
        addBack(data);
    } else{ // add to middle
        ListNode<T>* newNode = new ListNode<T>(data);
        int cPos = 0;
        ListNode<T>* current = m_front;
        while (cPos != pos){
            current = current->m_next;
            ++cPos;
        }
        current->m_prev->m_next = newNode;
        newNode->m_prev = current->m_prev;
        current->m_prev = newNode;
        newNode->m_next = current;
        ++m_size;
    }
}

// remove
template <typename T>
T DblList<T>::removeFront(){
    // ** BEGIN CODE FROM CHAT GPT, PROMPT ASKED: how to throw errors if list is empty condition is met **
    if (isEmpty()){
        throw runtime_error("Cannot remove from an empty list");
    }
    // ** END CODE FROM CHAT GPT **

    T data;
    data = m_front->m_data;
    if(m_size == 1){ // yay
        delete m_front;
        m_front = NULL;
        m_back = NULL;
    } else{ // multiple things in list
        ListNode<T>* currFront = m_front;
        m_front = m_front->m_next;
        m_front->m_prev = NULL;
        currFront->m_next = NULL;
        delete currFront;
    }
    --m_size;
    return data;
}

template <typename T>
T DblList<T>::removeBack(){
    // ** BEGIN CODE FROM CHAT GPT, PROMPT ASKED: how to throw errors if list is empty condition is met **
    if (isEmpty()){
        throw runtime_error("Cannot remove from an empty list");
    }
    // ** END CODE FROM CHAT GPT **

    T data;
    data = m_back->m_data;
    if(m_size == 1){ //yay
        delete m_back;
        m_front = NULL;
        m_back = NULL;
    } else{ //multiple things in list
        ListNode<T>* currBack = m_back;
        m_back = m_back->m_prev;
        m_back->m_next = NULL;
        currBack->m_prev = NULL;
        delete currBack;
    }
    --m_size;
    return data;
}

template <typename T>
T DblList<T>::remove(int pos){
    T data;
    if(pos <= 0){
        data = removeFront();
    } else if (pos >= m_size - 1){
        data = removeBack();
    } else {
        int cPos = 0;
        ListNode<T>* current = m_front;
        while(cPos != pos){
            current = current->m_next;
            ++cPos;
        }
        data = current->m_data;
        current->m_prev->m_next = current->m_next;
        current->m_next->m_prev = current->m_prev;
        current->m_next = NULL;
        current->m_prev = NULL;
        delete current;
        --m_size;
    }
    return data;
}

// get random
template <typename T>
T DblList<T>::get(int pos){
    // ** BEGIN CODE FROM CHAT GPT, PROMPT ASKED: how to throw errors if out of bounds condition is met **
    if (isEmpty() || pos < 0 || pos >= m_size){
        throw out_of_range("Position out of range");
    }
    // ** END CODE FROM CHAT GPT **

    int cPos = 0;
    ListNode<T>* current = m_front;
    while(cPos != pos){
        current = current->m_next;
        ++cPos;
    }
    return current->m_data;
}

template <typename T>
bool DblList<T>::contains(T data){
    ListNode<T>* current = m_front;
    bool found = false;
    while(current != NULL){
        if(current->m_data == data){
            found = true;
            break;
        }
        current = current->m_next;
    }
    return found;
}


#endif
