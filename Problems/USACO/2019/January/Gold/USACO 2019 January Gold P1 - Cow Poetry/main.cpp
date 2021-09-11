#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e3+1;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
int len[MN],rhyme[MN],am[MN];
ll dp[MN][MN];//number of ways with i syllables and ending with word j
ll ways[MN],dpsum[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>len[i]>>rhyme[i];
    dp[0][0]=1,dpsum[0]=1;
    for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)dp[i][j]=(i-len[j]>=0?dpsum[i-len[j]]:ll(0)),dpsum[i]=(dpsum[i]+dp[i][j])%mod;
    for(int i=1;i<=n;i++)ways[rhyme[i]]=(ways[rhyme[i]]+dp[k][i])%mod;
    char a;
    for(int i=0;i<m;i++)cin>>a,am[a-'A']++;
    ll ans=1;
    for(int i=0;i<26;i++)if(am[i]){
        ll sum=0;
        for(int j=1;j<=n;j++)sum=(sum+fp(ways[j],am[i]))%mod;
        ans=ans*sum%mod;
    }
    printf("%lli\n",ans);
    return 0;
}