#include <iostream>
using namespace std;

int main() {
    string firstName, lastName, fullName;

    cout << "Enter your first name: ";
    getline(cin, firstName); 
    cout << "Enter your last name: ";
    getline(cin, lastName); 

    fullName = firstName + " " + lastName;

    cout << "Full name = " << fullName << endl;

    return 0;
}
