#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mod=1e9+7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int h,w;
	cin>>h>>w;
	lli dp[h+1][w+1];
	memset(dp,0,sizeof(dp));
	string a;
	dp[1][1]=1;
	for(int i=1;i<=h;i++){
		cin>>a;
		for(int j=(i==1?2:1);j<=w;j++){
			if(a[j-1]=='#')dp[i][j]=0;
			else{
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
			}
		}
	}
	printf("%lli\n",dp[h][w]);
    return 0;
}