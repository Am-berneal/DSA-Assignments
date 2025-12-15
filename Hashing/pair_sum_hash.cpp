#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    unordered_set<int> seen;

    for (int x : arr) {
        if (seen.count(target - x)) {
            cout << "true";
            return 0;
        }
        seen.insert(x);
    }

    cout << "false";
    return 0;
}
