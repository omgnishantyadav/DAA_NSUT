#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> maxh; // max heap
    priority_queue<int, vector<int>, greater<int>> minh; // min heap

    vector<int> arr = {10, 5, 30, 2};
    for (int x : arr) { maxh.push(x); minh.push(x); }

    cout << "Max-heap order: ";
    while (!maxh.empty()) { cout << maxh.top() << " "; maxh.pop(); }

    cout << "\nMin-heap order: ";
    while (!minh.empty()) { cout << minh.top() << " "; minh.pop(); }
}
