#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerElement(vector<int>& A) {
    vector<int> result;
    stack<int> st;   // will store previous elements

    for (int i = 0; i < A.size(); i++) {

        // remove elements that are greater than or equal to A[i]
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }

        // if stack becomes empty, no smaller element on left
        if (st.empty())
            result.push_back(-1);
        else
            result.push_back(st.top());  // nearest smaller element

        // push current element
        st.push(A[i]);
    }

    return result;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};

    vector<int> res = nearestSmallerElement(A);

    cout << "Nearest smaller element (on left) for each element:\n";
    for (int x : res)
        cout << x << " ";

    return 0;
}
