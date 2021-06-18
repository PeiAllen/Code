#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MC=1e5+1;
ll dp[2][MC][2];
int cost[2];
ll taste[2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,c;
    cin>>n>>c;
    int cur=1;
    for(int i=0;i<n;i++){
        cin>>cost[0]>>taste[0]>>cost[1]>>taste[1];
        dp[cur][0][1]=LLONG_MIN;
        for(int j=1;j<=c;j++){
            dp[cur][j][0]=max(dp[!cur][j][0],dp[!cur][j][1]);
            dp[cur][j][1]=LLONG_MIN;
            if(j-cost[0]>=0)dp[cur][j][1]=max(dp[cur][j][1],dp[cur][j-cost[0]][0]+taste[0]);
            if(j-cost[1]>=0)dp[cur][j][0]=max(dp[cur][j][0],dp[cur][j-cost[1]][1]+taste[1]);
        }
        cur=!cur;
    }
    ll best=0;
    for(int i=0;i<=c;i++)best=max({best,dp[!cur][i][0],dp[!cur][i][1]});
    printf("%lli\n",best);
    return 0;
}