#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k): key(k), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

Node* search(Node* root, int key) {
    if (!root || root->key == key) return root;
    return key < root->key ? search(root->left, key) : search(root->right, key);
}

int main() {
    Node* root = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = insert(root, x);
    }
    inorder(root);
    cout << "\nEnter key to search: ";
    int k; cin >> k;
    cout << (search(root, k) ? "Found" : "Not Found");
}
