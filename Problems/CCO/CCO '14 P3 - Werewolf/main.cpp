#include<bits/stdc++.h>
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
const int MAXN=201;
lli mod=1e9+7;
vector<pair<int,int>> matrix[MAXN];
lli dp[MAXN][MAXN][2];
bool done[MAXN];
void dfs(int loc){
	done[loc]=true;
	for(auto x:matrix[loc]){

	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,w,m;
    sc(n,w,m);
    int a,b;
    char c;
    rep(i,0,m){
    	sc(c,a,b);
    	matrix[a].push_back({b,(c=='D'?1:0)});
    }
    lli ans=1;
    rep(i,1,n+1){
    	if(!done[i]){
    		dfs(i);
    		ans=ans*((dp[i][0]+dp[i][1])%mod)%mod;
    	}
    }
    prl(ans);
    return 0;
}