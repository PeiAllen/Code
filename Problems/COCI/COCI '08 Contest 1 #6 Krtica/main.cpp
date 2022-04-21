#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
vector<int> adj[MN];
pii dp[MN];//dia, longest path
pii dpup[MN];
pii suffix[MN];
int par[MN];
int best=INT_MAX;
pii removeedge={-1,-1};
void dfs1(int loc, int parent){
    dp[loc]={0,0};
    par[loc]=parent;
    if(parent!=0)adj[loc].erase(find(adj[loc].begin(),adj[loc].end(),parent));
    for(auto x:adj[loc]){
        dfs1(x,loc);
        dp[loc].first=max({dp[loc].first,dp[x].first,dp[x].second+1+dp[loc].second});
        dp[loc].second=max(dp[loc].second,dp[x].second+1);
    }
}
void dfs2(int loc, int parent){
    if(parent==0)dpup[loc]={-1,-1};
    else {
        int newdiam = max({dpup[loc].first, dp[loc].first, 1 + (dpup[loc].first + 1) / 2 + (dp[loc].first + 1) / 2});
        if (newdiam < best)best = newdiam, removeedge = {loc, parent};
    }
    suffix[sz(adj[loc])]={0,0};
    for(int i=sz(adj[loc])-1;i>=0;i--){
        suffix[i].first=max({suffix[i+1].first,dp[adj[loc][i]].first,dp[adj[loc][i]].second+1+suffix[i+1].second});
        suffix[i].second=max(suffix[i+1].second,dp[adj[loc][i]].second+1);
    }
    pii cur={max(dpup[loc].first,dpup[loc].second+1+0),dpup[loc].second+1};
    for(int i=0;i<sz(adj[loc]);i++){
        dpup[adj[loc][i]]={max({cur.first,suffix[i+1].first,cur.second+suffix[i+1].second}),max(cur.second,suffix[i+1].second)};
        cur.first=max({cur.first,dp[adj[loc][i]].first,dp[adj[loc][i]].second+1+cur.second});
        cur.second=max(cur.second,dp[adj[loc][i]].second+1);
    }
    for(auto x:adj[loc]) {
        dfs2(x,loc);
    }
}
int dist[MN],n;
void dfs(int loc, int parent){
    dist[loc]=dist[parent]+1;
    for(auto x:adj[loc]){
        if(x!=parent&&x!=removeedge.first&&x!=removeedge.second){
            dfs(x,loc);
        }
    }
}
vector<int> nodes;
int ansnode=0;
void dfsm(int loc, int parent, int diam){
    nodes.push_back(loc);
    if(sz(nodes)-1==diam){
        ansnode=nodes[sz(nodes)/2];
    }
    for(auto x:adj[loc]){
        if(x!=parent&&pii{min(loc,x),max(loc,x)}!=pii{min(removeedge.first,removeedge.second),max(removeedge.first,removeedge.second)}){
            dfsm(x,loc,diam);
        }
    }
    nodes.pop_back();
}
int getcenter(int st, int diam){
    for(int i=0;i<=n;i++)dist[i]=-1;
    dfs(st,0);
    int oneside=max_element(dist,dist+n+1)-dist;
    dfsm(oneside,0, diam);
    return ansnode;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a,b;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,0),dfs2(1,0);
    for(int i=2;i<=n;i++)adj[i].push_back(par[i]);
    printf("%d\n",best);
    printf("%d %d\n",removeedge.first,removeedge.second);
    printf("%d %d\n",getcenter(removeedge.first,dp[removeedge.first].first),getcenter(removeedge.second,dpup[removeedge.first].first));
    return 0;
}