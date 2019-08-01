#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	double coins[n+1];
	for(int i=1;i<=n;i++){
		cin>>coins[i];
	}
	double dp[n+1][n+1];//first i coins getting j heads
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			dp[i][j]=dp[i-1][j]*(1-coins[i])+(j>0?dp[i-1][j-1]*coins[i]:0);
		}
	}
	double ans=0;
	for(int i=n/2+1;i<=n;i++){
		ans+=dp[n][i];
	}
	printf("%.9f\n",ans);
    return 0;
}