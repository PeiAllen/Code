#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=101;
int xc[4]={-1,1,0,0},yc[4]={0,0,1,-1};
map<char,pii> dir={{'L',{0,-1}},{'R',{0,1}},{'U',{-1,0}},{'D',{1,0}}};
string arr[MN];
int dist[MN][MN];
pii deq[MN*MN];
int n,m,l,r;
bool out(int x, int y){
    return x<0||x>=n||y<0||y>=m;
}
void go(int x, int y, int xi, int yi){
    if(out(x,y)||arr[x][y]=='W')return;
    if(!dir.count(arr[x][y]))dist[x][y]=-1;
    go(x+xi,y+yi,xi,yi);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    pii st;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]==0)dist[i][j]=INT_MAX;
            if(arr[i][j]=='S')st={i,j},arr[i][j]='.';
            if(arr[i][j]=='C')for(int k=0;k<4;k++)go(i,j,xc[k],yc[k]);
        }
    }
    l=0,r=-1;
    if(dist[st.first][st.second]==INT_MAX)deq[++r]=st,dist[st.first][st.second]=0;
    while(l<=r){
        auto cur=deq[l++];
        if(arr[cur.first][cur.second]=='.'){
            for(int i=0;i<4;i++){
                int nx=cur.first+xc[i],ny=cur.second+yc[i];
                if(!out(nx,ny)&&arr[nx][ny]!='W'&&dist[nx][ny]>dist[cur.first][cur.second]+1){
                    dist[nx][ny]=dist[cur.first][cur.second]+1;
                    deq[++r]={nx,ny};
                }
            }
        }
        else{
            int nx=cur.first+dir[arr[cur.first][cur.second]].first,ny=cur.second+dir[arr[cur.first][cur.second]].second;
            if(!out(nx,ny)&&arr[nx][ny]!='W'&&dist[nx][ny]>dist[cur.first][cur.second]){
                dist[nx][ny]=dist[cur.first][cur.second];
                deq[--l]={nx,ny};
            }
        }
    }
    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j]=='.'&&pii{i,j}!=st){
                if(dist[i][j]==INT_MAX)printf("-1\n");
                else printf("%d\n",dist[i][j]);
            }
        }
    }
    return 0;
}