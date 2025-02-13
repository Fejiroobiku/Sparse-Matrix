#include <iostream>
#include "SparseMatrix.h"
#include "file_handler.h"

using namespace std;

int main() {
    string file1, file2, outputFile;
    int choice;

    cout << "Enter first matrix file path: ";
    cin >> file1;
    cout << "Enter second matrix file path: ";
    cin >> file2;
    cout << "Enter output file path: ";
    cin >> outputFile;

    try {
        // Load matrices from files
        SparseMatrix matrix1 = FileHandler::readMatrixFromFile(file1);
        SparseMatrix matrix2 = FileHandler::readMatrixFromFile(file2);
        SparseMatrix result;

        cout << "Select an operation:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            result = matrix1 + matrix2;
        } else if (choice == 2) {
            result = matrix1 - matrix2;
        } else if (choice == 3) {
            result = matrix1 * matrix2;
        } else {
            cerr << "Invalid choice!" << endl;
            return 1;
        }

        // Write result to output file
        FileHandler::writeMatrixToFile(outputFile, result);
        cout << "Operation completed! Result saved to " << outputFile << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
