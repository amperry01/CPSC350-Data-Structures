# Genetic Palindromes

A C++ program that takes input from a file of DNA sequences and returns all possible genetic palindromes from the input file. A genetic palindrome occurs when a sequence matches the reverse of its complementary strand.

---

## 🛠 Features
- **File I/O:** Reads DNA sequences from a text file
- **Validation:** Checks for valid DNA characters (A, C, T, G)
- **Data Structures:** Custom doubly linked list implementation
- **Algorithm:** Generates complements, reverses sequences, and checks for palindromes
- **Substring Search:** Finds and reports all palindromic substrings of length ≥ 5

---

## 📂 File Structure
- `main.cpp` — Program entry point
- `ListNode.h` — Node structure for doubly linked list
- `DblList.h` — Custom doubly linked list implementation
- `DNASeq.h` — Represents and manipulates DNA sequences
- `PalindromeFinder.h` — Controls file processing and palindrome detection logic
- `input.txt` — Example DNA sequence input file

---

## 📦 How to Run
```bash
# Compile
g++ *.cpp -o genetic_palindromes

# Run (example)
./genetic_palindromes input.txt
