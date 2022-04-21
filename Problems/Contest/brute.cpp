#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt"
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
const ll MV=-2e9;
ll arr[MN];
struct node{
    ll sum,masum,presum,sufsum,maval,mival,lazy;
    node(){
        sum=MV,masum=0,presum=0,sufsum=0,maval=MV,mival=MV,lazy=MV;
    }
    void apply(ll v, ll range){
        sum=v*range;
        masum=max(ll(0),sum);
        presum=max(ll(0),sum);
        sufsum=max(ll(0),sum);
        maval=v,mival=v;
        lazy=v;
    }
};
node merge(const node& a, const node& b){
    node te=node();
    te.sum=a.sum+b.sum;
    te.presum=max(a.presum,a.sum+b.presum);
    te.sufsum=max(b.sufsum,a.sufsum+b.sum);
    te.mival=min(a.mival,b.mival);
    te.maval=max(a.maval,b.maval);
    te.masum=max({a.masum,b.masum,a.sufsum+b.presum});
    return te;
}
struct seg{
    node t[2*MN];
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy,mid-le+1);
        t[right].apply(t[ind].lazy,ri-mid);
        t[ind].lazy=MV;
    }
    void build(int ind, int le, int ri){
        if(le==ri){
            t[ind].apply(arr[le],1);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        build(left,le,mid),build(right,mid+1,ri);
        t[ind]=merge(t[left],t[right]);
    }
    void update(int ind, int le, int ri, int l, int r, ll v){
        if(l>ri||r<le||t[ind].mival>=v)return;
        if(le>=l&&ri<=r&&t[ind].mival==t[ind].maval){
            t[ind].apply(v,ri-le+1);
            return;
        }
        if(t[ind].lazy!=MV)rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind]=merge(t[left],t[right]);
    }
    node query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return node();
        if(t[ind].mival==t[ind].maval){
            node te=node();
            te.apply(t[ind].mival,min(r,ri)-max(l,le)+1);
            return te;
        }
        if(le>=l&&ri<=r)return t[ind];
        if(t[ind].lazy!=MV)rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return merge(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,t,a,b,c;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    tree.build(0,1,n);
    while(q--){
        cin>>t>>a>>b;
        if(t==0){
            cin>>c;
            tree.update(0,1,n,a,b,c);
        }
        else printf("%lli\n",tree.query(0,1,n,a,b).masum);
    }
    return 0;
}