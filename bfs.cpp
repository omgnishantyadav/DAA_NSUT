#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj){
    vector<bool> vis(adj.size(), false);
    queue<int>q;
    q.push(start);
    vis[start]=true;

    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v: adj[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
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

    //bfs
    bfs(1,adj,vis);
    
}