#include <iostream>
using namespace std;
#define MAX 100

class Stack {
    int top;
    int arr[MAX];
public:
    Stack() { top = -1; }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == MAX - 1; }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top Element: " << arr[top] << endl;
    }
};

int main() {
    Stack st;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; st.push(value); break;
            case 2: st.pop(); break;
            case 3: cout << (st.isEmpty() ? "Stack is Empty" : "Stack is Not Empty") << endl; break;
            case 4: cout << (st.isFull() ? "Stack is Full" : "Stack is Not Full") << endl; break;
            case 5: st.display(); break;
            case 6: st.peek(); break;
            case 7: return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
}
