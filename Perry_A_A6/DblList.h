// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA6: Spanning the Gamut

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
        void add(int idx, T data);

        //remove
        T removeBack();
        T removeFront();
        T remove(int idx);

        // get
        T get(int idx);
        bool contains(T data);

        template <typename R>
        friend class MinPQueue;

    private:
        ListNode<T>* m_front;
        ListNode<T>* m_back;
        int m_size;

};

template <typename T>
DblList<T>::DblList(){
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template <typename T>
DblList<T>::~DblList(){
    ListNode<T>* curr = m_front;
    while (curr != NULL){
        ListNode<T>* next = curr -> m_next;
        delete curr;
        curr = next;
    }
    
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template <typename T>
bool DblList<T>::isEmpty(){
  return (m_size==0);
}

template <typename T>
int DblList<T>::getSize(){
  return m_size;
}

template <typename T>
void DblList<T>::addFront(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if (!isEmpty()){
        m_front -> m_prev = newNode;
        newNode -> m_next = m_front;
    } else { // if empty
        m_back = newNode;
    }
    m_front = newNode;
    ++m_size;
}

template <typename T>
void DblList<T>::addBack(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if (!isEmpty()){
        m_back -> m_prev = newNode;
        newNode -> m_next = m_back;
    } else { // if empty
        m_front = newNode;
    }
    m_back = newNode;
    ++m_size;
}

template <typename T>
void DblList<T>::add(int idx, T data){
    if (isEmpty() || idx <= 0){
        addFront(data);
    } else if (idx >= m_size){
        addBack(data);
    } else {
        ListNode<T>* newNode = new ListNode<T>(data);
        int currIdx = 0;
        ListNode<T>* curr = m_front;
        while (currIdx != idx){
            curr = curr -> m_next;
            ++currIdx;
        }
        curr->m_prev->m_next = newNode;
        newNode->m_prev = curr->m_prev;
        curr->m_prev = newNode;
        newNode->m_next = curr;
        ++m_size;
    }
}

//remove
template <typename T>
T DblList<T>::removeBack(){
    if (isEmpty()){
        throw runtime_error("Cannot remove from an empty list");
    }
    T data;
    data = m_back->m_data;
    if(m_size == 1){ // yay
        delete m_back;
        m_front = NULL;
        m_back = NULL;
    } else { // multiple things in list
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
T DblList<T>::removeFront(){
    if (isEmpty()){
        throw runtime_error("Cannot remove from an empty list");
    }
    T data;
    data = m_front->m_data;
    if(m_size == 1){ // yay
        delete m_front;
        m_front = NULL;
        m_back = NULL;
    } else { // multiple things in list
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
T DblList<T>::remove(int idx){
    T data;
    if(idx <= 0){
        data = removeFront();
    } else if (idx >= m_size-1){
        data = removeBack();
    } else {
        int currIdx = 0;
        ListNode<T>* curr = m_front;
        while(currIdx != idx){
            curr = curr->m_next;
            ++currIdx;
        }
        data = curr->m_data;
        curr->m_prev->m_next = curr->m_next;
        curr->m_next->m_prev = curr->m_prev;
        curr->m_next = NULL;
        curr->m_prev = NULL;
        delete curr;
        --m_size;
    }
    return data;
}

template <typename T>
T DblList<T>::get(int idx){
    int currIdx = 0;
    ListNode<T>* curr = m_front;
    while (currIdx != idx){
        curr = curr -> m_next;
        ++currIdx;
    }
    return curr -> m_data;
}

template <typename T>
bool DblList<T>::contains(T data){
    ListNode<T>* curr = m_front;
    bool found = false;
    while(curr != NULL){
        if(curr->m_data == data){
            found = true;
            break;
        }
        curr = curr->m_next;
    }
    return found;
}

#endif