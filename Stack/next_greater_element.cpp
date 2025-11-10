#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;  // will store elements for which NGE is not found yet

    for (int i = n - 1; i >= 0; i--) {

        // remove all smaller or equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // if stack becomes empty -> no greater element exists
        nge[i] = (st.empty() ? -1 : st.top());

        // push current element for future comparisons
        st.push(arr[i]);
    }

    return nge;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = nextGreaterElement(arr);

    cout << "Next Greater Element for each element:\n";
    for (int x : result)
        cout << x << " ";

    return 0;
}
