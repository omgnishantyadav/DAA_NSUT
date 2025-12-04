#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX), parent(n + 1, -1);
    vector<bool> mstSet(n + 1, false);
    key[1] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (mstSet[u]) continue;
        mstSet[u] = true;

        for (auto [v, w] : adj[u]) {
            if (!mstSet[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST:\n";
    for (int i = 2; i <= n; i++)
        cout << parent[i] << " - " << i << " (" << key[i] << ")\n";
}
