#include <bits/stdc++.h>
using namespace std;

struct Item {
    double value, weight;
};

bool cmp(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(int W, vector<Item>& arr) {
    sort(arr.begin(), arr.end(), cmp);
    double profit = 0.0;
    for (auto &item : arr) {
        if (W >= item.weight) {
            W -= item.weight;
            profit += item.value;
        } else {
            profit += item.value * (W / item.weight);
            break;
        }
    }
    return profit;
}

int main() {
    int n, W; cin >> n >> W;
    vector<Item> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].value >> arr[i].weight;
    cout << "Max Profit = " << fractionalKnapsack(W, arr);
}
