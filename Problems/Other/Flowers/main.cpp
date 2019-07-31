#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
int height[(int)2e5+1];
int become[(int)2e5+1];
lli beauty[(int)2e5+1];
lli bit[(int)2e5+1];
int n;
void update(int loc, lli am){
	for(;loc<=n;loc+=loc&-loc)bit[loc]=max(bit[loc],am);
}
lli query(lli loc){
	lli ma=0;
	for(;loc>0;loc-=loc&-loc)ma=max(ma,bit[loc]);
	return ma;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	lli dp[2][n+1];
	dp[0][0]=0;
	dp[1][0]=0;
	for(int i=1;i<=n;i++){
		cin>>height[i];
		become[height[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>beauty[i];
		dp[1][i]=query(height[i])+beauty[i];
		dp[0][i]=max(dp[0][i-1],dp[1][i]);
		update(height[i],dp[1][i]);
	}
	printf("%lli\n",dp[0][n]);
	return 0;
}