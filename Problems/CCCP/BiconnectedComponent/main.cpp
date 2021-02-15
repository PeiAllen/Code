#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
vector<pii> adj[MN];
int depth[MN],mindepth[MN];
vector<int> st;
vector<vector<int>> bct;
void dfs(int loc, int eind, int dep){
    depth[loc]=mindepth[loc]=dep;
    for(auto x:adj[loc]){
        if(x.second!=eind){
            if(depth[x.first])mindepth[loc]=min(depth[x.first],mindepth[loc]);
            else{
                dfs(x.first,x.second,dep+1);
                mindepth[loc]=min(mindepth[loc],mindepth[x.first]);
                if(mindepth[x.first]==dep){
                    bct.push_back({loc});
                    while(1){
                        int cur=st.back();
                        st.pop_back();
                        bct.back().push_back(cur);
                        if(cur==x.first)break;
                    }
                }
            }
        }
    }
    if(mindepth[loc]<depth[loc])st.push_back(loc);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back({b,i}),adj[b].push_back({a,i});
    }
    for(int i=0;i<n;i++)if(!depth[i])dfs(i,-1,1);
    return 0;
}