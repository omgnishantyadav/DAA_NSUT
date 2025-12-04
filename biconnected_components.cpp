#include <bits/stdc++.h>
using namespace std;

int timer = 0;
vector<int> tin, low;
vector<vector<int>> adj;
stack<pair<int,int>> st;

void dfs(int u, int p, vector<vector<int>>& adj) {
    tin[u] = low[u] = ++timer;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (tin[v] != -1) {
            low[u] = min(low[u], tin[v]);
            if (tin[v] < tin[u]) st.push({u,v});
        } else {
            st.push({u,v});
            dfs(v, u, adj);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u]) {
                cout << "Biconnected Component: ";
                while (true) {
                    auto e = st.top(); st.pop();
                    cout << "(" << e.first << "," << e.second << ") ";
                    if (e.first == u && e.second == v) break;
                }
                cout << "\n";
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (int i = 1; i <= n; i++)
        if (tin[i] == -1) dfs(i, -1, adj);
}
