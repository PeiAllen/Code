#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
vector<pii> matrix[MAXN];
pii dsu[MAXN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return 0;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return 1;
}
vector<int> torem;
int dfs(int loc, int par){
    int sts=1;
    for(auto x:matrix[loc])if(x.first!=par){
        int te=dfs(x.first,loc);
        if(te%2==0)torem.push_back(x.second);
        sts+=te;
    }
    return sts;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)dsu[i]={i,1};
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        if(uni(a,b))matrix[a].push_back({b,i}),matrix[b].push_back({a,i});
        else torem.push_back(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)if(find(i)==i)ans+=dfs(i,0)>>1<<1;
    printf("%d\n%d\n",ans,sz(torem));
    for(auto x:torem)printf("%d ",x);
    return 0;
}