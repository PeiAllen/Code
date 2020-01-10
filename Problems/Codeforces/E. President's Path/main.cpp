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
const int MAXN=501;
const int MAXM=124750;
vector<pair<pii,lli>> matrix[MAXN];
vector<bitset<MAXM>> ths;
lli dist[MAXN];
int ans[MAXN];
int cnt;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	sc(n,m);
	int a,b;
	lli c;
	rep(i,0,m){
		sc(a,b,c);
		matrix[a].push_back({{b,i},c});
		matrix[b].push_back({{a,i},c});
	}
	priority_queue<pair<pair<lli,int>,pii>,vector<pair<pair<lli,int>,pii>>,greater<pair<pair<lli,int>,pii>>> q;
	rep(i,1,n){
		cnt=0;
		rep(j,1,n+1)dist[j]=LLONG_MAX,ans[j]=0,ths.clear();
		dist[i]=0;
		ths.emplace_back(0);
		q.push({{0,i},{-1,0}});
		while(sz(q)){
			auto cur=q.top();
			q.pop();
			if(cur.first.first<=dist[cur.first.second]){
				int loc=sz(ths);
				ths.emplace_back(ths[cur.second.second]);
				if(cur.second.first!=-1)ths[loc][cur.second.first]=1;
				while(sz(q)&&q.top().first==cur.first){
					ths[loc]|=ths[q.top().second.second];
					if(q.top().second.first!=-1)ths[loc][q.top().second.first]=1;
					q.pop();
				}
				ans[cur.first.second]=ths[loc].count();
				if(cur.first.second>i)cnt++;
				if(cnt==n-i)break;
				for(auto x:matrix[cur.first.second]){
					if(dist[x.first.first]>=cur.first.first+x.second){
						dist[x.first.first]=cur.first.first+x.second;
						q.push({{cur.first.first+x.second,x.first.first},{x.first.second,loc}});
					}
				}
			}
		}
		while(!q.empty())q.pop();
		rep(j,i+1,n+1){
			pr(ans[j],"");
		}
	}
	return 0;
}