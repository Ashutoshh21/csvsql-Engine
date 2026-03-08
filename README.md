# CSVSQL Engine (C++)

A lightweight SQL-like query engine being built in **C++** that executes queries on **CSV files**.
The goal of this project is to understand how database engines process tabular data internally, starting from CSV parsing and gradually adding SQL-style query capabilities.

---

## Current Features

### 1. CSV File Reader

* Reads CSV files from disk.
* Parses header row and data rows.
* Handles structured data loading using STL containers.

### 2. Table Abstraction

* Introduced a `Table` class to represent structured tabular data in memory.
* Stores:

  * column headers
  * row data
* Builds a **column index map** for efficient column lookup.

### 3. Column Indexing

* Uses `unordered_map<string, size_t>` to map column names to indices.
* Enables **O(1) column access**, which will be useful for future query operations.

### 4. Layered Architecture

The project separates responsibilities across components:

```
CSVReader   → Handles file parsing
Table       → Stores structured tabular data
main.cpp    → Application / display logic
```

This structure prepares the project for adding query execution layers.

### 5. Tabular Output

* Displays CSV data in a formatted table using `iomanip`.

---

## Project Structure

```
csvsql-engine/
├── include/
│   ├── csv_reader.h
│   └── table.h
├── src/
│   ├── csv_reader.cpp
│   ├── table.cpp
│   └── main.cpp
├── data/
│   └── employeesalary.csv
├── Makefile
└── README.md
```

---

## Build Instructions

Compile the project using the provided Makefile:

```
make
```

Run the executable:

```
./build/csvsql
```

Clean build artifacts:

```
make clean
```

---

## Example Run

```
csvsql-engine started

Enter the file name of the CSV to be fetched:
data/employeesalary.csv

#Example Output table looks like:
EmployeeID    | Name           | Department    | Experience_Years    | Education_Level    | Age    | Gender    | City         | Monthly_Salary    | 
-------------------------------------------------------------------------------------------------------------------------
1             | Employee_1     | Marketing     | 15                  | Master             | 53     | Female    | Delhi        | 111416            | 
2             | Employee_2     | Operations    | 7                   | Bachelor           | 25     | Female    | Bangalore    | 95271             | 
3             | Employee_3     | IT            | 12                  | High School        | 51     | Female    | Hyderabad    | 69064             | 
4             | Employee_4     | Operations    | 8                   | PhD                | 44     | Male      | Delhi        | 95091             |

```

---

## Technologies Used

* C++
* STL (`vector`, `unordered_map`, `string`)
* Makefile build system
* Git & GitHub

---

## Learning Goals

This project is being developed to explore:

* Data representation for tabular structures
* Column indexing strategies
* Query execution fundamentals
* Basic database engine architecture

---

## Planned Features

* SELECT queries on CSV data
* Column projection
* WHERE filtering
* ORDER BY sorting
* LIMIT support
* Query parsing layer

---

## Status

**Work in progress** – currently implementing the foundational table structure and preparing the engine for query processing.

