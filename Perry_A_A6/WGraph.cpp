// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA6: Spanning the Gamut

#include "WGraph.h"

WGraph::WGraph(){
    m_size = 0;
    m_adj = NULL;
}

WGraph::WGraph(unsigned int sz){
    m_size = sz;

    // allocate memory for adj matrix
    m_adj = new double*[sz];
    m_mstAdj = new double*[sz];
    for (int i = 0; i < m_size; ++i){
        m_adj[i] = new double[sz];
        m_mstAdj[i] = new double[sz];
    }

    // set edges to empty (max double value)
    for (int i = 0; i < m_size; ++i){
        for (int j = 0; j < m_size; ++j){
            m_adj[i][j] = std::numeric_limits<double>::max();
            m_mstAdj[i][j] = 0.0;
        }
    }
}

WGraph::~WGraph(){
    if (m_adj != NULL){
        // delete each row
        for (int i = 0; i < m_size; ++i){
            delete m_adj[i];
        }
        delete[] m_adj; // delete array of row pointers
    }

    if (m_mstAdj != NULL){
        for (int i = 0; i < m_size; ++i){
            delete m_mstAdj[i];
        }
        delete[] m_mstAdj;
    }
}

// not using add and remove methods for orig adjacency matrix since its read from input so using for mst adj matrix
void WGraph::addEdge(VertexID i, VertexID j, double w){
    if (i < m_size && j < m_size){
        m_mstAdj[i][j] = w;
        m_mstAdj[j][i] = w; 
    }
}

void WGraph::removeEdge(VertexID i, VertexID j){
    if (i < m_size && j < m_size){
        m_mstAdj[i][j] = 0.0;
        m_mstAdj[j][i] = 0.0;
    }
}

// necessary for orig adj matrix, not entirely necessary for mst adj matrix in this use case 
bool WGraph::areAdjacent(VertexID i, VertexID j){
    return (m_adj[i][j] < std::numeric_limits<double>::max() && m_adj[i][j] > 0);
}

void WGraph::computeMST(){
    // populate min pqueue
    for (int i = 0; i < m_size; ++i) {
        for (int j = i + 1; j < m_size; ++j) { // only consider upper triangle (i < j) so duplicate edges aren't included
            if (areAdjacent(i, j)) {
                m_pq.add({i, j, m_adj[i][j]});
            }
        }
    }
    
    // m_pq.print(); // print pqueue for testing

    // variable to track cost
    double cost = 0.0;

    // remove from pqueue, first one to start the MST and comparisons
    tuple<VertexID, VertexID, double> temp = m_pq.remove();

    // add first two values to visited & add edge to MST 
    m_visited.insert(get<0>(temp));
    m_visited.insert(get<1>(temp));
    addEdge(get<0>(temp), get<1>(temp), get<2>(temp));
    cost += get<2>(temp);
    
    // remove rest of pqueue
    while (!(m_pq.isEmpty())){
        temp = m_pq.remove();

        if (m_visited.find(get<0>(temp)) != m_visited.end() && m_visited.find(get<1>(temp)) != m_visited.end()){ // both in visited
            continue;
        } else if (m_visited.find(get<0>(temp)) != m_visited.end() || m_visited.find(get<1>(temp)) != m_visited.end()){ // 1 in visited, 1 out
            // check if in islands, connect/add 1 out to visited & add to MSTadj
            VertexID visitedVertex;
            VertexID unvisitedVertex;
            
            if (m_visited.find(get<0>(temp)) != m_visited.end()) {
                visitedVertex = get<0>(temp);
                unvisitedVertex = get<1>(temp);
            } else {
                visitedVertex = get<1>(temp);
                unvisitedVertex = get<0>(temp);
            }
            
            if (m_islands.find(unvisitedVertex) != m_islands.end()) {
                // unvisited vertex belongs to an island
                addEdge(get<0>(temp), get<1>(temp), get<2>(temp)); // add edge to MST
                cost += get<2>(temp);

                // add all from islands to visited
                // ** BEGIN CODE FROM CHATGPT, PROMPT ASKED: how to remove all items from one set and put into another set **
                m_visited.insert(m_islands.begin(), m_islands.end());
                m_islands.clear();
                // ** END CODE FROM CHATGPT **

            } else {
                // not in islands, add to visited
                addEdge(get<0>(temp), get<1>(temp), get<2>(temp));
                cost += get<2>(temp);
                m_visited.insert(unvisitedVertex);
            }


        } else { // both not in visited: check/add to islands & MSTadj
            addEdge(get<0>(temp), get<1>(temp), get<2>(temp));
            cost += get<2>(temp);
            m_islands.insert(get<0>(temp));
            m_islands.insert(get<1>(temp));
        }
    }

    if (!m_islands.empty()) {
        std::cerr << "island graph is disconnected!" << std::endl;
    }

    // ** BEGIN CODE FROM CHATGPT, PROMPT ASKED: this prints as ints, they need to be doubles, the info in input file is doubles: **
    // *copied my processFile() and printAdjMatrix() as is currently minus this line*
    cout << fixed << setprecision(1); // Fixed-point notation with 1 decimal place
    // ** END CODE FROM CHATGPT **
    cout << "The MST cost is: " << cost << endl;
    printAdjMatrix(m_mstAdj);
}

void WGraph::processFile(string inFile){
    ifstream file(inFile);
    string line;

    // get size from first line
    getline(file, line);
    m_size = stoi(line);

    // get graph from remainder of file
    int i = 0;
    while (getline(file, line)){
        if (line == "END"){break;} // break loop if end of file

        if (i >= m_size){
            cerr << "Error: more rows than expected from file" << endl;
            break;
        }

        // getting each double from rows and assigning in adj matrix
        stringstream s(line);
        for (int j = 0; j < m_size; ++j){
            s >> m_adj[i][j];
        }
        i++;
    }
    file.close();
}

void WGraph::printAdjMatrix(double** &matrix){
    // ** BEGIN CODE FROM CHATGPT, PROMPT ASKED: this prints as ints, they need to be doubles, the info in input file is doubles: **
    // *copied my processFile() and printAdjMatrix() as is currently minus this line
    cout << fixed << setprecision(1); // Fixed-point notation with 1 decimal place
    // ** END CODE FROM CHATGPT **

    for (int i = 0; i < m_size; ++i){
        for (int j = 0; j < m_size; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}