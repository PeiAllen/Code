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
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
lli mod=1e9+7;
lli fastpow(lli a,lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
lli fact[101];
lli am[26];
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string a,b;
	sc(a,b);
	if(sz(b)<sz(a)){
		prl("0");
		return 0;
	}
	fact[0]=1;
	rep(i,1,101)fact[i]=fact[i-1]*i%mod;
	for(char x:b)am[x-'a']+=1;
	for(char x:a)am[x-'a']-=1;
	lli cur=fact[sz(b)-sz(a)+1];
	rep(i,0,26){
		cur=cur*fastpow(fact[am[i]],mod-2)%mod;
	}
	prl(cur);
	return 0;
}