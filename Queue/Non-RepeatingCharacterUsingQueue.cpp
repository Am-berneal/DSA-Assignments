#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char c : str) {
        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1) q.pop();

        if (!q.empty()) cout << q.front() << " ";
        else cout << "-1 ";
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;
    firstNonRepeating(str);
    return 0;
}
