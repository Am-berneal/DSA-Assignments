#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Insert at beginning
Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* getIntersection(Node* h1, Node* h2) {
    unordered_set<int> s;
    Node* temp = h1;

    while (temp) {
        s.insert(temp->data);
        temp = temp->next;
    }

    Node* result = nullptr;
    temp = h2;

    while (temp) {
        if (s.count(temp->data)) {
            result = insert(result, temp->data);
        }
        temp = temp->next;
    }

    return result;
}

Node* getUnion(Node* h1, Node* h2) {
    unordered_set<int> s;

    Node* temp = h1;
    while (temp) {
        s.insert(temp->data);
        temp = temp->next;
    }

    temp = h2;
    while (temp) {
        s.insert(temp->data);
        temp = temp->next;
    }

    Node* result = nullptr;
    for (int x : s) {
        result = insert(result, x);
    }

    return result;
}

int main() {
    // Example:
    // List 1: 10 -> 15 -> 4 -> 20
    // List 2: 8 -> 4 -> 2 -> 10

    Node* head1 = nullptr;
    head1 = insert(head1, 20);
    head1 = insert(head1, 4);
    head1 = insert(head1, 15);
    head1 = insert(head1, 10);

    Node* head2 = nullptr;
    head2 = insert(head2, 10);
    head2 = insert(head2, 2);
    head2 = insert(head2, 4);
    head2 = insert(head2, 8);

    Node* intersection = getIntersection(head1, head2);
    Node* unionList = getUnion(head1, head2);

    cout << "Intersection List: ";
    printList(intersection);

    cout << "Union List: ";
    printList(unionList);

    return 0;
}
