#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli dp[100][10001][2];
string a;
int b;
lli tomod=1e9+7;
lli go(int mod, int digits, bool max){
	if(digits==a.size())return dp[mod][digits][max]=(mod?0:1);
	if(dp[mod][digits][max]!=-1)return dp[mod][digits][max];
	lli ans=0;
	for(int i=0;i<=(max?a[digits]-'0':9);i++){
		ans=(ans+go((mod+i)%b,digits+1,(max&&i==a[digits]-'0')))%tomod;
	}
	return dp[mod][digits][max]=ans;
}
lli make(lli a){
	while(a<0)a+=tomod;
	return a%tomod;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	printf("%lli\n",make(go(0,0,1)-1));
	return 0;
}