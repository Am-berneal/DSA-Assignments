#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool areEqual(vector<int>& a, vector<int>& b) {
    if (a.size() != b.size()) return false;

    unordered_map<int, int> freq;

    for (int x : a) freq[x]++;
    for (int x : b) freq[x]--;

    for (auto &p : freq)
        if (p.second != 0) return false;

    return true;
}

int main() {
    vector<int> a = {1, 7, 1};
    vector<int> b = {7, 7, 1};

    if (areEqual(a, b))
        cout << "true";
    else
        cout << "false";

    return 0;
}
