#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
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
    int n,k,l,r;
    cin>>n>>k>>l>>r;
    vector<pair<int,pii>> tocheck;
    for(int i=l;i<=r;i++){
        if(i%k==0){
            int cur=i/k;
            vector<int> factors;
            for(int j=2;j*j<=cur;j++){
                if(cur%j==0){
                    factors.push_back(j);
                    while(cur%j==0)cur/=j;
                }
            }
            if(cur!=1)factors.push_back(cur);
            for(int j=0;j<(1<<sz(factors));j++){
                int prod=1,cnt=0;
                for(int f=0;f<sz(factors);f++){
                    if(j&(1<<f))prod*=factors[f],cnt++;
                }
                tocheck.push_back({prod,{(cnt%2?-1:1),i/k}});
            }
        }
    }
    l=(l+k-1)/k,r=r/k;
    ll ans=0;
    for(auto x:tocheck){
        if(x.second.second/x.first==(l+x.first-1)/x.first){
            ans=(ans+ll(x.second.first)*fp(r/x.first-(l-1)/x.first,n)+mod)%mod;
        }
    }
    printf("%lli\n",ans);
    return 0;
}