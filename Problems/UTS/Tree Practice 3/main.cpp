#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll arr[MN];
ll bit[MN];
vector<int> adj[MN];
int n,q,st[MN],en[MN],lst[MN],let=0,et=1,sparse[19][MN*2],depth[MN];
void update(int loc, ll val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
ll query(int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
void dfs(int loc, int parent){
    depth[loc]=depth[parent]+1;
    sparse[0][let]=loc,lst[loc]=let++;
    st[loc]=et++;
    for(auto x:adj[loc])if(x!=parent)dfs(x,loc),sparse[0][let++]=loc;
    en[loc]=et-1;
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<=18;i++){
        for(int j=0;j+(1<<i)<=let;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=lst[a],b=lst[b];
    if(a>b)swap(a,b);
    int k=__lg(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    int t,a,b;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0),ms();
    for(int i=1;i<=n;i++)update(st[i],arr[i]),update(en[i]+1,-arr[i]);
    while(q--){
        cin>>t>>a>>b;
        if(t==1)update(st[a],b),update(en[a]+1,-b),arr[a]+=b;
        else{
            ll lca=getlca(a,b);
            printf("%lli\n",query(st[a])+query(st[b])-ll(2)*query(st[lca])+arr[lca]);
        }
    }
    return 0;
}