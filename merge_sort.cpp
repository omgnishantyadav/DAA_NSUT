#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int l, int m, int r) {
    vector<int> L(a.begin()+l, a.begin()+m+1), R(a.begin()+m+1, a.begin()+r+1);
    int i=0, j=0, k=l;
    while(i<L.size() && j<R.size()) a[k++] = (L[i]<=R[j]?L[i++]:R[j++]);
    while(i<L.size()) a[k++] = L[i++];
    while(j<R.size()) a[k++] = R[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    vector<int> a={12,11,13,5,6,7};
    mergeSort(a,0,a.size()-1);
    for(int x:a) cout<<x<<" ";
}
