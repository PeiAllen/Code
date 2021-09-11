#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
int val[MAXN];
int ups[MAXN];
int parent[MAXN];
int depth[MAXN];
int st[MAXN];
int et=0;
int sparse[19][2*MAXN];
vector<int> matrix[MAXN];
void dfs(int loc, int par, int dep){
    depth[loc]=dep;
    parent[loc]=par;
    st[loc]=et;
    sparse[0][et++]=loc;
    for(auto x:matrix[loc]){
        if(x!=par){
            dfs(x,loc,dep+1);
            sparse[0][et++]=loc;
        }
    }
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<=18;i++){
        for(int j=0;j+(1<<i)<=et;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int k=log2(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
void dfsans(int loc){
    for(auto x:matrix[loc])if(x!=parent[loc])dfsans(x);
    if(depth[loc]>2)ups[parent[parent[loc]]]^=ups[loc];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int a,b;
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0,1);
    ms();
    int c;
    while(q--){
        cin>>a>>b>>c;
        int lca=getlca(a,b);
        ups[a]^=c;
        if((depth[a]+depth[b]-2*depth[lca])%2){
            if(b!=1)ups[parent[b]]^=c;
        }
        else ups[b]^=c;
        if((depth[a]-depth[lca])%2==0)val[lca]^=c;
    }
    dfsans(1);
    for(int i=1;i<=n;i++)printf("%d ",val[i]^ups[i]);
    return 0;
}