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
const int MAXN=1e5;
lli arr[2][MAXN];
int n,m;
lli k;
lli count(lli a){
	lli cnt=0;
	rep(i,0,n){
		cnt+=upper_bound(arr[1],arr[1]+m,(a-1)/arr[0][i])-arr[1];
	}
	return cnt;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,m);
    rep(i,0,n)sc(arr[0][i]);
    rep(i,0,m)sc(arr[1][i]);
    sort(arr[0],arr[0]+n),sort(arr[1],arr[1]+m);
    sc(k);
    k-=1;
    lli lo=arr[0][0]*arr[1][0],hi=arr[0][n-1]*arr[1][m-1];
	while(lo!=hi){
		lli mid=(lo+hi)/2+1;
		if(count(mid)<=k)lo=mid;
		else hi=mid-1;
	}
	prl(lo);
    return 0;
}