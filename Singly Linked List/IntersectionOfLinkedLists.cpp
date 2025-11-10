// Filename: IntersectionOfLinkedLists.cpp

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

// Function to get the intersection node of two linked lists
Node* getIntersectionNode(Node* headA, Node* headB) {
    if (headA == nullptr || headB == nullptr)
        return nullptr;

    Node* a = headA;
    Node* b = headB;

    // Traverse both lists; when reaching end, switch to the other list’s head
    while (a != b) {
        a = (a == nullptr) ? headB : a->next;
        b = (b == nullptr) ? headA : b->next;
    }

    return a;  // Either intersection node or nullptr
}

// Utility function to print list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating a Y-shaped linked list:
    // List A: 10 -> 20 -> 30 \
    //                         40 -> 50 -> NULL
    // List B:       25 ------/

    Node* newNode;

    // Common nodes
    Node* headCommon = new Node(40);
    headCommon->next = new Node(50);

    // List A
    Node* headA = new Node(10);
    headA->next = new Node(20);
    headA->next->next = new Node(30);
    headA->next->next->next = headCommon;

    // List B
    Node* headB = new Node(25);
    headB->next = headCommon;

    cout << "Linked List A: ";
    printList(headA);

    cout << "Linked List B: ";
    printList(headB);

    Node* intersection = getIntersectionNode(headA, headB);

    if (intersection != nullptr)
        cout << "\nIntersection Node: " << intersection->data << endl;
    else
        cout << "\nNo intersection found." << endl;

    return 0;
}
