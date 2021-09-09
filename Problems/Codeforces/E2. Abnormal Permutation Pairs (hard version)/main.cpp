#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
//const int MN=501,offset=130000;
const int MN=501,offset=20;
ll mod;
ll dp[2][2][MN*MN*2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>mod;
    dp[0][0][offset+0]=1%mod;
    int maxinver=n*(n-1)/2;
//    for(int i=1;i<=maxinver;i++)dp[0][0][offset+i]=(dp[0][0][offset+i]+dp[0][0][offset+i-1])%mod;
    int cur=1;
    for(int i=1;i<=n;i++){
        for(int j=-maxinver;j<=maxinver;j++) {
            dp[cur][0][j+offset]=dp[!cur][0][j+offset]*i%mod;
//            dp[cur][0][j+offset]=(dp[cur][0][j+offset]+dp[cur][0][j+offset-1])%mod;
        }
        for(int j=-maxinver;j<=maxinver;j++) {
            for(int diff=-(i-1);diff<=i-1;diff++) {
                if(j+diff>=-maxinver&&j+diff<=maxinver) {
                    dp[cur][1][j + offset] = (dp[cur][1][j + offset] + dp[!cur][1][j - diff + offset] * (i - abs(diff)) % mod) % mod;
                    if (diff < 0)dp[cur][1][j + offset] = (dp[cur][1][j + offset] + dp[!cur][0][j - diff + offset] * (i - abs(diff)) % mod) % mod;
                }
            }
//            dp[cur][1][j+offset]=(dp[cur][1][j+offset]+dp[cur][1][j+offset-1])%mod;
        }
        cur=!cur;
    }
    ll ans=0;
    for(int i=1;i<=maxinver;i++){
        ans=(ans+dp[!cur][1][i+offset])%mod;
    }
    printf("%lli\n",ans);
    return 0;
}