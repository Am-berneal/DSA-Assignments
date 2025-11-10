#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }

    // Insertion at beginning
    void insertBeginning(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = head;
        head = temp;
    }

    // Insertion at end
    void insertEnd(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = nullptr;
        if (!head) { head = temp; return; }
        Node* ptr = head;
        while (ptr->next) ptr = ptr->next;
        ptr->next = temp;
    }

    // Insertion before/after a node with given value
    void insertAfter(int val, int x) {
        Node* ptr = head;
        while (ptr && ptr->data != val) ptr = ptr->next;
        if (!ptr) { cout << "Value not found\n"; return; }
        Node* temp = new Node();
        temp->data = x;
        temp->next = ptr->next;
        ptr->next = temp;
    }

    void insertBefore(int val, int x) {
        if (!head) return;
        if (head->data == val) { insertBeginning(x); return; }
        Node* ptr = head;
        while (ptr->next && ptr->next->data != val) ptr = ptr->next;
        if (!ptr->next) { cout << "Value not found\n"; return; }
        Node* temp = new Node();
        temp->data = x;
        temp->next = ptr->next;
        ptr->next = temp;
    }

    // Deletion from beginning
    void deleteBeginning() {
        if (!head) { cout << "List is empty\n"; return; }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted\n";
        delete temp;
    }

    // Deletion from end
    void deleteEnd() {
        if (!head) { cout << "List is empty\n"; return; }
        if (!head->next) { cout << head->data << " deleted\n"; delete head; head=nullptr; return; }
        Node* ptr = head;
        while (ptr->next->next) ptr = ptr->next;
        cout << ptr->next->data << " deleted\n";
        delete ptr->next;
        ptr->next = nullptr;
    }

    // Deletion of specific node
    void deleteNode(int val) {
        if (!head) return;
        if (head->data == val) { deleteBeginning(); return; }
        Node* ptr = head;
        while (ptr->next && ptr->next->data != val) ptr = ptr->next;
        if (!ptr->next) { cout << "Value not found\n"; return; }
        Node* temp = ptr->next;
        ptr->next = temp->next;
        cout << temp->data << " deleted\n";
        delete temp;
    }

    // Search
    void search(int val) {
        Node* ptr = head;
        int pos = 1;
        while (ptr) {
            if (ptr->data == val) { cout << "Found at position " << pos << endl; return; }
            ptr = ptr->next;
            pos++;
        }
        cout << "Value not found\n";
    }

    // Display
    void display() {
        if (!head) { cout << "List is empty\n"; return; }
        Node* ptr = head;
        cout << "List: ";
        while (ptr) { cout << ptr->data << " -> "; ptr = ptr->next; }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, ref;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After a Node\n4. Insert Before a Node\n";
        cout << "5. Delete from Beginning\n6. Delete from End\n7. Delete a Node\n8. Search\n9. Display\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; list.insertBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; list.insertEnd(val); break;
            case 3: cout << "Enter node value to insert after and new value: "; cin >> ref >> val; list.insertAfter(ref,val); break;
            case 4: cout << "Enter node value to insert before and new value: "; cin >> ref >> val; list.insertBefore(ref,val); break;
            case 5: list.deleteBeginning(); break;
            case 6: list.deleteEnd(); break;
            case 7: cout << "Enter value to delete: "; cin >> val; list.deleteNode(val); break;
            case 8: cout << "Enter value to search: "; cin >> val; list.search(val); break;
            case 9: list.display(); break;
            case 10: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
