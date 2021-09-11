#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
pll arr[MN];
int n;
ll r;
bool workmin(ll val){
    ll am=0;
    for(int i=1;i<=n;i++){
        ll ter=(i==n?0:r);
        am+=arr[i].second;
        if(arr[i].first+am<val)return false;
        ll needed=max(ll(0),val-arr[i].first);
        am-=needed;
        am=min(am,ter);
    }
    return true;
}
bool workmax(ll val){
    ll am=0;
    for(int i=1;i<=n;i++){
        ll ter=(i==n?0:r);
        am+=arr[i].second;
        ll mustget=max(ll(0),am-ter);
        if(arr[i].first+mustget>val)return false;
        ll mosttake=max(ll(0),val-arr[i].first);
        am-=min(am,mosttake);
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>r;
    for(int i=1;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    ll lo=0,hi=3e9;
    while(lo!=hi){
        ll mid=(lo+hi+1)/2;
        if(workmin(mid))lo=mid;
        else hi=mid-1;
    }
    ll maxmin=lo;
    lo=0,hi=3e9;
    while(lo!=hi){
        ll mid=(lo+hi)/2;
        if(workmax(mid))hi=mid;
        else lo=mid+1;
    }
    ll minmax=lo;
    printf("%lli\n",minmax-maxmin);
    return 0;
}