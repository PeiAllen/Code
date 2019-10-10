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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    string s;
    sc(s);
    int arr[n+1];
    arr[0]=0;
    rep(i,1,n+1)arr[i]=(s[i-1]=='A'?1:0);
    int extend[n+1][2];
    int dp[n+1];
    extend[1][0]=-1;
	extend[1][1]=-1;
	extend[1][arr[1]]=2;
    rep(i,2,n+1){
	    extend[i][0]=-1;
	    extend[i][1]=-1;
    	if(extend[i-1][arr[i]]==-1){
		    extend[i][arr[i]]=i+1;
		    dp[i]=-1;
    	}
    	else{

    	}
    }
    return 0;
}