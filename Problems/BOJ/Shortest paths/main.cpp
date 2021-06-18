#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2001;
vector<pair<int,ll>> adj[MN];
vector<int> adj2[MN];
int parent[MN];
ll dist[2][MN];
bool out[MN];
vector<int> nodes;
void dfs(int loc, int nogo){
    nodes.push_back(loc);
    for(auto x:adj2[loc])if(x!=nogo)dfs(x,nogo);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b,u,v,k;
    cin>>n>>m>>u>>v;
    ll c;
    for(int i=1;i<=n;i++)dist[0][i]=dist[1][i]=LLONG_MAX;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin>>k;
    vector<int> path;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    for(int i=1;i<=k;i++){
        cin>>a;
        if(i==1)dist[0][a]=0;
        else{
            dist[0][a]=dist[0][path.back()];
            for(auto x:adj[path.back()])if(x.first==a)dist[0][a]+=x.second;
        }
        path.push_back(a);
        q.push({dist[0][a],a});
    }
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first>dist[0][cur.second])continue;
        for(auto x:adj[cur.second]){
            if(dist[0][x.first]>cur.first+x.second){
                parent[x.first]=cur.second;
                dist[0][x.first]=cur.first+x.second;
                q.push({dist[0][x.first],x.first});
            }
        }
    }
    dist[1][v]=0,q.push({0,v});
    for(int i=k-2;i>=0;i--){
        dist[1][path[i]]=dist[1][path[i+1]];
        for(auto x:adj[path[i+1]])if(x.first==path[i])dist[1][path[i]]+=x.second;
        q.push({dist[1][path[i]],path[i]});
    }
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first>dist[1][cur.second])continue;
        for(auto x:adj[cur.second]){
            if(dist[1][x.first]>cur.first+x.second){
                dist[1][x.first]=cur.first+x.second;
                q.push({dist[1][x.first],x.first});
            }
        }
    }
    for(int i=1;i<=n;i++)adj2[parent[i]].push_back(i);
    dfs(u,path[1]);
    multiset<ll> distances;
    for(auto x:nodes)out[x]=true;
    for(auto i:nodes)for(auto x:adj[i])if(!out[x.first]&&(i!=path[0]||x.first!=path[1]))distances.insert(dist[0][i]+x.second+dist[1][x.first]);
    printf("%lli\n",(sz(distances)?*distances.begin():ll(-1)));
    for(int i=1;i<sz(path)-1;i++){
        nodes=vector<int>();
        dfs(path[i],path[i+1]);
        for(auto j:nodes)for(auto x:adj[j]){
            if(out[x.first]&&(j!=path[i]||x.first!=path[i-1]))distances.erase(distances.find(dist[0][x.first]+x.second+dist[1][j]));
        }
        for(auto j:nodes)out[j]=true;
        for(auto j:nodes)for(auto x:adj[j]) {
            if (!out[x.first]&&(j!=path[i]||x.first!=path[i+1]))distances.insert(dist[0][j] + x.second + dist[1][x.first]);
        }
        printf("%lli\n",(sz(distances)?*distances.begin():ll(-1)));
    }
    return 0;
}