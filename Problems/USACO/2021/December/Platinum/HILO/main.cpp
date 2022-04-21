#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=5001;
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
ll choose(ll a, ll b){
    if(a<b||a<0||b<0)return 0;
    return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
ll permute(ll a, ll b){
    if(a<b||a<0||b<0)return 0;
    return fact[a]*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,x;
    cin>>n>>x;
    fact[0]=inv[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*ll(i)%mod;
        inv[i]=fp(fact[i],mod-2);
    }
    ll ways=0;
    for(int j=2;j<=n;j++) {
        ll te=choose(n-x,j-1)*fact[j-2]%mod;
        te=te*fact[n-j]%mod*ll(j-1)%mod*ll(x)%mod;
        ways=(ways+te)%mod;
    }
    for(int j=3;j<=n;j++){
        ll te=(choose(n,j)-choose(x,j)+mod-choose(n-x,j)+mod)%mod;
        te=te%mod*fact[j-3]%mod;
        ll terem=choose(n-x,j-1)*fact[j-3]%mod*x%mod;
        te=(te-terem%mod+mod)%mod;
        te=te%mod*fact[n - j] % mod;
        ways=(ways+te*(ll(j-2)*ll(j-1)/2%mod)%mod)%mod;
    }
    printf("%lli\n",ways);
    return 0;
}