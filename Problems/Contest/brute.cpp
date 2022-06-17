#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e3+1;
int arr[MN][MN];
char grid[MN][MN];
unordered_map<char,pii> conver={{'U',{-1,0}},{'D',{1,0}},{'L',{0,-1}},{'R',{0,1}}};
vector<pii> adj[MN][MN];
bool bad[MN][MN];
bool done[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
            pii nxt={i+conver[grid[i][j]].first,j+conver[grid[i][j]].second};
            adj[i][j].push_back(nxt);
            bad[nxt.first][nxt.second]=true;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!bad[i][j]&&!done[i][j]){
                ans++;
                pii cur={i,j};
                while(!done[cur.first][cur.second]){
                    done[cur.first][cur.second]=true;
                    cur=adj[cur.first][cur.second].back();
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!done[i][j]){
                ans++;
                pii cur={i,j};
                while(!done[cur.first][cur.second]){
                    done[cur.first][cur.second]=true;
                    cur=adj[cur.first][cur.second].back();
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}