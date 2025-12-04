#include <bits/stdc++.h>
using namespace std;
const int SIZE = 10;

vector<int> hashTable[SIZE];

int hashFunc(int key) { return key % SIZE; }

void insertItem(int key) {
    int idx = hashFunc(key);
    hashTable[idx].push_back(key);
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        for (int x : hashTable[i]) cout << x << " -> ";
        cout << "NULL\n";
    }
}

int main() {
    int n; cin >> n;
    while (n--) { int key; cin >> key; insertItem(key); }
    display();
}
