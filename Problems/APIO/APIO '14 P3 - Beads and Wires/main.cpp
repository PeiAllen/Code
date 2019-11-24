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
const int MAXN=2e5+1;
vector<pii> matrix[MAXN];
int dp[MAXN][2][2];
void dfs(int loc, int parent, int w){
	vector<pii> max11;
	vector<pii> max10;
	int dp01sum=0;
	for(pii x:matrix[loc]){
		if(x.first!=parent){
			dfs(x.first,loc,x.second);
			dp01sum+=dp[x.first][0][1];
			dp[loc][1][1]+=dp[x.first][1][1];
			max11.push_back({-dp[x.first][0][1]+x.second+dp[x.first][1][1],x.first});
			max10.push_back({-dp[x.first][0][1]+x.second+dp[x.first][1][0],x.first});
		}
	}
	sort(max11.begin(),max11.end(),greater<pii>());
	sort(max10.begin(),max10.end(),greater<pii>());
	dp[loc][0]=max(dp0sum,(sz(ifrem)&&parent)?w+dp0sum+ifrem[0]:0);
	dp[loc][1]=max(dp0sum,max(dp1sum,sz(ifrem)>=2?dp0sum+ifrem[0]+ifrem[1]:0));
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    int a,b,c;
    rep(i,1,n){
    	sc(a,b,c);
    	matrix[a].push_back({b,c});
	    matrix[b].push_back({a,c});
    }
    dfs(1,0,0);
    prl(dp[1][1]);
    return 0;
}