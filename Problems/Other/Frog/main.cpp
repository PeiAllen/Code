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
int n;
lli c;
const int MAXN=2e5+1;
int best[MAXN];
int le=0,ri=-1;
lli heights[MAXN];
lli dp[MAXN];
double inter(int a, int b){
	return (double)(dp[b]-dp[a]-pow(heights[a],2)+pow(heights[b],2))/(double)(2*heights[b]-2*heights[a]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,c);
    sc(heights[1]);
    best[++ri]=1;
    rep(i,2,n+1){
    	sc(heights[i]);
    	while(ri-le>=1&&inter(best[le+1],best[le])<=heights[i])le++;
		dp[i]=dp[best[le]]+c+pow(heights[i]-heights[best[le]],2);
		while(ri-le>=1&&inter(best[ri],best[ri-1])>=inter(i,best[ri]))ri--;
		best[++ri]=i;
    }
    prl(dp[n]);
    return 0;
}
//dp[a]+c+pow(heights[i]-heights[a],2)
//dp[a]+c+pow(heights[i]-heights[a],2)>=dp[b]+c+pow(heights[i]-heights[b],2)&&a>=b, then a better forever
//heights[i]^2-2heights[i]heights[a]+heights[a]^2-heights[i]^2+2heights[i]heights[b]-heights[b]^2>=dp[b]-dp[a]
//heights[i](2heights[b]-2heights[a])>=dp[b]-dp[a]-heights[a]^2+heights[b]^2
//heights[i]>=(dp[b]-dp[a]-heights[a]^2+heights[b]^2)/(2heights[b]-2heights[a])