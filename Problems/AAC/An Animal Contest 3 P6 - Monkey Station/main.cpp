#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
ll rows[MN],cols[MN];
ll r,c;
int n,m;
vector<int> ind[2];
ll ans[2*MN];
ll offset[2]={LLONG_MIN,LLONG_MIN};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>r>>c>>n>>m;
    for(int i=0;i<n;i++)cin>>rows[i];
    for(int i=0;i<m;i++)cin>>cols[i];
    vector<pair<ll,pair<ll,int>>> ordrows,ordcols,ord;
    for(int i=n-1;i>=0;i--){
        ll earliest=-rows[i];
        ll off=(c+1)+rows[i];
        ordrows.push_back({earliest,{off,i}});
    }
    for(int i=m-1;i>=0;i--){
        ll earliest=-cols[i];
        ll off=(r+1)+cols[i];
        ordcols.push_back({earliest,{off,i+n}});
    }
    ord.resize(n+m);
    merge(ordrows.begin(),ordrows.end(),ordcols.begin(),ordcols.end(),ord.begin());
    ll worst=LLONG_MIN;
    for(int i=0;i<sz(ord);i++){
        int type=ord[i].second.second>=n;
        offset[type]=max(offset[type],ord[i].second.first);
        ind[type].push_back(ord[i].second.second);
        while(i+1<sz(ord)&&ord[i+1].first==ord[i].first){
            i++;
            type=ord[i].second.second>=n;
            offset[type]=max(offset[type],ord[i].second.first);
            ind[type].push_back(ord[i].second.second);
        }
        int use=offset[1]>offset[0];
        if(sz(ind[use])) {
            worst = max(worst, offset[use] + ord[i].first);
            for (auto x:ind[use])ans[x] = ord[i].first + (use ? cols[x - n] : rows[x]);
            ind[use] = vector<int>(), offset[use] = LLONG_MIN;
        }
        if(i+1==sz(ord)||ord[i+1].first>ord[i].first+1){
            use=!use;
            if(sz(ind[use])) {
                worst = max(worst, offset[use] + ord[i].first + 1);
                for (auto x:ind[use])ans[x] = ord[i].first + 1 + (use ? cols[x - n] : rows[x]);
                ind[use] = vector<int>(), offset[use] = LLONG_MIN;
            }
        }
    }
    printf("%lli\n",worst);
    for(int i=0;i<n+m;i++)printf("%lli%c",ans[i]," \n"[i==n+m-1||i==n-1]);
    return 0;
}