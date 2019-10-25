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
const int MAXN=501;
const int MAXO=5001;
lli dp[MAXN][MAXO];
pair<lli,int> dp2[MAXN][MAXO];
int fuel[MAXN];
pll cash[MAXN];
vector<int> matrix[MAXO];
pair<int,pll> change[MAXO];
pair<int,pair<int,pll>> eulertour[2*MAXO];
int ind=0;
void dfs(int loc, int parent){
	pll old=cash[change[loc].first];
	cash[change[loc].first]=change[loc].second;
	eulertour[ind++]={loc,{change[loc]}};
	for(int x:matrix[loc]){
		if(x!=parent)dfs(x,loc);
	}
	cash[change[loc].first]=old;
	eulertour[ind++]={0,{change[loc].first,{old}}};
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,q,f,k;
	sc(n,q,f,k);
	rep(i,1,n+1)sc(fuel[i],cash[i].first,cash[i].second);
	int in;
	rep(i,1,q+1){
		sc(in,change[i].first,change[i].second.first,change[i].second.second);
		matrix[in].push_back(i);
	}
	for(int x:matrix[0])dfs(x,0);
	int loc=0;
	int block=sqrt(2*q);
	lli ans[q+1];
	while(loc<=2*q){
		int end=min(loc+block,2*q+1);
		set<int> routes;
		set<int> todote;
		rep(i,1,n+1)routes.insert(i);
		rep(i,loc,end){
			routes.erase(eulertour[i].second.first);
			todote.insert(eulertour[i].second.first);
		}
		int i=1;
		for(int x:routes){
			rep(j,1,f+1){
				dp2[i][j]=max(dp2[i][j-1],max({dp[i-1][j],0},j>=fuel[x]?max({dp[i-1][j-fuel[x]]+cash[x].second,1},(dp2[i][j-fuel[x]].second==k-1?make_pair(cash[x].second*(k-1)+dp[i-1][j-fuel[x]*(k-1)],(k-1)):make_pair(dp2[i][j-fuel[x]].first+cash[x].second,dp2[i][j-fuel[x]].second+1))):make_pair((lli)0,0)));
				dp[i][j]=max(dp[i][j-1],max(dp[i-1][j],j>=fuel[x]?dp2[i][j-fuel[x]].first+cash[x].first:0));
			}
			i++;
		}
		vector<int> todo;
		for(int x:todote)todo.push_back(x);
		rep(cur,loc,end){
			cash[eulertour[cur].second.first]=eulertour[cur].second.second;
			i=sz(routes)+1;
			for(int x:todo){
				rep(j,1,f+1){
					dp2[i][j]=max(dp2[i][j-1],max({dp[i-1][j],0},j>=fuel[x]?max({dp[i-1][j-fuel[x]]+cash[x].second,1},(dp2[i][j-fuel[x]].second==k-1?make_pair(cash[x].second*(k-1)+dp[i-1][j-fuel[x]*(k-1)],(k-1)):make_pair(dp2[i][j-fuel[x]].first+cash[x].second,dp2[i][j-fuel[x]].second+1))):make_pair((lli)0,0)));
					dp[i][j]=max(dp[i][j-1],max(dp[i-1][j],j>=fuel[x]?dp2[i][j-fuel[x]].first+cash[x].first:0));
				}
				i++;
			}
			ans[eulertour[cur].first]=dp[n][f];
		}
		loc=end;
	}
	rep(i,1,q+1)prl(ans[i]);
    return 0;
}