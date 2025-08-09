# Scare Games Tournament Simulator

A C++ program that simulates the **Scare Games** tournament from *Monsters University* using binary trees to manage **single** and **double elimination** formats. The program determines winners and losers dynamically and outputs the tournament structure as a DOT file for visualization.

---

## 🛠 Features
- **Tournament Formats:** Single and double elimination
- **Custom Data Structures:** Tournament tree nodes and binary tree traversal
- **Operator Overloading:** Compare monsters based on scream power level
- **File I/O:** Reads monster roster from text file
- **DOT File Output:** Generates `.dot` file for Graphviz visualization of brackets

---

## 📂 File Structure
- `main.cpp` — Program entry point
- `Monster.cpp` / `Monster.h` — Represents a monster competitor and implements comparison logic
- `TournamentNode.h` — Binary tree node structure for tournament brackets
- `TournamentTree.h` — Builds and manages tournament bracket logic
- `RunScareGame.h` — Reads input file, runs tournament, and outputs results
- `monsters.txt` — Example roster of monsters (name, scream power level)

---

## 📦 How to Run
```bash
# Compile
g++ *.cpp -o scare_games

# Run with single elimination
./scare_games monsters.txt single

# Run with double elimination
./scare_games monsters.txt double
