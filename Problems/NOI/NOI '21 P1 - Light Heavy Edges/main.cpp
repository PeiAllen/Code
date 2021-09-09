#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 1048576, stdin)] = 0, *_pbuf++))
char _buf[1048577], *_pbuf = _buf;

inline int readint() {
    int c, o = 0;
    while ((c = getchar()) < '0');
    do {o = (o<<3)+(o<<1) + (c - '0');} while ((c = getchar()) >= '0');
    return o;
}
const int MN=1e5+1;
struct node{
    int data,lazy,left,right;
    node(){
        data=0,lazy=-1,left=INT_MIN,right=INT_MIN;
    }
    void apply(int v, int range){
        if(v==-1)return;
        lazy=left=right=v;
        data=range-1;
    }
};
node merge(const node &left, const node &right){
    if(left.left==INT_MIN)return right;
    if(right.left==INT_MIN)return left;
    node te=node();
    te.left=left.left,te.right=right.right;
    te.data=left.data+right.data+(left.right==right.left);
    return te;
}
struct seg{
    node t[2*MN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind].left=t[ind].right=-le;
            t[ind].data=0,t[ind].lazy=-1;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind].left=t[left].left,t[ind].right=t[right].right;
        t[ind].data=t[left].data+t[right].data+(t[left].right==t[right].left);
        t[ind].lazy=-1;
    }
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy,mid-le+1),t[right].apply(t[ind].lazy,ri-mid);
        t[ind].lazy=-1;
    }
    void update(int ind, int le, int ri, int l, int r, int v){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v,ri-le+1);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind].left=t[left].left,t[ind].right=t[right].right;
        t[ind].data=t[left].data+t[right].data+(t[left].right==t[right].left);
    }
    node query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return node();
        if(le>=l&&ri<=r)return t[ind];
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return merge(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
vector<int> adj[MN];
int rep[MN],sts[MN],et,st[MN],par[MN],depth[MN];
int dfssts(int loc, int parent){
    par[loc]=parent,depth[loc]=depth[parent]+1;
    if(loc>1)adj[loc].erase(find(adj[loc].begin(),adj[loc].end(),parent));
    sts[loc]=1;
    for(auto x:adj[loc])sts[loc]+=dfssts(x,loc);
    sort(adj[loc].begin(),adj[loc].end(),[&](const auto &lhs, const auto &rhs){
       return sts[lhs]>sts[rhs];
    });
    return sts[loc];
}
void makehld(int loc, int r){
    rep[loc]=r;
    st[loc]=et++;
    for(auto x:adj[loc])makehld(x,(x==adj[loc][0]?r:x));
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    t=readint();
    while(t--){
        int n,m,a,b;
        n=readint(),m=readint();
        for(int i=1;i<=n;i++)adj[i]=vector<int>();
        for(int i=1;i<n;i++){
            a=readint(),b=readint();
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        et=1;
        dfssts(1,0),makehld(1,1);
        tree.mt(0,1,n);
        for(int op=1,type=0;op<=m;op++){
            type=readint(),a=readint(),b=readint();
            if(type==1){
                while(rep[a]!=rep[b]){
                    if(depth[rep[a]]<depth[rep[b]])swap(a,b);
                    tree.update(0,1,n,st[rep[a]],st[a],op);
                    a=par[rep[a]];
                }
                if(depth[a]>depth[b])swap(a,b);
                tree.update(0,1,n,st[a],st[b],op);
            }
            else{
                int ans=0;
                while(rep[a]!=rep[b]){
                    if(depth[rep[a]]<depth[rep[b]])swap(a,b);
                    ans+=tree.query(0,1,n,st[rep[a]],st[a]).data;
                    ans+=tree.query(0,1,n,st[rep[a]],st[rep[a]]).left==tree.query(0,1,n,st[par[rep[a]]],st[par[rep[a]]]).left;
                    a=par[rep[a]];
                }
                if(depth[a]>depth[b])swap(a,b);
                ans+=tree.query(0,1,n,st[a],st[b]).data;
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}