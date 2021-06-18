#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e2+1,MM=1e3+1;
vector<int> adj[MN];
pii edge[MM];
bool used[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        edge[i]={a,b};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pii best={0,1};
    vector<int> nodes;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)used[j]=false;
        int cnt=1;
        int edges=0;
        used[i]=true;
        while(1){
            bool added=false;
            for(int j=0;j<m&&!added;j++){
                int willadd=0;
                int addednodes=0;
                if(!used[edge[j].first]){
                    addednodes++;
                    for(auto x:adj[edge[j].first])if(used[x]&&x!=edge[j].second)willadd++;
                }
                if(!used[edge[j].second]){
                    addednodes++;
                    for(auto x:adj[edge[j].second])if(used[x]&&x!=edge[j].first)willadd++;
                }
                if(willadd&&addednodes){
                    if((willadd+1+edges)*cnt>=edges*(cnt+addednodes)){
                        cnt+=addednodes;
                        edges+=willadd+1;
                        used[edge[j].first]=true;
                        used[edge[j].second]=true;
                    }
                }
            }
            if(!added)break;
        }
        while(1){
            bool deled=false;
            for(int j=1;j<=n&&!deled;j++){
                if(used[j]&&j!=i){
                    int willdel=0;
                    for(auto x:adj[j]){
                        if(used[x])willdel++;
                    }
                    if((edges-willdel)*cnt>=edges*(cnt-1)){
                        used[j]=false;
                        deled=true;
                        cnt--;
                        edges-=willdel;
                    }
                }
            }
            if(!deled)break;
        }
        if(edges*best.second>=cnt*best.first){
            best={edges,cnt};
            nodes=vector<int>();
            for(int j=1;j<=n;j++){
                if(used[j])nodes.push_back(j);
            }
        }
    }
    printf("%d\n",sz(nodes));
    for(auto x:nodes)printf("%d\n",x);
    return 0;
}