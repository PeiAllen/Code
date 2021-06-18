#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e3+1;
vector<pair<int,ll>> adj[MN];
ll dist[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,u,v,a,b,k;
    cin>>n>>m>>u>>v;
    ll c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a;
        
    }
    return 0;
}