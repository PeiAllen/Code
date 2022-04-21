#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=90001,MM=130001;
pii par[MN];
int dist[MN];
bool used[MM];
vector<pii> adj[MN];
vector<int> nodes;
void dfs(int loc, int parent){
    nodes.push_back(loc);
    for(auto x:adj[loc]){
        if(x.first!=parent&&used[x.second]){
            par[x.first]={loc,x.second};
            dfs(x.first,loc);
        }
    }
}
void find_pair(int n, vector<int> u, vector<int> v, int a, int b){
    int m=sz(u);
    fill(dist,dist+n,INT_MAX);
    for(int i=0;i<n;i++)par[i]={-1,-1};
    for(int i=0;i<m;i++)adj[u[i]].push_back({v[i],i}),adj[v[i]].push_back({u[i],i});
    ll pathcnt=ask(vector<int>(m,0))/a;
    int lo=0,hi=m-1;
    vector<int> edges(m,0);
    while(lo!=hi){
        int mid=(lo+hi)/2;
        fill(edges.begin(),edges.end(),0);
        for(int i=0;i<=mid;i++)edges[i]=1;
        if(ask(edges)==pathcnt*a)lo=mid+1;
        else hi=mid;
    }
    int root1=u[lo],root2=v[lo];
    int middleedge=lo;
    queue<int> q;
    used[lo]=true;
    dist[root1]=dist[root2]=0;
    q.push(root1),q.push(root2);
    while(sz(q)){
        auto cur=q.front();
        q.pop();
        for(auto x:adj[cur]){
            if(x.second>=middleedge&&dist[x.first]>dist[cur]+1){
                dist[x.first]=dist[cur]+1;
                q.push(x.first);
                used[x.second]=true;
            }
        }
    }
    par[root1]={root2,middleedge};
    dfs(root1,root2);
    sort(nodes.begin(),nodes.end(),[&](const auto &lhs, const auto &rhs){
        return dist[lhs]>dist[rhs];
    });
    lo=0,hi=sz(nodes)-1;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        fill(edges.begin(),edges.end(),0);
        for(int i=0;i<m;i++)if(!used[i])edges[i]=1;
        for(int i=0;i<=mid;i++)edges[par[nodes[i]].second]=1;
        if(ask(edges)==pathcnt*a)lo=mid+1;
        else hi=mid;
    }
    int oneend=nodes[lo];
    nodes=vector<int>();
    par[root2]={root1,middleedge};
    dfs(root2,root1);
    sort(nodes.begin(),nodes.end(),[&](const auto &lhs, const auto &rhs){
        return dist[lhs]>dist[rhs];
    });
    lo=0,hi=sz(nodes)-1;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        fill(edges.begin(),edges.end(),0);
        for(int i=0;i<m;i++)if(!used[i])edges[i]=1;
        for(int i=0;i<=mid;i++)edges[par[nodes[i]].second]=1;
        if(ask(edges)==pathcnt*a)lo=mid+1;
        else hi=mid;
    }
    int othend=nodes[lo];
    answer(oneend,othend);
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}