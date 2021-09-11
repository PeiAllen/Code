#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int sts[MN];
vector<int> matrix[MN];
set<int> vals[MN];
set<int> othvals;
int ans=INT_MAX;
int n;
int getsz(int loc, int parent){
    sts[loc]=1;
    for(auto x:matrix[loc])if(x!=parent)sts[loc]+=getsz(x,loc);
    return sts[loc];
}
void dfs(int loc, int parent){
    int a=n-sts[loc];
    auto it=othvals.lower_bound(a/2);
    if(it!=othvals.end())ans=min(ans,max({a-*it,*it,sts[loc]})-min({a-*it,*it,sts[loc]}));
    if(it!=othvals.begin()){
        it--;
        ans=min(ans,max({a-*it,*it,sts[loc]})-min({a-*it,*it,sts[loc]}));
    }
    for(auto x:matrix[loc])if(x!=parent){
        dfs(x,loc);
        if(sz(vals[x])>sz(vals[loc]))vals[x].swap(vals[loc]);
        vals[loc].insert(vals[x].begin(),vals[x].end());
    }
    it=vals[loc].lower_bound(sts[loc]/2);
    if(it!=vals[loc].end())ans=min(ans,max({a,*it,sts[loc]-*it})-min({a,*it,sts[loc]-*it}));
    if(it!=vals[loc].begin()){
        it--;
        ans=min(ans,max({a,*it,sts[loc]-*it})-min({a,*it,sts[loc]-*it}));
    }
    vals[loc].insert(sts[loc]);
    othvals.insert(sts[loc]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    getsz(1,0);
    dfs(1,0);
    othvals=set<int>();
    for(int i=1;i<=n;i++)reverse(matrix[i].begin(),matrix[i].end()),vals[i]=set<int>();
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}