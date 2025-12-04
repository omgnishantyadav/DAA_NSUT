#include <bits/stdc++.h>
using namespace std;

int main(){
    //adjacency list representation
    int N=4;
    //unweiehted
    vector<int> adj[N];  

    //storing data
    adj[1].push_back(2); //1--->2 (1 se 2)
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(1);

    //weighted
    vector<pair<int,int>>adj2[N];

    //storing data
    adj2[1].push_back({2,5}); //1---5-->2(5: weight)
    adj2[2].push_back({3,7}); 
    adj2[2].push_back({4,6}); 
    adj2[3].push_back({4,5}); 
    adj2[4].push_back({1,2});


    //traversal
    int s=1; //the following loop goes through all nodes to which we can move from node s
    for(auto u:adj[s]){
        //process nude u
    }
    
}