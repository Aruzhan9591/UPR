# UPR
# CSV Processor

## Overview

CSV Processor is a command-line application written in C for working with CSV (Comma-Separated Values) files.

The program allows users to load tabular data, modify the dataset by adding rows and columns, perform basic statistical analysis, and save the updated data back to a CSV file.

This project was developed as part of the UPR course at VSB – Technical University of Ostrava.

## Features

* Import data from CSV files
* Add new rows to existing datasets
* Add new columns with custom values
* Calculate minimum values in numeric columns
* Calculate maximum values in numeric columns
* Calculate sums of numeric columns
* Calculate average values
* Save modified data to an output CSV file
* Interactive command-line interface

## Implemented Commands

| Command   | Description                                     |
| --------- | ----------------------------------------------- |
| `addrow`  | Add a new row to the table                      |
| `addcol`  | Add a new column to the table                   |
| `min`     | Find the minimum value in a column              |
| `max`     | Find the maximum value in a column              |
| `sum`     | Calculate the sum of a numeric column           |
| `average` | Calculate the average value of a numeric column |
| `exit`    | Save changes and terminate the program          |

## Technologies

* C Programming Language
* GCC Compiler
* Makefile
* CSV File Processing
* Dynamic Memory Management

## Project Structure

```text
main.c          - Program entry point
commands.c      - Command implementation
commands.h      - Command declarations
csv.c           - CSV file operations
csv.h           - Data structures and declarations
utils.c         - Helper functions
utils.h         - Utility declarations
Makefile        - Build configuration
```

## Example Usage

```bash
./csv_program --input input.csv --output output.csv
```

Example commands:

```text
addrow petr,kolar,40
addcol age 25,30,45,35,50
sum points
average points
min points
max points
```

## Learning Outcomes

Through this project, I gained experience in:

* C programming
* File handling
* Dynamic memory allocation
* Data processing
* Modular software design
* Command-line application development
* Software testing and debugging

## Author

**Aruzhan Abilmazhinova**

Bachelor's Degree in Computational and Applied Mathematics

Faculty of Electrical Engineering and Computer Science (FEI)

VSB – Technical University of Ostrava
