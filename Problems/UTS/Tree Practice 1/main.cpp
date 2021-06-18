#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<int> adj[MN];
int depth[MN],sparse[19][2*MN],st[MN],et;
void dfs(int loc, int parent){
    sparse[0][et]=loc,st[loc]=et++,depth[loc]=depth[parent]+1;
    for(auto x:adj[loc])if(x!=parent)dfs(x,loc),sparse[0][et++]=loc;
}
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
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,b;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0),ms();
    for(int i=1;i<=q;i++){
        cin>>a>>b;
        printf("%d\n",depth[a]+depth[b]-2*depth[getlca(a,b)]);
    }
    return 0;
}