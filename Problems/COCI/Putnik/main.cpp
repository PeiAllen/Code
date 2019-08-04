#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[1501][1501];
lli arr[1501][1501];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
			cin>>arr[i][j];
			dp[i][j]=INT_MAX;
    	}
    }
    dp[1][1]=0;
    for(int i=1;i<n;i++){
    	for(int j=1;j<n;j++){
    		int cur=max(i,j)+1;
    		dp[cur][j]=min(dp[cur][j],arr[cur][j]+dp[i][j]);
		    dp[cur][i]=min(dp[cur][i],arr[i][cur]+dp[i][j]);
	    }
    }
    lli ans=LLONG_MAX;
    for(int i=1;i<n;i++)ans=min(ans,max(dp[n][i],dp[i][n]));
    printf("%lli\n",ans);
    return 0;
}