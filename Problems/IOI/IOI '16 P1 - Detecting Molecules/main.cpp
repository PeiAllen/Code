#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int find_subset(int l, int u, int* w, int n, int* result){
    vector<pii> arr;
    for(int i=0;i<n;i++){
        arr.push_back({w[i],i});
    }
    sort(arr.begin(),arr.end());
    int neededsize=0;
    ll sum=0;
    for(int i=n-1;i>=0;i--){
        neededsize++;
        sum+=arr[i].first;
        if(sum>=l)break;
    }
    if(sum<l)return 0;
    ll sum2=0;
    for(int i=0;i<neededsize;i++){
        sum2+=arr[i].first;
    }
    if(sum2>u)return 0;
    int ind=n-1;
    while(sum>u){
        sum-=arr[ind].first;
        sum+=arr[ind-neededsize].first;
        ind--;
    }
    for(int i=0;i<neededsize;i++){
        result[i]=arr[ind-i].second;
    }
    return neededsize;
}
//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//    vector<int> result;
//    printf("%d\n",find_subset(10, 20, {15, 17, 16, 18}, 4, result));
//    for(auto x:result)printf("%d ",x);
//    return 0;
//}