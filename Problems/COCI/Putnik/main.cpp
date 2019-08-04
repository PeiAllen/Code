#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int dp[1501][1501];
int arr[1501][1501];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
			cin>>arr[i][j];
			dp[i][j]=1500001;
    	}
    }
    dp[1][1]=0;
    for(int i=1;i<n;i++){
    	for(int j=1;j<n;j++){
    		int cur=max(i,j)+1;
    		dp[cur][j]=min(dp[cur][j],arr[cur][i]+dp[i][j]);
		    dp[i][cur]=min(dp[i][cur],arr[j][cur]+dp[i][j]);
	    }
    }
    int ans=INT_MAX;
    for(int i=1;i<n;i++)ans=min(ans,min(dp[n][i],dp[i][n]));
    printf("%d\n",ans);
    return 0;
}