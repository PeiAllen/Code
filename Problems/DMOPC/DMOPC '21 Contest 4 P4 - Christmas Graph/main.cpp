#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
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
    return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    fact[0]=inv[0]=1;
    for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod,inv[i]=fp(fact[i],mod-2);
    ll exp=0;
    for(int i=2;i<=n;i++){
        ll prob=fact[i-1]*fp(fp(n-1,i),mod-2)%mod;
        exp=(exp+prob*choose(n,i)%mod)%mod;
    }
    printf("%lli\n",exp);
    return 0;
}