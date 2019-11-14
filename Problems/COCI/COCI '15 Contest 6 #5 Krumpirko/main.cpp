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
double dp[101][101][501];
int am[101];
double cost[101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,l;
	sc(n,l);
	int tot=0;
	double totcost=0;
	rep(i,1,n+1){
		sc(am[i]);
		tot+=am[i];
	}
	rep(i,1,n+1){
		sc(cost[i]);
		totcost+=cost[i];
	}
	rep(j,0,n+1) {
		rep(k, 0, tot + 1) {
			dp[0][j][k]=DBL_MAX;
		}
	}
	dp[0][0][0]=0;
	rep(i,1,n+1){
		rep(j,0,n+1){
			 rep(k,0,tot+1){
				dp[i][j][k]=min(dp[i-1][j][k],(k>=am[i]?dp[i-1][j-1][k-am[i]]+cost[i]:DBL_MAX));
			 }
		}
		dp[i][0][0]=0;
	}
	double best=DBL_MAX;
	rep(k,1,tot+1){
		if(dp[n][l][k]!=DBL_MAX){
			best=min(best,((totcost-dp[n][l][k])*dp[n][l][k])/((tot-k)*k));
		}
	}
	rep(k,1,tot+1){
		if(dp[n][n-l][k]!=DBL_MAX){
			best=min(best,((totcost-dp[n][n-l][k])*dp[n][n-l][k])/((tot-k)*k));
		}
	}
	printf("%.3f\n",best);
    return 0;
}