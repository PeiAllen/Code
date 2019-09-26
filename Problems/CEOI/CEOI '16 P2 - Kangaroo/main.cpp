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
lli dp[2001][2001];
lli mod=1e9+7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b;
    sc(n,a,b);
    dp[0][0]=1;
	rep(i,1,n+1){
		rep(j,0,i+1){
			if(i==a||i==b){
				// become own block(doesn't add to counter special) then join one block, since youre larger. and need to be beginning
				dp[i][j]=(dp[i-1][j]+(dp[i-1][j+1]*(j+1)%mod))%mod;
			}
			else{
				// become own block then merge two blocks, since youre larger than both numbers
				dp[i][j]=((j>0?dp[i-1][j-1]:0)+(dp[i-1][j+1]*((((j+1)*j%mod)/*left and right block*/+(j+1)*(i>a)+(j+1)*(i>b)/*combine with start and end blocks, since they don't add to blockcount*/)%mod)%mod))%mod;
			}
		}
	}
	prl(dp[n][0]);
    return 0;
}
/*
 * old things
 * dp[i][j][0]=(dp[i][j-1][0]+dp[i-1][j-1][1])%mod;
			dp[i][j][1]=(dp[i][j-1][1]+make(dp[i-1][i-1][0]-dp[i-1][j-1][0]))%mod;
	dp[0][a][0]=1;
	dp[0][a][1]=1;
	rep(i,1,n+1){
		dp[0][i][0]=(dp[0][i][0]+dp[0][i-1][0])%mod;
		dp[0][i][1]=(dp[0][i][1]+dp[0][i-1][1])%mod;
	}
    rep(i,1,n){
		rep(j,1,n+1){
			dp[i][j][0]=(dp[i][j-1][0]+make(dp[i-1][j-1][1]-((lli)(j-1)*(i>=2?make(dp[i-2][j][0]-dp[i-2][j-1][0]):0)%mod)))%mod;
			dp[i][j][1]=(dp[i][j-1][1]+make(dp[i-1][n][0]-dp[i-1][j][0]-((lli)(n-j)*(i>=2?make(dp[i-2][j][1]-dp[i-2][j-1][1]):0)%mod)))%mod;
		}
    }
    prl((make(dp[n-1][b][0]-dp[n-1][b-1][0])+make(dp[n-1][b][1]-dp[n-1][b-1][1]))%mod);
 */