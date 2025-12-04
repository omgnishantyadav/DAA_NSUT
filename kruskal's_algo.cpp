#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
};

int find(int x, vector<int>& parent) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end());
    vector<int> parent(n + 1), rank(n + 1, 0);
    iota(parent.begin(), parent.end(), 0);

    int cost = 0;
    cout << "Edges in MST:\n";
    for (auto &e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            unite(e.u, e.v, parent, rank);
            cost += e.w;
            cout << e.u << " - " << e.v << " (" << e.w << ")\n";
        }
    }
    cout << "Total cost: " << cost;
}
