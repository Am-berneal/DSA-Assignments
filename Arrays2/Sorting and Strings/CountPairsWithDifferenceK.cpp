// FILE NAME: CountPairsWithDifferenceK.cpp

#include <iostream>
#include <unordered_set>
using namespace std;

int countPairsWithDiffK(int arr[], int n, int k) {
    unordered_set<int> s;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (s.count(arr[i] + k)) count++;
        if (s.count(arr[i] - k)) count++;
        s.insert(arr[i]);
    }
    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Count of pairs with difference " << k << ": "
         << countPairsWithDiffK(arr, n, k);

    return 0;
}
