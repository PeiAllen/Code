#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
lli mod=1e9+7;
lli fastpow(lli a,lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(i&b){
			ans=ans*a%mod;
		}
		a=(a*a)%mod;
	}
	return ans;
}
lli make(lli a){
	while(a<0)a+=mod;
	return a%mod;
}
lli dp[251][251];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	lli n,k;
	sc(n,k);
	lli inver=fastpow(2,mod-2);
	dp[0][0]=1;
	rep(i,1,n+1){
		rep(j,1,n+1){
			lli up=(dp[i-1][j]*make(fastpow(k,j)-fastpow(k-1,j))%mod);
			lli left=(dp[i][j-1]*make(fastpow(k,i)-fastpow(k-1,i))%mod);
			dp[i][j]=(make(((up+left)%mod)-(dp[i-1][j-1]*fastpow(k,i+j-1)%mod))+2*dp[i-1][j-1])%mod;
		}
	}
	prl(dp[n][n]);
    return 0;
}