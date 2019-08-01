#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli arr[401];
lli dp[401][401];
lli go(int a, int b){
	if(dp[a][b]!=-1)return dp[a][b];
	lli mi=LLONG_MAX;
	for(int i=a;i<b;i++){
		mi=min(mi,go(a,i)+go(i+1,b));
	}
	return dp[a][b]=mi+arr[b]-arr[a-1];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
    	cin>>arr[i];
    	arr[i]+=arr[i-1];
    	dp[i][i]=0;
    }
	printf("%lli\n",go(1,n));
    return 0;
}