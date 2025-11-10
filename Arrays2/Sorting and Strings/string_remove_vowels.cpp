#include <iostream>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    string result = "";
    for (char c : str) {
        if (!isVowel(c)) result += c;
    }
    cout << "String without vowels: " << result << endl;
    return 0;
}
