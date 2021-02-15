#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e3+1;
char arr[MN][MN];
bool gone[MN][MN];
int xc[4]={1,-1,0,0},yc[4]={0,0,1,-1};
int psa[MN][MN];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,query;
    cin>>n>>m>>query;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>arr[i][j];

    if(n<=50&&m<=50){
        int a,b,c,d;
        while(query--){
            cin>>a>>b>>c>>d;
            for(int i=a;i<=c;i++)for(int j=b;j<=d;j++)gone[i][j]=false;
            int ans=0;
            for(int i=a;i<=c;i++){
                for(int j=b;j<=d;j++){
                    if(!gone[i][j]){
                        ans++;
                        gone[i][j]=true;
                        queue<pii> q;
                        q.push({i,j});
                        while(sz(q)){
                            auto cur=q.front();
                            q.pop();
                            for(int k=0;k<4;k++){
                                pii ne={xc[k]+cur.first,yc[k]+cur.second};
                                if(ne.first>=a&&ne.first<=c&&ne.second>=b&&ne.second<=d){
                                    if(!gone[ne.first][ne.second]&&arr[ne.first][ne.second]==arr[i][j]){
                                        gone[ne.first][ne.second]=true;
                                        q.push(ne);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            printf("%d\n",ans);
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            psa[i][j]=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
            if(!gone[i][j]){
                psa[i][j]++;
                gone[i][j]=true;
                queue<pii> q;
                q.push({i,j});
                while(sz(q)){
                    auto cur=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        pii ne={xc[k]+cur.first,yc[k]+cur.second};
                        if(ne.first>=1&&ne.first<=n&&ne.second>=1&&ne.second<=m){
                            if(!gone[ne.first][ne.second]&&arr[ne.first][ne.second]==arr[i][j]){
                                gone[ne.first][ne.second]=true;
                                q.push(ne);
                            }
                        }
                    }
                }
            }
        }
    }
    int a,b,c,d;
    while(query--){
        cin>>a>>b>>c>>d;
        int ans=psa[c][d]-psa[a-1][d]-psa[c][b-1]+psa[a-1][b-1];
        for(int i=max(1,a-2);i<=min(n,c+2);i++){
            for(int j=1;j<=2;j++){
                if(b-j>=1)gone[i][b-j]=false;
                if(d+j<=m)gone[i][d+j]=false;
            }
        }
        for(int i=max(1,b-2);i<=min(m,d+2);i++){
            for(int j=1;j<=2;j++){
                if(a-j>=1)gone[a-j][i]=false;
                if(c+j<=n)gone[c+j][i]=false;
            }
        }
        queue<pii> q;
        for(int i=a;i<=c;i++){
            q.push({i,b});
            if(b!=d)q.push({i,d});
        }
        for(int i=b+1;i<=d-1;i++){
            q.push({a,i});
            if(a!=c)q.push({c,i});
        }
        while(sz(q)){
            auto cur=q.front();
            q.pop();
            if(cur.first<a||cur.first>c||cur.second<b||cur.second>d){
                if(psa[cur.first][cur.second]-psa[cur.first-1][cur.second]-psa[cur.first][cur.second-1]+psa[cur.first-1][cur.second-1]>0)ans++;
            }
            for(int k=0;k<4;k++){
                pii ne={xc[k]+cur.first,yc[k]+cur.second};
                if(ne.first>=1&&ne.first<=n&&ne.second>=1&&ne.second<=m){
                    if(!gone[ne.first][ne.second]&&arr[ne.first][ne.second]==arr[cur.first][cur.second]){
                        gone[ne.first][ne.second]=true;
                        q.push(ne);
                    }
                }
            }
        }
        for(int i=max(1,a-2);i<=min(n,c+2);i++){
            for(int j=1;j<=2;j++){
                if(b-j>=1)gone[i][b-j]=true;
                if(d+j<=m)gone[i][d+j]=true;
            }
        }
        for(int i=max(1,b-2);i<=min(m,d+2);i++){
            for(int j=1;j<=2;j++){
                if(a-j>=1)gone[a-j][i]=true;
                if(c+j<=n)gone[c+j][i]=true;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}