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
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
map<int,lli> dp[MAXN];
pll val[MAXN];
int uni(int a, int b){
	if(sz(dp[a])<sz(dp[b]))swap(a,b);
	for(auto x:dp[b]){
		dp[a][x.first]+=x.second;
	}
	dp[b].clear();
	return a;
}
int dfs(int loc, int parent){
	int cur=loc;
	for(int x:matrix[loc]){
		if(x!=parent){
			int te=dfs(x,loc);
			cur=uni(cur,te);
		}
	}
	if(val[loc].first){
		dp[cur][val[loc].first]+=val[loc].second;
		auto it=dp[cur].find(val[loc].first);
		it++;
		vector<int> todel;
		for(;it!=dp[cur].end();it++){
			lli am=min(val[loc].second,it->second);
			val[loc].second-=am;
			it->second-=am;
			if(it->second==0)todel.push_back(it->first);
			if(val[loc].second==0)break;
		}
		for(int x:todel)dp[cur].erase(x);
	}
	return cur;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    sc(n,m,k);
    int a,b;
    rep(i,2,n+1){
		sc(a);
		matrix[a].push_back(i);
		matrix[i].push_back(a);
    }
    lli c;
    rep(i,0,m){
    	sc(a,b,c);
    	val[a]={b,c};
    }
    int loc=dfs(1,0);
    lli ans=0;
    for(auto x:dp[loc]){
    	ans+=x.second;
    }
    prl(ans);
    return 0;
}