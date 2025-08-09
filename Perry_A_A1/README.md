# Robber Language Translator

A C++ program that translates American English text from a plain text file into **Robber Language (Rövarspråket)**.  
In this encoding:
- Every consonant (spelling-based, not pronunciation) is doubled
- An `o` is inserted between doubled consonants
- Vowels remain unchanged

The program reads an input file, outputs the original text, and then produces an HTML file showing the translated text.

---

## 🛠 Features
- **File I/O:** Reads from plain text, writes to HTML
- **String manipulation:** Character-by-character translation logic
- **Command-line interface:** Accepts input and output file paths as arguments

---

## 📂 File Structure
- `main.cpp` — Program entry point
- `Model.cpp` / `Model.h` — Handles translation of single characters
- `Translator.cpp` / `Translator.h` — Handles translation of words/sentences
- `FileProcessor.cpp` / `FileProcessor.h` — Manages file reading/writing
- `input.txt` — Example input file
- `output.html` — Example translated HTML output

---

## 📦 How to Run
```bash
# Compile
g++ *.cpp -o translator

# Run (example)
./translator input.txt output.html
