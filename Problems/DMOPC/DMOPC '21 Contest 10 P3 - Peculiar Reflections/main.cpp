#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
//left,top is 0
pii change[2][2]={{{0,1},{0,-1}},{{1,0},{-1,0}}};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    if(n%2==m%2){
        printf("-1\n");
        return 0;
    }
    vector<vector<char>> arr(n+1,vector<char>(m+1));
    vector<vector<vector<int>>> dist(n+1,vector<vector<int>>(m+1,vector<int>(2,INT_MAX)));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    dist[1][1][0]=0;
    priority_queue<pair<int,pair<pii,int>>,vector<pair<int,pair<pii,int>>>,greater<>> q;
    q.push({0,{{1,1},0}});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first>dist[cur.second.first.first][cur.second.first.second][cur.second.second])continue;
        int cursquare=(cur.second.first.first+cur.second.first.second)%2;
        pii nxt={cur.second.first.first+change[cursquare][cur.second.second].first,cur.second.first.second+change[cursquare][cur.second.second].second};
        if(nxt.first>=1&&nxt.first<=n&&nxt.second>=1&&nxt.second<=m&&dist[nxt.first][nxt.second][cur.second.second]>dist[cur.second.first.first][cur.second.first.second][cur.second.second]+(arr[cur.second.first.first][cur.second.first.second]=='/')){
            dist[nxt.first][nxt.second][cur.second.second]=dist[cur.second.first.first][cur.second.first.second][cur.second.second]+(arr[cur.second.first.first][cur.second.first.second]=='/');
            q.push({dist[nxt.first][nxt.second][cur.second.second],{nxt,cur.second.second}});
        }
        nxt={cur.second.first.first-change[cursquare][cur.second.second].first,cur.second.first.second-change[cursquare][cur.second.second].second};
        if(nxt.first>=1&&nxt.first<=n&&nxt.second>=1&&nxt.second<=m&&dist[nxt.first][nxt.second][!cur.second.second]>dist[cur.second.first.first][cur.second.first.second][cur.second.second]+(arr[cur.second.first.first][cur.second.first.second]=='\\')){
            dist[nxt.first][nxt.second][!cur.second.second]=dist[cur.second.first.first][cur.second.first.second][cur.second.second]+(arr[cur.second.first.first][cur.second.first.second]=='\\');
            q.push({dist[nxt.first][nxt.second][!cur.second.second],{nxt,!cur.second.second}});
        }
    }
    if(dist[n][m][0]==INT_MAX)printf("-1\n");
    else printf("%d\n",dist[n][m][0]+(arr[n][m]=='/'));
    return 0;
}