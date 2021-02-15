#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e2+1;
const ll mod=1e9+7;
ll fix(ll a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
ll dp[2][MAXN][MAXN][MAXN];// loc, component count, components with last mbs, components with current mbs
ll arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    dp[0][1][0][1]=1;
    int cur=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<MAXN;j++)for(int k=0;k<MAXN;k++)for(int l=0;l<MAXN;l++)dp[cur][j][k][l]=0;
        for(int j=1;j<=i;j++){
            if(__builtin_clzll(arr[i]) + 1 < __builtin_clzll(arr[i - 1])){
                for(int k=0;k<=j-1;k++){
                    for(int l=0;l+k<=j-1;l++) {
                        dp[cur][j][0][1] = fix(dp[cur][j][0][1] + dp[!cur][j - 1][k][l]);
                    }
                }
                for(int k=0;k<=j;k++) {
                    for (int l = 0; l + k <= j; l++) {
                        dp[cur][j][0][0] = fix(dp[cur][j][0][0] + (dp[!cur][j][k][l] * (ll) j % mod));
                    }
                }
            }
            else {
                for (int k = 0; k <= j; k++) {
                    if (__builtin_clzll(arr[i]) == __builtin_clzll(arr[i - 1])) {
                        for (int l = 0; l + k <= j; l++) {
                            if (l > 0)dp[cur][j][k][l] = fix(dp[cur][j][k][l] + dp[!cur][j - 1][k][l - 1]);
                            if (l > 0)
                                dp[cur][j][k][l] = fix(
                                        dp[cur][j][k][l] + (dp[!cur][j][k + 1][l - 1] * (ll) (k + 1) % mod));
                            dp[cur][j][k][l] = fix(dp[cur][j][k][l] + (dp[!cur][j][k][l] * (ll) (j) % mod));
                            dp[cur][j][k][l] = fix(dp[cur][j][k][l] +
                                                 ((dp[!cur][j + 1][k + 1][l] * (ll) (j + 1 - (k + 1)) % mod) *
                                                  (ll) (k + 1) % mod));
                            dp[cur][j][k][l] = fix(dp[cur][j][k][l] +
                                                 ((dp[!cur][j + 1][k + 1][l] * (ll) (k + 1) % mod) * (ll) (k) % mod));
                        }
                    } else {
                        for (int l = 0; l + k <= j - 1; l++)
                            dp[cur][j][k][1] = fix(dp[cur][j][k][1] + dp[!cur][j - 1][l][k]);
                        for (int l = 0; l + k + 1 <= j; l++)
                            dp[cur][j][k][1] = fix(dp[cur][j][k][1] + (dp[!cur][j][l][k + 1] * (ll) (k + 1) % mod));
                        for (int l = 0; l + k <= j; l++)
                            dp[cur][j][k][0] = fix(dp[cur][j][k][0] + (dp[!cur][j][l][k] * (ll) (j) % mod));
                        for (int l = 0; l + k + 1 <= j + 1; l++) {
                            dp[cur][j][k][0] = fix(dp[cur][j][k][0] +
                                                 ((dp[!cur][j + 1][l][k + 1] * (ll) (j + 1 - (k + 1)) % mod) *
                                                  (ll) (k + 1) % mod));
                            dp[cur][j][k][0] = fix(dp[cur][j][k][0] +
                                                 ((dp[!cur][j + 1][l][k + 1] * (ll) (k + 1) % mod) * (ll) (k) % mod));
                        }
                    }
                }
            }
        }
        cur=!cur;
    }
    ll ans=0;
    for(int i=0;i<=1;i++){
        for(int j=0;j+i<=1;j++){
            ans=fix(ans+dp[!cur][1][i][j]);
        }
    }
    printf("%lli\n",ans);
    return 0;
}