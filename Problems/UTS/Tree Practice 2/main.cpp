#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<pair<int,ll>> adj[MN];
int depth[MN],sparse[19][2*MN],st[MN],et;
ll dist[MN],totadd[MN],pardis[MN];
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<19;i++){
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
void dfs(int loc, int parent, ll w){
    depth[loc]=depth[parent]+1;
    sparse[0][et]=loc;
    st[loc]=et++;
    for(auto x:adj[loc])if(x.first!=parent)dfs(x.first,loc,x.second),sparse[0][et++]=loc;
}
ll dfsw(int loc, int parent){
    ll totsum=totadd[loc];
    for(auto x:adj[loc])if(x.first!=parent)totsum+=dfsw(x.first,loc);
    pardis[loc]=totsum;
    return totsum;
}
void dfsans(int loc, int parent, ll w){
    dist[loc]=dist[parent]+w+pardis[loc];
    for(auto x:adj[loc])if(x.first!=parent)dfsans(x.first,loc,x.second);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,q,a,b;
    ll c;
    cin>>n>>m>>q;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,0,0),ms();
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        totadd[a]+=c,totadd[b]+=c,totadd[getlca(a,b)]-=2*c;
    }
    dfsw(1,0),dfsans(1,0,0);
    for(int i=1;i<=q;i++){
        cin>>a>>b;
        printf("%lli\n",dist[a]+dist[b]-2*dist[getlca(a,b)]);
    }
    return 0;
}