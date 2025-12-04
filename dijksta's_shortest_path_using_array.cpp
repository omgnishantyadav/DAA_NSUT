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

    int src; cin >> src;
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> vis(n + 1, false);
    dist[src] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        vis[u] = true;

        for (auto [v, w] : adj[u])
            if (dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
    }

    for (int i = 1; i <= n; i++)
        cout << i << ": " << dist[i] << "\n";
}
