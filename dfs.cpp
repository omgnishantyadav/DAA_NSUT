#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis){
    vis[u]=true;
    cout<<u<<" ";
    for(int v: adj[u]){
        if(!vis[v]) dfs(v,adj,vis);
    }
}

int main(){
    int n,m; cin>>n>>m;
    //n: no of nodes
    //m: no of edges

    vector<vector<int>>adj(n+1);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v; // taking input u--->v
        //for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //visited array == false initially
    vector<bool> vis(n+1, false);

    //dfs
    dfs(1,adj,vis);
    
}