# csvsql-engine

A lightweight SQL-like query engine in C++ that operates on CSV files.  
This repository currently contains a **basic CSV reader module** that loads and displays CSV data in a table-like format.  
(SQL parsing and query execution will be added incrementally.)

---

## Current Features

- Read CSV files from disk
- Parse header row and data rows
- Store data in a table-like structure (rows × columns)
- Display CSV contents in the terminal
- Simple Makefile-based build system for now (Later I'll switch to Cmake)

---

## Project Structure
csvsql-engine/
├── include/
│ └── csv_reader.h
├── src/
│ ├── main.cpp
│ └── csv_reader.cpp
├── data/
│ └── sample.csv
├── Makefile
└─README.md

#PreRequisites
- g++ (C++17 compatible)
- make

#Build
- make
- ./build/csvsql 
- make clea

#Example Output for now
 id | name | age | country
--------------------------------
 1 | Ashutosh | 21 | India
 2 | Rahul | 22 | India
 3 | David | 24 | USA

My next step is to fix this column Size to make it look uniform and formatted
