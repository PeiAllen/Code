#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1001;
vector<pair<int,ll>> adj[MN];
ll dist[MN][MN];
int ind[MN];
void dijkstra(int st){
    dist[st][st]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    q.push({0,st});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        for(auto x:adj[cur.second]){
            if(dist[st][x.first]>cur.first+x.second){
                dist[st][x.first]=cur.first+x.second;
                q.push({dist[st][x.first],x.first});
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    ll c;
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dist[i][j]=LLONG_MAX;
    ll ans=0;
    set<pair<pii,ll>> dup;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        if(dup.insert({{min(a,b),max(a,b)},c}).second){
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        else{
            ans+=c;
        }
    }
    vector<pair<pii,ll>> needed;
    for(int i=1;i<=n;i++){
        dijkstra(i);
        for(int j=1;j<=n;j++)ind[j]=0;
        for(int j=1;j<=n;j++){
            if(dist[i][j]!=LLONG_MAX){
                for(auto x:adj[j]){
                    if(dist[i][x.first]==dist[i][j]+x.second){
                        ind[x.first]++;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(dist[i][j]!=LLONG_MAX){
                for(auto x:adj[j]){
                    if(dist[i][x.first]==dist[i][j]+x.second&&ind[x.first]==1){
                        if(dup.erase({{min(j,x.first),max(j,x.first)},x.second})){
                            needed.push_back({{j,x.first},x.second});
                        }
                    }
                }
            }
        }
    }
    for(auto x:dup)ans+=x.second;
    for(int i=1;i<=n;i++){
        adj[i]=vector<pair<int,ll>>();
        for(int j=1;j<=n;j++)dist[i][j]=LLONG_MAX;
    }
    for(auto x:needed){
        adj[x.first.first].push_back({x.first.second,x.second});
        adj[x.first.second].push_back({x.first.first,x.second});
    }
    for(int i=1;i<=n;i++){
        dijkstra(i);
        for(int j=1;j<=n;j++)printf("%lli%c",dist[i][j]," \n"[j==n]);
    }
    return 0;
}