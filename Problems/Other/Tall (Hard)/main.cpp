#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int arr[MN];
pii solve(int l, int r, int bit, int add){
    if(r<l)return {INT_MIN,0};
    if(bit==-1)return {0,-arr[l]};
    int mid=lower_bound(arr+l,arr+r+1,add+(1<<bit))-arr;
    if(mid-l==(1<<bit)||r-mid+1==(1<<bit)){
        pii te=(mid-l==(1<<bit)?solve(mid,r,bit-1,add+(1<<bit)):solve(l,mid-1,bit-1,add));
        if(te.first==INT_MIN)return {(1<<bit),(mid-l==(1<<bit)?-arr[l]:-arr[mid])};
        return {te.first+(1<<bit),-((-te.second)^(1<<bit))};
    }
    return max(solve(l,mid-1,bit-1,add),solve(mid,r,bit-1,add+(1<<bit)));
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        pii ans=solve(0,unique(arr,arr+n)-arr-1,30,0);
        printf("%d %d\n",ans.first,-ans.second);
    }
    return 0;
}