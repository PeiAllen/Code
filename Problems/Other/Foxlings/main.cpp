#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
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
    int n,m,a,b;
    cin>>n>>m;
    vector<pii> edges;
    vector<int> nodes;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        edges.push_back({a,b});
        nodes.push_back(a);
        nodes.push_back(b);
    }
    sort(nodes.begin(),nodes.end()),nodes.erase(unique(nodes.begin(),nodes.end()),nodes.end());
    int ans=n;
    for(int i=0;i<sz(nodes);i++)dsu[i]={i,1};
    for(auto x:edges){
        ans-=uni(lower_bound(nodes.begin(),nodes.end(),x.first)-nodes.begin(),lower_bound(nodes.begin(),nodes.end(),x.second)-nodes.begin());
    }
    printf("%d\n",ans);
    return 0;
}