// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA3: Do You See What I See?

#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <cstdlib>

using namespace std;

template <typename T>
class MonoStack{
    public:
        MonoStack();
        MonoStack(int size, char o);
        virtual ~MonoStack();
        void push(T c);
        T pop();
        T peek();
        bool isEmpty();
        int size();
    
    private:
        T* stackArr;
        int m_count; // current size
        int m_top; // index of top
        int m_max; // max size of array
        char m_o; // increasing or decreasing mono stack
};

template <typename T>
MonoStack<T>::MonoStack(){
    m_count = 0;
    m_top = -1;
    m_max = 0;
    m_o = 'i'; // going to make mono stack increasing if default
    stackArr = NULL;
}

// if o = 'i', increasing
// if o = 'd', decreasing
template <typename T>
MonoStack<T>::MonoStack(int size, char o){
    m_count = 0;
    m_top = -1;
    m_max = size;
    m_o = o;
    stackArr = new T[m_max];
}

template <typename T>
MonoStack<T>::~MonoStack(){
    if (stackArr != NULL){
        delete[] stackArr;
    }
}

template <typename T>
void MonoStack<T>::push(T c){
    if(m_count == m_max){
        T* temp = new T[2*m_max];
        for(int i = 0; i < m_max; ++i){
            temp[i] = stackArr[i];
        }
        m_max *= 2;
        delete[] stackArr;
        stackArr = temp;
    }

    if (!isEmpty() && m_o == 'i'){
        while(!isEmpty() && peek() >= c){
            pop();
        }
    } else if (!isEmpty() && m_o == 'd'){
        while(!isEmpty() && peek() <= c){
            pop();
        }
    }

    ++m_count;
    stackArr[++m_top] = c;
}

template <typename T>
T MonoStack<T>::pop(){
    T ret;
    if (isEmpty()){
        ret = -1;
    } else {
        m_count--;
        ret = stackArr[m_top--];
    }

    return ret;
}

template <typename T>
T MonoStack<T>::peek(){
    T ret;
    if (isEmpty()){
        ret = -1;
    } else {
        ret = stackArr[m_top];
    }

    return ret;
}

template <typename T>
bool MonoStack<T>::isEmpty(){
    return (m_count == 0);
}

template <typename T>
int MonoStack<T>::size(){
    return m_count;
}


#endif