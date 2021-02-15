#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll offset=1000;// if x works then floor of x will also work
const ll MAXV=ll(250000)*offset;
pii arr[251];
ll dp[1000];
int n,w;
bool work(ll val){
    for(int j=1;j<=w;j++)dp[j]=-MAXV-ll(1);
    for(int i=0;i<n;i++) {
        for (int j = w; j >= 0; j--) {
            dp[min(w,j+arr[i].first)] = max(dp[min(w,j+arr[i].first)],dp[j]+ll(arr[i].second)*offset-ll(arr[i].first)*val);
        }
    }
    return dp[w]>=0;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>w;
    for(int i=0;i<n;i++)cin>>arr[i].first>>arr[i].second;
    ll lo=0,hi=MAXV;
    while(lo!=hi){
        ll mid=(lo+hi+1)/2;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    printf("%lli\n",lo/(offset/ll(1000)));
    return 0;
}