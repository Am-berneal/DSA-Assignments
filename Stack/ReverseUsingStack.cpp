#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str, rev = "";
    cout << "Enter a string: ";
    cin >> str;

    stack<char> s;
    for (char c : str) s.push(c);
    while (!s.empty()) { rev += s.top(); s.pop(); }

    cout << "Reversed String: " << rev << endl;
    return 0;
}
