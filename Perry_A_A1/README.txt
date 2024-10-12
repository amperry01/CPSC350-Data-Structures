AUTHOR INFO
Full name: Alyssa Perry 
Student ID: 2347996
Chapman Email: alperry@chapman.edu 
Course number and section: CPSC-350-02
Assignment or exercise number: PA1: Robber Language Translation

OVERVIEW
A C++ program that translates American English text stored in a plain text file to Robber Language/
Rövarspråket. The encoding is as follows: every consonant (spelling matters, not pronunciation) is doubled, 
and an o is inserted in between and vowels are left intact.

SOURCE FILES
main.cpp
Model.cpp /Model.h
Translator.cpp /Translator.h
FileProcessor.cpp /FileProcessor.h

input.txt
output.html

ERRORS
There are no known compile or runtime errors.

REFERENCES
Used to learn C++ basics before starting assignment - https://youtu.be/vLnPwxZdW4Y?si=_aRDCTfecxsrSbmO
isAlpha() - https://stackoverflow.com/questions/8611815/determine-if-char-is-a-num-or-letter
Basic html elements - https://html.com/#Creating_Your_First_HTML_Webpage
Example html file output -  https://stackoverflow.com/questions/11206604/create-html-reports-using-c
Using command line to pass input files - https://stackoverflow.com/questions/21789850/c-how-to-provide-the-input-filename-from-the-command-line-without-hardcoding
getline(inFile, line) - "read from input file c++" Google AI Response

RUN INSTRUCTIONS
To compile: g++ *.cpp -o A1.exe
To run: ./A1.exe input.txt output.html