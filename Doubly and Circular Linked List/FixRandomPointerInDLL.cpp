#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure for Doubly Linked List with Random pointer
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        prev = next = random = NULL;
    }
};

// Insert node at end
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

// Fix incorrect random pointer
void fixRandomPointer(Node* head, int incorrectValue, int correctValue) {
    unordered_map<int, Node*> nodeMap;
    Node* temp = head;

    // Step 1: Map data to respective node pointers
    while (temp != NULL) {
        nodeMap[temp->data] = temp;
        temp = temp->next;
    }

    // Step 2: Find wrong random pointer and correct it
    temp = head;
    while (temp != NULL) {
        if (temp->random != NULL && temp->random->data == incorrectValue) {
            temp->random = nodeMap[correctValue];  // correcting pointer
            cout << "✅ Random Pointer Fixed for Node " << temp->data << endl;
            return;
        }
        temp = temp->next;
    }
}

// Display list with random pointers
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node " << temp->data;
        if (temp->random)
            cout << " (Random → " << temp->random->data << ")";

        cout << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    // Random pointers
    head->random = head->next;       // 10 → 20
    head->next->random = head->next->next->next; // 20 → 40 (Incorrect random pointer)
    head->next->next->random = head; // 30 → 10
    head->next->next->next->random = head->next; // 40 → 20

    cout << "Before fixing:\n";
    display(head);

    // Correct wrong random pointer (20 should point to 30, not 40)
    fixRandomPointer(head, 40, 30);

    cout << "\nAfter fixing:\n";
    display(head);

    return 0;
}
