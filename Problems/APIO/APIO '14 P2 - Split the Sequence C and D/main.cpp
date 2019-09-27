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
const int MAXN=1e5+1;
lli arr[MAXN];
int from[200][MAXN];
int ret[2][MAXN];
lli dp[2][MAXN];
int cur=1,oth=0;
int curind=0;
int n,k;
void run(int l, int r, int lm,int rm){
	if(r<l)return;
	int mid=(l+r)/2;
	dp[cur][mid]=-1;
	rep(i,lm,min(mid,rm)+1){
		if(dp[oth][i-1]+(arr[mid]-arr[i-1])*(arr[n]-arr[mid])>dp[cur][mid]){
			dp[cur][mid]=dp[oth][i-1]+(arr[mid]-arr[i-1])*(arr[n]-arr[mid]);
			from[curind][mid]=ret[oth][i-1];
			ret[cur][mid]=mid;
		}
	}
	if(l!=r){
		run(l,mid-1,lm,from[curind][mid]+1),run(mid+1,r,from[curind][mid]+1,rm);
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,k);
    rep(i,1,n+1){
    	sc(arr[i]);
    	arr[i]+=arr[i-1];
    }
    for(curind=0;curind<k;curind++){
    	dp[cur][0]=-1;
    	run(1,n-1,curind+1,n-1);
    	rep(i,1,n){
    		if(dp[cur][i-1]>dp[cur][i]){
			    dp[cur][i]=dp[cur][i-1];
			    ret[cur][i]=ret[cur][i-1];
    		}
    	}
    	cur=oth;
    	oth=(oth+1)%2;
    }
    prl(dp[oth][n-1]);
    stack<int> points;
    int loc=ret[oth][n-1];
    rep(i,k,0){
    	points.push(loc);
    	loc=from[i][loc];
    }
    rep(i,0,k){
    	pr(points.top(),"");
    	points.pop();
    }
    return 0;
}