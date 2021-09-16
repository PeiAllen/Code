#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1002;
struct flow{
    vector<pair<int,ll>> edges;
    vector<int> adj[MN];
    pii from[MN];
    int N;
    void setN(int n){
        N=n;
    }
    void addedge(int a, int b, ll c){
        adj[a].push_back(sz(edges));
        adj[b].push_back(sz(edges)+1);
        edges.push_back({b,c});
        edges.push_back({a,0});
    }
    ll bfs(ll s, ll t){
        for(int i=0;i<=N;i++)from[i]={-1,-1};
        queue<pair<int,ll>> q;
        from[s]={s,-1};
        q.push({s,LLONG_MAX});
        while(sz(q)){
            auto cur=q.front();
            q.pop();
            if(cur.first==t)return cur.second;
            for(auto ind:adj[cur.first]){
                auto x=edges[ind];
                if(x.second&&from[x.first].first==-1){
                    from[x.first]={cur.first,ind};
                    q.push({x.first,min(cur.second,x.second)});
                }
            }
        }
        return 0;
    }
    ll maxflow(ll s, ll t){
        ll flow=0;
        while(1){
            ll f=bfs(s,t);
            if(!f)break;
            flow+=f;
            int cur=t;
            while(cur!=s){
                edges[from[cur].second].second-=f;
                edges[from[cur].second^1].second+=f;
                cur=from[cur].first;
            }
        }
        return flow;
    }
}solver;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    solver.setN(n+m+1);
    ll sum=0,cost=0;
    ll c;
    for(int i=1;i<=n;i++){
        cin>>c;
        sum+=c,cost+=c;
        solver.addedge(0,i,c);
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        sum+=c;
        solver.addedge(a,i+n,LLONG_MAX);
        solver.addedge(b,i+n,LLONG_MAX);
        solver.addedge(i+n,n+m+1,c);
    }
    printf("%lli\n",sum-solver.maxflow(0,n+m+1)-cost);
    return 0;
}