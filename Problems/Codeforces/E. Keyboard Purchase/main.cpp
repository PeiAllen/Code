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
pair<lli,vector<int>> dp[(1<<20)];
lli am[21][21];
lli mut[21][21][24];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,m;
	sc(n,m);
	string s;
	sc(s);
	rep(i,0,n-1){
		am[s[i]-'a'][s[i+1]-'a']+=1;
		am[s[i+1]-'a'][s[i]-'a']+=1;
	}
	rep(i,0,m)rep(j,0,m)rep(k,0,24){
		mut[i][j][k]=am[i][j]*k;
	}
	dp[0]={0,{}};
	vector<int> te2;
	rep(i,1,(1<<m)){
		dp[i]={LLONG_MAX,{}};
		te2.resize(__builtin_popcount(i));
		rep(j,0,m){
			if(i&(1<<j)){
				int oth=i^(1<<j);
				lli te=dp[oth].first;
				te2[0]=j;
				rep(k,0,sz(dp[oth].second)){
					te+=mut[j][dp[oth].second[k]][k+1];
					te2[k+1]=dp[oth].second[k];
				}
				if(te<dp[i].first){
					dp[i]={te,te2};
				}
				te=dp[oth].first;
				te2[sz(te2)-1]=j;
				rep(k,sz(dp[oth].second),0){
					te+=mut[j][dp[oth].second[k]][sz(dp[oth].second)-k];
					te2[sz(dp[oth].second)-k-1]=dp[oth].second[k];
				}
				if(te<dp[i].first){
					dp[i]={te,te2};
				}
			}
		}
	}
	prl(dp[(1<<m)-1].first);
    return 0;
}