#include <iostream>
using namespace std;
#define MAX 100

class CircularQueue {
    int front, rear;
    int arr[MAX];
public:
    CircularQueue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % MAX == front; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Overflow!\n"; return; }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        cout << x << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow!\n"; return; }
        cout << arr[front] << " dequeued\n";
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Front Element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is Empty\n"; return; }
        cout << "Queue Elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, val;

    while (true) {
        cout << "\n--- Circular Queue Menu ---\n1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Peek\n6. Display\n7. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; cq.enqueue(val); break;
            case 2: cq.dequeue(); break;
            case 3: cout << (cq.isEmpty() ? "Empty" : "Not Empty") << endl; break;
            case 4: cout << (cq.isFull() ? "Full" : "Not Full") << endl; break;
            case 5: cq.peek(); break;
            case 6: cq.display(); break;
            case 7: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
