#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const lli MAXV=2125000000;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    lli arr[n+1][m+1];
	lli dp[4][n+1][m+1];
    for(int i=0;i<=n;i++){
    	arr[i][0]=0;
    	dp[0][i][0]=0;
    }
	for(int i=0;i<=m;i++){
		arr[0][i]=0;
		dp[0][0][i]=0;
	}
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		dp[0][i][j]=0;
    		cin>>arr[i][j];
    		arr[i][j]+=arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
    	}
    }
    for(int i=1;i<=3;i++){
    	for(int x=0;x<=n;x++){
    		for(int y=0;y<=m;y++){
				if(x>=k&&y>=k){
					dp[i][x][y]=max(dp[i][x-1][y],dp[i][x][y-1]);
					lli sum=arr[x][y]-arr[x-k][y]-arr[x][y-k]+arr[x-k][y-k];
					lli bestprev=max(dp[i-1][x-k][y],dp[i-1][x][y-k]);
					if(i==3){
						if(dp[i-2][x-k][y-k]>=0)bestprev=max(bestprev,dp[i-1][x-k][y]+dp[i-1][x][y-k]-2*dp[i-2][x-k][y-k]);
					}
					dp[i][x][y]=max(dp[i][x][y],sum+bestprev);
				}
				else{
					dp[i][x][y]=-MAXV;
				}
    	    }
    	}
    }
    lli best=0;
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=m;j++){
    		best=max(best,dp[3][i][j]);
    	}
    }
    printf("%lli\n",best);
    return 0;
}