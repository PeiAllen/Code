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
vector<pii> matrix[MAXN];
int uppre[MAXN];
int downpre[MAXN];
int valid[MAXN];
int lcat[MAXN][17];
int depth[MAXN];
int n;
lli mod=1e9+7;
lli fix(lli a){
	if(a<0)a+=mod;
	return a%mod;
}
lli fastpow(lli a,lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
void dfs(int loc, int down, int parent,int dep){
	depth[loc]=dep;
	lcat[loc][0]=parent;
	valid[loc]=down;
	for(auto x:matrix[loc]){
		if(x.first!=parent){
			dfs(x.first,x.second,loc,dep+1);
		}
	}
}
void presum(int loc, int parent){
	for(auto x:matrix[loc]){
		if(x.first!=parent){
			presum(x.first,loc);
			uppre[loc]+=uppre[x.first];
			downpre[loc]+=downpre[x.first];
		}
	}
}
void maketable(){
	for(int i=1;i<17;i++){
		for(int j=1;j<=n;j++){
			lcat[j][i]=lcat[lcat[j][i-1]][i-1];
		}
	}
}
int findlca(int a, int b){
	if(depth[a]<depth[b])swap(a,b);
	int diff=depth[a]-depth[b];
	for(int i=0;i<17;i++){
		if(diff&(1<<i))a=lcat[a][i];
	}
	if(a==b)return a;
	for(int i=16;i>=0;i--){
		if(lcat[a][i]!=lcat[b][i]){
			a=lcat[a][i],b=lcat[b][i];
		}
	}
	return lcat[a][0];
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	sc(n);
	int a,b,c;
	rep(i,1,n){
		sc(a,b,c);
		if(c==0){
			matrix[a].push_back({b,0});
			matrix[b].push_back({a,0});
		}
		else {
			matrix[a].push_back({b, 1});
			matrix[b].push_back({a, 2});
		}
	}
	dfs(1,true,0,0);
	maketable();
	int k;
	sc(k);
	int cur=1;
	int in;
	rep(i,0,k){
		sc(in);
		int lca=findlca(cur,in);
		uppre[cur]+=1;
		uppre[lca]-=1;
		downpre[in]+=1;
		downpre[lca]-=1;
		cur=in;
	}
	presum(1,0);
	lli tot=0;
	rep(i,1,n+1){
		if(valid[i]==1)tot=(tot+fix(fastpow(2,uppre[i])-1))%mod;
		else if(valid[i]==2)tot=(tot+fix(fastpow(2,downpre[i])-1))%mod;
	}
	prl(tot);
	return 0;
}