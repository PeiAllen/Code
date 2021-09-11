#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll dp[2][1001][8];
ll arr[3001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int cur=1;
    for(int j=0;j<=k;j++)for(int m=0;m<8;m++)dp[0][j][m]=LLONG_MIN;
    dp[0][0][7]=0;
    for(int i=0;i<3*n;i++){
        cin>>arr[i];
        for(int j=0;j<=k;j++)for(int m=0;m<8;m++)dp[cur][j][m]=LLONG_MIN;
        for(int j=0;j<=k;j++) {
            for (int m = 0; m < 8; m++) {
                if(dp[!cur][j][m]!=LLONG_MIN){
                    if(j+1<=k){
                        if(i%3&&(m&1)==0)dp[cur][j+1][3+(1<<2)*!!(m&(1<<1))]=max(dp[cur][j+1][3+(1<<2)*!!(m&(1<<1))],dp[!cur][j][m]+arr[i]+arr[i-1]);
                        if(i>=3&&(m&(1<<2))==0)dp[cur][j+1][1+((m&((1<<2)-1))<<1)]=max(dp[cur][j+1][1+((m&((1<<2)-1))<<1)],dp[!cur][j][m]+arr[i]+arr[i-3]);
                    }
                    dp[cur][j][(m&((1<<2)-1))<<1]=max(dp[cur][j][(m&((1<<2)-1))<<1],dp[!cur][j][m]);
                }
            }
        }
        cur=!cur;
    }
    ll ans=0;
    for(int m=0;m<8;m++)ans=max(ans,dp[!cur][k][m]);
    printf("%lli\n",ans);
    return 0;
}