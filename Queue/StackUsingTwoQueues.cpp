#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) { cout << "Stack Underflow\n"; return; }
        cout << q1.front() << " popped\n";
        q1.pop();
    }

    int top() {
        if (!q1.empty()) return q1.front();
        return -1;
    }

    bool empty() { return q1.empty(); }
};

int main() {
    Stack s;
    s.push(10); s.push(20); s.push(30);
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top: " << s.top() << endl;
    return 0;
}
