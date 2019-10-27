#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
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
const int MAXO=3001;
lli dp[MAXN][MAXO];
lli dp2[MAXO];
int fuel[MAXN];
pll cash[MAXN];
vector<int> matrix[MAXO];
pair<int,pll> change[MAXO];
pair<int,pair<int,pll>> eulertour[2*MAXO];
int ind=0;
void dfs(int loc, int parent){
	pll old=cash[change[loc].first];
	cash[change[loc].first]=change[loc].second;
	eulertour[ind++]={loc,{change[loc]}};
	for(int x:matrix[loc]){
		if(x!=parent)dfs(x,loc);
	}
	cash[change[loc].first]=old;
	eulertour[ind++]={0,{change[loc].first,{old}}};
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,q,f,k;
	sc(n,q,f,k);
	vector<int> amounts;
	int am=k-1;
	int inc=1;
	while(am>=inc){
		amounts.push_back(inc);
		am-=inc;
		inc*=2;
	}
	if(am)amounts.push_back(am);
	rep(i,1,n+1){
		sc(fuel[i],cash[i].first,cash[i].second);
	}
	int in;
	rep(i,1,q+1){
		sc(in,change[i].first,change[i].second.first,change[i].second.second);
		matrix[in].push_back(i);
	}
	for(int x:matrix[0])dfs(x,0);
	int loc=0;
	int block=max(1,(int)sqrt(0.25*q));
	lli ans[q+1];
	int fuelam;
	lli casham;
	int endq=2*q;
	int end;
	while(loc<=endq){
		end=min(loc+block,endq+1);
		set<int> routes;
		vector<int> todo;
		rep(i,1,n+1)routes.insert(i);
		rep(i,loc,end){
			if(routes.count(eulertour[i].second.first))todo.push_back(eulertour[i].second.first);
			routes.erase(eulertour[i].second.first);
		}
		int i=1;
		for(int x:routes){
			rep(l, 1, f + 1)dp2[l] = dp[i - 1][l];
			rep(j, 0, sz(amounts)) {
				fuelam=fuel[x] * amounts[j];
				casham=cash[x].second * amounts[j];
				for(int l=f;l>=1;l--){
					dp2[l] =  max(dp2[l], l - fuelam >= 0 ? dp2[l - fuelam] + casham : 0);
				}
			}
			rep(l, 1, f + 1) {
				dp[i][l] =  max(dp[i - 1][l], l >= fuel[x] ? dp2[l - fuel[x]] + cash[x].first : 0);
			}
			i++;
		}
		int te=i;
		rep(cur,loc,end){
			cash[eulertour[cur].second.first]=eulertour[cur].second.second;
			i=te;
			for(int x:todo){
				rep(l, 1, f + 1)dp2[l] = dp[i - 1][l];
				rep(j, 0, sz(amounts)) {
					fuelam=fuel[x] * amounts[j];
					casham=cash[x].second * amounts[j];
					for(int l=f;l>=1;l--){
						dp2[l] =  max(dp2[l], l - fuelam >= 0 ? dp2[l - fuelam] + casham : 0);
					}
				}
				rep(l, 1, f + 1) {
					dp[i][l] = max(dp[i - 1][l], l >= fuel[x] ? dp2[l - fuel[x]] + cash[x].first : 0);
				}
				i++;
			}
			ans[eulertour[cur].first]=dp[n][f];
		}
		loc=end;
	}
	rep(i,1,q+1)prl(ans[i]);
	return 0;
}