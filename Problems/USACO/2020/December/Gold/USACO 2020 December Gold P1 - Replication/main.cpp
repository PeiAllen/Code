#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e3+1;
string arr[MN];
int dist[2][MN][MN];
int xc[4]={1,-1,0,0},yc[4]={0,0,1,-1};
int n,d;
int adist[MN][MN];
bool inbounds(pii a){
    return a.first>=0&&a.first<n&&a.second>=0&&a.second<n;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>d;
    queue<pii> q[2];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<n;j++){
            adist[i][j]=-1;
            dist[0][i][j]=INT_MAX,dist[1][i][j]=INT_MAX;
            if(arr[i][j]=='#')q[0].push({i,j}),dist[0][i][j]=0;
            else if(arr[i][j]=='S')q[1].push({i,j}),dist[1][i][j]=0;
        }
    }
    priority_queue<pair<int,pii>> ans;
    for(int t=0;t<2;t++){
        while(sz(q[t])){
            auto cur=q[t].front();
            q[t].pop();
            if(t==1) {
                int i=cur.first,j=cur.second;
                if (dist[1][i][j] != INT_MAX && dist[1][i][j] / d < dist[0][i][j]) {
                    ans.push({dist[1][i][j] / d, {i, j}});
                    adist[i][j] = dist[1][i][j] / d;
                } else if (dist[1][i][j] != INT_MAX && (dist[1][i][j] - 1) / d < dist[0][i][j]) {
                    ans.push({(dist[1][i][j] - 1) / d, {i, j}});
                    adist[i][j] = (dist[1][i][j] - 1) / d;
                    continue;
                }
                else continue;
            }
            for(int i=0;i<4;i++){
                pii ne={cur.first+xc[i],cur.second+yc[i]};
                if(inbounds(ne)&&dist[t][ne.first][ne.second]>dist[t][cur.first][cur.second]+1&&arr[ne.first][ne.second]!='#'){
                    dist[t][ne.first][ne.second]=dist[t][cur.first][cur.second]+1;
                    q[t].push(ne);
                }
            }
        }
    }
    int tot=0;
    while(sz(ans)){
        auto cur=ans.top();
        ans.pop();
        if(cur.first<adist[cur.second.first][cur.second.second])continue;
        if(cur.first>=0)tot++;
        for(int i=0;i<4;i++){
            pii ne={cur.second.first+xc[i],cur.second.second+yc[i]};
            if(inbounds(ne)&&adist[ne.first][ne.second]<cur.first-1&&arr[ne.first][ne.second]!='#'){
                adist[ne.first][ne.second]=cur.first-1;
                ans.push({cur.first-1,ne});
            }
        }
    }
    printf("%d\n",tot);
    return 0;
}