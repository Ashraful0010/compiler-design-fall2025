#include <iostream>
#include <limits>
using namespace std;

//Option 1
bool isNumericConstant(string str) {
    int dot = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            if (i != 0) return false;
        }
        else if (str[i] == '.') {
            dot++;
            if (dot > 1) return false;
        }
        else if (str[i] < '0' || str[i] > '9') {
            return false; 
        }
    }
    if (str == "-" || str == "." || str == "-.") return false;

    return true;
}


//Option 2
void findOperators(string str) {
    cout << "Input expression: " << str << endl;
    cout << "Operators found: " << endl;

    bool plus = false, minus = false, mul = false, div = false, mod = false, eq = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+' && !plus) {
            cout << "Operator: +" << endl;
            plus = true;
        }
        else if (str[i] == '-' && !minus) {
            cout << "Operator: -" << endl;
            minus = true;
        }
        else if (str[i] == '*' && !mul) {
            cout << "Operator: *" << endl;
            mul = true;
        }
        else if (str[i] == '/' && !div) {
            cout << "Operator: /" << endl;
            div = true;
        }
        else if (str[i] == '%' && !mod) {
            cout << "Operator: %" << endl;
            mod = true;
        }
        else if (str[i] == '=' && !eq) {
            cout << "Operator: =" << endl;
            eq = true;
        }
    }
}


//Option 3 
void checkComment() {
    string line, str = "";
    cout << "Enter comment (or expression):" << endl;

    if (!getline(cin, line)) {
        cout << "\nNo input received." << endl;
        return;
    }
    str = line;

    if (str.rfind("//", 0) == 0) {
        cout << "\nInput:\n" << str << endl;
        cout << "This is a single-line comment." << endl;
        return;
    }

    if (str.find("/*") != string::npos) {
        if (str.find("*/") != string::npos) {
            cout << "\nInput:\n" << str << endl;
            cout << "This is a multi-line comment." << endl;
            return;
        }

        while (getline(cin, line)) {
            str += "\n" + line;
            if (line.find("*/") != string::npos) {
                cout << "\nInput:\n" << str << endl;
                cout << "This is a multi-line comment." << endl;
                return;
            }
        }
    }
    
    cout << "\nInput:\n" << str << endl;
    cout << "This is not a comment." << endl;
}

//Option 4
bool isIdentifier(string str) {
    if (str.empty()) return false;  
    
    char first = str[0];
    if (!((first >= 'A' && first <= 'Z') || 
          (first >= 'a' && first <= 'z') || 
          (first == '_'))) {
        return false;
    }

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
    getline(cin, firstName);

    cout << "Enter your last name: ";
    getline(cin, lastName);

    fullName = firstName + " " + lastName;

    cout << "Full name = " << fullName << endl;
}

int main() {
    int choice;
    string input;

    cout << "1. Check Numeric Constant" << endl;
    cout << "2. Check Operators" << endl;
    cout << "3. Check Comment Line(s)" << endl;
    cout << "4. Check Identifier" << endl;
    cout << "5. Find Average of Array" << endl;
    cout << "6. Find Min and Max of Array" << endl;
    cout << "7. Concatenate Strings" << endl;

    cout << "Enter your choice (1-7): ";
    cin >> choice;
    if (choice == 3 || choice == 7) { 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

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
           checkComment();
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
