// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA1: Robber Language Translation

#include "FileProcessor.h"
#include <iostream>
#include <fstream>
#include <string>

FileProcessor::FileProcessor(){
    t = new Translator();
}

FileProcessor::~FileProcessor(){
    //BEGIN CODE FROM SOURCE: help in office hours from guy whose name I do not remember//
    if (t != NULL){
        delete t;
    }
    //END OF CODE FROM SOURCE: help in office hours from guy whose name I do not remember//
}

/* @param string representing input file in english
@param string representing output file in robber language
*/
void FileProcessor::processFile(string engFile, string rovFile){
    ifstream inFile(engFile);
    ofstream outFile(rovFile);
    string line;

    // file header
    outFile << "<!DOCTYPE html>\n";
    outFile << "<html>\n";
    outFile << "<head>\n";
    outFile << "<title>Robber Language Translation</title>\n";
    outFile << "</head>\n";

    // add original txt file and blank line to output file
    outFile << "<body>\n";

    while (getline(inFile, line)){
        outFile << "<p><b>";
        outFile << line;
        outFile << "</b><br></p>";
    }
    
    outFile << "<br>";
    inFile.close();

    // translation
    inFile.open(engFile);
    outFile << "<i>\n";

    while (getline(inFile, line)){
        outFile << "<p><i>";
        outFile << t->translateEnglishSentence(line);
        outFile << "</i><br></p>";
    }

    outFile << "</body>\n";
    outFile << "</html>\n";
    inFile.close();
    outFile.close();

}