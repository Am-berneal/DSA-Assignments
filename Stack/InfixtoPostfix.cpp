#include <iostream>
#include <stack>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string exp) {
    stack<char> s;
    string result = "";

    for (char c : exp) {
        if (isalnum(c)) result += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top(); s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && prec(s.top()) >= prec(c)) {
                result += s.top(); s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) { result += s.top(); s.pop(); }
    return result;
}

int main() {
    string exp;
    cout << "Enter Infix: ";
    cin >> exp;
    cout << "Postfix: " << infixToPostfix(exp) << endl;
    return 0;
}
