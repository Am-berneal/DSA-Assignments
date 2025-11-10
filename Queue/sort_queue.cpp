#include <iostream>
#include <queue>
#include<climits>
using namespace std;

// Function to find index of minimum element in queue (up to sortedIndex)
int findMinIndex(queue<int>& q, int sortedIndex) {
    int minIndex = -1;
    int minValue = INT_MAX;
    int size = q.size();

    for (int i = 0; i < size; i++) {
        int current = q.front();
        q.pop();

        if (current <= minValue && i <= sortedIndex) {
            minValue = current;
            minIndex = i;
        }

        q.push(current);
    }
    return minIndex;
}

// Function to move the element at minIndex to the rear of the queue
void insertMinToRear(queue<int>& q, int minIndex) {
    int size = q.size();
    int minValue;
    for (int i = 0; i < size; i++) {
        int current = q.front();
        q.pop();

        if (i == minIndex)
            minValue = current;
        else
            q.push(current);
    }
    q.push(minValue);
}

// Main sort function
void sortQueue(queue<int>& q) {
    for (int i = q.size() - 1; i >= 0; i--) {
        int minIndex = findMinIndex(q, i);
        insertMinToRear(q, minIndex);
    }
}

int main() {
    queue<int> q;

    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
