#include <bits/stdc++.h>
using namespace std;

int main(){
    //edge list representation
    vector<pair<int,int>> edges;

    //data storing
    edges.push_back({1,2}); 
    edges.push_back({2,3}); 
    edges.push_back({2,4}); 
    edges.push_back({3,4}); 
    edges.push_back({4,1});


    //for weighted egde list use tuple instead of pair to store weight
    vector<tuple<int,int,int>> edges2;
    edges2.push_back({1,2,5}); 
    edges2.push_back({2,3,7}); 
    edges2.push_back({2,4,6}); 
    edges2.push_back({3,4,5}); 
    edges2.push_back({4,1,2});

}
