#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1001;
ll cost[MAXN];
vector<int> matrix[MAXN];
ll dp[MAXN][MAXN][3];//0 not drunk, 1 drunk but not added, 2 drunk and added
ll ans[MAXN];
bool gone[MAXN];
pii combine(int a, int b){
    if(a==0||b==0)return {0,a};
    return {int(a==1)+int(b==1),2};
}
int dfs(int loc, int parent){
    int maxsize=1;
    gone[loc]=true;
    dp[loc][0][0]=0;
    dp[loc][0][1]=cost[loc];
    for(auto x:matrix[loc]){
        if(x!=parent){
            int chsize=dfs(x,loc);
            for(int cursize=maxsize;cursize>=0;cursize--){
                for(int state=2;state>=0;state--){
                    if(dp[loc][cursize][state]<LLONG_MAX)for(int othsize=0;othsize<=chsize;othsize++){
                        for(int othstate=0;othstate<=2;othstate++){
                            if(dp[x][othsize][othstate]<LLONG_MAX){
                                pii te=combine(state,othstate);
                                dp[loc][cursize+othsize+te.first][te.second]=min(dp[loc][cursize+othsize+te.first][te.second],dp[loc][cursize][state]+dp[x][othsize][othstate]);
                            }
                        }
                    }
                }
            }
            maxsize+=chsize;
        }
    }
    return maxsize;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++)for(int k=0;k<3;k++)dp[i][j][k]=LLONG_MAX;
        cin>>cost[i];
        ans[i]=LLONG_MAX;
    }
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    int totsize=0;
    for(int i=1;i<=n;i++)if(!gone[i]){
        int sts=dfs(i,0);
        for(int k=totsize;k>=0;k--){
            if(ans[k]<LLONG_MAX)for(int j=1;j<=sts;j++){
                if(min({dp[i][j][0],dp[i][j][1],dp[i][j][2]})<LLONG_MAX)ans[k+j]=min(ans[k+j],ans[k]+min({dp[i][j][0],dp[i][j][1],dp[i][j][2]}));
            }
        }
        totsize+=sts;
    }
    for(int i=n-1;i>=0;i--)ans[i]=min(ans[i],ans[i+1]);
    int q;
    cin>>q;
    ll s;
    while(q--){
        cin>>s;
        printf("%d\n",int(upper_bound(ans,ans+n+1,s)-ans)-1);
    }
    return 0;
}