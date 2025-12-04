#include <bits/stdc++.h>
using namespace std;

int main(){
    //adjacency matrix representation of graph
    int N=4;
    int adj[N][N];
    //adj[a][b]=1; a--->b is presnt

    //directed = only adj[a][b] or a[b] is presnt(a--->b)
    //undirected = both adj[a][b] and adj[a][b] will be present (a---b)

    /*The drawback of the adjacency matrix representation is that the 
    matrix contains n2 elements, and usually most of them are zero.
     For this reason, the representation cannot be used if the graph is large*/
}