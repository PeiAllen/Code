#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
ll val[MAXN];
int dfnloc;
vector<pair<int,ll>> matrix[MAXN];
int parent[MAXN];
bool cent[MAXN];
int sts[MAXN];
vector<int> nodes;
ll tedist[MAXN];
int dfn[18][MAXN];
int en[18][MAXN];
int depth[MAXN];
map<pii,ll> edges;
struct seg{
    struct node{
        ll lazy;
        pair<ll,int> data;
        node(){
            data={0,0},lazy=0;
        }
        void apply(ll val){
            lazy+=val,data.first+=val;
        }
    };
    vector<node> t;
    seg(){
        t={};
    }
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind].data={val[nodes[le]]-tedist[le],-nodes[le]};
            return;
        }
        int mid=le+(ri-le)/2,left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind].data=max(t[left].data,t[right].data);
    }
    void prop(int ind, int le, int ri){
        int mid=le+(ri-le)/2,left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy),t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, ll val){
        if(r<le||l>ri||l>r)return;
        if(le>=l&&ri<=r){t[ind].apply(val);return;}
        if(t[ind].lazy&&le!=ri)prop(ind,le,ri);
        int mid=le+(ri-le)/2,left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=max(t[left].data,t[right].data);
    }
    pair<ll,int> query(int ind, int le, int ri, int l, int r){
        if(r<le||l>ri||l>r)return {LLONG_MIN,0};
        if(le>=l&&ri<=r)return t[ind].data;
        if(t[ind].lazy&&le!=ri)prop(ind,le,ri);
        int mid=le+(ri-le)/2,left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree[MAXN];
int dfssz(int loc, int par){
    sts[loc]=1;
    for(auto x:matrix[loc])if(x.first!=par&&!cent[x.first])sts[loc]+=dfssz(x.first,loc);
    return sts[loc];
}
int getcent(int loc, int par, int centsz){
    for(auto x:matrix[loc])if(x.first!=par&&!cent[x.first]&&sts[x.first]>centsz)return getcent(x.first,loc,centsz);
    return loc;
}
void getdfn(int loc, int par, ll dis, int rt, int dep){
    tedist[dfnloc]=dis;
    dfn[dep][loc]=dfnloc;
    nodes[dfnloc++]=loc;
    for(auto x:matrix[loc])if(x.first!=par&&!cent[x.first])getdfn(x.first,loc,dis+x.second,rt,dep);
    en[dep][loc]=dfnloc-1;
}
void makecenttree(int loc, int par, int dep){
    assert(dep<18);
    int compsize=dfssz(loc,0);
    loc=getcent(loc,0,compsize/2);
    sts[loc]=compsize;
    depth[loc]=dep;
    cent[loc]=true;
    parent[loc]=par;
    dfnloc=0;
    nodes.resize(compsize);
    getdfn(loc,0,0,loc,dep);
    assert(dfnloc==compsize);
    tree[loc].t.resize(2*compsize);
    tree[loc].mt(0,0,compsize-1);
    for(auto x:matrix[loc])if(!cent[x.first])makecenttree(x.first,loc,dep+1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>val[i];
    int a,b;
    ll c;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        if(a>b)swap(a,b);
        edges[{a,b}]=c;
        matrix[a].push_back({b,c});
        matrix[b].push_back({a,c});
    }
    makecenttree(1,0,0);
    int lastloc=1;
    int op;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>a>>c;
            c-=val[a],val[a]+=c;
            for(int cur=a;cur;cur=parent[cur])tree[cur].update(0,0,sts[cur]-1,dfn[depth[cur]][a],dfn[depth[cur]][a],c);
        }
        else{
            cin>>a>>b>>c;
            if(a>b)swap(a,b);
            c-=edges[{a,b}],edges[{a,b}]+=c;
            if(depth[a]>depth[b])swap(a,b);
            for(int cur=a;cur;cur=parent[cur]){
                if(dfn[depth[cur]][a]<dfn[depth[cur]][b])swap(a,b);
                tree[cur].update(0,0,sts[cur]-1,dfn[depth[cur]][a],en[depth[cur]][a],-c);
            }
        }
        pair<ll,int> best={LLONG_MIN,0};
        for(int cur=lastloc;cur;cur=parent[cur]){
            pair<ll,int> te=max(tree[cur].query(0,0,sts[cur]-1,0,dfn[depth[cur]][lastloc]-1),tree[cur].query(0,0,sts[cur]-1,dfn[depth[cur]][lastloc]+1,sts[cur]-1));
            if(te.first!=LLONG_MIN)te.first-=abs(tree[cur].query(0,0,sts[cur]-1,dfn[depth[cur]][lastloc],dfn[depth[cur]][lastloc]).first-val[lastloc]);
            best=max(best,te);
        }
        lastloc=-best.second;
        printf("%d ",lastloc);
    }
    return 0;
}