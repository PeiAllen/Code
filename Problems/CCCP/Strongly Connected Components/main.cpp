#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
vector<int> adj[MN];
int etind;
int et[MN],etmin[MN];
bool inst[MN];
vector<int> reach;
vector<vector<int>> scc;
void dfs(int loc){
    et[loc]=etmin[loc]=etind++;
    reach.push_back(loc),inst[loc]=true;
    for(auto x:adj[loc]){
        if(!et[x]){
            dfs(x);
            etmin[loc]=min(etmin[loc],etmin[x]);
        }
        else if(inst[x])etmin[loc]=min(etmin[loc],et[x]);
    }
    if(et[loc]==etmin[loc]){
        scc.push_back({});
        while(1){
            int cur=reach.back();
            reach.pop_back();
            scc.back().push_back(cur);
            inst[cur]=false;
            if(cur==loc)break;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++)cin>>a>>b,adj[a].push_back(b);
    etind=1;
    for(int i=0;i<n;i++)if(!et[i])dfs(i);
    printf("%d\n",sz(scc));
    reverse(scc.begin(),scc.end());
    for(auto x:scc){
        printf("%d",sz(x));
        reverse(x.begin(),x.end());
        for(auto y:x)printf(" %d",y);
        printf("\n");
    }
    return 0;
}