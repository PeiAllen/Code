#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
vector<pii> matrix[MAXN];
vector<pii> times[MAXN];
int ans[MAXN];
void dfs(int loc, int time, int parent){
    ans[loc]++;
    for(auto x:matrix[loc]){
        if(x.first!=parent){
            int ind=lower_bound(times[x.second].begin(),times[x.second].end(),pii{time,0})-times[x.second].begin();
            if(ind<sz(times[x.second]))dfs(x.first,max(time,times[x.second][ind].second),loc);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,q;
    cin>>n>>m>>q;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back({b,i}),matrix[b].push_back({a,i});
    }
    for(int i=1;i<=m;i++){
        cin>>a;
        if(sz(times[a])==0||times[a].back().second!=-1)times[a].push_back({i,-1});
        else times[a].back().second=i-1;
    }
    for(int i=1;i<n;i++){
        if(sz(times[i])&&times[i].back().second==-1)times[i].back().second=m;
        for(auto &&x:times[i])swap(x.first,x.second);
    }
    for(int i=1;i<=n;i++)dfs(i,1,0);
    while(q--){
        cin>>a;
        printf("%d\n",ans[a]);
    }
    return 0;
}