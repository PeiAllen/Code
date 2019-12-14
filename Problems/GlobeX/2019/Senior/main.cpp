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
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
int MAXF=4e5+1;
lli fact[(int)4e5+1];
lli inv[(int)4e5+1];
lli mod=1e9+7;
const int MAXN=301;
lli dp[MAXN][MAXN];
lli ans[MAXN];
pair<pii,pii> arr[MAXN];
int n,k;
lli fastpow(lli a, lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
lli fix(lli a){
	if(a<0)a+=mod;
	return a%mod;
}
bool check(int a, int b){
	bool an=(a<0?1:0),bn=(b<0?1:0);
	if(an!=bn&&(b!=0&&a!=0))return false;
	return abs(a)<=abs(b);
}
lli go(int loc, int sp){
	if(dp[loc][sp]!=-1)return dp[loc][sp];
	dp[loc][sp]=(((fact[abs(arr[loc].first.first)+abs(arr[loc].first.second)+abs(arr[loc].second.first)]*inv[abs(arr[loc].first.first)]%mod)*inv[abs(arr[loc].first.second)]%mod)*inv[abs(arr[loc].second.first)]%mod);
	rep(i,0,n){
		if(i!=loc&&check(arr[i].first.first,arr[loc].first.first)&&check(arr[i].first.second,arr[loc].first.second)&&check(arr[i].second.first,arr[loc].second.first)&&arr[i].second.second!=sp){
			dp[loc][sp]=fix(dp[loc][sp]-(go(i,sp)*(((fact[abs(arr[loc].first.first-arr[i].first.first)+abs(arr[loc].first.second-arr[i].first.second)+abs(arr[loc].second.first-arr[i].second.first)]*inv[abs(arr[loc].first.first-arr[i].first.first)]%mod)*inv[abs(arr[loc].first.second-arr[i].first.second)]%mod)*inv[abs(arr[loc].second.first-arr[i].second.first)]%mod)%mod));
		}
	}
	return dp[loc][sp];
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	fact[0]=1;
	inv[0]=1;
	rep(i,1,MAXF){
		fact[i]=fact[i-1]*i%mod;
		inv[i]=fastpow(fact[i],mod-2);
	}
	sc(n,k);
	int a,b,c,t;
	rep(i,0,n){
		sc(a,b,c,t);
		arr[i]={{a,b},{c,t}};
		rep(j,1,k+1)dp[i][j]=-1;
	}
	rep(i,0,n){
		ans[arr[i].second.second]=(ans[arr[i].second.second]+go(i,arr[i].second.second))%mod;
	}
	lli fans=1;
	rep(i,1,k+1){
		if(ans[i]==0)ans[i]=1;
		fans=fans*ans[i]%mod;
	}
	prl(fans);
	return 0;
}