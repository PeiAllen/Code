#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int bit[MN];
int my;
void update(int loc, int val){
    for(;loc<=my;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=bit[loc];
    return ans;
}
map<int,pair<vector<pii>,vector<int>>> ups;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    ll ans=0;
    vector<int> ys;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        ys.push_back(b);
        ups[0].first.push_back({b,1});
        ups[a+1].first.push_back({b,-1});
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        ups[a].second.push_back(b);
    }
    sort(ys.begin(),ys.end()),ys.erase(unique(ys.begin(),ys.end()),ys.end());
    my=sz(ys);
    for(auto x:ups){
        for(auto y:x.second.first)update(lower_bound(ys.begin(),ys.end(),y.first)-ys.begin()+1,y.second);
        for(auto y:x.second.second)ans+=query(upper_bound(ys.begin(),ys.end(),y)-ys.begin());
    }
    printf("%lli\n",ans);
    return 0;
}