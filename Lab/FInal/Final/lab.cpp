#include <iostream>
#include <string>
using namespace std;

int main() {

    // DFA states are represented by integers
    // D0 = 0, D1 = 1, D2 = 2, D3 = 3, D4 = 4

    int state = 0; // Start state D0
    string input;

    cout << "Enter a string consisting of a and b: ";
    cin >> input;

    // Process each character of the input string
    for (int i = 0; i < input.length(); i++) {

        char ch = input[i];

        // State transitions
        if (state == 0) {          // D0
            if (ch == 'a') state = 1;
            else if (ch == 'b') state = 0;
            else {
                cout << "Invalid character\n";
                return 0;
            }
        }

        else if (state == 1) {     // D1
            if (ch == 'a') state = 2;
            else if (ch == 'b') state = 3;
            else {
                cout << "Invalid character\n";
                return 0;
            }
        }

        else if (state == 2) {     // D2 (Accepting)
            if (ch == 'a') state = 2;
            else if (ch == 'b') state = 3;
            else {
                cout << "Invalid character\n";
                return 0;
            }
        }

        else if (state == 3) {     // D3
            if (ch == 'a') state = 4;
            else if (ch == 'b') state = 0;
            else {
                cout << "Invalid character\n";
                return 0;
            }
        }

        else if (state == 4) {     // D4 (Accepting)
            if (ch == 'a') state = 2;
            else if (ch == 'b') state = 3;
            else {
                cout << "Invalid character\n";
                return 0;
            }
        }
    }

    // Check if final state is accepting
    if (state == 2 || state == 4) {
        cout << "String Accepted\n";
    } else {
        cout << "String Rejected\n";
    }

    return 0;
}
