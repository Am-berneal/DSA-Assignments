#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if (isupper(ch)) ch = tolower(ch);
    cout << "Lowercase: " << ch << endl;
    return 0;
}
