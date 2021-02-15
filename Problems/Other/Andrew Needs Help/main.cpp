#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,d;
    cin>>n>>d;
    ll ans=0;
    ll fact=1;
    for(ll i=1;i<=n-1;i++)fact=(fact*i)%mod;
    ll val=ll(2)*(n-d)*fact%mod;
    for(ll i=n-1;i>=d;i--){
        ans=(ans+val)%mod;
        val=val*(mod-1)%mod*ll(2)%mod*fp(i,mod-2)%mod*(n-d-(n-i))%mod*fp(n-i+1,mod-2)%mod;
    }
    printf("%lli\n",ans);
    return 0;
}