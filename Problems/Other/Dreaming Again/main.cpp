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
const int MAXN=3e5+1;
vector<pair<int,lli>> matrix[MAXN];
/*
dp[u][0]=0
dp[u][1]=-constant originially
dp[u][2]=MINVAL
Mxv=max( dp[v][0], dp[v][1], dp[v][2] )
dp[u][0]=max{dp[u][0],dp[u][0]+Maxv}
dp[u][1]=max{dp[u][1],dp[u][1]+Mxv,dp[u][0]+<u,v>+dp[v][1]}
dp[u][2]=max{dp[u][2],dp[u][2]+Mxv,dp[u][1]+<u,v>+dp[v][1]+constant}
if(pathlength<=k)Return max(dp[1][0]+(paths*constant),dp[1][1]+(paths*constant),dp[1][2]+(paths*constant))
 */
pair<lli,int> mxv[MAXN];
pair<lli,int> oneedge[MAXN];
lli constant;
lli MINVAL=-1e15;
void dfs(int cur, pair<int,lli> par){
	pair<lli,int> arr[3]={{0,0},{-constant,-1},{MINVAL,0}};
	for(auto x:matrix[cur]){
		if(x.first!=par.first){
			dfs(x.first,{cur,x.second});
			arr[2]=max(arr[2],max(make_pair(arr[2].first+mxv[cur].first,arr[2].second+mxv[cur].second),make_pair(arr[1].first+oneedge[cur].first+constant,arr[1].second+oneedge[cur].second+1)));
			arr[1]=max(arr[1],max(make_pair(arr[1].first+mxv[cur].first,arr[1].second+mxv[cur].second),make_pair(arr[0].first+oneedge[cur].first,arr[0].second+oneedge[cur].second)));
			arr[0]=max(arr[0],make_pair(arr[0].first+mxv[cur].first,arr[0].second+mxv[cur].second));
		}
	}
	mxv[par.first]={max(arr[0],max(arr[1],arr[2]))};
	oneedge[par.first]={arr[1].first+par.second,arr[1].second};
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,k;
	sc(n,k);
	int a,b;
	lli c;
	rep(i,1,n){
		sc(a,b,c);
		matrix[a].push_back({b,c});
		matrix[b].push_back({a,c});
	}
	lli lo=0;
	lli hi=1e12;
	while(lo!=hi){

	}
    return 0;
}