#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
int mod=1e9+7;
int make(int a){
	while(a<0)a+=mod;
	return a%mod;
}
int dp[101][101][101][101];//at position i,and cur length of inc k, with last num j, and max length of l
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,oth;
	cin>>n>>oth;
	dp[0][0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=i;k++){
			for(int j=1;j<=i;j++){
				for(int l=k;l<=i;l++){
					dp[i][k][j][l]=make(dp[i-1][k-1][j-1][l]-dp[i-1][max(0,k-2)][j-1][l]);
					if(k==l){
						dp[i][k][j][l]+=make(dp[i-1][k-1][j-1][l-1]-(k-2<0?0:dp[i-1][k-2][j-1][l-1]));
						dp[i][k][j][l]%=mod;
					}
					if(k==1){
						dp[i][k][j][l]+=make(dp[i-1][min(i-1,l)][i-1][l]-dp[i-1][min(i-1,l)][j-1][l]);
						dp[i][k][j][l]%=mod;
					}
					dp[i][k][j][l]+=make(dp[i][k-1][j][l]+dp[i][k][j-1][l]-dp[i][k-1][j-1][l]);
					dp[i][k][j][l]%=mod;
				}
			}
		}
	}
	printf("%d\n",dp[n][min(oth,n)][n][oth]);
	return 0;
}