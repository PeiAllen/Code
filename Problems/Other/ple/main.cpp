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
pll dp[2002][2002][2];
pll bt(pll a, pll b,lli todo){
	if(a.first+a.second*todo<b.first+b.second*todo)return a;
	return b;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n;
	lli l;
	sc(n,l);
	vector<lli> pre;
	vector<lli> suf;
	lli in;
	set<lli> used;
	rep(i,0,n){
		sc(in);
		if(used.count(in))continue;
		used.insert(in);
		if(in<l){
			pre.push_back(in);
		}
		else suf.push_back(in);
	}
	pre.push_back(l);
	suf.push_back(l);
	sort(pre.begin(),pre.end(),greater<lli>());
	sort(suf.begin(),suf.end());
	rep(i,1,sz(pre)){
		dp[i][0][0]={dp[i-1][0][0].first+l-pre[i],l-pre[i]};
		dp[i][0][1]={dp[i][0][0].first,dp[i][0][0].second*2};
	}
	rep(i,1,sz(suf)){
		dp[0][i][1]={dp[0][i-1][1].first+suf[i]-l,suf[i]-l};
		dp[0][i][0]={dp[0][i][1].first,dp[0][i][1].second*2};
	}
	rep(i,1,sz(pre)){
		rep(j,1,sz(suf)){
			dp[i][j][0]={1e11,1e11};
			assert(suf[j]-suf[j-1]>=0);
			assert(pre[i-1]-pre[i]>=0);
			assert(suf[j]-pre[i]>=0);
			pll te={dp[i-1][j][0].first+dp[i-1][j][0].second+pre[i-1]-pre[i],dp[i-1][j][0].second+pre[i-1]-pre[i]};
			dp[i][j][0]=bt(dp[i][j][0],te,n-i-j);
			te={dp[i][j-1][0].first+dp[i][j-1][0].second+suf[j]-pre[i],dp[i][j-1][0].second+suf[j]-pre[i]+suf[j]-pre[i]};
			dp[i][j][0]=bt(dp[i][j][0],te,n-i-j);
			te={dp[i-1][j][1].first+dp[i-1][j][1].second+suf[j]-pre[i],dp[i-1][j][1].second+suf[j]-pre[i]};
			dp[i][j][0]=bt(dp[i][j][0],te,n-i-j);
			te={dp[i][j-1][1].first+dp[i][j-1][1].second+suf[j]-suf[j-1],dp[i][j-1][1].second+suf[j]-suf[j-1]+suf[j]-pre[i]};
			dp[i][j][0]=bt(dp[i][j][0],te,n-i-j);
			dp[i][j][1]={1e11,1e11};
			te={dp[i-1][j][0].first+dp[i-1][j][0].second+pre[i-1]-pre[i],dp[i-1][j][0].second+pre[i-1]-pre[i]+suf[j]-pre[i]};
			dp[i][j][1]=bt(dp[i][j][1],te,n-i-j);
			te={dp[i][j-1][0].first+dp[i][j-1][0].second+suf[j]-pre[i],dp[i][j-1][0].second+suf[j]-pre[i]};
			dp[i][j][1]=bt(dp[i][j][1],te,n-i-j);
			te={dp[i-1][j][1].first+dp[i-1][j][1].second+suf[j]-pre[i],dp[i-1][j][1].second+suf[j]-pre[i]+suf[j]-pre[i]};
			dp[i][j][1]=bt(dp[i][j][1],te,n-i-j);
			te={dp[i][j-1][1].first+dp[i][j-1][1].second+suf[j]-suf[j-1],dp[i][j-1][1].second+suf[j]-suf[j-1]};
			dp[i][j][1]=bt(dp[i][j][1],te,n-i-j);
		}
	}
	prl(min(dp[sz(pre)-1][sz(suf)-1][0].first,dp[sz(pre)-1][sz(suf)-1][1].first));
	return 0;
}