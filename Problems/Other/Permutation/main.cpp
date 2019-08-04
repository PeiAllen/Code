#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[2][3001];
lli mod=1e9+7;
lli make(lli a){
	while(a<0)a+=mod;
	return a%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string a;
	cin>>a;
	int flip=1;
	dp[0][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[flip][j]=dp[flip][j-1];
			if(a[i-2]=='<'){
				dp[flip][j]=make(dp[flip][j]+make(dp[(flip+1)%2][j-1]-dp[(flip+1)%2][0]));
			}
			else{
				dp[flip][j]=make(dp[flip][j]+make(dp[(flip+1)%2][i-1]-dp[(flip+1)%2][j-1]));//trick, sop we can allow larger numbers in.
			}
		}
		flip=(flip+1)%2;
	}
	printf("%lli\n",dp[(flip+1)%2][n]);
    return 0;
}
