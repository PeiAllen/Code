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
lli dist[26][26];
lli shortest[26];
lli am[MAXN][26];
lli dp[MAXN][26];
lli which[MAXN];
lli LMAX=1e16;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("cowmbat.in","r",stdin);
	freopen("cowmbat.out","w",stdout);
	lli n,m,k;
	sc(n,m,k);
	string s;
	sc(s);
	rep(i,1,n+1){
		which[i]=s[i-1]-'a';
		rep(j,0,m){
			am[i][j]=am[i-1][j];
		}
		am[i][s[i-1]-'a']+=1;
	}
	rep(i,0,m)rep(j,0,m)sc(dist[i][j]);
	rep(i,0,m){
			rep(j,0,m)shortest[j]=LMAX;
			priority_queue<pii,vector<pii>,greater<pii>> q;
			shortest[i]=0;
			q.push({0,i});
			while(sz(q)){
				auto cur=q.top();
				q.pop();
				if(shortest[cur.second]>=cur.first){
					rep(j,0,m){
						if(dist[cur.second][j]+cur.first<shortest[j]){
							shortest[j]=dist[cur.second][j]+cur.first;
							q.push({dist[cur.second][j]+cur.first,j});
						}
					}
				}
			}
			rep(j,0,m)dist[i][j]=shortest[j];
		}
	rep(i,1,k)rep(j,0,m)dp[i][j]=LMAX;
	rep(i,k,n+1){
		rep(j,0,m){
			lli toadd=0;
			rep(p,0,m){
				toadd+=dist[p][j]*(am[i][p]-am[i-k][p]);
			}
			dp[i][j]=LMAX;
			rep(l,0,m){
				dp[i][j]=min(dp[i][j],dp[i-k][l]+toadd);
			}
			dp[i][j]=min(dp[i][j],dp[i-1][j]+dist[which[i]][j]);
		}
	}
	lli ans=LMAX;
	rep(i,0,m){
		ans=min(ans,dp[n][i]);
	}
	prl(ans);
	return 0;
}