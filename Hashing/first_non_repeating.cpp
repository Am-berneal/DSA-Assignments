#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};
    unordered_map<int, int> freq;

    for (int n : nums) freq[n]++;

    for (int n : nums) {
        if (freq[n] == 1) {
            cout << n;
            return 0;
        }
    }

    // If none found
    cout << "No non-repeating element";
    return 0;
}
