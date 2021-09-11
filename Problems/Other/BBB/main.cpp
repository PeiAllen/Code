#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll arr[MN];
vector<pair<int,bool>> adj[MN];
pll dfs(int loc, int parent, bool edge){
    ll am=arr[loc],ma=0;
    for(auto x:adj[loc])if(x.first!=parent){
        auto te=dfs(x.first,loc,x.second);
        if(!x.second)ma=max(ma,te.second);
        else am+=te.first,ma=max(ma,te.second);
    }
    return (edge?pll{am,ma}:pll{0,am+ma});
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b,t;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<n;i++)cin>>a>>b>>t,adj[a].push_back({b,t>=2}),adj[b].push_back({a,t>=2});
    printf("%lli\n",dfs(1,0,0).second);
    return 0;
}