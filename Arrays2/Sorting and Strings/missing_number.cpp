#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int i = 0; i < n - 1; i++)
        actualSum += arr[i];
    return expectedSum - actualSum;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; // Missing 4
    int n = 6; // Array should have numbers from 1 to 6

    cout << "Missing number: " << findMissingNumber(arr, n) << endl;
    return 0;
}
