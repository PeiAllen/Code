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
const int MAXN=1e6+1;
vector<int> matrix[MAXN];
int dist[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    sc(n,m);
    int a,b;
    rep(i,0,m){
    	sc(a,b);
    	matrix[a].push_back(b);
    	matrix[b].push_back(a);
    }
    int s,t;
    sc(s,t);
    rep(i,1,n+1)dist[i]=-1;
    dist[s]=0;
	queue<int> q;
	q.push(s);
	while(sz(q)){
		int cur=q.front();
		q.pop();
		for(int x:matrix[cur]){
			if(dist[x]==-1){
				dist[x]=dist[cur]+1;
				q.push(x);
			}
		}
	}
	prl(m-dist[t]);
    return 0;
}