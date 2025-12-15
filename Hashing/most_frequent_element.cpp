#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 4, 1};

    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;

    int ans = -1, maxFreq = 0;

    for (auto &p : freq) {
        int value = p.first;
        int count = p.second;

        if (count > maxFreq || (count == maxFreq && value > ans)) {
            ans = value;
            maxFreq = count;
        }
    }

    cout << ans;
    return 0;
}
