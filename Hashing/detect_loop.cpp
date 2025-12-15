#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

bool hasLoop(Node* head) {
    unordered_set<Node*> visited;

    Node* curr = head;
    while (curr != nullptr) {
        if (visited.count(curr))
            return true;     // Loop detected

        visited.insert(curr);
        curr = curr->next;
    }
    return false;            // No loop
}

int main() {
    // Creating linked list: 1 → 2 → 3 → 4 → 2 (loop)
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // Creates loop

    if (hasLoop(n1))
        cout << "true";
    else
        cout << "false";

    return 0;
}
