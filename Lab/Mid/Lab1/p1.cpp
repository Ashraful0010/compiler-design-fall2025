#include <iostream>
using namespace std;

bool isNumeric(const string &str) {
    if (str.empty()) return false;  

    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter something: ";
    cin >> input;

    if (isNumeric(input)) {
        cout << "The input is numeric." << endl;
    } else {
        cout << "The input is not numeric." << endl;
    }

    return 0;
}
