#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=5;i<=n;i*=5){
        ans+=n/i;
    }
    printf("%lli\n",ans);
    return 0;
}