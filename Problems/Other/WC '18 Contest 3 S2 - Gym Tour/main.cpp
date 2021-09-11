#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
bool vis[MAXN],spec[MAXN];
int depth[MAXN];
vector<int> matrix[MAXN];
bool dfs(int loc, int par, int dep){
    depth[loc]=dep;
    for(auto x:matrix[loc])if(x!=par)vis[loc]|=dfs(x,loc,dep+1);
    return vis[loc];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,f;
    cin>>n>>k>>f;
    int a,b;
    vis[1]=true;
    spec[1]=true;
    for(int i=0;i<k;i++){
        cin>>a;
        vis[a]=true;
        spec[a]=true;
    }
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0,0);
    int cnt=0;
    int longest=0;
    for(int i=1;i<=n;i++){
        if(vis[i])cnt++,longest=max(longest,depth[i]);
        vis[i]=spec[i];
    }
    vis[f]=true;
    dfs(1,0,0);
    int cnt2=0;
    for(int i=1;i<=n;i++){
        if(vis[i])cnt2++;
    }
    printf("%d\n",min(cnt2-1,(cnt-1)*2-longest));
    return 0;
}