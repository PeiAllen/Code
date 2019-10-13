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
const int MAXN=6001;
vector<int> matrix[MAXN];
lli am[MAXN];
int lca[MAXN][13];
lli inc[MAXN];
lli amd[MAXN];
lli amu[MAXN];
lli depth[MAXN];
lli down[MAXN];
lli up[MAXN];
int n;
int ao,bo;
void dfs(int loc, int parent, lli dep){
	depth[loc]=dep;
	lca[loc][0]=parent;
	amd[loc]=am[loc];
	for(int x:matrix[loc]){
		if(x!=parent){
			dfs(x,loc,dep+1);
			amd[loc]+=amd[x];
			inc[loc]+=inc[x]+amd[x];
		}
	}
	down[loc]=inc[loc];
}
void dfs2(int loc, int parent){
	if(loc!=1) {
		amu[loc] = amu[parent] + amd[parent] - amd[loc];
		up[loc] = inc[parent] + amu[loc] - inc[loc] - amd[loc];
		inc[loc] += up[loc];
	}
	for(int x:matrix[loc]){
		if(x!=parent){
			dfs2(x,loc);
		}
	}
}
void make(){
	rep(i,1,13){
		rep(j,1,n+1){
			lca[j][i]=lca[lca[j][i-1]][i-1];
		}
	}
}
int getlca(int a, int b){
	if(depth[a]>depth[b])swap(a,b);
	lli diff=depth[b]-depth[a];
	for(lli i=0;i<13;i++){
		if(diff&(1<<i))b=lca[b][i];
	}
	if(a==b)return a;
	for(int i=12;i>=0;i--){
		if(lca[a][i]!=lca[b][i]){
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	ao=a;
	bo=b;
	return lca[a][0];
}
lli check(int a, int b){
	lli ans=inc[a]+inc[b];
	if(depth[a]>depth[b])swap(a,b);
	int telca=getlca(a,b);
	lli od=depth[b];
	lli oa=depth[a];
	lli diff=(depth[b]+depth[a]-depth[telca]*2)/2;
	for(lli i=0;i<13;i++){
		if(diff&(1<<i)){
			b=lca[b][i];
		}
	}
	if(telca==b){
		ans-=down[bo]+amd[bo]*(oa-depth[telca]);
		ans-=down[ao]+amd[ao]*(od-depth[telca]);
		ans-=inc[telca]-down[ao]-down[bo]-amd[ao]-amd[bo]+(amu[telca]+amd[telca]-amd[bo]-amd[ao])*(oa-depth[telca]);
	}
	else{
		ans-=down[b]+amd[b]*(depth[b]+depth[a]-2*depth[telca]);
		int nb=lca[b][0];
		ans-=inc[nb]-down[b]-amd[b]+(amd[nb]+amu[nb]-amd[b])*(od-depth[nb]);
	}
	return ans;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	sc(n);
	int a,b;
	rep(i,1,n+1)sc(am[i]);
	rep(i,1,n){
		sc(a,b);
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	dfs(1,0,0);
	dfs2(1,0);
	make();
	lli ans=LLONG_MAX;
	rep(i,1,n+1){
		rep(j,1,i){
			ans=min(ans,check(i,j));
		}
	}
	prl(ans);
	return 0;
}