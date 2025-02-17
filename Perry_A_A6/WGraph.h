// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA6: Spanning the Gamut

#ifndef WGRAPH_H
#define WGRAPH_H

#include "MinPQueue.h"

#include <cstdlib>
#include <set>
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <tuple>
#include <iomanip>

using namespace std;

typedef unsigned int VertexID;

class WGraph{
    public:
        WGraph(); // default constructor
        WGraph(unsigned int sz); // overloaded constructor with graph size
        virtual ~WGraph(); // default destructor
        void addEdge(VertexID i, VertexID j, double w);
        void removeEdge(VertexID i, VertexID j);
        bool areAdjacent(VertexID i, VertexID j);
        void processFile(string inFile);
        void computeMST();
        
        void printAdjMatrix(double** &matrix); // print adj matrix

    private:
        double** m_adj;
        unsigned int m_size;
        MinPQueue<std::tuple<VertexID, VertexID, double>> m_pq;
        set<VertexID> m_visited;
        set<VertexID> m_islands;
        double** m_mstAdj;
};

#endif