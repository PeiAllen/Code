#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    lli dp[33][33];
    for(int i=0;i<=32;i++){
    	dp[0][i]=0;
    	dp[i][0]=0;
    }
    for(int i=1;i<=32;i++){
    	for(int j=1;j<=32;j++){
		    dp[i][j]=dp[i][j-1]+1+dp[i-1][j-1];
    	}
    }
    while(t--){
    	int n,k;
    	cin>>n>>k;
    	bool done=false;
    	for(int i=0;i<=32&&!done;i++){
    		if(dp[k][i]>=n){
    			printf("%d\n",i);
    			done=true;
    		}
    	}
    	if(!done)printf("Impossible\n");
    }
    return 0;
}
