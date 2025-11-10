// Filename: ReverseInKGroups.cpp

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to reverse nodes in groups of K
Node* reverseK(Node* head, int k) {
    if (!head || k <= 1)
        return head;

    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    // Check if there are at least k nodes remaining
    Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (!temp) return head; // not enough nodes, return as is
        temp = temp->next;
    }

    // Reverse first k nodes
    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Recursively call for remaining list
    if (next != nullptr)
        head->next = reverseK(next, k);

    return prev;
}

// Utility function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Driver Code
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original Linked List:\n";
    printList(head);

    int k = 3;
    head = reverseK(head, k);

    cout << "\nLinked List after reversing in groups of " << k << ":\n";
    printList(head);

    return 0;
}
