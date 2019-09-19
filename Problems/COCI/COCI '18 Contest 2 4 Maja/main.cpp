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
int xdir[4]={1,-1,0,0};
int ydir[4]={0,0,1,-1};
lli dp[2][101][101];
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m,a,b,k;
	sc(n,m,a,b,k);
	a-=1,b-=1;
	lli arr[n][m];
	rep(i,0,n)rep(j,0,m)sc(arr[i][j]),dp[0][i][j]=-1,dp[1][i][j]=-1;
	dp[0][a][b]=arr[a][b];
	int ind=1,othind=0;
	lli ans=0;
	rep(d,(lli)1,(lli)n*m) {
		if(d*2>k)break;
		bool cont=true;
		if((k-2*d)%2)cont=false;
		lli thingy=(k-2*d)/2;
		rep(i, 0, n)rep(j, 0, m) {
				if(abs(i-a)+abs(j-b)>d||(abs(i-a)+abs(j-b))%2!=d%2)continue;
				rep(w, 0, 4) {
					pii oth = {i + xdir[w], j + ydir[w]};
					if (oth.first >= 0 && oth.first < n && oth.second >= 0 && oth.second < m) {
						dp[ind][i][j] = max(dp[ind][i][j], dp[othind][oth.first][oth.second] + arr[i][j]);
					}
				}
				if(cont)if(dp[ind][i][j]!=-1)rep(w,0,4){
					pii oth={i+xdir[w],j+ydir[w]};
					if(oth.first>=0&&oth.first<n&&oth.second>=0&&oth.second<m) {
						ans=max(ans,dp[ind][i][j]*2+arr[oth.first][oth.second]*thingy+arr[i][j]*(thingy-1));
					}
				}
			}
		othind=ind;
		ind=(ind+1)%2;
	}
	prl(ans);
	return 0;
}