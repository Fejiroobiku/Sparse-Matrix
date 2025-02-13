#include "utils.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

// Function to trim leading and trailing whitespaces from a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

// Function to split a string by a delimiter
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    
    while (getline(ss, token, delimiter)) {
        tokens.push_back(trim(token)); // Trim and store each token
    }
    return tokens;
}

// Function to check if a string represents an integer
bool isInteger(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c) && c != '-') return false;
    }
    return true;
}

// Function to validate matrix format and throw an error if incorrect
void validateMatrixFormat(const string& line) {
    if (line.empty()) return;
    
    // Check if line has parentheses
    if (line.front() != '(' || line.back() != ')') {
        throw invalid_argument("Input file has wrong format: " + line);
    }

    // Extract contents inside parentheses
    string content = line.substr(1, line.size() - 2);
    vector<string> values = split(content, ',');

    if (values.size() != 3 || !isInteger(values[0]) || !isInteger(values[1]) || !isInteger(values[2])) {
        throw invalid_argument("Invalid matrix entry format: " + line);
    }
}
