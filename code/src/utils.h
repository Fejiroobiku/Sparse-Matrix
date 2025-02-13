#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

using namespace std;

// Function to trim leading and trailing whitespaces from a string
string trim(const string& str);

// Function to split a string by a given delimiter
vector<string> split(const string& str, char delimiter);

// Function to check if a given string represents a valid integer
bool isInteger(const string& str);

// Function to validate a matrix entry format from input file
void validateMatrixFormat(const string& line);

#endif // UTILS_H
