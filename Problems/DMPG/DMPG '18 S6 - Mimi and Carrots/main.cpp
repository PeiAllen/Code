#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<pii> matrix[MAXN];
vector<int> bmatrix[2*MAXN];
int depth[MAXN],ldepth[MAXN];
stack<int> st;
int nodeind;
int n,m;
void GetBlockTree(int loc, int edgeind, int dep){
    depth[loc]=dep,ldepth[loc]=dep;
    st.push(loc);
    for(auto x:matrix[loc]){
        if(x.second!=edgeind){
            if(!depth[x.first]){
                GetBlockTree(x.first,x.second,dep+1);
                if(ldepth[x.first]==dep){
                    for(int cur=st.top();cur!=x.first;st.pop(),cur=st.top()){
                        bmatrix[cur].push_back(nodeind);
                        bmatrix[nodeind].push_back(cur);
                    }
                    st.pop();
                    bmatrix[loc].push_back(nodeind);
                    bmatrix[nodeind].push_back(loc);
                    bmatrix[x.first].push_back(nodeind);
                    bmatrix[nodeind].push_back(x.first);
                    nodeind++;
                }
                else if(ldepth[x.first]==depth[x.first])bmatrix[loc].push_back(x.first),bmatrix[x.first].push_back(loc);
                ldepth[loc]=min(ldepth[loc],ldepth[x.first]);
            }
            else ldepth[loc]=min(ldepth[loc],depth[x.first]);
        }
    }
    if(ldepth[loc]==dep)st.pop();
}
int sts[2*MAXN];
pii ans={INT_MAX,0};
void dfs(int loc, int par){
    sts[loc]=(loc<=n);
    int masize=0;
    for(auto x:bmatrix[loc]){
        if(x!=par){
            dfs(x,loc);
            masize=max(masize,sts[x]);
            sts[loc]+=sts[x];
        }
    }
    if(sz(bmatrix[loc])>=2&&loc<=n){
        masize=max(masize,n-sts[loc]);
        ans=min(ans,{masize,-loc});
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    nodeind=n+1;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        matrix[u].push_back({v,i});
        matrix[v].push_back({u,i});
    }
    for(int i=1;i<=n;i++)if(!depth[i])GetBlockTree(i,-1,1);
    dfs(1,0);
    if(ans.second==0)printf("-1 -1\n");
    else printf("%d %d\n",-ans.second,ans.first);
    return 0;
}