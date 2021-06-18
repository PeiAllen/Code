#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=998244353;
const ll MV=1e7+1;
bool nprime[MV];
vector<ll> primes;
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
    for(ll i=2;i<=MV;i++){
        if(!nprime[i]){
            primes.push_back(i);
            for(ll j=i*i;j<=MV;j+=i)nprime[j]=true;
        }
    }
    int t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        ll basissize=0;
        for(auto x:primes){
            if(r/x!=(l-1)/x)basissize++;
        }
        printf("%lli\n",fp(2,r-l+1-basissize));
    }
    return 0;
}