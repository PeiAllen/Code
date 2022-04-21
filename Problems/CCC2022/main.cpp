#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
const ll MAX_VAL=1e16;
ll arr[MN];
bool done[MN];
vector<int> adj[MN];
ll dp[MN][2][2];//needing,pushed
ll te[2][2];
void dfs(int loc, int parent){
    if(done[loc]){
        dp[loc][0][0]=0;
        dp[loc][0][1]=arr[loc];
        dp[loc][1][0]=0;
        dp[loc][1][1]=arr[loc];
    }
    else{
        dp[loc][0][0]=MAX_VAL;
        dp[loc][0][1]=MAX_VAL;
        dp[loc][1][0]=0;
        dp[loc][1][1]=arr[loc];
    }
    for(auto x:adj[loc]){
        if(x!=parent){
            dfs(x,loc);
            te[0][0]=min(MAX_VAL,min(dp[loc][0][0]+min(dp[x][0][0],dp[x][0][1]),dp[loc][1][0]+dp[x][0][1]));
            te[0][1]=min(MAX_VAL,min(dp[loc][0][1]+min({dp[x][0][0],dp[x][0][1],dp[x][1][0],dp[x][1][1]}),dp[loc][1][1]+dp[x][0][1]));
            te[1][0]=min(MAX_VAL,dp[loc][1][0]+min(dp[x][0][0],dp[x][0][1]));
            te[1][1]=min(MAX_VAL,dp[loc][1][1]+min({dp[x][0][0],dp[x][1][0],dp[x][1][1],dp[x][0][1]}));
            for(int i=0;i<2;i++)for(int j=0;j<2;j++)dp[loc][i][j]=te[i][j];
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b;
    char c;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        done[i]=(s[i-1]=='Y');
    }
    for(int i=1;i<=n;i++)cin>>arr[i];
    dfs(1,0);
    printf("%lli\n",min(dp[1][0][0],dp[1][0][1]));
    return 0;
}