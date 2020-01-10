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
const int MAXN=401;
lli arr[MAXN];
lli dp[MAXN][MAXN][MAXN];
lli best[MAXN][MAXN];
lli MAXV=1e13;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    sc(n,k);
    rep(i,1,n+1)sc(arr[i]);
    rep(i,1,n+1){
    	rep(j,0,k+1){
    		best[i][j]=MAXV;
    		rep(l,0,n+1){
				dp[i][j][l]=min((arr[i]<=arr[l]?dp[i-1][j][l]+arr[l]-arr[i]:LLONG_MAX),min((j==k||arr[i]>arr[l]?LLONG_MAX:best[i-1][j+1]+arr[l]-arr[i]),MAXV));
				best[i][j]=min(best[i][j],dp[i][j][l]);
    		}
    	}
    }
    lli ans=MAXV;
	rep(j,0,k+1)rep(l,0,n+1){
    	ans=min(ans,dp[n][j][l]);
    }
    prl(ans);
    return 0;
}