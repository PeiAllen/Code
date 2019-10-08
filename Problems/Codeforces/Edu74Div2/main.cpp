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
lli mod=1e9+9;
lli fastpow(lli a,lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i){
			ans=ans*a%mod;
		}
		a=a*a%mod;
	}
	return ans;
}
lli make(lli a){
	while(a<0)a+=mod;
	return a%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	string s;
	sc(s);
	lli act[n+1];
	rep(i,1,n+1)act[i]=(s[i-1]=='A'?1:0);
	lli r=31;
	lli mut[n];
	lli invmut[n];
	mut[0]=1;
	invmut[0]=fastpow(mut[0],mod-2);
	rep(i,1,n){
		mut[i]=mut[i-1]*r%mod;
		invmut[i]=fastpow(mut[i],mod-2);
	}
	lli prefix[n+2];
	lli suffix[n+2];
	prefix[0]=0;
	prefix[n+1]=0;
	rep(i,1,n+1){
		prefix[i]=(prefix[i-1]+(act[i]*mut[i-1]%mod))%mod;
	}
	for(int i=n;i>=1;i--){
		suffix[i]=(suffix[i+1]+(mut[n-i]*act[i]%mod))%mod;
	}
	lli partof[n+1];
	partof[0]=0;
	memset(partof,0,sizeof(partof));
	lli ans=0;
	for(int i=1;i<=n;i++){
		int lo=0;
		int hi=min(i-1,n-i);
		while(lo!=hi){
			int mid=(lo+hi)/2+1;
			if(make(prefix[i+mid]-prefix[i])*invmut[i]%mod==make(suffix[i-mid]-suffix[i])*invmut[n-(i+1)+2]%mod){
				lo=mid;
			}
			else hi=mid-1;
		}
		partof[i-lo]+=1;
		partof[i+lo]-=1;
	}
	for(int i=1;i<n;i++){
		int lo=0;
		int hi=min(i,n-i);
		while(lo!=hi){
			int mid=(lo+hi)/2+1;
			if(make(prefix[i+mid]-prefix[i])*invmut[i]%mod==make(suffix[i-mid+1]-suffix[i+1])*invmut[n-i]%mod){
				lo=mid;
			}
			else hi=mid-1;
		}
		partof[i-lo+1]+=1;
		partof[i+lo+1]-=1;
	}
	int last=0;
	rep(i,1,n+1){
		partof[i]+=partof[i-1];
		if(!partof[i])last=i;
		else {
			ans+=i-last-1;
		}
	}
	prl(ans);
    return 0;
}