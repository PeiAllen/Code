#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
pii arr[MN];
ll ans[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,x,y,a,b;
    cin>>n>>q>>x>>y;
    map<pii,vector<int>> teams;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>ans[i];
        arr[i]={a,b};
        pii slope={b-y,a-x};
        int gc=__gcd(abs(slope.first),abs(slope.second));
        slope.first/=gc,slope.second/=gc;
        teams[slope].push_back(i);
    }
    for(auto cur:teams){
        sort(cur.second.begin(),cur.second.end(),[&](const auto &lhs, const auto &rhs){
            return abs(arr[lhs].first-x)+abs(arr[lhs].second-y)<abs(arr[rhs].first-x)+abs(arr[rhs].second-y);
        });
        for(int i=1;i<sz(cur.second);i++)ans[cur.second[i]]+=ans[cur.second[i-1]];
    }
    while(q--){
        cin>>a;
        printf("%lli\n",ans[a]);
    }
    return 0;
}