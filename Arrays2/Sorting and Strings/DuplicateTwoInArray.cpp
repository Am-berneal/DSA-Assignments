// FILE NAME: DuplicateTwoInArray.cpp

#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int possible = n - 1;

    for (int i = 0; i <= possible; i++)
        if (arr[i] == 2)
            possible--;

    for (int i = possible; i >= 0; i--) {
        if (arr[i] == 2) {
            if (i + 2 < n) arr[i + 2] = 2;
            if (i + 1 < n) arr[i + 1] = 2;
        } else {
            if (i + 1 < n) arr[i + 1] = arr[i];
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    duplicateTwos(arr, n);

    cout << "Modified Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
