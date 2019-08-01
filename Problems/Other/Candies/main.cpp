#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli mod=1e9+7;
lli make(lli a){
	while(a<0)a+=mod;
	return a%mod;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n,k;
	cin>>n>>k;
	lli dp[2][k+1];
	memset(dp,0,sizeof(dp));
	int flip=1;
	for(lli i=k;i>=0;i--)dp[0][i]=1;
	lli a;
	for(lli i=1;i<=n;i++){
		cin>>a;
		for(lli j=0;j<=k;j++){
			dp[flip][j]=make(dp[(flip+1)%2][j]-(j+a+1<=k?dp[(flip+1)%2][j+a+1]:(lli)0));
		}
		for(lli j=k-1;j>=0;j--){
			dp[flip][j]+=dp[flip][j+1];
			dp[flip][j]%=mod;
		}
		flip=(flip+1)%2;
	}
	printf("%lli\n",make(dp[(flip+1)%2][0]-(k>=1?dp[(flip+1)%2][1]:0)));
	return 0;
}