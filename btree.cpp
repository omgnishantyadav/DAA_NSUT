#include <bits/stdc++.h>
using namespace std;
#define T 2 // minimum degree (order = 2*T)

struct BTreeNode {
    vector<int> keys;
    vector<BTreeNode*> child;
    bool leaf;
    BTreeNode(bool l): leaf(l) {}
};

void traverse(BTreeNode* root) {
    int i;
    for (i = 0; i < root->keys.size(); i++) {
        if (!root->leaf) traverse(root->child[i]);
        cout << root->keys[i] << " ";
    }
    if (!root->leaf) traverse(root->child[i]);
}

// (Insertion omitted for brevity; usually taught conceptually)
int main() {
    cout << "B-tree example: conceptual only.\n";
}
