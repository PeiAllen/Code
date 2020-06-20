#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e3+1;
int dp[MAXN][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int a;
    int ans=INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a;
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+(i-2>=0?-dp[i-2][j-1]:0)+1;
            if(dp[i][j]<=k)ans=min(ans,a);
        }
    }
    printf("%d\n",ans);
    return 0;
}