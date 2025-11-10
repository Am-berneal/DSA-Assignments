#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

// Insert node at the end
void insertEnd(Node* &head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to reverse every group of k nodes in a Doubly Linked List
Node* reverseInGroups(Node* head, int k) {
    if (head == NULL)
        return NULL;

    Node* current = head;
    Node* nextNode = NULL;
    Node* prevNode = NULL;
    int count = 0;

    // Reverse first k nodes of the list
    while (current != NULL && count < k) {
        nextNode = current->next;
        current->next = prevNode;
        current->prev = nextNode;

        prevNode = current;
        current = nextNode;
        count++;
    }

    // nextNode is now at (k+1)th node
    // Recursively reverse remaining nodes
    if (nextNode != NULL) {
        head->next = reverseInGroups(nextNode, k);
        if (head->next != NULL)
            head->next->prev = head;
    }

    // prevNode is new head of reversed group
    return prevNode;
}

// Display Doubly Linked List
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    // Example input
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);
    insertEnd(head, 60);
    insertEnd(head, 70);

    int k = 3;

    cout << "Original Doubly Linked List:\n";
    display(head);

    head = reverseInGroups(head, k);

    cout << "\n\nDoubly Linked List after reversing every group of " << k << " nodes:\n";
    display(head);

    return 0;
}
