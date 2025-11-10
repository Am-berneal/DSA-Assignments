// Filename: MenuDriven_Circular_Doubly_LinkedList.cpp

#include <iostream>
using namespace std;

// ---------------- DOUBLY LINKED LIST ----------------
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyList {
public:
    DNode* head = NULL;

    // Insert as first, last, or before/after specific node
    void insert(int val, int key = -1, bool before = false, bool after = false) {
        DNode* newNode = new DNode(val);
        if (!head) { head = newNode; return; }

        if (key == -1) { // Insert at beginning
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;

        if (!temp) return;

        if (before) {
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev) temp->prev->next = newNode;
            else head = newNode;
            temp->prev = newNode;
        } else if (after) {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    // Delete node
    void deleteNode(int key) {
        if (!head) return;
        DNode* temp = head;

        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;

        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp == head) head = temp->next;

        delete temp;
    }

    void search(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
        }
        cout << "Not found\n";
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ---------------- CIRCULAR LINKED LIST ----------------
struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(NULL) {}
};

class CircularList {
public:
    CNode* head = NULL;

    void insert(int val, int key = -1, bool before = false, bool after = false) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = newNode;
            return;
        }

        if (key == -1) { // Insert at beginning
            CNode* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
            return;
        }

        CNode* temp = head;
        do {
            if (temp->data == key) break;
            temp = temp->next;
        } while (temp != head);

        if (after) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else if (before) {
            CNode* prev = head;
            while (prev->next != temp) prev = prev->next;
            prev->next = newNode;
            newNode->next = temp;
        }
    }

    void deleteNode(int key) {
        if (!head) return;

        CNode* temp = head;
        CNode* prev = NULL;

        do {
            if (temp->data == key) break;
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (temp == head && temp->next == head) {
            head = NULL;
            delete temp;
            return;
        }

        if (temp == head) {
            CNode* last = head;
            while (last->next != head) last = last->next;
            head = head->next;
            last->next = head;
        } else {
            prev->next = temp->next;
        }

        delete temp;
    }

    void search(int key) {
        CNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
        } while (temp != head);
        cout << "Not found\n";
    }

    void display() {
        if (!head) return;
        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl; // repeating head at end
    }
};

int main() {
    DoublyList dl;
    CircularList cl;

    cout << "\n✅ Menu Driven Program for Doubly & Circular Linked List Completed\n";
    return 0;
}
