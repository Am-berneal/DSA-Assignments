#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX], n = 0;

// Function to create array
void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
}

// Function to display array
void display() {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements are: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// Function to insert element
void insert() {
    int pos, val;
    cout << "Enter position and value: ";
    cin >> pos >> val;
    if (pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

// Function to delete element
void deleteElement() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

// Linear Search
void linearSearch() {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i << endl;
            return;
        }
    }
    cout << "Element not found\n";
}

int main() {
    int choice;
    do {
        cout << "\n---MENU---\n";
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    return 0;
}
