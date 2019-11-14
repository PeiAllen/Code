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
lli dp[1048576];
lli mod=1e9;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    vector<pii> arr;
    arr.push_back({-1,-1});
    rep(i,1,n+1){
    	rep(j,i+1,n+1){
    		if(__gcd(i,j)==1){
    			arr.push_back({i,j});
    		}
    	}
    }
    dp[0]=1;
    rep(i,1,sz(arr)){
    	rep(j,(1<<n),0){
    		if(dp[j]) {
			    int willfix = ((1 << (arr[i].second - arr[i].first)) - 1) << arr[i].first;
			    int newind = j | willfix;
			    dp[newind] = (dp[newind] + dp[j]) % mod;
		    }
    	}
    }
    prl(dp[(1<<n)-2]);
    return 0;
}