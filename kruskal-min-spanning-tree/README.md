# Kruskal Minimum Spanning Tree

A C++ program that computes the **Minimum Spanning Tree (MST)** of an undirected, weighted graph using **Kruskal’s algorithm**.  
Reads an adjacency matrix from a file, builds the MST, prints the total cost, and outputs the MST adjacency matrix.

## Features
- **Algorithm:** Kruskal’s MST with a custom min-priority queue
- **Data Structures:** Doubly linked list, priority queue, sets, tuples
- **File I/O:** Reads graph size + adjacency matrix from a text file
- **Output:** Prints MST total cost and MST adjacency matrix (fixed 1-decimal precision)

## File Structure
- `main.cpp` — Program entry point
- `WGraph.h` / `WGraph.cpp` — Graph representation, file parsing, MST construction, printing
- `MinPQueue.h` — Custom min-priority queue (backed by `DblList`)
- `DblList.h` — Doubly linked list template
- `ListNode.h` — List node template
- `input.txt` — Example graph input

## How to Run
```bash
# Compile (uses tuples, so enable C++11)
g++ -std=c++11 -o mst *.cpp

# Run (example)
./mst input.txt
