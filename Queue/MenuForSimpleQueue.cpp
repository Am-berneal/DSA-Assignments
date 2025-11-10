#include <iostream>
using namespace std;
#define MAX 100

class Queue {
    int front, rear;
    int arr[MAX];
public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == MAX - 1; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Overflow!\n"; return; }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
        cout << x << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow!\n"; return; }
        cout << arr[front] << " dequeued\n";
        if (front == rear) front = rear = -1;
        else front++;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Front Element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is Empty\n"; return; }
        cout << "Queue Elements: ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, val;

    while (true) {
        cout << "\n--- Queue Menu ---\n1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Peek\n6. Display\n7. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: cout << (q.isEmpty() ? "Empty" : "Not Empty") << endl; break;
            case 4: cout << (q.isFull() ? "Full" : "Not Full") << endl; break;
            case 5: q.peek(); break;
            case 6: q.display(); break;
            case 7: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
