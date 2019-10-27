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
const int MAXN=18;
lli matrix[MAXN][MAXN];
lli dist[MAXN][(1<<16)];
int shift[18];
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	sc(n,m);
	int cars=n/5+(n%5?1:0);
	rep(i,0,18){
		shift[i]=(1<<i);
		rep(j,0,18)matrix[i][j]=LLONG_MAX;
	}
	int a,b;
	lli c;
	rep(i,0,m){
		sc(a,b,c);
		matrix[a][b]=min(matrix[a][b],c);
		matrix[b][a]=min(matrix[b][a],c);
	}
	priority_queue<pair<lli,pii>,vector<pair<lli,pii>>,greater<pair<lli,pii>>> q;
	dist[0][shift[n]-1]=0;
	lli dfssfd=1e12;
	rep(i,0,(int)n+2)rep(j,0,(1<<n))dist[i][j]=dfssfd;
	q.push({0,{0,(shift[n])-1}});
	int donies=0;
	while(sz(q)){
		auto cur=q.top();
		q.pop();
		if(cur.first<=dist[cur.second.first][cur.second.second]){
			if(cur.second.first==n+1)donies++;
			if(donies==(1<<n))break;
			for(int i=0;i<=n+1;i++){
				if(matrix[cur.second.first][i]!=LLONG_MAX) {
					int next = cur.second.second;
					lli dis=matrix[cur.second.first][i];
					if (i > 0 && i <= n && cur.second.second & (shift[(i - 1)]))next ^=(shift[(i - 1)]);
					if (cur.first + dis < dist[i][next]) {
						dist[i][next] = cur.first + dis;
						q.push({cur.first + dis, {i, next}});
					}
				}
			}
		}
	}
	rep(i, 0, n) {
		rep(j, 0, (shift[n])) {
			if (j & (shift[i])){
				rep(k,0,n+2) {
					dist[k][j]=min(dist[k][j],dist[k][j^(shift[i])]);
				}
			}
		}
	}
	lli best=LLONG_MAX;
	int te=pow(3,n);
	int ams[3]={};
	int othte;
	bool work=true;
	rep(i,0,te){
		work=true;
		othte=i;
		rep(j,0,3)ams[j]=0;
		rep(j,1,n+1){
			int kl=othte%3;
			ams[kl]+=(shift[(j-1)]);
			if(__builtin_popcount(ams[kl])>5){
				work=false;
				break;
			}
			if((kl)>=cars){
				work=false;
				break;
			}
			othte/=3;
		}
		if(!work)continue;
		lli tebest=0;
		rep(i,0,cars){
			tebest=max(tebest,(lli)__builtin_popcount(ams[i])*(lli)5+dist[n+1][(shift[n])-ams[i]-1]);
		}
		best=min(best,tebest);
	}
	prl(best);
	return 0;
}