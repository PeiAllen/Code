#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
vector<int> adj[MN];
bool inst[MN];
stack<int> nodes;
int st[MN],low[MN],et;
vector<vector<int>> comps;
void dfs(int loc){
    st[loc]=low[loc]=++et;
    inst[loc]=true,nodes.push(loc);
    for(auto x:adj[loc]){
        if(!st[x]){
            dfs(x);
            low[loc]=min(low[loc],low[x]);
        }
        else if(inst[x])low[loc]=min(low[loc],st[x]);
    }
    if(low[loc]==st[loc]){
        comps.push_back({});
        while(1){
            auto cur=nodes.top();
            nodes.pop();
            comps.back().push_back(cur);
            inst[cur]=false;
            if(cur==loc)break;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=0;i<n;i++)if(!st[i])dfs(i);
    reverse(comps.begin(),comps.end());
    printf("%d\n",sz(comps));
    for(auto x:comps){
        printf("%d ",sz(x));
        for(auto y:x)printf("%d%c",y," \n"[y==x.back()]);
    }
    return 0;
}