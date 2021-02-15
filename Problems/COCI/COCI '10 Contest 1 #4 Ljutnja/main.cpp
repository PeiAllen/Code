#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll m,n;
    cin>>m>>n;
    map<ll,ll> stff;
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        stff[a]++;
    }
    for(auto it=stff.rbegin();next(it,1)!=stff.rend();it++){
        auto ne=next(it,1);
        ll diff=it->first-ne->first;
        if(diff*it->second<=m)ne->second+=it->second,m-=diff*it->second;
        else{
            ll am=m/it->second,expeeps=m%it->second;
            ll ans=0;
            ans+=expeeps*(it->first-am-1)*(it->first-am-1);
            ans+=(it->second-expeeps)*(it->first-am)*(it->first-am);
            for(it++;it!=stff.rend();it++)ans+=it->second*it->first*it->first;
            printf("%lli\n",ans);
            return 0;
        }
    }
    auto it=stff.begin();
    ll am=m/it->second,expeeps=m%it->second;
    ll ans=0;
    ans+=expeeps*max(ll(0),it->first-am-1)*max(ll(0),it->first-am-1);
    ans+=(it->second-expeeps)*max(ll(0),it->first-am)*max(ll(0),it->first-am);
    printf("%lli\n",ans);
    return 0;
}