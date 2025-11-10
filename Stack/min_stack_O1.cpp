#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long minVal;

public:
    void push(long long x) {
        if (st.empty()) {
            st.push(x);
            minVal = x;
        }
        else if (x >= minVal) {
            st.push(x);
        }
        else {
            // store modified value
            st.push(2*x - minVal);
            minVal = x;
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() < minVal) {
            // modified value → restore old minVal
            minVal = 2*minVal - st.top();
        }
        st.pop();
    }

    long long top() {
        if (st.empty()) return -1;

        return (st.top() < minVal) ? minVal : st.top();
    }

    long long getMin() {
        if (st.empty()) return -1;
        return minVal;
    }
};

int main() {
    MinStack s;
    s.push(5);
    s.push(3);
    s.push(7);

    cout << "Min: " << s.getMin() << endl;  // 3
    s.pop();

    cout << "Top: " << s.top() << endl;     // 3
    cout << "Min: " << s.getMin() << endl;  // 3

    return 0;
}
