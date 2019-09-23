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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
double dp[101][101][201];
double run(int *hp,int *atk, int *def,double *ac,int moves){
	if(hp[0]<=0)return 0;
	if(hp[1]<=0)return 1;
	if(moves==200)return 0.5;
	if(dp[hp[0]][hp[1]][moves]!=-1)return dp[hp[0]][hp[1]][moves];
	double ans=0;
	int player=moves%2;
	ans+=run(hp,atk,def,ac,moves+1)*((double)1-ac[player]/20);
	for(int i=1;i<=8;i++){
		hp[!player]-=atk[player]+i-def[!player];
		ans+=run(hp,atk,def,ac,moves+1)*(ac[player]/20)/8;
		hp[!player]+=atk[player]+i-def[!player];
	}
	return dp[hp[0]][hp[1]][moves]=ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int hp[2],atk[2],def[2],n;
	double ac[2];
	sc(hp[0],atk[0],def[0],ac[0],n);
	while(n--){
		memset(dp,-1,sizeof(dp));
		sc(hp[1],atk[1],def[1],ac[1]);
		prl(run(hp,atk,def,ac,0));
	}
    return 0;
}