#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st;  // stores indices of days

    for (int i = n - 1; i >= 0; i--) {

        // pops all days with temperature <= current day
        while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
            st.pop();
        }

        // if stack is empty => no warmer day exists
        if (!st.empty())
            answer[i] = st.top() - i;

        // push current day's index into stack
        st.push(i);
    }

    return answer;
}

int main() {
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> result = dailyTemperatures(temp);

    cout << "Days to wait for warmer temperature:\n";
    for (int x : result)
        cout << x << " ";

    return 0;
}
