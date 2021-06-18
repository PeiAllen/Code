#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
vector<pair<int,ll>> adj[MN];
int depth[MN],st[MN],sparse[20][2*MN],et,par[MN];
ll dist[MN];
bool canuse[MN];
void dfs(int loc, int parent, ll w){
    par[loc]=parent;
    depth[loc]=depth[parent]+1;
    dist[loc]=dist[parent]+w;
    sparse[0][et]=loc;
    st[loc]=et++;
    for(auto x:adj[loc])if(x.first!=parent)dfs(x.first,loc,x.second),sparse[0][et++]=loc;
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<20;i++){
        for(int j=0;j+(1<<i)<=et;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int k=__lg(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
ll getdist(int a, int b){
    return dist[a]+dist[b]-2*dist[getlca(a,b)];
}
int mah(int a, int b){
    if(depth[a]>depth[b])return a;
    return b;
}
pii inter(pii a, pii b){
    int alca=getlca(a.first,a.second),blca=getlca(b.first,b.second);
    if(depth[alca]>depth[blca])swap(a,b),swap(alca,blca);
    if(alca==blca){
        return {mah(getlca(a.first,b.first),getlca(a.first,b.second)),mah(getlca(a.second,b.first),getlca(a.second,b.second))};
    }
    if(getlca(blca,a.first)==blca){
        return {getlca(a.first,b.first),getlca(a.first,b.second)};
    }
    if(getlca(blca,a.second)==blca){
        return {getlca(a.second,b.first),getlca(a.second,b.second)};
    }
    return {-1,-1};
}
void getpath(int a, int b){
    int lca=getlca(a,b);
    while(a!=lca)canuse[a]=false,a=par[a];
    while(b!=lca)canuse[b]=false,b=par[b];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    ll c;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,0,0),ms();
    vector<pair<ll,pii>> paths;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        if(a!=b)paths.push_back({getdist(a,b),{a,b}});
    }
    if(sz(paths)==0){
        printf("0\n");
        return 0;
    }
    sort(paths.begin(),paths.end(),greater<>());
    int lca=getlca(paths[0].second.first,paths[0].second.second);
    a=paths[0].second.first;
    vector<pair<ll,int>> edges;
    while(a!=lca)canuse[a]=true,edges.push_back({dist[a]-dist[par[a]],a}),a=par[a];
    a=paths[0].second.second;
    while(a!=lca)canuse[a]=true,edges.push_back({dist[a]-dist[par[a]],a}),a=par[a];
    sort(edges.begin(),edges.end());
    ll ans=max((sz(paths)>=2?paths[1].first:0),paths[0].first-edges.back().first);
    pii path=paths[0].second;
    for(int i=1;i<sz(paths);i++){
        pii newpath=inter(path,paths[i].second);
        if(newpath.first==newpath.second)break;
        if(getdist(path.first,path.second)<getdist(path.first,newpath.first)+getdist(path.second,newpath.second))swap(newpath.first,newpath.second);
        getpath(path.first,newpath.first),getpath(path.second,newpath.second);
        path=newpath;
        while(!canuse[edges.back().second])edges.pop_back();
        ans=min(ans,max((i==sz(paths)-1?0:paths[i+1].first),paths[0].first-edges.back().first));
    }
    printf("%lli\n",ans);
    return 0;
}