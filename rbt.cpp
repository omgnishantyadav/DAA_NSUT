#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> rbt;  // red-black tree
    rbt.insert(10); rbt.insert(5); rbt.insert(20);
    cout << "Elements: ";
    for (int x : rbt) cout << x << " ";
    cout << "\nFind 10: " << (rbt.find(10)!=rbt.end()?"Found":"Not Found");
}
