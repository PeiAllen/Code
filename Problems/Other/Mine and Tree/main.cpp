#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
const ld DTR=acos(-1)/180;
template <class T> using matrix=array<array<T,2>,2>;
template <class T>
matrix<T> operator*(const matrix<T> &a,const matrix<T> &b) {
    matrix<T> ans={};
    for(int i=0;i<sz(a);i++){
        for(int j=0;j<min(sz(a[0]),sz(b));j++){
            for(int k=0;k<sz(b[0]);k++){
                ans[i][k]+=a[i][j]*b[j][k];
            }
        }
    }
    return ans;
}
template <class T>
matrix<T> operator+(const matrix<T> &a, const matrix<T> &b){
    matrix<T> ans={};
    for(int i=0;i<max(sz(a),sz(b));i++){
        for(int j=0;j<max(sz(a[0]),sz(b[0]));j++){
            ans[i][j]=a[i][j]+b[i][j];
        }
    }
    return ans;
}

int rep[MN],depth[MN],sts[MN],st[MN],et[MN],etind;
array<matrix<ld>,2> arr[MN];
vector<int> adj[MN];
int n,m;
array<matrix<ld>,2> merge(const array<matrix<ld>,2> &a, const array<matrix<ld>,2> &b){
    return {a[0]*b[0],a[1]*b[0]+b[1]};
}
matrix<ld> make(ld a, ld b, ld c, ld d){
    matrix<ld> ret;
    ret[0][0]=a,ret[0][1]=b,ret[1][0]=c,ret[1][1]=d;
    return ret;
}
matrix<ld> one=make(1,0,0,1);
struct node{
    array<matrix<ld>,2> forw,back;
    node(array<matrix<ld>,2> a={}, array<matrix<ld>,2> b={}){
        forw=a,back=b;
    }
};
struct seg{
    node t[2*MN];
    void mt(int ind, int le, int ri){
        if(le==ri)t[ind].forw=t[ind].back=arr[et[le]];
        else{
            int mid=(le+ri)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            mt(left,le,mid),mt(right,mid+1,ri);
            t[ind].forw=merge(t[left].forw,t[right].forw);
            t[ind].back=merge(t[right].back,t[left].back);
        }
    }
    void update(int ind, int le, int ri, int loc){
        if(le>loc||ri<loc)return;
        if(le>=loc&&ri<=loc){
            t[ind].forw=t[ind].back=arr[et[le]];
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc),update(right,mid+1,ri,loc);
        t[ind].forw=merge(t[left].forw,t[right].forw);
        t[ind].back=merge(t[right].back,t[left].back);
    }
    node query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return node({one,{}},{one,{}});
        if(le>=l&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        node a=query(left,le,mid,l,r),b=query(right,mid+1,ri,l,r);
        return node(merge(a.forw,b.forw),merge(b.back,a.back));
    }
}tree;
void dfssize(int loc, int par){
    depth[loc]=depth[par]+1,sts[loc]=1;
    for(auto x:adj[loc])if(x!=par)dfssize(x,loc);
    sts[par]+=sts[loc];
    sort(adj[loc].begin(),adj[loc].end(),[&](const auto&lhs, const auto&rhs){return sts[lhs]>sts[rhs];});
}
void dfshld(int loc){
    if(!rep[loc])rep[loc]=loc;
    st[loc]=etind,et[etind++]=loc;
    if(sz(adj[loc])>=2)rep[adj[loc][1]]=rep[loc];
    for(int i=1;i<sz(adj[loc]);i++)dfshld(adj[loc][i]);
}
array<matrix<ld>,2> query(int a, int b){
    array<matrix<ld>,2> left = {one,{}},right = {one,{}};//forw is down tree, back is up tree
    while(rep[a]!=rep[b]){
        if(depth[rep[a]]>depth[rep[b]]){
            auto te=tree.query(0,1,n,st[rep[a]],st[a]);
            left=merge(left,te.back);
            a=adj[rep[a]][0];
        }
        else{
            auto te=tree.query(0,1,n,st[rep[b]],st[b]);
            right=merge(te.forw,right);
            b=adj[rep[b]][0];
        }
    }
    if(depth[a]>depth[b]){
        auto te=tree.query(0,1,n,st[b],st[a]);
        left=merge(left,te.back);
    }
    else{
        auto te=tree.query(0,1,n,st[a],st[b]);
        right=merge(te.forw,right);
    }
    return merge(left,right);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    char t;
    ld A,B,C;
    for(int i=1;i<=n;i++){
        cin>>t>>A;
        arr[i][0]=one,arr[i][1]={};
        if(t=='R'){
            A*=DTR;
            arr[i][0]=make(cos(A),sin(A),-sin(A),cos(A));
        }
        else if(t=='T'){
            cin>>B;
            arr[i][1]=make(A,0,0,B);
        }
        else{
            cin>>B>>C;
            arr[i]=merge({one,make(-A,0,0,-B)},{make(C/100,0,0,C/100),make(A,0,0,B)});
        }
    }
    int a,b;
    adj[1].push_back(0);
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    etind=1;
    dfssize(1,0),dfshld(1);
    tree.mt(0,1,n);
    while(m--){
        cin>>t;
        if(t=='Q'){
            cin>>a>>b>>A>>B;
            auto transform=query(a,b);
            matrix<ld> res=make(A,0,0,B)*transform[0]+transform[1];
            printf("%.9f %.9f\n",double(res[0][0]+res[1][0]),double(res[1][1]+res[0][1]));
        }
        else{
            cin>>a>>t>>A;
            arr[a][0]=one,arr[a][1]={};
            if(t=='R'){
                A*=DTR;
                arr[a][0]=make(cos(A),sin(A),-sin(A),cos(A));
            }
            else if(t=='T'){
                cin>>B;
                arr[a][1]=make(A,0,0,B);
            }
            else{
                cin>>B>>C;
                arr[a]=merge({one,make(-A,0,0,-B)},{make(C/100,0,0,C/100),make(A,0,0,B)});
            }
            tree.update(0,1,n,st[a]);
        }
    }
    return 0;
}