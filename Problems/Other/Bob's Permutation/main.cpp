#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
vector<int> adj[MN];
int cnt=0;
void dfs(int loc){
    cnt++;
    for(auto x:adj[loc])dfs(x);
}
int parent[MN];
int rep[MN];
int root[MN];
int size[MN];
ll sum[MN];
ll val[MN];
int find(int a){
    if(rep[a]==a)return a;
    return rep[a]=find(rep[a]);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    ll offset=sum[bp]*size[ap];
    if(size[ap]<size[bp])root[bp]=root[ap],swap(ap,bp);
    size[ap]+=size[bp];
    rep[bp]=ap;
    sum[ap]+=sum[bp];
    val[ap]+=val[bp]+offset;
    return true;
}
class comp{
public:
    bool operator()(const pair<int,pll>& a, const pair<int,pll>& b){
        return __int128(b.second.first)*__int128(a.second.second)<__int128(a.second.first)*__int128(b.second.second);
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        adj[a].push_back(i);
        parent[i]=a;
    }
    parent[0]=-1;
    dfs(0);
    if(cnt!=n+1){
        printf("-1\n");
        return 0;
    }
    priority_queue<pair<int,pll>,vector<pair<int,pll>>,comp> q;
    for(int i=0;i<=n;i++){
        rep[i]=i,size[i]=1,val[i]=0,root[i]=i;
        if(i)cin>>sum[i];
        q.push({i,{sum[i],size[i]}});
    }
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        cur.first=find(cur.first);
        if(root[cur.first]==0||cur.second.first!=sum[cur.first])continue;
        uni(parent[root[cur.first]],cur.first);
        q.push({find(cur.first),{sum[find(cur.first)],size[find(cur.first)]}});
    }
    printf("%lli\n",val[find(0)]);
    return 0;
}