// Filename: SplitCircularLinkedList.cpp
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

// Insert node at end (create / maintain circular linked list)
void insertEnd(Node* &head, int val) {
    Node* newNode = new Node(val);

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

// Function to split circular linked list into two halves
void splitCircularList(Node* head, Node* &head1, Node* &head2) {
    if (head == NULL || head->next == head) {
        head1 = head;
        head2 = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Using slow-fast pointer technique
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // If even number of nodes, adjust fast pointer
    if (fast->next->next == head)
        fast = fast->next;

    // Set heads of two halves
    head1 = head;
    head2 = slow->next;

    // Break first list circular link
    slow->next = head1;

    // Complete circular link for second list
    fast->next = head2;
}

// Display circular linked list
void display(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main() {
    Node* head = NULL;
    Node* head1 = NULL;
    Node* head2 = NULL;

    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);
    insertEnd(head, 60);

    splitCircularList(head, head1, head2);

    cout << "First Circular Linked List: ";
    display(head1);

    cout << "\nSecond Circular Linked List: ";
    display(head2);

    return 0;
}
