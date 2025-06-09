# Sparse-Matrix

Efficient C implementation of sparse matrices using linked data structures. Ideal for compressing and computing large, mostly-zero matrices.

## 🧠 Overview

This project uses a custom sparse matrix structure in C, where only nonzero elements are stored. It leverages:

- `Element` nodes holding `value`, row, column, and pointers for row/column navigation.
- `Header` nodes to access the first elements of each row and column.
- `Matrix` struct encapsulating sparsity metadata and header pointers.

This design suits use-cases like image compression, graph storage, or any large matrix with low density of non-zero entries.

## 📦 Features

- Representation of sparse matrices as per Illinois algorithm (row and column linked lists).
- Efficient insertion, lookup, traversal, and formatting for only non-zero entries.
- Fixed “fill value” compression: omits frequently recurring values, stores only “important” ones.
- Demo program for reading a matrix from `matrix.txt`, compressing it, and outputting compressed results.

## 🛠️ Prerequisites

- GCC or any C compiler
- Unix command-line (bash, sh)

## 🔧 Installation & Build

```sh
# Clone repo
git clone https://github.com/Fejiroobiku/Sparse-Matrix.git
cd Sparse-Matrix

# Build the executable
gcc -ansi -Wpedantic -Wextra -Wall main.c -o sparse.exe
🚀 Usage
Place your matrix (space-separated rows) in matrix.txt, then:

sh
Copy
Edit
./sparse.exe
You'll see output showing each non-zero entry with index and value, plus memory usage stats comparing dense vs. compressed formats.

📋 File Structure
bash
Copy
Edit
Sparse-Matrix/
├── main.c         # Driver: reads input, builds sparse data structure
├── matrix.txt     # Sample input matrix
├── exe/           # Optional pre-built executable
├── test.c         # Optional test harness
├── output.txt     # Sample output
├── run.sh         # Script to compile/run the program
├── git_push.sh    # Utility script
└── LICENSE        # MIT License
📚 How It Works
Reads input matrix line-by-line.

Builds Element nodes for nonzeros, linking via row/column headers.

Stores row headers and column headers in two separate sequences.

Outputs triplet format with memory usage stats comparing sparse vs. dense storage.


🧩 Extensibility
This core data structure can be extended to support:

Sparse matrix operations (addition, multiplication)

File I/O (CSV, binary formats)

Integration with image processing pipelines


How to Customize
Add operations: Implement functions like add_element(), multiply_matrices(), etc.

Different fill values: Support compression schemes beyond zero-value omission.

Optimizations: Add memory pooling, faster lookup (e.g. via balanced trees or hash maps for row
How to Run
Run Main.py
