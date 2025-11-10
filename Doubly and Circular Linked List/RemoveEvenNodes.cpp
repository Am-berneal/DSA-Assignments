// Filename: RemoveEvenNodes.cpp
#include <iostream>
using namespace std;

// ----------- DOUBLY LINKED LIST SECTION ------------

struct DNode {
    int data;
    DNode* next;
    DNode* prev;

    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

void insertEndD(DNode* &head, int val) {
    DNode* newNode = new DNode(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    DNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Remove even nodes from Doubly Linked List
void removeEvenD(DNode* &head) {
    DNode* temp = head;

    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            DNode* del = temp;

            if (temp == head) {
                head = head->next;
                if (head) head->prev = NULL;
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }

            temp = temp->next;
            delete del;
        } else {
            temp = temp->next;
        }
    }
}

void displayD(DNode* head) {
    DNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// ----------- CIRCULAR SINGLY LINKED LIST SECTION ------------

struct CNode {
    int data;
    CNode* next;

    CNode(int val) {
        data = val;
        next = NULL;
    }
};

void insertEndC(CNode* &head, int val) {
    CNode* newNode = new CNode(val);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Remove even nodes from Circular Linked List
void removeEvenC(CNode* &head) {
    if (head == NULL) return;

    CNode* temp = head;
    CNode* prev = NULL;

    // Loop through the circular linked list
    do {
        if (temp->data % 2 == 0) {
            if (temp == head) {  // deleting head
                CNode* last = head;

                while (last->next != head)
                    last = last->next;

                head = head->next;
                last->next = head;

                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }

    } while (temp != head);
}

// Display circular linked list
void displayC(CNode* head) {
    if (head == NULL) return;

    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

// ---------------- MAIN FUNCTION ----------------

int main() {
    // Doubly Linked List
    DNode* dHead = NULL;
    insertEndD(dHead, 10);
    insertEndD(dHead, 21);
    insertEndD(dHead, 32);
    insertEndD(dHead, 43);
    insertEndD(dHead, 54);

    cout << "Original Doubly Linked List: ";
    displayD(dHead);

    removeEvenD(dHead);
    cout << "\nAfter Removing Even Nodes (Doubly): ";
    displayD(dHead);


    // Circular Singly Linked List
    CNode* cHead = NULL;
    insertEndC(cHead, 15);
    insertEndC(cHead, 24);
    insertEndC(cHead, 35);
    insertEndC(cHead, 46);

    cout << "\n\nOriginal Circular Linked List: ";
    displayC(cHead);

    removeEvenC(cHead);
    cout << "\nAfter Removing Even Nodes (Circular): ";
    displayC(cHead);

    return 0;
}
