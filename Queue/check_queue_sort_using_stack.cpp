#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSortingPossible(queue<int>& q) {
    stack<int> st;
    int expected = 1;
    int n = q.size();

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // If current element is the expected number
        if (front == expected) {
            expected++;
        }
        // If stack top is the expected number
        else if (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
            q.push(front); // process front again
        }
        // Else push into stack
        else {
            st.push(front);
        }
    }

    // Now empty the stack too
    while (!st.empty() && st.top() == expected) {
        st.pop();
        expected++;
    }

    return (expected == n + 1);
}

int main() {
    queue<int> q;

    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (checkSortingPossible(q))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
