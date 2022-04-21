#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
int sz(const T &a){return int(a.size());}
const int MN=101;
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
int runmst(vector<pair<pii,int>> edges){
    for(int i=0;i<MN;i++)dsu[i]={i,1};
    sort(edges.begin(),edges.end(),[&](const pair<pii,int> &lhs, const pair<pii,int> &rhs){
        return lhs.second<rhs.second;
    });
    int ans=0;
    for(auto x:edges){
        if(uni(x.first.first,x.first.second))ans+=x.second;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,edgecnt,a;
    cin>>m;
    map<pii,pii> edges;
    vector<pair<pii,int>> gedges;
    for(int i=1;i<=m;i++){
        cin>>edgecnt;
        vector<int> nodes(edgecnt);
        for(int j=0;j<edgecnt;j++)cin>>nodes[j];
        for(int j=0;j<edgecnt;j++){
            cin>>a;
            if(edges.count({min(nodes[j],nodes[(j+1)%edgecnt]),max(nodes[j],nodes[(j+1)%edgecnt])})){
                gedges.push_back({{edges[{min(nodes[j],nodes[(j+1)%edgecnt]),max(nodes[j],nodes[(j+1)%edgecnt])}].first,i},a});
                edges.erase({min(nodes[j],nodes[(j+1)%edgecnt]),max(nodes[j],nodes[(j+1)%edgecnt])});
            }
            else edges[{min(nodes[j],nodes[(j+1)%edgecnt]),max(nodes[j],nodes[(j+1)%edgecnt])}]={i,a};
        }
    }
    int best=runmst(gedges);
    for(auto x:edges){
        gedges.push_back({{0,x.second.first},x.second.second});
    }
    best=min(best,runmst(gedges));
    printf("%d\n",best);
    return 0;
}