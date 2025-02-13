#include "SparseMatrix.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor to initialize an empty sparse matrix
SparseMatrix::SparseMatrix(int rows, int cols) {
    this->numRows = rows;
    this->numCols = cols;
}

// Method to set an element in the matrix
void SparseMatrix::setElement(int row, int col, int value) {
    if (row >= numRows || col >= numCols || row < 0 || col < 0) {
        throw invalid_argument("Index out of bounds");
    }
    if (value != 0) {
        matrixData[{row, col}] = value;
    } else {
        matrixData.erase({row, col}); // Remove if value is zero
    }
}

// Method to get an element from the matrix
int SparseMatrix::getElement(int row, int col) const {
    if (row >= numRows || col >= numCols || row < 0 || col < 0) {
        throw invalid_argument("Index out of bounds");
    }
    auto it = matrixData.find({row, col});
    return (it != matrixData.end()) ? it->second : 0;
}

// Overloaded addition operator
SparseMatrix SparseMatrix::operator+(const SparseMatrix& other) const {
    if (numRows != other.numRows || numCols != other.numCols) {
        throw invalid_argument("Matrix dimensions do not match for addition");
    }

    SparseMatrix result(numRows, numCols);
    result.matrixData = matrixData;

    for (const auto& entry : other.matrixData) {
        result.matrixData[entry.first] += entry.second;
    }

    return result;
}

// Overloaded subtraction operator
SparseMatrix SparseMatrix::operator-(const SparseMatrix& other) const {
    if (numRows != other.numRows || numCols != other.numCols) {
        throw invalid_argument("Matrix dimensions do not match for subtraction");
    }

    SparseMatrix result(numRows, numCols);
    result.matrixData = matrixData;

    for (const auto& entry : other.matrixData) {
        result.matrixData[entry.first] -= entry.second;
    }

    return result;
}

// Overloaded multiplication operator
SparseMatrix SparseMatrix::operator*(const SparseMatrix& other) const {
    if (numCols != other.numRows) {
        throw invalid_argument("Matrix dimensions do not match for multiplication");
    }

    SparseMatrix result(numRows, other.numCols);

    for (const auto& entryA : matrixData) {
        int rowA = entryA.first.first;
        int colA = entryA.first.second;
        int valueA = entryA.second;

        for (int colB = 0; colB < other.numCols; colB++) {
            int valueB = other.getElement(colA, colB);
            if (valueB != 0) {
                result.matrixData[{rowA, colB}] += valueA * valueB;
            }
        }
    }

    return result;
}

// Print the sparse matrix
void SparseMatrix::print() const {
    for (const auto& entry : matrixData) {
        cout << "(" << entry.first.first << ", " << entry.first.second << ", " << entry.second <<
