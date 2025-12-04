/*
MULTISTAGE_GRAPH_SHORTEST_PATH(cost, n)
1. Create an array dist[1..n] to store minimum cost to reach sink
2. Set dist[n] ← 0     // Base case: cost from sink to sink is 0

3. For i ← n-1 down to 1 do
4.     Set dist[i] ← ∞     // Initialize with large value
5.     For j ← i+1 to n do
6.         If cost[i][j] ≠ 0 then
7.             temp ← cost[i][j] + dist[j]
8.             If temp < dist[i] then
9.                 dist[i] ← temp
10.            End If
11.        End If
12.    End For
13. End For

14. Return dist[1]     // Minimum cost from source to sink
*/

#include <bits/stdc++.h>
using namespace std;

int MULTISTAGE_GRAPH_SHORTEST_PATH(vector<vector<int>>& cost,int n){
    vector<int>d(n+1);
    d[n]=0;

    for(int i=n-1; i>=1; i--){
        d[i]=INT_MAX;
        for(int j=i+1; j<=n; j++){
            if(cost[i][j]!=0){
                d[i]=min(cost[i][j] + d[j],d[i]);
            }
        }
    }
    return d[1];
}

int main(){
    int n=8;
    vector<vector<int>> cost = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 1, 2, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 11, 0, 0},
        {0, 0, 0, 0, 0, 9, 5, 16, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 18},
        {0, 0, 0, 0, 0, 0, 0, 0, 13},
        {0, 0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int minCost = MULTISTAGE_GRAPH_SHORTEST_PATH(cost, n);
    cout << "Minimum cost from Source (1) to Sink (" << n << ") = " << minCost << endl;

}