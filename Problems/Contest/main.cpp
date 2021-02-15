#include "bits/stdc++.h"
using namespace std;
using ll=long long;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=998244353;
const int MN=21;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll lcm(ll a,ll b){
    return a*b/__gcd(a,b);
}
ll arr[MN];
ll val[(1<<MN)];
ll dp[(1<<MN)];
ll actval[(1<<MN)];
int n;
ll m;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>m>>n;
    ll ans=0;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<(1<<n);i++){
        val[i]=1;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                val[i]=lcm(val[i],arr[j]);
                if(val[i]>m)break;
            }
        }
    }
    for(int i=0;i<(1<<n);i++){
        dp[(1<<n)-1-i]=actval[i]=((__builtin_popcount(i) % 2 == 1 ? 1 : -1)*((m/val[i])*(1<<(n-__builtin_popcount(i)))%mod)+mod)%mod;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            if(j&(1<<i))dp[j]=(dp[j]+dp[j^(1<<i)])%mod;
        }
    }
    for(int i=0;i<(1<<n);i++){
        if(__builtin_popcount(i)%4==0){
            ll cnt=m/val[i];
            int op = (1 << n) - 1 - i;
            ans = (ans + cnt*(1<<__builtin_popcount(op))%mod) % mod;
            ans=(ans-dp[(1<<n)-1-i]+mod)%mod;
            ans=(ans+actval[i])%mod;
        }
    }
    printf("%lli\n",ans*fp((1<<n),mod-2)%mod);
    return 0;
}