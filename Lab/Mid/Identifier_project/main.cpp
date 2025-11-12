#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isIdentifier(string str){
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



int main() {
    ifstream file("sample.txt");

    if (!file){
        cout << "File cannot be opened!" << endl;
        return 1;
    }

    string word;
    while (getline(file, word)) {
        if (isIdentifier(word)) {
            cout << word << " is a valid identifier." << endl;
        } else {
            cout << word << " is not a valid identifier." << endl;
        }
    }
    file.close();
    return 0;
}
