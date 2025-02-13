#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <map>
#include <iostream>

using namespace std;

class SparseMatrix {
private:
    int numRows, numCols;
    map<pair<int, int>, int> matrixData; // Store nonzero elements as (row, col) -> value

public:
    // Constructors
    SparseMatrix(int rows, int cols);

    // Element access
    void setElement(int row, int col, int value);
    int getElement(int row, int col) const;

    // Matrix operations
    SparseMatrix operator+(const SparseMatrix& other) const;
    SparseMatrix operator-(const SparseMatrix& other) const;
    SparseMatrix operator*(const SparseMatrix& other) const;

    // Utility functions
    void print() const;
};

#endif // SPARSE_MATRIX_H
