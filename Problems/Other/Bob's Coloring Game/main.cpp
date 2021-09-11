#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e4+1;
int col[MN],edgecnt,nodecnt;
vector<int> onedegnodes;
vector<int> nodes;
set<int> adj[MN];
bool dfs(int loc, int c){
    col[loc]=c;
    if(sz(adj[loc])==1)onedegnodes.push_back(loc);
    nodes.push_back(loc);
    nodecnt++,edgecnt+=sz(adj[loc]);
    for(auto x:adj[loc]){
        if(col[x]==c)return false;
        if(col[x]==-1&&!dfs(x,!c))return false;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m;
        for(int i=1;i<=n;i++)col[i]=-1,adj[i]=set<int>();
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            adj[a].insert(b),adj[b].insert(a);
        }
        bool work=true;
        for(int i=1;i<=n&&work;i++){
            if(col[i]==-1){
                edgecnt=0,nodecnt=0;
                work&=dfs(i,0);
                edgecnt/=2;
                if(edgecnt>nodecnt+1)work=false;
                if(edgecnt<=nodecnt||!work)continue;
                while(sz(onedegnodes)){
                    int cur=onedegnodes.back();
                    onedegnodes.pop_back();
                    int oth=*adj[cur].begin();
                    adj[oth].erase(cur);
                    if(sz(adj[oth])==1)onedegnodes.push_back(oth);
                }
                set<int> tot;
                for(auto x:nodes){
                    if(sz(adj[x])==3){
                        for(auto y:adj[x]){
                            if(sz(adj[y])==2)tot.insert(y);
                        }
                    }
                }
                if(sz(tot)>=5)work=false;
                nodes=vector<int>();
            }
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}