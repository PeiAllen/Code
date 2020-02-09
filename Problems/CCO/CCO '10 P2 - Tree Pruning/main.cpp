#include<bits/stdc++.h>
using namespace std;
const int MAXN=301;
vector<int> matrix[MAXN];
int col[MAXN];
int dp[MAXN][602];
int te[602];
int dfs(int loc){
    int am=col[loc];
    dp[loc][301]=0;
    for(int x:matrix[loc]){
        am+=dfs(x);
        for(int j=0;j<602;j++){
            te[j]=400;
        }
        for(int j=0;j<602;j++){
            for(int l=max(0,301-j);l<602+301-j;l++){
                te[j-301+l-301+301]=min(te[j-301+l-301+301],dp[x][j]+dp[loc][l]);
            }
        }
        for(int j=0;j<602;j++){
            dp[loc][j]=min(dp[loc][j],te[j]);
        }
    }
    dp[loc][am+301]=min(dp[loc][am+301],1);
    return am;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,d;
    cin>>n>>d;
    int a,b,c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        col[a]=(b?1:-1);
        for(int j=0;j<602;j++)dp[i][j]=400;
        while(c--){
            cin>>b;
            matrix[a].push_back(b);
        }
    }
    int te=dfs(0);
    if(dp[0][te-d+301]>300)printf("-1\n");
    else printf("%d\n",dp[0][te-d+301]);
    return 0;
}