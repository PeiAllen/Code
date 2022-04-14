#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
const int MN=1e6+1;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll dp[MN];//number of ways using i subsets (ordered);
ll permuteval=1;
ll permute(ll a, ll b){
    return permuteval;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    ll numofsets=(fp(2,n)-1+mod)%mod;
    ll fact=1;
    dp[0]=1;
    for(int i=1;i<=m;i++){
        dp[i]=permute(numofsets,i-1);//last element is determined as the xorsum
        dp[i]=(dp[i]-dp[i-1]+mod)%mod;//overcount if last element is empty set
        if(i-2>=0)dp[i]=(dp[i]-dp[i-2]*(i-1)%mod*(numofsets-(i-2))%mod+mod)%mod;//overcount if last element already in previous i-1 elements
        permuteval=permuteval*(numofsets-(i-1)+mod)%mod;
        fact=fact*i%mod;
    }
    printf("%lli\n",dp[m]*fp(fact,mod-2)%mod);
    return 0;
}