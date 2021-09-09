#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=201;
vector<int> adj[MN];
pll arr[MN];
pll dp[MN][MN];//first is max, second is max of cur node
int m;
void dfs(int loc){
    vector<ll> te(m+1,(sz(adj[loc])?LLONG_MAX:0));
    for(auto x:adj[loc]){
        dfs(x);
        for(int i=0;i<=m;i++){
            dp[loc][i].first=max(dp[loc][i].first,dp[x][i].first);
        }
        for(int i=m;i>=0;i--){
            te[i]=min(te[i],dp[x][0].second);
            for(int j=1;j<=i;j++){
                te[i]=max(te[i],min(te[i-j],dp[x][j].second));
            }
        }
    }
    for(int i=m;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[loc][i].second=max(dp[loc][i].second,arr[loc].first+arr[loc].second*(te[j]+i-j));
        }
        dp[loc][i].first=max(dp[loc][i].first,dp[loc][i].second);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a>>arr[i].first>>arr[i].second;
        adj[a].push_back(i);
    }
    dfs(1);
    printf("%lli\n",dp[1][m].second);
    return 0;
}