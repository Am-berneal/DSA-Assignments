#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node dynamically
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Create binary tree dynamically (User input)
Node* createTree() {
    int data;
    cout << "Enter node value (-1 for no node): ";
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = createNode(data);

    cout << "Enter left child of " << data << endl;
    root->left = createTree();

    cout << "Enter right child of " << data << endl;
    root->right = createTree();

    return root;
}

// Utility function to check BST using inorder traversal
bool isBSTUtil(Node* root, Node* &prev) {
    if (root == NULL) return true;

    if (!isBSTUtil(root->left, prev))
        return false;

    if (prev != NULL && root->data <= prev->data)
        return false;

    prev = root;

    return isBSTUtil(root->right, prev);
}

// Main function
bool isBST(Node* root) {
    Node* prev = NULL;
    return isBSTUtil(root, prev);
}

int main() {
    cout << "\nCreate Binary Tree:\n";
    Node* root = createTree();   // Dynamic tree creation by user

    if (isBST(root))
        cout << "\n✅ The given Binary Tree IS a BST\n";
    else
        cout << "\n❌ The given Binary Tree is NOT a BST\n";

    return 0;
}
