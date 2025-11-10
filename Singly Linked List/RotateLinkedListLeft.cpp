// Filename: RotateLinkedListLeft.cpp

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

// Function to rotate the linked list to the left by k positions
Node* rotateLeft(Node* head, int k) {
    if (head == nullptr || k == 0)
        return head;

    // Compute the length of the list
    Node* temp = head;
    int len = 1;
    while (temp->next != nullptr) {
        temp = temp->next;
        len++;
    }

    // Connect last node to head (circular list)
    temp->next = head;

    // Effective rotations (if k >= len)
    k = k % len;
    if (k == 0) {
        temp->next = nullptr;  // Break the loop
        return head;
    }

    // Move to the (k-1)th node
    Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    // New head is next of newTail
    Node* newHead = newTail->next;
    newTail->next = nullptr;  // Break the circle

    return newHead;
}

// Print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Driver code
int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;  // Rotate left by 2 positions

    cout << "Original List:\n";
    printList(head);

    head = rotateLeft(head, k);

    cout << "\nRotated List (Left by " << k << " positions):\n";
    printList(head);

    return 0;
}
