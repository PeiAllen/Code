#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MV= 1e7 + 1;
const int MN=1e5+1;
pii best[MV];
pii dsu[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> vals(n);
    for(int i=0;i<n;i++){
        cin>>vals[i];
    }
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=1; i < MV; i++)best[i]={INT_MAX, INT_MAX};
    for(int i=0;i<sz(vals);i++){
        best[vals[i]]={vals[i],i};
        dsu[i]={i,1};
    }
    for(int i= MV - 2; i >= 1; i--)best[i]=min(best[i], best[i + 1]);
    vector<pair<int,pii>> death;
    for(int i=0;i<sz(vals);i++){
        int prev=INT_MAX;
        ll start=(MV-1)/vals[i]*vals[i];
        for(int j=start; j >=2*vals[i]; j-=vals[i]){
            if(best[j].first!=prev&&best[j].first!=INT_MAX){
                prev=best[j].first;
                death.push_back({best[j].first-j,{i,best[j].second}});
            }
        }
        if(vals[i]+1 < MV && best[vals[i] + 1].first != INT_MAX&&best[vals[i]+1].first!=prev){
            death.push_back({best[vals[i] + 1].first - vals[i], {i, best[vals[i] + 1].second}});
        }
    }
    sort(death.begin(),death.end());
    ll ans=0;
    for(auto x:death){
        if(uni(x.second.first,x.second.second))ans+=x.first;
    }
    printf("%lli\n",ans);
    return 0;
}