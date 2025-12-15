#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    // Step 1: Find the maximum element in the array
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    // Step 2: Create count array of size maxVal + 1
    vector<int> count(maxVal + 1, 0);

    // Step 3: Store frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 4: Convert count array to prefix sum (cumulative)
    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    // Step 5: Create output array
    vector<int> output(n);

    // Step 6: Build output array (stable sorting)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 7: Copy sorted values back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
