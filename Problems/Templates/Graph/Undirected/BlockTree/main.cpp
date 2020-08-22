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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    nodeind=n+1;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        matrix[u].push_back({v,i});
        matrix[v].push_back({u,i});
    }
    for(int i=1;i<=n;i++)if(!depth[i])GetBlockTree(i,-1,1);
    for(int i=1;i<nodeind;i++)for(auto x:bmatrix[i])if(x<=i)printf("%d %d\n",x,i);
    return 0;
}