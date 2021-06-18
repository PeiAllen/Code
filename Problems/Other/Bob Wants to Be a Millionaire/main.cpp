#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1001;
int n,m;
struct ford{
    vector<pair<pii,int>> adj[MN*3];
    ford(){}
    void clear(){
        for(int i=0;i<=n+m+1;i++)adj[i]=vector<pair<pii,int>>();
    }
    void addedge(int a, int b, ll f){
        if(a==b||!f)return;
        adj[a].push_back({{b,f},sz(adj[b])});
        adj[b].push_back({{a,0},sz(adj[a])-1});
    }
    pii from[MN*3];
    int bfs(int st, int en){
        queue<pii> q;
        for(int i=0;i<=n+m+1;i++)from[i]={-1,-1};
        from[st].second=0;
        q.push({st,INT_MAX});
        while(sz(q)){
            pii cur=q.front();
            q.pop();
            if(cur.first==en)return cur.second;
            for(int i=0;i<sz(adj[cur.first]);i++){
                if(adj[cur.first][i].first.second&&from[adj[cur.first][i].first.first].second==-1){
                    from[adj[cur.first][i].first.first]={cur.first,i};
                    q.push({adj[cur.first][i].first.first,min(cur.second,adj[cur.first][i].first.second)});
                }
            }
        }
        return 0;
    }
    int maxFlow(int st, int en){
        int am=bfs(st,en),flow=0;
        while(am){
            int cur=en;
            while(cur!=st){
                adj[from[cur].first][from[cur].second].first.second-=am;
                adj[cur][adj[from[cur].first][from[cur].second].second].first.second+=am;
                cur=from[cur].first;
            }
            flow+=am;
            am=bfs(st,en);
        }
        return flow;
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a,b;
    cin>>n>>m;
    vector<pii> pain;
    ford flow;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        pain.push_back({a+1,b+1});
    }
    int lo=0,hi=m;
    auto work=[&](int am){
        flow.clear();
        for(int i=1;i<=n;i++)flow.addedge(0,i,1);
        for(int i=1;i<=am;i++) {
            a=pain[i-1].first,b=pain[i-1].second;
            flow.addedge(i + n, n + m + 1, 1);
            flow.addedge(a, i + n, 1), flow.addedge(b, i + n, 1);
        }
        return flow.maxFlow(0,n+m+1)==am;
    };
    while(lo!=hi){
        int mid=(lo+hi+1)/2;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    printf("%lli\n",lo);
    return 0;
}