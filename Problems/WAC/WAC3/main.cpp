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
const int MAXN=5001;
pll arr[MAXN];
lli dp[MAXN][MAXN];
lli pre[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    rep(i,1,n+1)sc(arr[i].first,arr[i].second);
    sort(arr+1,arr+n+1);
    rep(i,1,n+1){
        pre[i]=pre[i-1]+arr[i].second;
        dp[i][0]=pre[i-1];
        int fir=(upper_bound(arr+1,arr+n+1,pll{arr[i].first/2,INT_MAX})-arr);
        rep(j,1,fir)dp[i][j]=dp[j][j-1]+pre[i-1]-pre[j];
        rep(j,fir,i){
            int loc=(upper_bound(arr+1,arr+n+1,pll{arr[i].first-arr[j].first,INT_MAX})-arr)-1;
            dp[i][j]=dp[j][loc]+pre[i-1]-pre[j];
        }
        rep(j,1,i)dp[i][j]=min(dp[i][j],dp[i][j-1]);
    }
    lli ans=LLONG_MAX;
    rep(i,1,n+1)ans=min(ans,dp[i][i-1]+pre[n]-pre[i]);
    prl(ans);
    return 0;
}