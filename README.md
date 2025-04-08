# Sparse Matrix Operations in Python

This project implements a **Sparse Matrix** data structure in Python and performs operations such as **Addition**, **Subtraction**, and **Multiplication** on large sparse matrices stored in files.

## 📁 Project Structure

Sparse-Matrix/ ├── sparse_matrix.py # Main script ├── sample_inputs/ # Folder for matrix input files │ ├── matrix1.txt │ └── matrix2.txt ├── results/ # Folder where results will be saved │ ├── addition.txt │ ├── subtraction.txt │ └── multiplication.txt └── README.md # This file

mathematica
Copy
Edit

## 📝 Input File Format

Each matrix file should follow this format:

rows=3 cols=3 (0, 1, 5) (1, 2, -2) (2, 0, 7)

markdown
Copy
Edit

- First line: number of rows
- Second line: number of columns
- Remaining lines: non-zero values in `(row, column, value)` format

## ▶️ How to Run

1. Ensure you have Python installed (Python 3.6+).
2. Add your matrix files to the `sample_inputs/` folder as `matrix1.txt` and `matrix2.txt`.
3. Run the script:

```bash
python sparse_matrix.py
When prompted, enter the operation you want to perform:

1 for addition

2 for subtraction

3 for multiplication

Check the results/ folder for output files.

⚠️ Error Handling
If the input format is incorrect (e.g., wrong parentheses or non-integer values), the program will raise a clear error.

Matrices must follow valid mathematical rules (e.g., multiplication requires matrix1.columns == matrix2.rows).

💡 Features
Memory-efficient sparse matrix storage using dictionaries

Custom parsing of matrix files

User-interactive command line interface

Results are saved to disk for easy review

📌 Assignment Details
This was developed as part of the Data Structures and Algorithms for Engineers course. The assignment involved:

Loading matrices from files

Implementing custom sparse matrix storage

Supporting large matrices without using built-in libraries like numpy or regex