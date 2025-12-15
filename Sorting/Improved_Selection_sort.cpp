#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        // If the left element is greater than right element, swap them
        if (arr[minIndex] > arr[maxIndex])
            swap(arr[minIndex], arr[maxIndex]);

        // Scan the remaining unsorted array
        for (int i = left + 1; i < right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place minimum element at its correct position
        swap(arr[left], arr[minIndex]);

        // If max element was swapped earlier, update maxIndex
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place maximum element at its correct position
        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
