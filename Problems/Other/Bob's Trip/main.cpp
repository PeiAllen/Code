#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
vector<pair<int,ll>> adj[MN];
vector<pair<int,ll>> rails[MN];
vector<vector<pair<int,ll>>> rail;
vector<pii> from[MN];
vector<pll> st[MN*2];
ll dist[MN];
ll inter(pll a, pll b){//when does a beat b
    return (b.second-a.second+a.first-b.first-1)/(a.first-b.first);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,si;
    cin>>n>>m;
    ll b;
    for(int i=0;i<m;i++){
        cin>>si;
        cin>>a;
        rails[i].push_back({a,0});
        for(int j=1;j<=si;j++){
            cin>>b>>a;
            adj[rails[i].back().first].push_back({a,b});
            rails[i].push_back({a,b+rails[i].back().second});
        }
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    q.push({0,1});
    for(int i=2;i<=n;i++)dist[i]=LLONG_MAX;
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first>dist[cur.second])continue;
        for(auto x:adj[cur.second]){
            if(dist[x.first]>x.second+cur.first){
                dist[x.first]=x.second+cur.first;
                q.push({dist[x.first],x.first});
            }
        }
    }
    for(int i=0;i<m;i++){
        int last=0;
        for(int j=0;j<sz(rails[i]);j++){
            if(j+1==sz(rails[i])||dist[rails[i][j].first]==LLONG_MAX||dist[rails[i][j].first]+rails[i][j+1].second-rails[i][j].second>dist[rails[i][j+1].first]){
                if(last!=j){
                    rail.push_back({});
                    ll dis=rails[i][last].second;
                    for(;last<=j;last++){
                        from[rails[i][last].first].push_back({sz(rail)-1,sz(rail.back())});
                        rail.back().push_back({rails[i][last].first,rails[i][last].second-dis});
                    }
                }
                last=j+1;
            }
        }
    }
    vector<int> nodes;
    for(int i=1;i<=n;i++)nodes.push_back(i);
    sort(nodes.begin(),nodes.end(),[&](const auto &lhs, const auto &rhs){
       return dist[lhs]<dist[rhs];
    });
    for(auto x:nodes){
        ll best=0;
        for(auto r:from[x]){
            if(r.second){
                while(sz(st[r.first])>=2&&inter(st[r.first][sz(st[r.first])-2],st[r.first].back())<=rail[r.first][r.second].second)st[r.first].pop_back();
                best=max(best,st[r.first].back().first*rail[r.first][r.second].second+st[r.first].back().second+rail[r.first][r.second].second*rail[r.first][r.second].second);
            }
        }
        if(x==n){
            printf("%lli %lli\n",dist[x],best);
            return 0;
        }
        for(auto r:from[x]){
            pll cur={-2*rail[r.first][r.second].second,best+rail[r.first][r.second].second*rail[r.first][r.second].second};
            while(sz(st[r.first])>=2&&inter(st[r.first][sz(st[r.first])-2],st[r.first].back())<=inter(st[r.first].back(),cur))st[r.first].pop_back();
            st[r.first].push_back(cur);
        }
    }
    return 0;
}