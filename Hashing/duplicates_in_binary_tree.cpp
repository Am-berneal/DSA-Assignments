#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

bool checkDuplicates(Node* root, unordered_set<int>& seen) {
    if (root == nullptr)
        return false;

    if (seen.count(root->data))
        return true; // Duplicate value found

    seen.insert(root->data);

    return checkDuplicates(root->left, seen) ||
           checkDuplicates(root->right, seen);
}

int main() {
    /*
            5
           / \
          3   7
         /   /
        2   3   <-- duplicate value (3)
    */

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->right->left = new Node(3); // duplicate value

    unordered_set<int> seen;

    if (checkDuplicates(root, seen))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
