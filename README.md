# CSVSQL Engine (C++)

A lightweight SQL-like query engine built from scratch in **C++** using the STL. The project aims to understand how relational database engines process structured data by progressively implementing SQL parsing and query execution over CSV files.

## Features

- Reads and parses CSV files into an in-memory table representation.
- `Table` abstraction for structured storage of headers and rows.
- O(1) column lookup using `std::unordered_map<std::string, size_t>`.
- Layered architecture separating:
  - CSV parsing
  - Data representation
  - Query processing (in progress)
- Formatted tabular output using `iomanip`.
- Custom Makefile-based build system.

## Project Structure

```
csvsql-engine/
├── include/
├── src/
├── data/
├── Makefile
└── README.md
```

## Build

```bash
make
./build/csvsql
```

Clean build artifacts:

```bash
make clean
```

## Example

Input:

```
data/employeesalary.csv
```

Output:

```
EmployeeID | Name | Department | ...
1          | Employee_1 | Marketing | ...
2          | Employee_2 | Operations | ...
```

## Tech Stack

- C++17
- STL (`vector`, `unordered_map`, `string`)
- Makefile
- Git & GitHub

## Current Progress

- ✅ CSV Reader
- ✅ Table Abstraction
- ✅ Column Indexing
- ✅ Tokenizer (Lexer) *(in progress)*
- ⏳ SQL Parser
- ⏳ Query Executor
- ⏳ SELECT / WHERE / ORDER BY / LIMIT

## Roadmap

- [ ] Complete SQL tokenizer
- [ ] Build recursive-descent parser
- [ ] Execute `SELECT` queries
- [ ] Support `WHERE` filtering
- [ ] Support `ORDER BY`
- [ ] Support `LIMIT`

---

**Status:** 🚧 Active development