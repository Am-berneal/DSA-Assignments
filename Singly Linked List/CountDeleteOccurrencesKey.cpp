#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

Node* deleteAllOccurrences(Node* head, int key, int &count) {
    count = 0;
    Node* dummy = new Node(); dummy->next = head;
    Node* prev = dummy;
    Node* curr = head;

    while (curr) {
        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count++;
        } else { prev = curr; curr = curr->next; }
    }
    head = dummy->next;
    delete dummy;
    return head;
}

void display(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{1, new Node{2, new Node{1, new Node{3, new Node{1,nullptr}}}}}}};
    int key = 1;
    int count;
    cout << "Original List: "; display(head);
    head = deleteAllOccurrences(head, key, count);
    cout << "Count: " << count << "\nUpdated List: "; display(head);
    return 0;
}
