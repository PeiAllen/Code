#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2001;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll fact[MN],inv[MN];
ll dp[MN][MN];
ll choose(ll a, ll b){
    return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    fact[0]=inv[0]=1;
    for(ll i=1;i<=n;i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fp(fact[i],mod-2)%mod;
    }
    string a;
    map<string,int> am;
    for(int i=1;i<=n;i++){
        cin>>a;
        sort(a.begin(),a.end());
        am[a]++;
    }
    int i=1;
    dp[0][0]=1;
    for(auto it:am){
        for(int j=0;j<=k;j++){
            for(int l=0;l<=it.second;l++){
                if(choose(l,2)<=j)dp[i][j]=(dp[i][j]+dp[i-1][j-choose(l,2)]*choose(it.second,l)%mod)%mod;
            }
        }
        i++;
    }
    printf("%lli\n",dp[i-1][k]);
    return 0;
}