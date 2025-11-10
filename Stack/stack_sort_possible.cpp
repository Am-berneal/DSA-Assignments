#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool canBeSortedUsingStack(vector<int>& A) {
    stack<int> S;
    int expected = 1;   // for arrays containing 1..N

    for (int x : A) {
        S.push(x);

        while (!S.empty() && S.top() == expected) {
            S.pop();
            expected++;
        }
    }

    return S.empty();  // stack empty means all elements placed in sorted order
}

int main() {
    vector<int> A = {3, 1, 2};  // try changing and testing different inputs

    if (canBeSortedUsingStack(A))
        cout << "YES, array can be sorted using the stack.";
    else
        cout << "NO, array cannot be sorted using the stack.";

    return 0;
}
