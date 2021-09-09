#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=5e5+1;
const ll mod=998244353;
vector<int> adj[MN];
int depth[MN];
set<int> rfled;
struct seg{
    struct node{
        ll data,lazysumbm,lazysumam,lazymut;
        int left,right;
        vector<int> tmerge;
        node(){
            data=0,lazysumbm=0,lazysumam=0,lazymut=1,left=INT_MIN,right=INT_MIN,tmerge={};
        }
    };
    vector<node> t;
    seg(){
        t=vector<node>();
    }
    int nn(){
        t.push_back(node());
        return SZ(t)-1;
    }
    void apply(int ind, ll sumbm, ll sumam,ll mut, const vector<int> &merge){
        t[ind].data=(t[ind].data+sumbm)%mod,t[ind].lazysumbm=(t[ind].lazysumbm+sumbm)%mod;
        t[ind].data=t[ind].data*mut%mod,t[ind].lazymut=t[ind].lazymut*mut%mod;
        t[ind].tmerge.insert(t[ind].tmerge.end(),merge.begin(),merge.end());
        for(auto x:merge)t[ind].data=t[ind].data*t[x].data%mod;
        t[ind].data=(t[ind].data+sumam)%mod,t[ind].lazysumam=(t[ind].lazysumam+sumam)%mod;
    }
    pair<> rfl(int ind){//this node and its children will be forever constant afterwards
        assert(!rfled.count(ind));
        rfled.insert(ind);
        vector<int> left,right;
        ll mutleft=1,mutright=1;
        for(auto x:t[ind].tmerge){
            rfl(x);
            if(t[x].left>0)left.push_back(t[x].left);
            else if(t[x].left!=INT_MIN)mutleft=mutleft*(-t[x].left)%mod;
            if(t[x].right>0)right.push_back(t[x].right);
            else if(t[x].right!=INT_MIN)mutright=mutright*(-t[x].right)%mod;
        }
        if(SZ(left)&&t[ind].left==INT_MIN){int te=nn();t[ind].left=te;}
        if(SZ(right)&&t[ind].right==INT_MIN){int te=nn();t[ind].right=te;}
        if(t[ind].left!=INT_MIN)apply(t[ind].left,t[ind].lazysumbm,t[ind].lazysumam,mutleft*t[ind].lazymut%mod,left);
        else t[ind].left=-((mutleft*t[ind].lazysumbm%mod*t[ind].lazymut%mod+t[ind].lazysumam)%mod);
        if(t[ind].right!=INT_MIN)apply(t[ind].right,t[ind].lazysumbm,t[ind].lazysumam,mutright*t[ind].lazymut%mod,right);
        else t[ind].right=-((mutright*t[ind].lazysumbm%mod*t[ind].lazymut%mod+t[ind].lazysumam)%mod);
        t[ind].lazysumbm=0,t[ind].lazysumam=0,t[ind].lazymut=1,t[ind].tmerge=vector<int>();
    }
    void rl(int ind){
        vector<int> left,right;
        ll mutleft=1,mutright=1;
        for(auto x:t[ind].tmerge){
            rfl(x);
            if(t[x].left>0)left.push_back(t[x].left);
            else if(t[x].left!=INT_MIN)mutleft=mutleft*(-t[x].left)%mod;
            if(t[x].right>0)right.push_back(t[x].right);
            else if(t[x].right!=INT_MIN)mutright=mutright*(-t[x].right)%mod;
        }
        if(t[ind].left==INT_MIN){int te=nn();t[ind].left=te;}
        if(t[ind].right==INT_MIN){int te=nn();t[ind].right=te;}
        apply(t[ind].left,t[ind].lazysumbm,t[ind].lazysumam,mutleft*t[ind].lazymut%mod,left);
        apply(t[ind].right,t[ind].lazysumbm,t[ind].lazysumam,mutright*t[ind].lazymut%mod,right);
        t[ind].lazysumbm=0,t[ind].lazysumam=0,t[ind].lazymut=1,t[ind].tmerge=vector<int>();
    }
    void update(int ind, int le, int ri, int l, int r, ll vb, ll va){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            apply(ind,vb,va,1,{});
            return;
        }
        rl(ind);
        int mid=(le+ri)/2;
        update(t[ind].left,le,mid,l,r,vb,va),update(t[ind].right,mid+1,ri,l,r,vb,va);
        t[ind].data=(t[t[ind].left].data+t[t[ind].right].data)%mod;
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        rl(ind);
        int mid=(le+ri)/2;
        return (query(t[ind].left,le,mid,l,r)+query(t[ind].right,mid+1,ri,l,r))%mod;
    }
}forest;
int madepth[MN];
void getdepth(int loc, int par){
    depth[loc]=depth[par]+1;
    for(auto x:adj[loc])if(x!=par)getdepth(x,loc);
}
int n;
void dfs(int loc, int par){
    forest.update(loc,0,n,madepth[loc],depth[loc]-1,1,0);
    for(auto x:adj[loc])if(x!=par){
        dfs(x,loc);
        forest.update(x,0,n,0,depth[loc]-1,0,forest.query(x,0,n,depth[loc],depth[loc]));
        forest.apply(loc,0,0,1,{x});
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a,b,q;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    getdepth(1,0);
    cin>>q;
    while(q--){
        cin>>a>>b;
        if(depth[a]>depth[b])swap(a,b);
        madepth[b]=max(madepth[b],depth[a]);
    }
    forest.t.resize(n+1);
    dfs(1,0);
    printf("%lli\n",forest.query(1,0,n,0,0));
    return 0;
}