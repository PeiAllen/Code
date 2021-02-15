#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e2+1;
const double MAXV=1e13;
int xc[4]={1,-1,0,0},yc[4]={0,0,1,-1};
double dist[MAXN][MAXN][2*MAXN];
double price[MAXN][MAXN];
int n,m,f,k;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n>>f>>k;
        f=min(f,n+m);
        for(int i=1;i<=m;i++)for(int j=1;j<=n;j++){
            price[i][j]=MAXV;
            for(int l=0;l<=f;l++)dist[i][j][l]=MAXV;
        }
        int a,b;
        dist[1][1][f]=0;

        double c;
        for(int i=0;i<k;i++){
            cin>>a>>b;
            cin>>c;
            price[a][b]=min(price[a][b],c);
        }
        priority_queue<pair<double,pair<pii,int>>,vector<pair<double,pair<pii,int>>>,greater<>> q;
        q.push({0,{{1,1},f}});
        while(sz(q)){
            auto cur=q.top();
            q.pop();
            if(cur.second.second<f){
                if(cur.first+price[cur.second.first.first][cur.second.first.second]<dist[cur.second.first.first][cur.second.first.second][cur.second.second+1]){
                    dist[cur.second.first.first][cur.second.first.second][cur.second.second+1]=cur.first+price[cur.second.first.first][cur.second.first.second];
                    q.push({dist[cur.second.first.first][cur.second.first.second][cur.second.second+1],{cur.second.first,cur.second.second+1}});
                }
            }
            if(cur.second.second)for(int i=0;i<4;i++){
                int nx=cur.second.first.first+xc[i],ny=cur.second.first.second+yc[i];
                if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&dist[nx][ny][cur.second.second-1]>cur.first){
                    dist[nx][ny][cur.second.second-1]=cur.first;
                    q.push({cur.first,{{nx,ny},cur.second.second-1}});
                }
            }
        }
        double ans=MAXV;
        for(int i=0;i<=f;i++)ans=min(ans,dist[m][n][i]);
        if(ans==MAXV)printf("Stranded on the shoulder\n");
        else printf("%.2f\n",ans);
    }
    return 0;
}