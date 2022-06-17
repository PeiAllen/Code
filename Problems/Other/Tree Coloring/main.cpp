#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<pii> adj[MN];
int arr[MN];
void dfs(int loc, int par, int depth){
    arr[loc]=depth;
    for(auto x:adj[loc])if(x.first!=par)dfs(x.first,loc,(depth+x.second)%2);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b,c;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++)printf("%d%c",arr[i]," \n"[i==n]);
    return 0;
}