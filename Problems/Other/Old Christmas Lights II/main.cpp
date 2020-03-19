#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e4+1;
vector<int> matrix[MAXN];
int arr[MAXN];
int ind[MAXN];
pii vals[MAXN];
int ans[MAXN];
int lift[16][MAXN];
int depth[MAXN];
int st[MAXN],en[MAXN];
vector<int> et;
struct node {
    int data, mi, ma, le, ri;
    bool amount;
    node() {
        data = INT_MAX, amount = 0, mi = INT_MAX, ma = -1, le = 0, ri = 0;
    }

    int mid() { return (le + ri) / 2; }
};
node tree[3*MAXN];
int manode=0;
vector<int> ree;
void mt(int l, int r, int ind){
    tree[ind].le=l,tree[ind].ri=r;
    ree.push_back(ind);
    if(tree[ind].le!=tree[ind].ri){
        mt(tree[ind].le,tree[ind].mid(),(ind<<1)),mt(tree[ind].mid()+1,tree[ind].ri,(ind<<1)|1);
    }
}
void update(int loc, int ind){
    while(tree[ind].le!=tree[ind].ri){
        if(loc>tree[ind].mid())ind=(ind<<1)|1;
        else ind<<=1;
    }
    tree[ind].amount=!tree[ind].amount;
    if(!tree[ind].amount)tree[ind].mi=INT_MAX,tree[ind].ma=-1;
    else tree[ind].mi=vals[loc].first,tree[ind].ma=vals[loc].first;
    ind>>=1;
    while(ind!=0) {
        tree[ind].data = min(tree[(ind << 1)].data, tree[(ind << 1) | 1].data);
        if (tree[(ind << 1)].ma != -1 && tree[(ind << 1) | 1].mi != INT_MAX)tree[ind].data = min(tree[ind].data,
                                                                                                 tree[(ind << 1) |
                                                                                                      1].mi -
                                                                                                 tree[(ind << 1)].ma);
        tree[ind].mi = min(tree[(ind << 1)].mi, tree[(ind << 1) | 1].mi);
        tree[ind].ma = max(tree[(ind << 1)].ma, tree[(ind << 1) | 1].ma);
        ind>>=1;
    }
}
void reset(){
    for(int i:ree)tree[i].data=INT_MAX,tree[i].amount=0,tree[i].mi=INT_MAX,tree[i].ma=-1;
}
void dfs(int loc, int parent, int dep){
    st[loc]=sz(et);
    et.push_back(loc);
    depth[loc]=dep;
    lift[0][loc]=parent;
    for(int x:matrix[loc]){
        if(x!=parent)dfs(x,loc,dep+1);
    }
    en[loc]=sz(et);
    et.push_back(loc);
}
int n,q;
void ml(){
    for(int i=1;i<16;i++){
        for(int j=1;j<=n;j++){
            lift[i][j]=lift[i-1][lift[i-1][j]];
        }
    }
}
int lca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    int diff=depth[a]-depth[b];
    for(int i=0;i<16;i++){
        if(diff&(1<<i))a=lift[i][a];
    }
    if(a==b)return a;
    for(int i=15;i>=0;i--){
        if(lift[i][a]!=lift[i][b]){
            a=lift[i][a],b=lift[i][b];
        }
    }
    return lift[0][a];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    int a,b;
    for(int i=1;i<=n;i++)cin>>arr[i],vals[i]={arr[i],i};
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    sort(vals+1,vals+1+n);
    for(int i=1;i<=n;i++)ind[vals[i].second]=i;
    dfs(1,0,0);
    ml();
    vector<pair<pii,pair<int,int>>> queries;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(st[a]>st[b])swap(a,b);
        int lc=lca(a,b);
        if(a==lc)queries.push_back({{st[a],st[b]},{0,i}});
        else queries.push_back({{en[a],st[b]},{lc,i}});
    }
    int block=600;
    sort(queries.begin(),queries.end(),[&](auto lhs, auto rhs){
        if(lhs.first.first/block==rhs.first.first/block){
            return lhs.first.second<rhs.first.second;
        }
        return lhs.first.first<rhs.first.first;
    });
    mt(1,n,1);
    int l=0,r=-1;
    int lst=0;
    for(int i=0;i<q;i++){
        auto cur=queries[i];
        //if(cur.first.first/block!=lst){
        if(abs(cur.first.second-r)+abs(cur.first.first-l)>cur.first.first+cur.first.second)reset(),l=0,r=-1;
        //     lst=cur.first.first/block;
        // }
        while(l<cur.first.first)update(ind[et[l++]],1);
        while(l>cur.first.first)update(ind[et[--l]],1);
        while(r>cur.first.second)update(ind[et[r--]],1);
        while(r<cur.first.second)update(ind[et[++r]],1);
        if(cur.second.first!=0)update(ind[cur.second.first],1);
        ans[cur.second.second]=tree[1].data;
        if(cur.second.first!=0)update(ind[cur.second.first],1);
    }
    for(int i=0;i<q;i++)printf("%d\n",ans[i]);
    return 0;
}