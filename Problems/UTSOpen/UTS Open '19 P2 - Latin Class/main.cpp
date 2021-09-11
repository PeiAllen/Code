#include <bits/stdc++.h>
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
lli make(lli a){
	while(a<0)a+=mod;
	return a%mod;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	int dp[n+1];
	dp[0]=1;
	int in;
	int ma=0;
	pii deq[n+1];
	int l=0,r=-1;
	deq[++r]={0,0};
	rep(i,1,n+1){
		sc(in);
		while(r>=l+1&&deq[r].first<in)r--;
		if(in>=ma)dp[i]=make((deq[r].second?make(dp[deq[r].second]-dp[deq[r].second-1]):0)+dp[i-1]-((deq[r].second-1)>=0?dp[deq[r].second-1]:0));
		else dp[i]=make(dp[i-1]-(i-2>=0?dp[i-2]:0));
		dp[i]=(dp[i]+dp[i-1])%mod;
		ma=max(ma,in);
		deq[++r]={in,i};
	}
	prl(make(dp[n]-dp[n-1]));
	return 0;
}