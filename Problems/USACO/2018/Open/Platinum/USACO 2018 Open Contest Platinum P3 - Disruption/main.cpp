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
const int MAXN=5e4+1;
int disjoint[MAXN];
int par[MAXN][16];
int depth[MAXN];
vector<pii> matrix[MAXN];
int n,m;
int toc[MAXN];
int ans[MAXN];
void dfs(int loc, int parent,int dep, int ind){
	par[loc][0]=parent;
	toc[loc]=ind;
	disjoint[loc]=loc;
	depth[loc]=dep;
	for(auto x:matrix[loc]){
		if(x.first!=parent){
			dfs(x.first,loc,dep+1,x.second);
		}
	}
}
void makelca(){
	for(int i=1;i<16;i++){
		for(int j=1;j<=n;j++){
			par[j][i]=par[par[j][i-1]][i-1];
		}
	}
}
int find(int loc){
	if(disjoint[loc]==loc)return loc;
	return disjoint[loc]=find(disjoint[loc]);
}
int lca(int a, int b){
	if(depth[a]<depth[b])swap(a,b);
	int diff=depth[a]-depth[b];
	for(int i=0;i<16;i++){
		if(diff&(1<<i))a=par[a][i];
	}
	if(a==b)return a;
	for(int i=15;i>=0;i--){
		if(par[a][i]!=par[b][i]){
			a=par[a][i],b=par[b][i];
		}
	}
	return par[a][0];
}
void go(int loc, int end, int toset){
	if(depth[loc]<=depth[end])return;
	ans[toc[loc]]=toset;
	disjoint[loc]=find(par[loc][0]);
	go(disjoint[loc],end,toset);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,m);
    int a,b;
	rep(i,1,n){
		ans[i]=-1;
		sc(a,b);
		matrix[a].push_back({b,i});
		matrix[b].push_back({a,i});
	}
	dfs(1,0,0,-1);
	makelca();
	vector<pair<int,pii>> edges;
	int c;
	rep(i,0,m){
		sc(a,b,c);
		edges.push_back({c,{a,b}});
	}
	sort(edges.begin(),edges.end());
	rep(i,0,m){
		go(find(edges[i].second.first),lca(edges[i].second.first,edges[i].second.second),edges[i].first);
		go(find(edges[i].second.second),lca(edges[i].second.first,edges[i].second.second),edges[i].first);
	}
	rep(i,1,n)prl(ans[i]);
    return 0;
}