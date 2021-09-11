#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<pii> matrix[MN];
int dist[MN];
int ans[MN];
void dfs(int loc, int parent){for(auto x:matrix[loc])if(x.first!=parent)dist[x.first]=dist[loc]+x.second,dfs(x.first,loc);}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int a,b,c;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        matrix[a].push_back({b,c});
        matrix[b].push_back({a,c});
    }
    dfs(1,0);
    int dial=max_element(dist+1,dist+1+n)-dist;
    dist[dial]=0,dfs(dial,0);
    int diar=max_element(dist+1,dist+1+n)-dist;
    copy(dist+1,dist+1+n,ans+1);
    dist[diar]=0,dfs(diar,0);
    while(q--){
        cin>>a;
        printf("%d\n",max(ans[a],dist[a]));
    }
    return 0;
}