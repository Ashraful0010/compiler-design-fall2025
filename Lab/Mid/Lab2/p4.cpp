#include <iostream>
using namespace std;

// Function to check if the given string is a valid identifier
bool isIdentifier(string str) {
    if (str.empty()) return false;  // Empty string is not a valid identifier

    // Check first character: must be alphabet or underscore
    char first = str[0];
    if (!((first >= 'A' && first <= 'Z') || 
          (first >= 'a' && first <= 'z') || 
          (first == '_'))) {
        return false;
    }

    // Check remaining characters: must be alphanumeric or underscore
    for (int i = 1; i < str.length(); i++) {
        char ch = str[i];
        if (!((ch >= 'A' && ch <= 'Z') || 
              (ch >= 'a' && ch <= 'z') || 
              (ch >= '0' && ch <= '9') || 
              (ch == '_'))) {
            return false;
        }
    }

    return true;
}

int main() {
    string input;

    cout << "Enter input: ";
    cin >> input;  // read single word input

    cout << "\nYou entered: " << input << endl;

    if (isIdentifier(input)) {
        cout << "Result: This is a valid identifier." << endl;
    } else {
        cout << "Result: This is not a valid identifier." << endl;
    }

    return 0;
}
