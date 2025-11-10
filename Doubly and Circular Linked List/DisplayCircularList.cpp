// Filename: DisplayCircularLinkedList.cpp
#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert node at end to create Circular Linked List
void insertEnd(Node* &head, int val) {
    Node* newNode = new Node(val);

    // If list is empty
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Display Circular Linked List and repeat head node value at end
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    // Print head node value again
    cout << head->data << endl;
}

int main() {
    Node* head = NULL;

    insertEnd(head, 20);
    insertEnd(head, 100);
    insertEnd(head, 40);
    insertEnd(head, 80);
    insertEnd(head, 60);

    cout << "Circular Linked List values: ";
    display(head);

    return 0;
}
