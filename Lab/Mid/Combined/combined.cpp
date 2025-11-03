#include <iostream>
using namespace std;

//Option 1
bool isNumericConstant(string str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

//Option 2
void findOperators(string str) {
    cout << "Input expression: " << str << endl;
    cout << "Operators found: " << endl;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '=') {
            cout << "Operator: " << str[i] << endl;
        }
    }
}

//Option 3
void checkComment(string str) {
    cout << "Input: " << str << endl;
    if (str.length() >= 2 && str[0] == '/' && str[1] == '/')
        cout << "This is a single line comment." << endl;
    else if (str.length() >= 4 && str[0] == '/' && str[1] == '*' && 
        str[str.length() - 2] == '*' && str[str.length() - 1] == '/')
        cout << "This is a multi-line comment." << endl;
    else
        cout << "This is not a comment." << endl;
}

//Option 4
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

//Option 5
void findAverage() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    float avg = (float)sum / n;
    cout << "Average value = " << avg << endl;
}

//Option 6 
void findMinMax() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
}

//Option 7
void concatenateStrings() {
    string firstName, lastName, fullName;

    cout << "Enter your first name: ";
    cin.ignore();  // clear newline from previous input
    getline(cin, firstName);

    cout << "Enter your last name: ";
    getline(cin, lastName);

    fullName = firstName + " " + lastName;

    cout << "Full name = " << fullName << endl;
}

//main function using switch case
int main() {
    int choice;
    string input;

    cout << "========= MENU =========" << endl;
    cout << "1. Check Numeric Constant" << endl;
    cout << "2. Check Operators" << endl;
    cout << "3. Check Comment Line(s)" << endl;
    cout << "4. Check Identifier" << endl;
    cout << "5. Find Average of Array" << endl;
    cout << "6. Find Min and Max of Array" << endl;
    cout << "7. Concatenate Strings" << endl;
    cout << "========================" << endl;

    cout << "Enter your choice (1-7): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter input: ";
            cin >> input;
            if (isNumericConstant(input))
                cout << input << " is a numeric constant." << endl;
            else
                cout << input << " is not a numeric constant." << endl;
            break;

        case 2:
            cout << "Enter an expression: ";
            cin >> input;
            findOperators(input);
            break;

        case 3:
            cout << "Enter a line: ";
            cin.ignore();
            getline(cin, input);
            checkComment(input);
            break;

        case 4:
            cout << "Enter input: ";
            cin >> input;
            if (isIdentifier(input))
                cout << input << " is a valid identifier." << endl;
            else
                cout << input << " is not a valid identifier." << endl;
            break;

        case 5:
            findAverage();
            break;

        case 6:
            findMinMax();
            break;

        case 7:
            concatenateStrings();
            break;

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
