#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN=1001;
lli mod=998244353;
vector<int> matrix[MAXN];
bool type[MAXN];
lli dp[MAXN][MAXN][3][3];
int n,k;
lli fix(lli a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
void dfs(int loc, int parent){
    dp[loc][1][type[loc]==0][type[loc]==1]=1;
    for(int x:matrix[loc]){
        if(x!=parent){
            dfs(x,loc);
            for(int i2=k;i2>=1;i2--){
                for(int j2=0;j2<3;j2++){
                    for(int l2=0;l2<3;l2++){
                        for(int i=1;i<=k-i2;i++){
                            for(int j=0;j<3;j++){
                                for(int l=0;l<3;l++){
                                    dp[loc][i+i2][min(2,j+j2)][min(2,l+l2)]=fix(dp[loc][i+i2][min(2,j+j2)][min(2,l+l2)]+(dp[loc][i2][j2][l2]*dp[x][i][j][l]%mod));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    char c;
    for(int i=1;i<=n;i++){
        cin>>c;
        type[i]=c=='R';
    }
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0);
    lli ans=0;
    for(int i=1;i<=n;i++)ans=fix(ans+dp[i][k][2][2]);
    printf("%lli\n",ans);
    return 0;
}