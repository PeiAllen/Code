#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e7+1;
const ll mod=1e9+7;
ll inc[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,p,q,a,sum=0,tot=0;
    cin>>n>>p>>q;
    for(int i=0;i<n;i++){
        sum=(sum+inc[i])%mod;
        cin>>a;
        a=(a+sum)%mod;
        tot=(tot+a)%mod;
        printf("%lli%c",tot," \n"[i==n-1]);
        ll num=(n-i)*p/q;
        sum=(sum-a+mod)%mod;
        inc[n-num]=(inc[n-num]+ll(2)*a)%mod;
    }
    return 0;
}