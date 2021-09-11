#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
bool cent[MN];
vector<pair<pii,int>> range[MN];
vector<pii> children[MN];
multiset<ll> values[MN];
multiset<ll> diams;
int nval[MN];
vector<pair<pair<int,ll>,int>> adj[MN];
ll cost[MN];
vector<ll> dist;
struct segtree{
    struct node{
        ll data,lazy;
        node(){
            data=0,lazy=0;
        }
        void apply(ll a){
            data+=a;
            lazy+=a;
        }
    };
    vector<node> t;
    segtree(){
        t=vector<node>();
    }
    void mt(int ind, int le, int ri, const vector<ll> &vals){
        if(le==ri){
            t[ind].data=vals[le];
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid,vals),mt(right,mid+1,ri,vals);
        t[ind].data=max(t[left].data,t[right].data);
    }
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy),t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, ll val){
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].apply(val);
            return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=max(t[left].data,t[right].data);
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree[MN];
int sts[MN];
int dfssz(int loc, int parent){
    sts[loc]=1;
    for(auto x:adj[loc])if(!cent[x.first.first]&&x.first.first!=parent)sts[loc]+=dfssz(x.first.first,loc);
    return sts[loc];
}
int decompsubtree(int loc, int parent, int size){
    for(auto x:adj[loc])if(!cent[x.first.first]&&x.first.first!=parent&&sts[x.first.first]>size)return decompsubtree(x.first.first,loc,size);
    return loc;
}
void dfs(int loc, int parent, int eind, ll depth, int rt){
    range[eind].push_back({{sz(dist),0},rt});
    dist.push_back(depth);
    for(auto x:adj[loc]){
        if(x.first.first!=parent&&!cent[x.first.first]){
            dfs(x.first.first,loc,x.second,depth+x.first.second,rt);
        }
    }
    range[eind].back().first.second=sz(dist)-1;
}
ll getdiam(int loc){
    if(sz(values[loc])==0)return 0;
    if(sz(values[loc])==1)return *values[loc].begin();
    return (*values[loc].rbegin())+(*next(values[loc].rbegin()));
}
void decomp(int loc){
    loc=decompsubtree(loc,0,dfssz(loc,0)/2);
    cent[loc]=true;
    for(auto x:adj[loc]){
        if(!cent[x.first.first]){
            children[loc].push_back({sz(dist),0});
            dfs(x.first.first,loc,x.second,x.first.second,loc);
            children[loc].back().second=sz(dist)-1;
        }
    }
    if(sz(dist)) {
        tree[loc].t.resize(2 * (sz(dist) + 1));
        nval[loc] = sz(dist) - 1;
        tree[loc].mt(0, 0, sz(dist) - 1, dist);
    }
    dist=vector<ll>();
    for(auto x:children[loc]){
        values[loc].insert(tree[loc].query(0,0,nval[loc],x.first,x.second));
    }
    diams.insert(getdiam(loc));
    for(auto x:adj[loc]){
        if(!cent[x.first.first]){
            decomp(x.first.first);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,b;
    ll w,c;
    cin>>n>>q>>w;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        cost[i]=c;
        adj[a].push_back({{b,c},i});
        adj[b].push_back({{a,c},i});
    }
    decomp(1);
    ll lastans=0;
    while(q--){
        cin>>a>>c;
        a=(a+lastans)%(n-1);
        c=(c+lastans)%w;
        for(auto x:range[a]){
            diams.erase(diams.find(getdiam(x.second)));
            int ind=upper_bound(children[x.second].begin(),children[x.second].end(),x.first)-children[x.second].begin()-1;
            values[x.second].erase(values[x.second].find(tree[x.second].query(0,0,nval[x.second],children[x.second][ind].first,children[x.second][ind].second)));
            tree[x.second].update(0,0,nval[x.second],x.first.first,x.first.second,c-cost[a]);
            values[x.second].insert(tree[x.second].query(0,0,nval[x.second],children[x.second][ind].first,children[x.second][ind].second));
            diams.insert(getdiam(x.second));
        }
        cost[a]=c;
        printf("%lli\n",lastans=*diams.rbegin());
    }
    return 0;
}