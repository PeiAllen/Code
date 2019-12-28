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
const int MAXN=201;
lli mod=1e9+7;
vector<pii> matrix[MAXN];
lli dp[MAXN][2][MAXN];
bool done[MAXN];
lli ans[MAXN];
lli te[2][MAXN];
lli teans[MAXN];
int n,w,m;
void dfs(int loc){
	done[loc]=true;
	dp[loc][1][1]=1;
	dp[loc][0][0]=1;
	for(auto x:matrix[loc]){
		dfs(x.first);
		rep(i,0,2)rep(j,0,w+1)te[i][j]=dp[loc][i][j],dp[loc][i][j]=0;
		rep(i,0,2)rep(j,0,w+1){
			rep(a,0,2){
				if(i==0||x.second==a)for(int b=0;b<=w-j;b++){
					dp[loc][i][j+b]=(dp[loc][i][j+b]+(te[i][j]*dp[x.first][a][b]%mod))%mod;
				}
			}
		}
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,w,m);
    int a,b;
    char c;
    rep(i,0,m){
    	sc(c,a,b);
    	matrix[a].push_back({b,(c=='D'?1:0)});
    }
    ans[0]=1;
    rep(i,1,n+1){
    	if(!done[i]){
    		dfs(i);
    		rep(j,0,w+1)teans[j]=ans[j],ans[j]=0;
		    rep(j,0,w+1){
			    rep(a,0,2){
				    for(int b=0;b<=w-j;b++){
				    	ans[j+b]=(ans[j+b]+(teans[j]*dp[i][a][b]%mod))%mod;
				    }
			    }
		    }
    	}
    }
    prl(ans[w]);
    return 0;
}