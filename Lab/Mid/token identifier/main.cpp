#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;
 
// List of keywords
vector<string> keywords = {"int", "return", "main"};
 
// Function to check if a string is a keyword
bool isKeyword(const string &str) {
    for (auto k : keywords)
        if (str == k) return true;
    return false;
}
 
// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' ;
}
 
// Function to check if a character is a delimiter
bool isDelimiter(char ch) {
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' || ch == ',';
}
 
int main() {
    ifstream file("sample.txt");  // open the file
    if (!file.is_open()) {
        cout << "Failed to open file!" << endl;
        return 1;
    }
 
    string line;
    while (getline(file, line)) {
        string token = "";
        for (char ch : line) {
            if (isspace(ch) || isOperator(ch) || isDelimiter(ch)) {
                if (!token.empty()) {
                    if (isKeyword(token))
                        cout << "<Keyword> " << token << endl;
                    else
                        cout << "<Identifier> " << token << endl;
                    token = "";
                }
 
                if (isOperator(ch))
                    cout << "<Operator> " << ch << endl;
                if (isDelimiter(ch))
                    cout << "<Delimiter> " << ch << endl;
            } else {
                token += ch; // build token
            }
        }
    }
 
    file.close();
    return 0;
}