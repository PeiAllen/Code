#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e3+2;
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,k;
    ll n;
    cin>>n>>m>>k;
    k-=m;
    ll a,b,c,t;
    cin>>a>>c>>b>>t;
    arr[0]=1;
    for(int i=1;i<=m;i++)cin>>arr[i];
    arr[m+1]=n+1;
    ll time=0;
    priority_queue<ll> q;
    ll ans=0;
    for(int i=1;i<=m;i++){
        time+=(arr[i]-arr[i-1])*c;
        vector<ll> dist;
        if(time<=t)dist.push_back(min(arr[i+1]-arr[i],(t-time)/a+1));
        else dist.push_back(0);
        ans+=dist.back();
        for(int j=1;j<=k;j++){
            if(time+dist.back()*b<=t)dist.push_back(min(arr[i+1]-arr[i],dist.back()+(t-(time+dist.back()*b))/a+1));
            else dist.push_back(dist.back());
            q.push(dist.back()-dist[sz(dist)-2]);
        }
    }
    for(int i=0;i<k;i++)ans+=q.top(),q.pop();
    printf("%lli\n",ans-1);
    return 0;
}