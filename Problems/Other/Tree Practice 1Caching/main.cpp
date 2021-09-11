#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<int> adj[MN];
int sts[MN],st[MN],par[MN],depth[MN],et=1,marked[MN];
int dfs(int loc, int parent){
    sts[loc]=1;
    for(auto x:adj[loc])if(x!=parent)sts[loc]+=dfs(x,loc);
    if(sz(adj[loc])>=2&&adj[loc][0]==parent)swap(adj[loc][0],adj[loc][1]);
    for(auto &&x:adj[loc])if(x!=parent&&sts[x]>sts[adj[loc][0]])swap(x,adj[loc][0]);
    return sts[loc];
}
void dfset(int loc, int parent){
    depth[et]=depth[st[parent]]+1;
    par[et]=st[parent];
    st[loc]=et++;
    for(auto x:adj[loc])if(x!=parent)dfset(x,loc);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,b;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    dfset(1,0);
    for(int i=1;i<=q;i++){
        cin>>a>>b;
        a=st[a],b=st[b];
        int ans=depth[a]+depth[b];
        while(a)marked[a]=i,a=par[a];
        while(marked[b]!=i)b=par[b];
        printf("%d\n",ans-2*depth[b]);
    }
    return 0;
}