#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert (helper for BST creation)
Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// (a) Search Recursive
Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// (a) Search Non-Recursive
Node* searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// (b) Maximum element
Node* findMax(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

// (c) Minimum element
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// (d) Inorder Successor (next greater)
Node* inorderSuccessor(Node* root, Node* node) {
    Node* successor = NULL;
    while (root) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

// (e) Inorder Predecessor (next smaller)
Node* inorderPredecessor(Node* root, Node* node) {
    Node* predecessor = NULL;
    while (root) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    for (int val : arr) root = insert(root, val);

    int key = 60;
    Node* s = searchRecursive(root, key);
    cout << "Recursive Search: " << (s ? "Found" : "Not Found") << endl;

    s = searchNonRecursive(root, key);
    cout << "Non-Recursive Search: " << (s ? "Found" : "Not Found") << endl;

    cout << "Max Element: " << findMax(root)->data << endl;
    cout << "Min Element: " << findMin(root)->data << endl;

    cout << "Inorder Successor of 60: " << inorderSuccessor(root, s)->data << endl;
    cout << "Inorder Predecessor of 60: " << inorderPredecessor(root, s)->data << endl;

    return 0;
}
