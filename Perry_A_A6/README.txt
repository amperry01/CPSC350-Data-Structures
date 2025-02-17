// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA6: Spanning the Gamut

OVERVIEW
A C++ program that is capable of identifying a minimum spanning tree of an undirected, weighted graph using Kruskal’s algorithm.

SOURCE FILES
main.cpp
WGraph.h
WGraph.cpp
PQueue.h
DblList.h
ListNode.h

ERRORS
There are no known complie or runtime errors.

REFERENCES
CHATGPT, PROMPT ASKED: how to remove all items from one set and put into another set
CHATGPT, PROMPT ASKED: this prints as ints, they need to be doubles, the info in input file is doubles: 
    *copied my processFile() and printAdjMatrix() as is currently minus setprecision() line line*
CHATGPT, PROMPT ASKED: *copied and pasted error code below, and was given the -std=c++11 addition for compile command
    ./WGraph.h:40:24: error: no member named 'tuple' in namespace 'std' MinPQueue<std::tuple<VertexID, VertexID, double> > m_pq;
For overview on sets: https://www.geeksforgeeks.org/set-in-cpp-stl/
Used clang++ LLDB in mac terminal to help debug: 
    clang++ -std=c++11 -o test *.cpp 
    lldb ./test input.txt

RUN INSTRUCTIONS
To compile: g++ -std=c++11 -o A1.exe *.cpp
To run: ./A1.exe input.txt
Note: using -std=c++11 as I decided to use tuples to store my vertecies and edges
