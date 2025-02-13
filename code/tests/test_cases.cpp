#include <iostream>
#include <cassert>
#include "SparseMatrix.h"

void testAddition() {
    SparseMatrix mat1(5, 5);
    mat1.setElement(0, 1, 10);
    mat1.setElement(2, 3, 20);

    SparseMatrix mat2(5, 5);
    mat2.setElement(0, 1, 5);
    mat2.setElement(2, 3, -10);

    SparseMatrix result = mat1 + mat2;

    assert(result.getElement(0, 1) == 15);  // 10 + 5
    assert(result.getElement(2, 3) == 10);  // 20 - 10
    assert(result.getElement(1, 1) == 0);   // Default zero value

    std::cout << "Addition test passed!\n";
}

void testSubtraction() {
    SparseMatrix mat1(4, 4);
    mat1.setElement(1, 2, 8);
    mat1.setElement(3, 0, 12);

    SparseMatrix mat2(4, 4);
    mat2.setElement(1, 2, 3);
    mat2.setElement(3, 0, 7);

    SparseMatrix result = mat1 - mat2;

    assert(result.getElement(1, 2) == 5);  // 8 - 3
    assert(result.getElement(3, 0) == 5);  // 12 - 7
    assert(result.getElement(2, 2) == 0);  // Default zero value

    std::cout << "Subtraction test passed!\n";
}

void testMultiplication() {
    SparseMatrix mat1(2, 3);
    mat1.setElement(0, 1, 3);
    mat1.setElement(1, 2, 2);

    SparseMatrix mat2(3, 2);
    mat2.setElement(1, 0, 4);
    mat2.setElement(2, 1, 5);

    SparseMatrix result = mat1 * mat2;

    assert(result.getElement(0, 0) == 12);  // 3 * 4
    assert(result.getElement(1, 1) == 10);  // 2 * 5
    assert(result.getElement(0, 1) == 0);   // Default zero value

    std::cout << "Multiplication test passed!\n";
}

int main() {
    testAddition();
    testSubtraction();
    testMultiplication();
    std::cout << "All test cases passed successfully!\n";
    return 0;
}
