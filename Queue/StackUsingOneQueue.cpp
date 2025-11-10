#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int n = q.size();
        while (n > 1) { q.push(q.front()); q.pop(); n--; }
    }

    void pop() {
        if (q.empty()) { cout << "Stack Underflow\n"; return; }
        cout << q.front() << " popped\n";
        q.pop();
    }

    int top() {
        if (!q.empty()) return q.front();
        return -1;
    }

    bool empty() { return q.empty(); }
};

int main() {
    Stack s;
    s.push(10); s.push(20); s.push(30);
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top: " << s.top() << endl;
    return 0;
}
