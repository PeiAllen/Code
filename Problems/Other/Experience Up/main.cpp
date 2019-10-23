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
lli dp[(int)5e5+1][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    lli in;
    sc(in);
    dp[1][0]=in,dp[1][1]=in;
    rep(i,2,n+1){
    	sc(in);
    	dp[i][0]=max(dp[i-1][0]-in,max(in-dp[i-1][1],max(dp[i-1][1]-in,in-dp[i-1][0])));
    	dp[i][1]=min(dp[i-1][0]-in,min(in-dp[i-1][1],min(dp[i-1][1]-in,in-dp[i-1][0])));
    }
    prl(max(dp[n][0],dp[n][1]));
    return 0;
}