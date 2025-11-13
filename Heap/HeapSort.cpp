#include <iostream>
#include <algorithm>
using namespace std;

// Function to heapify a subtree rooted with node i
void heapify(int arr[], int n, int i, bool isMaxHeap) {
    int extreme = i; // Initialize largest/smallest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // For increasing order (Max Heap)
    if (isMaxHeap) {
        if (l < n && arr[l] > arr[extreme])
            extreme = l;
        if (r < n && arr[r] > arr[extreme])
            extreme = r;
    }
    // For decreasing order (Min Heap)
    else {
        if (l < n && arr[l] < arr[extreme])
            extreme = l;
        if (r < n && arr[r] < arr[extreme])
            extreme = r;
    }

    // If root is not the extreme (largest/smallest)
    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, isMaxHeap);
    }
}

// Heap Sort Function
void heapSort(int arr[], int n, bool increasing = true) {
    bool isMaxHeap = increasing; // True → MaxHeap for ascending order

    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0, isMaxHeap);
    }

    // If decreasing order, reverse array (since MinHeap gives descending)
    if (!increasing)
        reverse(arr, arr + n);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr, n, true); // Increasing order
    cout << "Heap Sort (Increasing order): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int arr2[] = {12, 11, 13, 5, 6, 7};
    heapSort(arr2, n, false); // Decreasing order
    cout << "Heap Sort (Decreasing order): ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
