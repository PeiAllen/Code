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
    int n;
    cin>>n;
    set<ll> vals;
    vector<pll> splits;
    ll psa=0;
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        psa+=a;
        if(sz(vals)&&i!=n-1){
            ll want=psa/2;
            auto it=vals.lower_bound(want);
            if(it!=vals.end())splits.push_back({*it,psa-*it});
            if(it!=vals.begin())it--,splits.push_back({*it,psa-*it});
        }
        vals.insert(psa);
    }
    ll ans=LLONG_MAX;
    for(auto x:splits)ans=min(ans,max({x.first,x.second,psa-x.first-x.second})-min({x.first,x.second,psa-x.first-x.second}));
    printf("%lli\n",ans);
    return 0;
}