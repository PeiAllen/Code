#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1008;
vector<pii> matrix[MAXN];
vector<vector<pair<int,lli>>> edges;
vector<pair<pii,pll>> oldedges;
lli srcam[MAXN],siam[MAXN];
int dist[MAXN];
int ind[MAXN];
int sink;
bool bfs(int source){
    fill(dist,dist+sink+1,-1);
    dist[source]=0;
    queue<int> q;
    q.push(source);
    while(sz(q)){
        int cur=q.front();
        q.pop();
        if(cur==sink)return dist[sink];
        for(pii x:matrix[cur]){
            if(dist[edges[x.first][x.second].first]==-1&&edges[x.first][x.second].second>0){
                dist[edges[x.first][x.second].first]=dist[cur]+1;
                q.push(edges[x.first][x.second].first);
            }
        }
    }
    return 0;
}
lli dfs(int loc, lli flow){
    if(loc==sink)return flow;
    for(int &cid=ind[loc];cid<sz(matrix[loc]);cid++){
        auto cur=matrix[loc][cid];
        if(edges[cur.first][cur.second].second<=0||dist[edges[cur.first][cur.second].first]!=dist[loc]+1)continue;
        lli push=dfs(edges[cur.first][cur.second].first,min(flow,edges[cur.first][cur.second].second));
        if(!push)continue;
        edges[cur.first][cur.second].second-=push;
        edges[cur.first][!cur.second].second+=push;
        return push;
    }
    return 0;
}
lli maxflow(int a, int b){
    sink=b;
    lli flow=0;
    while(bfs(a)){
        fill(ind,ind+sink+1,0);
        while(lli push=dfs(a,LLONG_MAX))flow+=push;
    }
    return flow;
}
bool check(int a, int b){
    for(auto x:matrix[a])if(edges[x.first][0].second)return 0;
    for(auto x:matrix[b])if(edges[x.first][0].second)return 0;
    return 1;
}
lli testore[501][501];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    lli a,b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        oldedges.push_back({{0,i},{a,b}});
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            cin >> testore[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            cin>>b;
            oldedges.push_back({{i,j+n},{testore[i][j],b}});
        }
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        oldedges.push_back({{i+n,n+m+1},{a,b}});
    }
    for(auto x:oldedges){
        srcam[x.first.second]+=x.second.first;
        siam[x.first.first]+=x.second.first;
        if(x.second.second-x.second.first){
            matrix[x.first.first].push_back({sz(edges),0});
            matrix[x.first.second].push_back({sz(edges),1});
            edges.push_back(vector<pair<int,lli>>(2));
            edges.back()[0]={x.first.second,x.second.second-x.second.first};
            edges.back()[1]={x.first.first,0};
        }
    }
    for(int i=0;i<=n+m+1;i++){
        if(srcam[i]) {
            matrix[n + m + 2].push_back({sz(edges), 0});
            matrix[i].push_back({sz(edges), 1});
            edges.push_back(vector<pair<int, lli>>(2));
            edges.back()[0] = {i, srcam[i]};
            edges.back()[1] = {n + m + 2, 0};
        }
        if(siam[i]) {
            matrix[i].push_back({sz(edges), 0});
            matrix[n + m + 3].push_back({sz(edges), 1});
            edges.push_back(vector<pair<int, lli>>(2));
            edges.back()[0] = {n + m + 3, siam[i]};
            edges.back()[1] = {i, 0};
        }
    }
    matrix[n+m+1].push_back({sz(edges),0});
    matrix[0].push_back({sz(edges),1});
    edges.push_back(vector<pair<int,lli>>(2));
    edges.back()[0]={0,-1};
    edges.back()[1]={n+m+1,0};
    bool work=false;
    lli lo=0,hi=5e16;
    while(lo!=hi){
        for(auto &x:edges)x[0].second+=x[1].second,x[1].second=0;
        lli mid=(lo+hi)/2;
        edges.back()[0].second=mid;
        maxflow(n+m+2,n+m+3);
        if(check(n+m+2,n+m+3))hi=mid;
        else lo=mid+1;
    }
    for(auto &x:edges)x[0].second+=x[1].second,x[1].second=0;
    edges.back()[0].second=lo;
    maxflow(n+m+2,n+m+3);
    if(check(n+m+2,n+m+3))work=true;
    edges.pop_back();
    while(sz(edges)&&(edges.back()[0].first>n+m+1||edges.back()[1].first>n+m+1))edges.pop_back();
    for(int i=0;i<=n+m+1;i++)while(sz(matrix[i])&&matrix[i].back().first>=sz(edges))matrix[i].pop_back();
    if(work)printf("%lli\n%lli\n",lo,lo+maxflow(0,n+m+1));
    else printf("-1\n");
    return 0;
}