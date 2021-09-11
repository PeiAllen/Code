#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
pll arr[MN];
int n,m;
bool work(ll d){
    ll last=LLONG_MIN;
    int am=0;
    for(int i=0;i<m;i++){
        while(arr[i].second>=last+d){
            last=max(last+d,arr[i].first);
            am++;
            if(am>=n)return true;
        }
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+m);
    ll lo=1,hi=1e18;
    while(lo!=hi){
        ll mid=(lo+hi+1)/2;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    printf("%lli\n",lo);
    return 0;
}