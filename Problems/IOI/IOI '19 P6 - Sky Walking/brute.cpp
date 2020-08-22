#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<int> points[(int)1e5+1];
map<int,int> fnodes[(int)1e5+1];
int node=0;
vector<pair<int,ll>> matrix[(int)1e5+1];
ll dist[(int)1e5+1];
void addedge(int a, int b, ll c){
    matrix[a].push_back({b,c});
    matrix[b].push_back({a,c});
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int s,g;
    vector<int> loc(n),height(n),lefttower(m),righttower(m),height2(m);
    for(int i=0;i<n;i++){
        cin>>loc[i]>>height[i];
    }
    for(int i=0;i<m;i++){
        cin>>lefttower[i]>>righttower[i]>>height2[i];
    }
    cin>>s>>g;
    points[s].push_back(0);
    points[g].push_back(0);
    for(int i=0;i<m;i++){
        for(int j=lefttower[i];j<=righttower[i];j++){
            if(height[j]>=height2[i]){
                points[j].push_back(height2[i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        sort(points[i].begin(),points[i].end());
        points[i].erase(unique(points[i].begin(),points[i].end()),points[i].end());
        if(sz(points[i])) {
            fnodes[i][points[i][0]] = node;
            node++;
            for (int j = 1; j < sz(points[i]); j++) {
                fnodes[i][points[i][j]] = node;
                node++;
                addedge(fnodes[i][points[i][j - 1]], fnodes[i][points[i][j]], points[i][j] - points[i][j - 1]);
            }
        }
    }
    for(int i=0;i<m;i++){
        int last=lefttower[i];
        for(int j=lefttower[i]+1;j<=righttower[i];j++){
            if(height[j]>=height2[i]){
                addedge(fnodes[last][height2[i]],fnodes[j][height2[i]],loc[j]-loc[last]);
                last=j;
            }
        }
    }
    for(int i=0;i<node;i++)dist[i]=LLONG_MAX;
    int st=fnodes[s][0];
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    q.push({0,st});
    dist[st]=0;
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first<=dist[cur.second]){
            for(auto ne:matrix[cur.second]){
                if(dist[ne.first]>cur.first+ne.second){
                    dist[ne.first]=cur.first+ne.second;
                    q.push({dist[ne.first],ne.first});
                }
            }
        }
    }
    if(dist[fnodes[g][0]]==LLONG_MAX)printf("-1\n");
    else printf("%lli\n",dist[fnodes[g][0]]);
    return 0;
}