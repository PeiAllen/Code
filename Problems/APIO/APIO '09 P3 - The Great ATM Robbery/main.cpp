#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
inline void sc(){}
template<typename T,typename... Args>
inline void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
inline void pr(T a){cout<<a;}
template<typename T,typename... Args>
inline void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
inline void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
inline void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
inline int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int  MAXN=5e5+1;
int n,m;
int matrix[MAXN];
pii matrix2[MAXN];
int matrixg[MAXN];
pii matrix2g[MAXN];
int ind[MAXN];
int low[MAXN];
int id[MAXN];
lli am[MAXN];
lli gam[MAXN];
lli dist[MAXN];
int rs=0;
int st[MAXN];
bool inst[MAXN];
int cur=0;
int icur=1;
void tarjan(int loc){
	ind[loc]=cur++;
	low[loc]=ind[loc];
	inst[loc]=true;
	st[++rs]=loc;
	int xloc=matrix[loc];
	while(xloc!=-1){
		int x=matrix2[xloc].first;
		if(!ind[x])tarjan(x);
		if(inst[x])low[loc]=min(low[loc],low[x]);
		xloc=matrix2[xloc].second;
	}
	if(low[loc]==ind[loc]){
		while(1){
			int cur=st[rs--];
			id[cur]=icur;
			inst[cur]=false;
			if(cur==loc)break;
		}
		icur++;
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,m;
	sc(n,m);
	memset(matrix,-1,sizeof(matrix));
	memset(matrixg,-1,sizeof(matrixg));
	int a,b;
	int r=0,rg=0;
	for(int i=0;i<m;i++){
		sc(a,b);
		matrix2[r]={b,matrix[a]};
		matrix[a]=r++;
	}
	for(int i=1;i<=n;i++)sc(am[i]);
	int s,p;
	sc(s,p);
	tarjan(s);
	for(int i=1;i<=n;i++){
		gam[id[i]]+=am[i];
		int xloc=matrix[i];
		while(xloc!=-1){
			int x=matrix2[xloc].first;
			if(id[i]!=id[x]){
				matrix2g[rg]={id[x],matrixg[id[i]]};
				matrixg[id[i]]=rg++;
			}
			xloc=matrix2[xloc].second;
		}
	}
	priority_queue<pair<lli,int>> q;
	dist[id[s]]=gam[id[s]];
	q.push({gam[id[s]],id[s]});
	while(sz(q)){
		auto cur=q.top();
		q.pop();
		if(cur.first>=dist[cur.second]){
			int xloc=matrixg[cur.second];
			while(xloc!=-1){
				int x=matrix2g[xloc].first;
				if(dist[x]<cur.first+gam[x]){
					dist[x]=cur.first+gam[x];
					q.push({dist[x],x});
				}
				xloc=matrix2g[xloc].second;
			}
		}
	}
	lli best=0;
	while(p--){
		sc(a);
		best=max(best,dist[id[a]]);
	}
	prl(best);
    return 0;
}