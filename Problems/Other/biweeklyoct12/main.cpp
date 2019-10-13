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
vector<pll> matrix[2001];
lli dist[2001][2001];
void dfs(lli loc, lli parent, lli dis, lli fr){
	dist[fr][loc]=dis;
	for(pll x:matrix[loc]){
		if(x.first!=parent){
			dfs(x.first,loc,dis+x.second,fr);
		}
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    sc(n,k);
    lli a,b,c;
    rep(i,1,n){
    	sc(a,b,c);
    	matrix[a].push_back({b,c});
    	matrix[b].push_back({a,c});
    }
    rep(i,1,n+1){
    	dfs(i,0,0,i);
    }
	lli cur=(1<<k)-1;
    rep(i,0,n-k+1){
    	rep(j,0,)
    }
    return 0;
}