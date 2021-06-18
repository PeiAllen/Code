#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<int> adj[MN];
pii edge[MN];
int dist[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>edge[i].first>>edge[i].second,adj[edge[i].first].push_back(edge[i].second),adj[edge[i].second].push_back(edge[i].first);
    for(int i=2;i<=n;i++)dist[i]=INT_MAX;
    dist[1]=0;
    queue<int> q;
    q.push(1);
    while(sz(q)){
        auto cur=q.front();
        q.pop();
        for(auto x:adj[cur]){
            if(dist[x]>dist[cur]+1){
                dist[x]=dist[cur]+1;
                q.push(x);
            }
        }
    }
    for(int i=0;i<m;i++){
        if(pii{dist[edge[i].first],edge[i].first}>pii{dist[edge[i].second],edge[i].second})swap(edge[i].first,edge[i].second);
        printf("%d %d\n",edge[i].first,edge[i].second);
    }
    return 0;
}