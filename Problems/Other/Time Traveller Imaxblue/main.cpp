#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<pair<int,ll>> adj[MN];
int depth[MN],sparse[18][2*MN],st[MN],et,cparent[MN],sts[MN],pc[2*MN];
ll dist[MN];
bool cent[MN];
vector<pair<int,ll>> deq[MN];
void dfs(int loc, int parent, ll w){
    dist[loc]=dist[parent]+w,depth[loc]=depth[parent]+1;
    st[loc]=et,sparse[0][et++]=loc;
    for(auto x:adj[loc])if(x.first!=parent)dfs(x.first,loc,x.second),sparse[0][et++]=loc;
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<18;i++){
        for(int j=0;j+(1<<i)<=et;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int k=pc[b-a+1];
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
ll getdist(int a, int b){
    int lca=getlca(a,b);
    return dist[a]+dist[b]-ll(2)*dist[lca];
}
int dfssize(int loc, int parent){
    sts[loc]=1;
    for(auto x:adj[loc])if(x.first!=parent&&!cent[x.first])sts[loc]+=dfssize(x.first,loc);
    return sts[loc];
}
int getcent(int loc, int parent, int halfsize){
    for(auto x:adj[loc])if(x.first!=parent&&!cent[x.first]&&sts[x.first]>halfsize)return getcent(x.first,loc,halfsize);
    return loc;
}
void decomp(int loc, int parent){
    int next=getcent(loc,0,dfssize(loc,0)/2);
    cparent[next]=parent,cent[next]=true;
    for(auto x:adj[next])if(!cent[x.first])decomp(x.first,next);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,q,t,a,b,c;
    cin>>n>>m>>q>>t;
    ll w;
    for(int i=1;i<n;i++){
        cin>>a>>b>>w,a++,b++;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    for(int i=0;i<=2*n;i++)pc[i]=__lg(i);
    et=0;
    dfs(1,0,0);
    ms();
    decomp(1,0);
    vector<pair<pii,pair<int,ll>>> ops;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c>>w,a++;
        ops.push_back({{c,b},{a,w}});
    }
    sort(ops.begin(),ops.end(),greater<>());
    auto update=[&](int loc, ll val, int time){
        for(int cur=loc;cur!=0;cur=cparent[cur]){
            ll te=val+getdist(loc,cur);
            while(sz(deq[cur])&&deq[cur].back().second>=te)deq[cur].pop_back();
            deq[cur].push_back({time,te});
        }
    };
    auto query=[&](int loc, int time){
        ll mi=LLONG_MAX;
        for(int cur=loc;cur!=0;cur=cparent[cur]){
            int ind=lower_bound(deq[cur].begin(),deq[cur].end(),time,[&](const pair<int,ll> &it, const int& val){
                return it.first>val;
            })-deq[cur].begin();
            if(ind!=sz(deq[cur]))mi=min(mi,deq[cur][ind].second+getdist(cur,loc));
        }
        return mi;
    };
    update(1,0,t);
    for(auto x:ops){
        ll micost=query(x.second.first,x.first.second);
        if(micost!=LLONG_MAX)update(x.second.first,micost+x.second.second,x.first.first);
    }
    for(int i=0;i<q;i++){
        cin>>a>>b,b++;
        ll ans=query(b,a);
        if(ans==LLONG_MAX)printf("-1\n");
        else printf("%lli\n",ans);
    }
    return 0;
}