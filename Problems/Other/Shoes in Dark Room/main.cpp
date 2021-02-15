#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=21;
ll arr[2][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int d=0;d<2;d++)for(int i=0;i<n;i++){
            cin>>arr[d][i];
        }
    map<ll,ll> points;
    for(int i=0;i<(1<<n);i++){
        ll sum[2]={0,0};
        for(int j=0;j<n;j++)sum[!!(i&(1<<j))]+=arr[!!(i&(1<<j))][j];
        points[sum[0]]=max(points[sum[0]],sum[1]);
    }
    ll ma=-1;
    vector<ll> toerase;
    for(auto it=points.rbegin();it!=points.rend();it++){
        if(it->second<=ma)toerase.push_back(it->first);
        else ma=it->second;
    }
    for(auto x:toerase)points.erase(x);
    ll ans=LLONG_MAX;
    for(auto it=points.begin();next(it,1)!=points.end();it++){
        ans=min(ans,it->first+1+next(it,1)->second+1);
    }
    printf("%lli\n",ans);
    return 0;
}