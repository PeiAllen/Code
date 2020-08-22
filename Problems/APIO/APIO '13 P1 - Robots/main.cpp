#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXD=501,MAXV=10000000;
pii to[MAXD][MAXD][4];
int n,w,h;
char grid[MAXD][MAXD];
int xc[4]={1,0,-1,0};
int yc[4]={0,-1,0,1};
int dp[10][10][MAXD][MAXD];
pii pos[10];
pair<int,pii> q[MAXD*MAXD];
pair<int,pii> stq[MAXD*MAXD];
int ql=0,qr=-1,stqp=-1;
pii go(int x, int y, int dir){
    if(x<0||y<0||x>=h||y>=w)return {-1,-1};
    if(to[x][y][dir]!=pii{-1,-1})return to[x][y][dir];
    if(grid[x][y]=='x')return {-1,-1};
    int nedir=dir;
    if(grid[x][y]=='C')nedir=(nedir==3?0:nedir+1);
    if(grid[x][y]=='A')nedir=(nedir?nedir-1:3);
    to[x][y][dir]=go(x+xc[nedir],y+yc[nedir],nedir);
    if(to[x][y][dir]==pii{-1,-1})to[x][y][dir]={x,y};
    return to[x][y][dir];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>w>>h;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        cin>>grid[i][j];
        if(isdigit(grid[i][j]))pos[grid[i][j]-'0']={i,j};
        for(int k=0;k<4;k++)to[i][j][k]={-1,-1};
    }
    for(int l=1;l<=n;l++)for(int r=l;r<=n;r++)for(int i=0;i<h;i++)for(int j=0;j<w;j++)dp[l][r][i][j]=MAXV;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)for(int k=0;k<4;k++)go(i,j,k);
    for(int len=1;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            if(l==r)dp[l][r][pos[l].first][pos[l].second]=0;
            else{
                for(int i=0;i<h;i++){
                    for(int j=0;j<w;j++){
                        for(int k=l;k<r;k++)dp[l][r][i][j]=min(dp[l][r][i][j],dp[l][k][i][j]+dp[k+1][r][i][j]);
                    }
                }
            }
            ql=0,qr=-1;
            stqp=-1;
            for(int i=0;i<h;i++)for(int j=0;j<w;j++)stq[++stqp]={dp[l][r][i][j],{i,j}};
            sort(stq,stq+stqp+1,greater<>());
            while(stqp>=0||ql<=qr){
                pair<int,pii> cur;
                if(stqp<0||(ql<=qr&&q[ql].first<stq[stqp].first))cur=q[ql++];
                else cur=stq[stqp--];
                if(dp[l][r][cur.second.first][cur.second.second]<cur.first)continue;
                for(int i=0;i<4;i++){
                    pii ne=to[cur.second.first][cur.second.second][i];
                    if(dp[l][r][ne.first][ne.second]>cur.first+1){
                        dp[l][r][ne.first][ne.second]=cur.first+1;
                        q[++qr]={cur.first+1,ne};
                    }
                }
            }
        }
    }
    int ans=MAXV;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)ans=min(ans,dp[1][n][i][j]);
    if(ans==MAXV)printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}