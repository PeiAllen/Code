#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<pii> adj[MN];
int depth[MN],lowdepth[MN];
bool art[MN];
bool bridge[MN];
bool gone[MN];
void dfs(int loc, int eind, int dep){
    depth[loc]=lowdepth[loc]=dep;
    int deg=(eind!=-1);
    for(auto x:adj[loc]){
        if(x.second!=eind){
            if(depth[x.first])lowdepth[loc]=min(lowdepth[loc],depth[x.first]);
            else{
                dfs(x.first,x.second,dep+1);
                art[x.first]|=(lowdepth[x.first]>=depth[loc]);
                lowdepth[loc]=min(lowdepth[loc],lowdepth[x.first]);
                deg++;
            }
        }
    }
    art[loc]&=(deg>=2);
    if(eind!=-1&&lowdepth[loc]==depth[loc])bridge[eind]=true;
}
void getbridge(int loc,vector<int>& c){
    c.push_back(loc),gone[loc]=true;
    for(auto x:adj[loc])if(!bridge[x.second]&&!gone[x.first])getbridge(x.first,c);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    for(int i=0;i<n;i++)if(!depth[i])dfs(i,-1,1);
    vector<vector<int>> bridgeans;
    for(int i=0;i<n;i++){
        if(!gone[i]) {
            vector<int> te;
            getbridge(i, te);
            bridgeans.push_back(te);
        }
    }
    printf("%d\n",sz(bridgeans));
    for(auto x:bridgeans){
        printf("%d ",sz(x));
        for(int i=0;i<sz(x);i++)printf("%d%c",x[i]," \n"[i==sz(x)-1]);
    }
    return 0;
}