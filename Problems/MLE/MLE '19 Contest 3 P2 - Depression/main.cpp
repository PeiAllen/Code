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
vector<lli> vals;
vector<vector<pair<int,lli>>> matrix;
pll run(int loc, int parent){
	pll cur={vals[loc],(vals[loc]%(lli)2?vals[loc]*(lli)2:vals[loc])};
	for(auto x:matrix[loc]){
		if(x.first!=parent){
			auto ch=run(x.first,loc);
			cur.first+=min(ch.first+((lli)__gcd(vals[x.first],vals[loc])==(lli)1?x.second:(lli)0),ch.second+((lli)__gcd(vals[x.first]*(lli)2,vals[loc])==(lli)1?x.second:(lli)0));
			cur.second+=min(ch.first+((lli)__gcd(vals[x.first],vals[loc]*(lli)2)==(lli)1?x.second:(lli)0),ch.second);
		}
	}
	return cur;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	vals.resize(n+1);
	matrix.resize(n+1);
	rep(i,1,n+1){
		sc(vals[i]);
	}
	int a,b;
	lli c;
	rep(i,1,n){
		sc(a,b,c);
		matrix[a].push_back({b,c});
		matrix[b].push_back({a,c});
	}
	auto te=run(1,0);
	prl(min(te.first,te.second));
    return 0;
}