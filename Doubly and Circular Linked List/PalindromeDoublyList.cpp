#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    char data;
    Node* prev;
    Node* next;

    Node(char x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

// Function to insert node at end
void insertEnd(Node* &head, char x) {
    Node* newNode = new Node(x);

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to check if a Doubly Linked List is Palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next)
        return true;

    Node* left = head;
    Node* right = head;

    // Move right pointer to last node
    while (right->next != nullptr)
        right = right->next;

    // Check characters from both ends
    while (left != right && right->next != left) { // handles even/odd nodes
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }
    return true;
}

// Display list
void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Example input
    insertEnd(head, 'R');
    insertEnd(head, 'A');
    insertEnd(head, 'D');
    insertEnd(head, 'A');
    insertEnd(head, 'R');

    cout << "Doubly Linked List: ";
    display(head);

    if (isPalindrome(head))
        cout << "True (The list is a palindrome)" << endl;
    else
        cout << "False (The list is not a palindrome)" << endl;

    return 0;
}

