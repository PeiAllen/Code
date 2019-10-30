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
lli mod=998244353;
inline lli fix(lli a){
	if(a<0)a+=mod;
	if(a>=mod)a-=mod;
	return a;
}
inline lli fastpow(lli a,lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
const int MAXN=1<<20;
int ALEN=MAXN;
vector<int> groups[17];
lli dp[2][MAXN];
lli scare[4];
lli mmi;
int am[5];
int mas[5];
void fhwt(int ind, bool inver){
	for(int len=1;len<ALEN;len<<=1){
		for(int i=0;i<ALEN;i+=2*len){
			for(int j=0;j<len;j++){
				lli a=dp[ind][i+j];
				lli b=dp[ind][i+j+len];
				dp[ind][i+j]=fix(a+b);
				dp[ind][i+j+len]=fix(a-b);
			}
		}
	}
	if(inver){
		for(int i=0;i<ALEN;i++){
			dp[ind][i]=dp[ind][i]*mmi%mod;
		}
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	mmi=fastpow(ALEN,mod-2);
	int n,q;
	sc(n,q);
	int in;
	string conver;
	int wh;
	string move;
	int gma;
	rep(i,1,n+1){
		conver=to_string(i);
		wh=0;
		for(char x:conver)wh+=x-'0';
		sc(in);
		gma=0;
		while(in--){
			sc(move);
			if(move[0]=='s')gma+=1;
			if(move[0]=='h')gma+=2;
			if(move[0]=='c')gma+=4;
			if(move[0]=='f')gma+=8;
		}
		groups[wh].push_back(gma);
	}
	dp[0][0]=1;
	fhwt(0,0);
	rep(i,1,17){
		if(sz(groups[i])==0)continue;
		memset(dp[1],0,sizeof(dp[1]));
		int upto=(int)pow(5,sz(groups[i]));
		int needed=ceil((double)sz(groups[i])/(double)2);
		rep(j,0,upto){
			memset(am,0,sizeof(am));
			memset(mas,0,sizeof(mas));
			int te=j;
			bool work=false;
			rep(k,0,sz(groups[i])){
				int othte=te%5;
				am[othte]+=1;
				if(am[othte]>=needed)work=true;
				mas[othte]^=groups[i][k];
				te/=5;
			}
			if(work){
				int fin=0;
				rep(k,0,5){
					fin+=mas[k]*(1<<4*k);
				}
				dp[1][fin]+=1;
			}
		}
		fhwt(1,0);
		rep(j,0,ALEN){
			dp[0][j]=dp[0][j]*dp[1][j]%mod;
		}
	}
	fhwt(0,1);
	rep(i,0,4)sc(scare[i]);
	map<lli,lli> anste;
	rep(i,0,ALEN){
		if(dp[0][i]) {
			lli tot = 0;
			rep(j, 0, 5) {
				rep(k, 0, 4) {
					if (i & (1 << (k + j * 4)))tot += scare[k];
				}
			}
			anste[tot] =fix(anste[tot]+dp[0][i]);
		}
	}
	vector<pll> ans;
	ans.push_back({-1,0});
	for(auto x:anste){
		ans.push_back(x);
		ans.back().second=fix(ans.back().second+ans[sz(ans)-2].second);
	}
	lli a,b;
	while(q--){
		sc(a,b);
		int rloc=upper_bound(ans.begin(),ans.end(),make_pair(b,LLONG_MAX))-ans.begin();
		int lloc=lower_bound(ans.begin(),ans.end(),make_pair(a,(lli)0))-ans.begin();
		prl(fix(ans[rloc-1].second-ans[lloc-1].second));
	}
	return 0;
}