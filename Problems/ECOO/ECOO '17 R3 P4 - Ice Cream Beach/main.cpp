#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pll;
lli lepre[4002][4002];
lli ripre[4002][4002];
lli lepremid[4002];
lli ripremid[4002];
lli arr[4001];
lli rel[4001];
lli dp[21][4001];
int n, m;
inline lli waht(int l, int mid, int r){
	return lepremid[mid]-lepre[mid][l]+ripremid[mid]-ripre[r+1][mid];
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	setbuf(stdout,NULL);
	for(int t=0;t<10;t++){
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin>>arr[i]>>rel[i];
			dp[0][i]=1e12*4002;
		}
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++) {
				lepre[i][j] = lepre[i][j-1] + rel[j]*(arr[i] - arr[j]);
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=n;j>=i;j--) {
				ripre[j][i] = ripre[j+1][i] + rel[j]*(arr[j] - arr[i]);
			}
		}
		for(int i=1;i<=n;i++){
			lepremid[i]=lepre[i][i];
			ripremid[i]=ripre[i][i];
		}
		for(int i=1;i<=m;i++){
			dp[i][0]=0;
			for(int j=1;j<=n;j++){
				dp[i][j]=LLONG_MAX;
				int last=1;
				lli lastcalc;
				lli te;
				for (int k = 0; k < j; k++) {
					last = max(k + 1, last);
					lastcalc = waht(k, last, j);
					te = waht(k, last + 1, j);
					while (last < j && lastcalc > te) {
						last += 1;
						lastcalc = te;
						te = waht(k, last + 1, j);
					}
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + lastcalc);
				}
			}
		}
		printf("%lli\n",dp[m][n]%((lli)1e9+7));
	}
	return 0;
}