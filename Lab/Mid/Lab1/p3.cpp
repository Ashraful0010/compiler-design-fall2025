#include <iostream>
#include <string>
using namespace std;

int checkComment(string str) {

    // single comment check
    if (str.length() >= 2 && str[0] == '/' && str[1] == '/') {
        return 1;
    }

    // multi line comment check
    if (str.length() >= 4 && str[0] == '/' && str[1] == '*' && 
        str[str.length() - 2] == '*' && str[str.length() - 1] == '/') {
        return 2;
    }

    return 0; //no comment
}

int main() {
    string input;

    cout << "Enter input: ";
    getline(cin, input);
    cout << "\nYou entered: " << input << endl;

    int result = checkComment(input);

    if (result == 1) {
        cout << "Result: This is a single-line comment." << endl;
    } 
    else if (result == 2) {
        cout << "Result: This is a multi-line comment." << endl;
    } 
    else {
        cout << "Result: This is not a comment." << endl;
    }

    return 0;
}
