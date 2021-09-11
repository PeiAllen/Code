#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=4001;
set<ll> bad;
ll dp[MN];
ll psa[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll k,a;
    int n;
    cin>>k>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        bad.insert(a);
    }
    dp[1]=0,dp[2]=0;
    psa[0]=0;
    psa[1]=(!bad.count(1));
    psa[2]=(!bad.count(1))+(!bad.count(2));
    for(int i=3;i<MN;i++){
        psa[i]=psa[i-1]+(!bad.count(i));
        for(int j=2;j<i;j++){
            if(i%j&&!bad.count(j)){
                dp[i]=max(dp[i],dp[i%j]+psa[j]-psa[i%j]);
            }
        }
    }
    ll best=0;
    for(ll i=k-1;i>=max(ll(2),k-3997);i--){
        if(k%i&&!bad.count(i)){
            ll am=i-k%i;
            for(auto x:bad){
                if(x>k%i&&x<=i)am--;
            }
            best=max(best,dp[k%i]+am);
        }
    }
    printf("%lli\n",best);
    return 0;
}