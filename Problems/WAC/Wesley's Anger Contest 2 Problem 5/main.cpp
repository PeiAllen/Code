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
int n,q,f,k;
vector<int> amounts;
lli dp[MAXN][MAXO];
lli dp2[MAXO];
int fuel[MAXN];
pll cash[MAXN];
pll defcash[MAXN];
vector<int> matrix[MAXO];
pair<int,pll> change[MAXO];
pair<int,pair<int,pll>> eulertour[2*MAXO];
lli ans[MAXO];
vector<int> chloc[MAXN];
int ind=0;
pll ch;
int fu,fuelam;
lli casham;
void dfs(int loc, int parent){
	pll old=cash[change[loc].first];
	cash[change[loc].first]=change[loc].second;
	chloc[change[loc].first].push_back(ind);
	eulertour[ind++]={loc,{change[loc]}};
	for(int x:matrix[loc]){
		if(x!=parent)dfs(x,loc);
	}
	cash[change[loc].first]=old;
	chloc[change[loc].first].push_back(ind);
	eulertour[ind++]={0,{change[loc].first,{old}}};
}
int dploc=1;
void rundp(int loc){
	ch=cash[loc];
	fu=fuel[loc];
	rep(l, 1, f + 1)dp2[l] = dp[dploc - 1][l];
	rep(j, 0, sz(amounts)) {
		fuelam=fu * amounts[j];
		casham=ch.second * amounts[j];
		for(int l=f;l>=1;l--){
			dp2[l] =  max(dp2[l], l - fuelam >= 0 ? dp2[l - fuelam] + casham : 0);
		}
	}
	rep(l, 1, f + 1) {
		dp[dploc][l] =  max(dp[dploc - 1][l], l >= fu ? dp2[l - fu] + ch.first : 0);
	}
	dploc++;
}
set<int> done;
void solve(int l, int r){
	if(l==r){
		if(eulertour[l].first==0)return;
		cash[eulertour[l].second.first]=eulertour[l].second.second;
		rundp(eulertour[l].second.first);
		ans[eulertour[l].first]=dp[n][f];
		return;
	}
	int m=(l+r)/2,oldam=dploc;
	rep(i,m+1,r+1){
		int te=lower_bound(chloc[eulertour[i].second.first].begin(),chloc[eulertour[i].second.first].end(),l)-chloc[eulertour[i].second.first].begin();
		if(!done.count(eulertour[i].second.first)&&chloc[eulertour[i].second.first][te]>m){
			done.insert(eulertour[i].second.first);
			if(chloc[eulertour[i].second.first][te-1]==-1)cash[eulertour[i].second.first]=defcash[eulertour[i].second.first];
			else cash[eulertour[i].second.first]=eulertour[chloc[eulertour[i].second.first][te-1]].second.second;
			rundp(eulertour[i].second.first);
		}
	}
	done.clear();
	solve(l,m);
	while(dploc>oldam)dploc--;
	rep(i,l,m+1){
		int te=lower_bound(chloc[eulertour[i].second.first].begin(),chloc[eulertour[i].second.first].end(),m+1)-chloc[eulertour[i].second.first].begin();
		if(!done.count(eulertour[i].second.first)&&(te>=sz(chloc[eulertour[i].second.first])||chloc[eulertour[i].second.first][te]>r)){
			done.insert(eulertour[i].second.first);
			if(chloc[eulertour[i].second.first][te-1]==-1)cash[eulertour[i].second.first]=defcash[eulertour[i].second.first];
			else cash[eulertour[i].second.first]=eulertour[chloc[eulertour[i].second.first][te-1]].second.second;
			rundp(eulertour[i].second.first);
		}
	}
	done.clear();
	solve(m+1,r);
	while(dploc>oldam)dploc--;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	sc(n,q,f,k);
	int am=k-1;
	int inc=1;
	while(am>=inc){
		amounts.push_back(inc);
		am-=inc;
		inc*=2;
	}
	if(am)amounts.push_back(am);
	rep(i,1,n+1){
		sc(fuel[i],defcash[i].first,defcash[i].second);
		cash[i]=defcash[i];
		chloc[i].push_back(-1);
	}
	int in;
	rep(i,1,q+1){
		sc(in,change[i].first,change[i].second.first,change[i].second.second);
		matrix[in].push_back(i);
	}
	for(int x:matrix[0])dfs(x,0);
	rep(i,1,n+1){
		if(sz(chloc[i])==1){
			rundp(i);
		}
	}
	solve(0,ind-1);
	rep(i,1,q+1)prl(ans[i]);
	return 0;
}