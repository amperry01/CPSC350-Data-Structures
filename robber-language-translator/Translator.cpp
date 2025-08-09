// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA1: Robber Language Translation

#include "Translator.h"
#include <iostream>

Translator::Translator(){
    model = new Model();
}

Translator::~Translator(){
    //BEGIN CODE FROM SOURCE: help in office hours from guy whose name I do not remember//
    if (model != NULL){
        delete model;
    }
    //END OF CODE FROM SOURCE: help in office hours from guy whose name I do not remember//
}

bool Translator::isVowel(char ch){

    switch (tolower(ch)){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
            break;
        default:
            return false;
    }

    return false;
}

/* @param string representing english word to be translated
@return string representing translated word in robber language
*/
string Translator::translateEnglishWord(string engWord){
    string m_rovWord = "";
    for (int i = 0; i < engWord.size(); i++){
        string s(1, engWord[i]);
        if (isVowel(engWord[i])) {
            m_rovWord += model->translateSingleVowel(engWord[i]);
        } else {
            m_rovWord += model->translateSingleConsonant(engWord[i]);
        }
    }

    return m_rovWord;
}

/* @param string representing english sentence to be translated
@return string representing translated sentence in robber language
updated from utilizing same structure as translateEnglishWord() so that I am only dealing with one method in FileProcessor
*/
string Translator::translateEnglishSentence(string engSentence){
    string m_rovSentence = "";
    string m_word = "";
    int i = 0;

    for (; i < engSentence.size(); i++){
        if (isalpha(engSentence[i])){
            m_word += engSentence[i];
        } else {
            m_rovSentence += engSentence[i];
        }

        m_rovSentence += translateEnglishWord(m_word);
        m_word = "";
    }

    return m_rovSentence;
}