#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
const ll mod = 998244353;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll arr[MN];
ll exam[MN];
ll cnt[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    ll expmut=(1-((sum-arr[n])*fp(sum,mod-2)%mod)%mod+mod)%mod;
    ll right=0;
    for(int i=1;i<n;i++){
        cin>>exam[i];
        right=(right+arr[i]*exam[i]%mod)%mod;
    }
    right=right*fp(sum,mod-2)%mod;
    ll exp=right*fp(expmut,mod-2)%mod;
    ll best=LLONG_MAX;
    for(int i=1;i<n;i++){
        cin>>cnt[i];
        if(cnt[i]>=1)best=min(best,exam[i]);
    }
    printf("%lli\n",exp+best);
    return 0;
}