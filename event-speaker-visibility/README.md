# Event Speaker Visibility

A C++ program that analyzes the seating arrangement of event attendees and determines which attendees can see the speaker. The program reads an input file of attendee heights and uses a **monotonically decreasing stack** to calculate visibility for each seat column.

## Features
- **File I/O:** Reads seating height data from text file
- **Data Structures:** Implements a generic monotonically decreasing stack
- **Algorithm:** Calculates visibility from front to back for each column
- **Command-line interface:** Specify input file path

## File Structure
- `main.cpp` — Program entry point
- `MonoStack.h` — Generic monotonically increasing/decreasing stack implementation
- `SpeakerView.h` — Reads seating data, stores in 2D array, calculates visibility
- `input.txt` — Example seating arrangement input

## How to Run
```bash
# Compile
g++ *.cpp -o speaker_visibility

# Run (example)
./speaker_visibility input.txt
