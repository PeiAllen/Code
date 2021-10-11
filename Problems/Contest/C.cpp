#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}
const int MN=2e5+1;
int depth[MN],ldepth[MN],n,m;
vector<int> nodes;
vector<int> badj[2*MN];
vector<int> adj[MN];
vector<vector<int>> finalcomps;
int col[MN];
bool bipartite(int loc, int c){
    col[loc]=c;
    for(auto x:adj[loc]){
        if(col[x]==2&&!bipartite(x,!c))return false;
        if(col[x]==c)return false;
    }
    return true;
}
void addedge(int a, int b){
    badj[a].push_back(b);
    badj[b].push_back(a);
}
void dfs(int loc, int parent, int dep){
    depth[loc]=ldepth[loc]=dep;
    nodes.push_back(loc);
    for(auto x:adj[loc]){
        if(x!=parent){
            if(!depth[x]){
                dfs(x,loc,dep+1);
                if(ldepth[x]==dep){
                    finalcomps.push_back({});
                    while(1){
                        int cur=nodes.back();
                        nodes.pop_back();
                        finalcomps.back().push_back(cur);
                        addedge(SZ(finalcomps)+n,cur);
                        if(cur==x)break;
                    }
                }
                else if(ldepth[x]==depth[x])addedge(loc,x);
                ldepth[loc]=min(ldepth[loc],ldepth[x]);
            }
            else ldepth[loc]=min(ldepth[loc],depth[x]);
        }
    }
    if(ldepth[loc]==dep)nodes.pop_back();
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>n>>m;
        finalcomps=vector<vector<int>>();
        for(int i=1;i<=n;i++)adj[i]=vector<int>(),col[i]=2,depth[i]=ldepth[i]=0;
        for(int i=1;i<=2*n;i++)badj[i]=vector<int>();
        for(int i=0;i<m;i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(!bipartite(1,0)){
            printf("No\n");
            continue;
        }
        dfs(1,0,1);
        bool work=true;
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(auto x:badj[i]){
                if(x>n)cnt++;
            }
            if(cnt>=2)work=false;
        }
        if(!work){
            printf("No\n");
            continue;
        }

    }
    return 0;
}