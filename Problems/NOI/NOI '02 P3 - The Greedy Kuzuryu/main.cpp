#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=301,MAXV=3e7+1;
vector<pii> matrix[MAXN];
int dp[MAXN][MAXN][2];
int tedp[MAXN][2];
int n,m,k;
int am(int a, int b){
    if(m==2)return a==b;
    return a==1&&b==1;
}
int dfs(int loc, int parent){
    dp[loc][0][0]=0;
    dp[loc][0][1]=MAXV;
    dp[loc][1][1]=0;
    dp[loc][1][0]=MAXV;
    int csts=1;
    for(auto x:matrix[loc])if(x.first!=parent){
            int te=dfs(x.first,loc);
            for(int cursz=min(k,csts+te);cursz>=0;cursz--)for(int partp = 0; partp < 2; partp++)tedp[cursz][partp]=MAXV;
            for(int cursz=min(k,csts);cursz>=0;cursz--){
                for(int partp=0;partp<2;partp++){
                    if(dp[loc][cursz][partp]<MAXV)for(int chsz=0;chsz<=te&&chsz+cursz<=k;chsz++){
                            for(int partch=0;partch<2;partch++){
                                if(dp[x.first][chsz][partch]<MAXV){
                                    tedp[cursz+chsz][partp]=min(tedp[cursz+chsz][partp],dp[loc][cursz][partp]+dp[x.first][chsz][partch]+am(partp,partch)*x.second);
                                }
                            }
                        }
                }
            }
            csts+=te;
            for(int cursz=min(k,csts);cursz>=0;cursz--)for(int partp = 0; partp < 2; partp++)dp[loc][cursz][partp]=tedp[cursz][partp];
        }
    return csts;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    if(k+(m-1)>n){
        printf("-1\n");
        return 0;
    }
    int a,b,c;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        matrix[a].push_back({b,c});
        matrix[b].push_back({a,c});
    }
    dfs(1,0);
    printf("%d\n",dp[1][k][1]);
    return 0;
}