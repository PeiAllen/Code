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
    int n;
    cin>>n;
    ll a;
    map<ll,ll> primes;
    map<ll,ll> ways,tot;
    for(int i=0;i<n;i++){
        cin>>a;
        ll te=a;
        for(ll j=2;j*j<=te;j++){
            if(te%j==0){
                ll prod=0;
                while(te%j==0)tot[j]++,prod++,te/=j;
                primes[j]=max(primes[j],prod);
            }
        }
        if(te>1)primes[te]=max(primes[te],ll(1)),tot[te]++;
    }
    for(auto x:primes)ways[x.first]+=x.second;
    ll val=1,val2=1;
    for(const auto &x:ways){
        if(tot.count(x.first))tot[x.first]-=x.second;
        else val=val*fp(x.first,x.second)%mod;
    }
    for(const auto &x:tot)val2=val2*fp(x.first,x.second)%mod;
    printf("%lli\n",(val+val2)%mod);
    return 0;
}