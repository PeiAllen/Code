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
const int MAXN=101;
int arr[MAXN];
int dp[MAXN][MAXN][MAXN];
int mi[MAXN][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    rep(i,1,n+1){
        sc(arr[i]);
        rep(j,0,n+1) {
            mi[i][j]=101;
            rep(k, 0, n + 1) {
                dp[i][j][k] = 101;
                if (i > 1) {
                    if(k==0&&j)dp[i][j][k] = mi[i-1][j-1]+(arr[i]!=k);
                    else if(k) dp[i][j][k]=dp[i-1][j][k-1]+(arr[i]!=k);
                }
                mi[i][j]=min(mi[i][j],dp[i][j][k]);
            }
        }
        if(i==1){
            dp[i][1][0]=arr[i]!=0;
            mi[i][1]=dp[i][1][0];
        }
    }
    rep(i,1,n+1)prl(mi[n][i]);
    return 0;
}