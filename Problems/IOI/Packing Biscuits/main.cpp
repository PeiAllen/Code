#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=62;
map<ll,ll> dp;//num of nums that are <= i that can be made.
ll psa[MAXN];
ll x;
ll solve(ll a){//greedy always wanna take from closest bit which is smaller, as such nothing will ever be wasted.
    if(a<0)return 0;
    if(a==0)return 1;
    if(dp.count(a))return dp[a];
    ll msb=__lg(a);
    return dp[a]=solve((ll(1)<<msb)-1)+solve(min(a,psa[msb]/x)-(ll(1)<<msb));//psa[msb]/x is largest integer s.t. x*y<=psa[i] and we use the dp to check y-2^i is good.
}
ll count_tastiness(ll X, vector<ll> a){//maytlenotsure
    x=X;
    int n=sz(a);
    dp=map<ll,ll>();
    psa[0]=a[0];
    for(int i=1;i<=60;i++){
        if(i<n)psa[i]=psa[i-1]+(ll(1)<<i)*a[i];
        else psa[i]=psa[i-1];
    }
    return solve((ll(1)<<60)-1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    printf("%lli\n",count_tastiness(2, {2,1,2}));
    return 0;
}