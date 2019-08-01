#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int dp[3][n+1];
    memset(dp,0,sizeof(dp));
    int a,b,c;
    for(int i=1;i<=n;i++){
    	cin>>a>>b>>c;
    	dp[0][i]=max(dp[1][i-1],dp[2][i-1])+a;
	    dp[1][i]=max(dp[0][i-1],dp[2][i-1])+b;
	    dp[2][i]=max(dp[0][i-1],dp[1][i-1])+c;
    }
    printf("%d\n",max(dp[0][n],max(dp[1][n],dp[2][n])));
    return 0;
}