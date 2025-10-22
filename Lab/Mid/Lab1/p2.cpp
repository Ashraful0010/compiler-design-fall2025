#include <iostream>
using namespace std;

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=') {
        return true;
    } else {
        return false;
    }
}

void findOperators(const string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (isOperator(str[i])) {
            cout << "Operator found: " << str[i]  << endl;
        }
    }
}
int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    findOperators(input);

    return 0;
}