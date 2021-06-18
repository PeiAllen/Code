#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MM=5e4+1,MN=2e4+1;
pair<pii,ll> edges[MM];
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
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        cin>>edges[i].first.first>>edges[i].first.second>>edges[i].second;
    }
    int a;
    ll b;
    while(q--){
        cin>>a>>b;
        edges[a].second=b;
        vector<pair<ll,pii>> sorted;
        for(int i=1;i<=n;i++)dsu[i]={i,1};
        for(int i=1;i<=m;i++)sorted.push_back({edges[i].second,edges[i].first});
        sort(sorted.begin(),sorted.end());
        ll ans=0;
        for(auto x:sorted){
            if(uni(x.second.first,x.second.second))ans+=x.first;
        }
        printf("%lli\n",ans);
    }
    return 0;
}