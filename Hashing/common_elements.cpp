#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};

    unordered_set<int> setA(A.begin(), A.end());

    cout << "Common elements: ";

    for (int x : B) {
        if (setA.count(x)) {
            cout << x << " ";
        }
    }
    return 0;
}
