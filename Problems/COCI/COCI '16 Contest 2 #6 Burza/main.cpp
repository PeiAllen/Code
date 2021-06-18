#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=401;
bool dp[MN][(1<<20)];
int n,k;
vector<int> adj[MN];
vector<int> firstanc[MN];
vector<int> length[MN];
vector<int> curanc;
vector<int> leaves;
void dfs(int loc, int parent, int depth){
    if(depth<=k)curanc.push_back(loc);
    firstanc[loc]=curanc;
    if(sz(adj[loc])==1)leaves.push_back(loc);
    for(auto x:adj[loc])if(x!=parent)dfs(x,loc,depth);
    if(depth<=k)curanc.pop_back();
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a,b;
    cin>>n>>k;
    if(k*k+1>n){
        printf("DA\n");
        return 0;
    }
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b),adj[b].push_back(a);
    }
    dfs(1,0,0);
    for(int j=0;j<(1<<k);j++)dp[0][j]=1;
    for(int i=0;i<sz(leaves);i++){
        vector<int> transitions;
        for(int j=0;j<sz(firstanc[leaves[i]]);j++){
            if(i==0||j>=sz(firstanc[leaves[i-1]])||firstanc[leaves[i-1]][j]!=firstanc[leaves[i]][j]){
                length[i].push_back(1);
            }
            else length[i].push_back(length[i-1][j]+1);
            if(j>=0&&(i==sz(leaves)-1||j>=sz(firstanc[leaves[i+1]])||firstanc[leaves[i+1]][j]!=firstanc[leaves[i]][j]))transitions.push_back(j);
        }
        for(int j=0;j<(1<<k);j++){
            for(auto x:transitions){
                if(j&(1<<(x-1)))dp[i+1][j]|=dp[i+1-length[i][x]][j^(1<<(x-1))];
                if(sz(firstanc[leaves[i]])<=k)dp[i+1][j]|=dp[i][j];
            }
        }
    }
    bool work=false;
    for(int j=0;j<(1<<k)&&!work;j++)if(dp[sz(leaves)][j])work=true;
    if(work)printf("DA\n");
    else printf("NE\n");
    return 0;
}