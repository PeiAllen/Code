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
const int MAXN=5e3+1;
vector<int> matrix[MAXN];
int depth[MAXN];
int parent[MAXN];
bool done[MAXN];
int n,s;
void dfs(int loc, int par, int dep){
	depth[loc]=dep;
	parent[loc]=par;
	for(int x:matrix[loc]){
		if(x!=par){
			dfs(x,loc,dep+1);
		}
	}
}
void mark(int loc, int par, int left){
	done[loc]=true;
	if(!left)return;
	for(int x:matrix[loc]){
		if(x!=par)mark(x,loc,left-1);
	}
}
bool check(int dist){
	priority_queue<pii> q;
	rep(i,1,n+1){
		q.push({depth[i],i});
		done[i]=false;
	}
	int am=0;
	while(sz(q)){
		pii cur=q.top();
		q.pop();
		if(done[cur.second])continue;
		am++;
		int te=dist;
		while(parent[cur.second]&&te--)cur.second=parent[cur.second];
		mark(cur.second,0,dist);
	}
	return am<=s;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	sc(n,s);
	int a,b;
	rep(i,1,n){
		sc(a,b);
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	dfs(1,0,0);
	int lo=0;
	int hi=n-1;
	while(lo!=hi){
		int mid=(lo+hi)/2;
		if(check(mid))hi=mid;
		else lo=mid+1;
	}
	prl(lo);
    return 0;
}