#include <iostream>
#include <stack>
using namespace std;

int evalPostfix(string exp) {
    stack<int> s;
    for (char c : exp) {
        if (isdigit(c)) s.push(c - '0');
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if (c == '+') s.push(a + b);
            else if (c == '-') s.push(a - b);
            else if (c == '*') s.push(a * b);
            else if (c == '/') s.push(a / b);
        }
    }
    return s.top();
}

int main() {
    string exp;
    cout << "Enter Postfix: ";
    cin >> exp;
    cout << "Result: " << evalPostfix(exp) << endl;
    return 0;
}
