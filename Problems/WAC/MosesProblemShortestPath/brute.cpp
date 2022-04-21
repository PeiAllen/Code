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
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++){
        dijkstra(i);
        for(int j=1;j<=n;j++)printf("%lli%c",dist[i][j]," \n"[j==n]);
    }
    return 0;
}