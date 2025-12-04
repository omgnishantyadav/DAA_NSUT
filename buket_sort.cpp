#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n=arr.size();
    vector<vector<float>> buckets(n);
    for(float x:arr){
        int idx=n*x;
        buckets[idx].push_back(x);
    }
    for(auto &b:buckets) sort(b.begin(),b.end());
    int k=0;
    for(auto &b:buckets)
        for(float x:b) arr[k++]=x;
}

int main(){
    vector<float> arr={0.897,0.565,0.656,0.123,0.665,0.343};
    bucketSort(arr);
    for(float x:arr) cout<<x<<" ";
}
