// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA1: Robber Language Translation

#include "Model.h"

Model::Model(){

}

Model::~Model(){
    
}

/* @param char consanant to encode
@return string with encoded robber language
*/ 
string Model::translateSingleConsonant(char ch){
    string s(1, ch);
    string s1(1, tolower(ch));
    if (isupper(ch)){
        return s + "o" + s1; // was originally printing "TOT" but modified to copy example output
    } else if (islower(ch)){
        return s + "o" + s;
    }

    return "Invalid Consonant";
}

/* @param char vowel to encode
@return string with encoded robber language
*/
string Model::translateSingleVowel(char ch){
    string s(1, ch);
    return s;
}