#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=501;
int dp[MN][MN][2];
int cnt[MN],m;
vector<int> adj[MN];
void dfs(int loc, int parent){
    dp[loc][1][0]=dp[loc][1][1]=cnt[loc];
    for(auto x:adj[loc]){
        if(x!=parent){
            dfs(x,loc);
            for(int i=m;i>=0;i--){
                for(int j=0;j<=i;j++){
                    if(j+2<=i)dp[loc][i][0]=max(dp[loc][i][0],dp[loc][i-j-2][0]+dp[x][j][0]);
                    if(j+2<=i)dp[loc][i][1]=max(dp[loc][i][1],dp[loc][i-j-2][1]+dp[x][j][0]);
                    if(j+1<=i)dp[loc][i][1]=max(dp[loc][i][1],dp[loc][i-j-1][0]+dp[x][j][1]);
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cnt[i];
    }
    for(int i=1;i<n;i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
    dfs(1,0);
    int ans=0;
    for(int i=0;i<=m;i++){
        ans=max({ans,dp[1][i][0],dp[1][i][1]});
    }
    printf("%d\n",ans);
    return 0;
}