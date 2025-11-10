// Filename: RemoveLoopFromLinkedList.cpp

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

// Function to detect and remove loop in linked list
void removeLoop(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    Node* slow = head;
    Node* fast = head;

    // Detect loop using Floyd’s cycle detection
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {   // loop detected
            break;
        }
    }

    // If no loop exists
    if (slow != fast)
        return;

    // Set slow to head and move both pointers at same pace to find loop start
    slow = head;
    Node* prev = nullptr;  // to track node before fast

    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // 'fast' is at loop start, prev points to last node in loop
    prev->next = nullptr;  // Remove loop
}

// Utility function to print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a loop: node 5 points back to node 3
    head->next->next->next->next->next = head->next->next;

    // Remove loop if exists
    removeLoop(head);

    cout << "Linked List after loop removal:\n";
    printList(head);

    return 0;
}
