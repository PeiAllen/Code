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
pii planet[MAXN];
pii galaxy[MAXN];
int findp(int a){
	if(planet[a].first==a)return a;
	return planet[a].first=findp(planet[a].first);
}
int findg(int a){
	if(galaxy[a].first==a)return a;
	return galaxy[a].first=findg(galaxy[a].first);
}
void unip(int a, int b){
	int ap=findp(a),bp=findp(b);
	if(planet[ap].second<planet[bp].second)swap(ap,bp);
	planet[bp].first=ap;
	planet[ap].second+=planet[bp].second;
}
void unig(int a, int b){
	int ap=findg(a),bp=findg(b);
	if(galaxy[ap].second<galaxy[bp].second)swap(ap,bp);
	galaxy[bp].first=ap;
	galaxy[ap].second+=galaxy[bp].second;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,m,p,q;
    sc(n,m,p,q);
    rep(i,1,m+1)planet[i]={i,1};
	rep(i,1,n+1)galaxy[i]={i,1};
    lli ans=0;
    int a,b;
    lli c;
    priority_queue<pair<lli,pii>,vector<pair<lli,pii>>,greater<pair<lli,pii>>> qu;
	priority_queue<pair<lli,int>,vector<pair<lli,int>>,greater<pair<lli,int>>> fin;
    rep(i,0,p){
		sc(a,b,c);
		qu.push({c,{a,b}});
		ans+=c*n;
	}
	while(!qu.empty()){
		auto cur=qu.top();
		qu.pop();
		if(findp(cur.second.first)!=findp(cur.second.second)){
			unip(cur.second.first,cur.second.second);
			fin.push({cur.first,0});
		}
	}
	rep(i,0,q){
		sc(a,b,c);
		qu.push({c,{a,b}});
		ans+=c*m;
	}
	while(!qu.empty()){
		auto cur=qu.top();
		qu.pop();
		if(findg(cur.second.first)!=findg(cur.second.second)){
			unig(cur.second.first,cur.second.second);
			fin.push({cur.first,1});
		}
	}
	lli used[2]={};
	lli te=0;
	while(!fin.empty()){
		auto cur = fin.top();
		fin.pop();
		used[cur.second]+=1;
		te+=cur.first*(cur.second?(m-used[0]):(n-used[1]));
	}
	prl(ans-te);
    return 0;
}