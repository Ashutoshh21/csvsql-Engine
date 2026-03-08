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
- make clean

#Example Output for now
EmployeeID    | Name           | Department    | Experience_Years    | Education_Level    | Age    | Gender    | City         | Monthly_Salary    | 
-------------------------------------------------------------------------------------------------------------------------
1             | Employee_1     | Marketing     | 15                  | Master             | 53     | Female    | Delhi        | 111416            | 
2             | Employee_2     | Operations    | 7                   | Bachelor           | 25     | Female    | Bangalore    | 95271             | 
3             | Employee_3     | IT            | 12                  | High School        | 51     | Female    | Hyderabad    | 69064             | 
4             | Employee_4     | Operations    | 8                   | PhD                | 44     | Male      | Delhi        | 95091             |

The column size is made uniform and column names have been mapped to indices.
