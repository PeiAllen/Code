#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n;
lli dp[3001][3001];
lli arr[3001];
lli solve(int l, int r,int who){
	if(dp[l][r]!=LLONG_MAX)return dp[l][r];
	if(who)return dp[l][r]=min(solve(l+1,r,(who+1)%2)-arr[l],solve(l,r-1,(who+1)%2)-arr[r]);
	else return dp[l][r]=max(solve(l+1,r,(who+1)%2)+arr[l],solve(l,r-1,(who+1)%2)+arr[r]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dp[i][j]=LLONG_MAX;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(n%2)dp[i][i]=arr[i];
		else dp[i][i]=-arr[i];
	}
	printf("%lli\n",solve(1,n,0));
    return 0;
}