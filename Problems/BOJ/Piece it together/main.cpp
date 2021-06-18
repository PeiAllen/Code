#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=501;
int xc[4]={1,-1,0,0},yc[4]={0,0,1,-1};
char arr[MN][MN];
int dir[MN][MN][4],st[MN*MN*8],mst[MN*MN*8],partof[MN*MN*8],et,comps;
vector<int> nodes;
bool inst[MN*MN*8];
vector<vector<int>> white;
vector<int> adj[MN*MN*8];
void scc(int loc){
    st[loc]=mst[loc]=et++;
    nodes.push_back(loc);
    inst[loc]=true;
    for(auto x:adj[loc]){
        if(!st[x])scc(x),mst[loc]=min(mst[loc],mst[x]);
        else if(inst[x])mst[loc]=min(mst[loc],st[x]);
    }
    if(mst[loc]==st[loc]){
        while(1){
            auto cur=nodes.back();
            nodes.pop_back();
            inst[cur]=false;
            partof[cur]=comps;
            if(cur==loc)break;
        }
        comps++;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,b=0,w=0,ncnt=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dir[i][j][0]=dir[i][j][1]=dir[i][j][2]=dir[i][j][3]=-1;
                cin>>arr[i][j];
                if(arr[i][j]=='B')b++;
                else if(arr[i][j]=='W')w++;
            }
        }
        if(w!=b*2){
            printf("NO\n");
            continue;
        }
        white=vector<vector<int>>();
        for(int i=1;i<=n;i++) {
            for (int j = 1; j <= m; j++) {
                if(arr[i][j]=='W'){
                    white.push_back({});
                    for(int k=0;k<4;k++){
                        pii nx={i+xc[k],j+yc[k]};
                        if(nx.first>=1&&nx.first<=n&&nx.second>=1&&nx.second<=m&&arr[nx.first][nx.second]=='B'){
                            white.back().push_back(ncnt);
                            dir[nx.first][nx.second][k]=ncnt;
                            ncnt+=2;
                        }
                    }
                }
            }
        }
        for(int i=0;i<ncnt;i++)adj[i]=vector<int>(),st[i]=mst[i]=0,partof[i]=-1;
        for(const auto& x:white){
            for(auto y:x){
                for(auto z:x){
                    if(y!=z){
                        adj[y].push_back(z+1);
                    }
                }
            }
        }
        bool bad=false;
        for(int i=1;i<=n&&!bad;i++) {
            for (int j = 1; j <= m&&!bad; j++) {
                if(arr[i][j]=='B'){
                    if(dir[i][j][0]==-1&&dir[i][j][1]==-1)bad=true;
                    else if(dir[i][j][0]==-1){
                        adj[dir[i][j][1]+1].push_back(dir[i][j][1]);
                    }
                    else if(dir[i][j][1]==-1){
                        adj[dir[i][j][0]+1].push_back(dir[i][j][0]);
                    }
                    else{
                        adj[dir[i][j][0]].push_back(dir[i][j][1]+1);
                        adj[dir[i][j][1]].push_back(dir[i][j][0]+1);
                        adj[dir[i][j][0]+1].push_back(dir[i][j][1]);
                        adj[dir[i][j][1]+1].push_back(dir[i][j][0]);
                    }
                    if(dir[i][j][2]==-1&&dir[i][j][3]==-1)bad=true;
                    else if(dir[i][j][2]==-1){
                        adj[dir[i][j][3]+1].push_back(dir[i][j][3]);
                    }
                    else if(dir[i][j][3]==-1){
                        adj[dir[i][j][2]+1].push_back(dir[i][j][2]);
                    }
                    else{
                        adj[dir[i][j][2]].push_back(dir[i][j][3]+1);
                        adj[dir[i][j][3]].push_back(dir[i][j][2]+1);
                        adj[dir[i][j][2]+1].push_back(dir[i][j][3]);
                        adj[dir[i][j][3]+1].push_back(dir[i][j][2]);
                    }
                }
            }
        }
        if(bad){
            printf("NO\n");
            continue;
        }
        et=1;
        comps=0;
        for(int i=0;i<ncnt;i++)if(!st[i])scc(i);
        for(int i=0;i<ncnt&&!bad;i+=2){
            if(partof[i]==partof[i+1]){
                bad=true;
            }
        }
        if(bad){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}