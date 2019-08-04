#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pll;
lli lepre[4002][4002];
lli ripre[4002][4002];
lli calc(lli l, lli mid, lli r){
	return lepre[mid][mid]-lepre[mid][l]+ripre[mid][mid]-ripre[mid][r+1];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    setbuf(stdout,NULL);
    int t=10;
    while(t--) {
	    int n, m;
	    cin >> n >> m;
	    pll arr[n + 1];
	    lli dp[m + 1][n + 1];
	    for (int i = 1; i <= n; i++) {
			cin>>arr[i].first>>arr[i].second;
			dp[0][i]=1e12*4002;
	    }
	    dp[0][0]=0;
	    sort(arr+1,arr+n+1);
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<=i;j++) {
			    lepre[i][j] = lepre[i][j-1] + arr[j].second*(arr[i].first - arr[j].first);
		    }
	    }
	    for(int i=n;i>=1;i--){
		    for(int j=n;j>=i;j--) {
			    ripre[i][j] = ripre[i][j+1] + arr[j].second*(arr[j].first - arr[i].first);
		    }
	    }
	    for(int i=1;i<=m;i++){
	    	dp[i][0]=0;
	    	for(int j=1;j<=n;j++){
	    		dp[i][j]=LLONG_MAX;
	    		int last=1;
	    		for(int k=0;k<j;k++){
	    			last=max(k+1,last);
					while(last<j&&(calc(k,last,j)>calc(k,last+1,j))){
						last+=1;
					}
					dp[i][j]=min(dp[i][j],dp[i-1][k]+calc(k,last,j));
	    		}
	    	}
	    }
	    printf("%lli\n",dp[m][n]%((lli)1e9+7));
    }
    return 0;
}