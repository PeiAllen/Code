#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const ll mod=1e9+7;
map<string,ll> dp;
ll fix(ll a){
    if(a>=mod)a-=mod;
    return a;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    string a;
    for(int i=0;i<k;i++){
        cin>>a;
        dp[a]+=1;
    }
    ll ans=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<k;j++){
            cin>>a;
            ll te=dp[a.substr(0,i-1)];
            if(a.substr(0,i-1)!=a.substr(1,i-1))te=fix(te+dp[a.substr(1,i-1)]);
            if(i==n)ans=fix(ans+te);
            else dp[a]=fix(dp[a]+te);
        }
    }
    if(n==1)ans=k;
    printf("%lli\n",ans);
    return 0;
}