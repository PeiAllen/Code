#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const ll mod=10000;
const int MN=1001;
ll dp[MN][2];
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
    ll tot=1;
    ll p,a;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        cin>>p>>a;
        if(p!=2){
            dp[i][0]=(dp[i-1][0]+dp[i-1][1]*(p-1)%mod)%mod;
            dp[i][1]=(dp[i-1][1]+dp[i-1][0]*(p-1)%mod)%mod;
        }
        else dp[i][0]=dp[i-1][0],dp[i][1]=dp[i-1][1];
        tot=tot*fp(p,a)%mod;
    }
    printf("%lli\n%lli\n%lli\n",(dp[n][0]-1+mod)%mod,dp[n][1],(tot-dp[n][1]-dp[n][0]+mod+mod)%mod);
    return 0;
}

/*
 *  1
 *  p-1
 *  p-1*p
 *  p-1*p^2
 *  ....
 *  sum of that
 *
 * also apprently this means that For m, all d | m  sum(phi(d))  = m
 */