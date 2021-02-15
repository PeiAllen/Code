#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e3+1;
int a[MAXN],b[MAXN];
int dp[MAXN][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(a[i]==b[j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}