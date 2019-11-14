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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    sc(n,k);
    map<int,pii> bestx;
	map<int,pii> besty;
	int from[n];
	pii coords[n];
	int x1,y1;
	sc(x1,y1);
	int in;
	sc(in);
	coords[0]={x1,y1};
	bestx[x1]={in,0};
	besty[y1]={in,0};
	priority_queue<pair<pii,pii>,vector<pair<pii,pii>>,greater<pair<pii,pii>>> q;
	int xin,yin;
	rep(i,1,n){
		sc(xin,yin,in);
		coords[i]={xin,yin};
		if(xin>=x1&&yin>=y1){
			q.push({{xin,yin},{in,i}});
		}
	}
	while(sz(q)){
		auto cur=q.top();
		q.pop();
		int locfrom=-1;
		int best=0;
		if(bestx[cur.first.first].first-k>=besty[cur.first.second].first-k){
			best=bestx[cur.first.first].first-k;
			locfrom=bestx[cur.first.first].second;
		}
		else{
			best=besty[cur.first.second].first-k;
			locfrom=besty[cur.first.second].second;
		}
		if(best<0)continue;
		best+=cur.second.first;
		from[cur.second.second]=locfrom;
		if(cur.second.second==n-1){
			prl(best);
			stack<int> pos;
			pos.push(cur.second.second);
			int came=locfrom;
			while(came!=0){
				pos.push(came);
				came=from[came];
			}
			pos.push(0);
			prl(pos.size());
			while(sz(pos)){
				prl(coords[pos.top()].first,coords[pos.top()].second);
				pos.pop();
			}
			return 0;
		}
		bestx[cur.first.first]=max(bestx[cur.first.first],{best,cur.second.second});
		besty[cur.first.second]=max(besty[cur.first.second],{best,cur.second.second});
	}
    return 0;
}