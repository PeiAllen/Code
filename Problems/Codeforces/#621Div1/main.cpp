#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=51;
set<pair<int,lli>> matrix[MAXN];
lli dis[MAXN][MAXN];
lli ans[(int)1e5+1];
lli dist[MAXN];
int n,m;
int maxquery=1e5;
vector<pair<pii,lli>> edges;
vector<pair<lli,int>> used;
int camefrom[MAXN];
lli run(){
    int s=1;
    for(int i=2;i<=n;i++)dist[i]=LLONG_MAX;
    dist[s]=0;
    priority_queue<pair<lli,int>,vector<pair<lli,int>>,greater<pair<lli,int>>> q;
    q.push({0,s});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first<=dist[cur.second]){
            for(auto x:matrix[cur.second]){
                if(x.second+cur.first<dist[x.first]){
                    dist[x.first]=x.second+cur.first;
                    camefrom[x.first]=cur.second;
                    q.push({dist[x.first],x.first});
                }
            }
        }
    }
    return dist[n];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int a,b;
    lli c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        matrix[a].insert({b,c});
        matrix[b].insert({a,c});
        edges.push_back({{a,b},c});
        dis[a][b]=c;
        dis[b][a]=c;
    }
    ans[0]=run();
    int cur=n;
    while(cur!=1){
        used.push_back({dis[n][camefrom[n]],n});
        cur=camefrom[n];
    }
    sort(used.begin(),used.end());
    for(int i=1;i<=maxquery;i++){
        for(int j=1)
    }
    return 0;
}