#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll dp[351][351][2];
const ll mod=1e9+7;
ll fact[351],inv[351];
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll choose(ll a, ll b){
    return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    dp[0][0][0]=1;
    fact[0]=1;
    inv[0]=1;
    for(ll i=1;i<=n;i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fp(fact[i],mod-2);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int l=0;l<2;l++) {
                for (int k = 0; k <= j; k++) {
                    if(l==0&&k!=i)dp[i][j][l]=(dp[i][j][l]+(dp[i-1][j-k][l]*choose(n-j+k,k)%mod))%mod;
                    if(l==1){
                        dp[i][j][l]=(dp[i][j][l]+(dp[i-1][j-k][l]*choose(n-j+k,k)%mod))%mod;
                        if(k==i)dp[i][j][l]=(dp[i][j][l]+(dp[i-1][j-k][0]*choose(n-j+k,k)%mod))%mod;
                    }
                }
            }
        }
    }
    printf("%lli\n",dp[n][n][1]);
    return 0;
}