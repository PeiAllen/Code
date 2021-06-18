#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int arr[MN];
int deccnt[MN];
int n,k,l;
bool work(int h){
    vector<int> lessthan;
    int tot=0;
    for(int i=0;i<n;i++){
        deccnt[i]=0;
        if(arr[i]<h)lessthan.push_back(arr[i]);
        else tot++;
    }
    if(tot>=h)return true;
    ll sum=0;
    for(int i=1;i<=h-tot;i++){
        if(h-lessthan[sz(lessthan)-i]>k)return false;
        sum+=h-lessthan[sz(lessthan)-i];
    }
    if(sum<=ll(k)*l)return true;
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>l;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int lo=0,hi=n;
    while(lo!=hi){
        int mid=(lo+hi+1)/2;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    printf("%d\n",lo);
    return 0;
}