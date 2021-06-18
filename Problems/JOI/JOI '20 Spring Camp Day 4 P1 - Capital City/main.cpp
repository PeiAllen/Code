#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int sts[MN],city[MN],ans=INT_MAX;
bool cent[MN];
vector<int> adj[MN];
int cnt[MN],par[MN];
bool gone[MN];
vector<int> needed[MN];
int dfssize(int loc, int parent){
    sts[loc]=1;
    for(auto x:adj[loc])if(x!=parent&&!cent[x])sts[loc]+=dfssize(x,loc);
    return sts[loc];
}
int getcent(int loc, int parent, int size){
    for(auto x:adj[loc])if(x!=parent&&!cent[x]&&sts[x]>size)return getcent(x,loc,size);
    return loc;
}
vector<int> cities;
void dfs(int loc, int parent){
    par[loc]=parent;
    cities.push_back(city[loc]);
    needed[city[loc]].push_back(loc);
    for(auto x:adj[loc])if(x!=parent&&!cent[x])dfs(x,loc);
}
void decomp(int loc){
    loc=getcent(loc,0,dfssize(loc,0)/2);
    cent[loc]=true;
    dfs(loc,0);
    bool good=cnt[city[loc]]==sz(needed[city[loc]]);
    gone[city[loc]]=true;
    queue<int> q;
    int citycnt=1;
    for(auto x:needed[city[loc]])q.push(x);
    while(sz(q)&&good){
        int cur=q.front();
        q.pop();
        if(cur==loc)continue;
        int ne=city[par[cur]];
        if(!gone[ne]){
            gone[ne]=true;
            good&=cnt[ne]==sz(needed[ne]);
            citycnt++;
            for(auto x:needed[ne])q.push(x);
        }
    }
    for(auto x:cities)gone[x]=false,needed[x]=vector<int>();
    cities=vector<int>();
    if(good)ans=min(ans,citycnt-1);
    for(auto x:adj[loc])if(!cent[x])decomp(x);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,a,b;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)cin>>city[i],cnt[city[i]]++;
    decomp(1);
    printf("%d\n",ans);
    return 0;
}