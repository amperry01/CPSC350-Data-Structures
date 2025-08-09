// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA3: Do You See What I See?

#ifndef SPEAKER_VIEW_H
#define SPEAKER_VIEW_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MonoStack.h"

using namespace std;

template <typename T>
class SpeakerView{
    public:
        SpeakerView();
        virtual ~SpeakerView();
        void processFile(string inFile);

    private:
        int N; // number of lines (rows) with heights
        int P; // number of columns with heights
        T** seatingArr; // 2D seating array to store seating assignments from file input
        void allocateSeatingArr(int row, int col);
        void fillSeatingArr(string inFile);
        void checkSpeakerView();
};

template <typename T>
SpeakerView<T>::SpeakerView(){
    N = 0;
    P = 0;
    seatingArr = NULL;
}

template <typename T>
SpeakerView<T>::~SpeakerView(){
    if (seatingArr != NULL){
        for (int i = 0; i < N; i++){
            delete[] seatingArr[i];
        }
        delete[] seatingArr;
    }
}

template <typename T>
void SpeakerView<T>::allocateSeatingArr(int row, int col){
    seatingArr = new T*[row]; // allocates memory for rows
    for (int i = 0; i < row; i++){
        seatingArr[i] = new T[col]; // allocates memory for columns
    }
}

template <typename T>
void SpeakerView<T>::fillSeatingArr(string inFile){
    ifstream file(inFile);
    string line;

    int currRow = 0;
    while(getline(file, line)){
        if (line == "BEGIN"){ continue; } // moves on to next line if first line of file
        else if (line == "END"){ break; } // exits loop if last line of file

        stringstream s(line);
        T height;

        int currCol = 0;
        while (s >> height){
            seatingArr[currRow][currCol] = height;
            currCol++;
        }
        currRow++;
    }

    file.close();
}

template <typename T>
void SpeakerView<T>::checkSpeakerView(){
    MonoStack<float> monoStack(N, 'd');
    
    for (int i = 0; i < P; i++){
        for (int j = N -1; j >= 0; --j){
            monoStack.push(seatingArr[j][i]);
        }

        cout << "In column " << i << " there are " << monoStack.size() << " that can see. Their heights are: ";
        while (!monoStack.isEmpty()){
            if (monoStack.size() > 1){ // checks if last item in stack to avoid putting comma after last item
                cout << monoStack.pop() << ", ";
            } else {
                cout << monoStack.pop();
            }
        }
        cout << " inches." << endl;
    }
}

template <typename T>
void SpeakerView<T>::processFile(string inFile){
    ifstream file(inFile);
    string line;

    while(getline(file, line)){
        if (line == "BEGIN"){ continue; } // moves on to next line if first line of file
        else if (line == "END"){ break; } // exits loop if last line of file

        // ** BEGIN CODE FROM SOURCE: https://stackoverflow.com/questions/50542569/count-columns-in-txt-with-c **
        stringstream s(line);
        T height;

        if (N == 0){
            while (s >> height){
                P++; // increment column count if first row
            }
        }
        // ** END CODE FROM SOURCE: https://stackoverflow.com/questions/50542569/count-columns-in-txt-with-c **

        N++; // increment rows per line
    }
    file.close();

    allocateSeatingArr(N, P);
    fillSeatingArr(inFile);
    checkSpeakerView();
    
}

#endif