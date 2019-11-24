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
    lli arr[2][n];
    lli sum[2];
    rep(i,0,2){
    	sum[i]=0;
    	rep(j,0,n){
    		sc(arr[i][j]);
    		sum[i]+=arr[i][j];
    	}
    }
    lli ans=LLONG_MAX;
    rep(i,0,n){
    	if(arr[0][i]&&arr[1][i]){
    		ans=min(ans,sum[0]-arr[0][i]+1+sum[1]-arr[1][i]+1);
    	}
    }
    rep(i,0,(1<<n)){
    	i=14;
		lli atmost=LLONG_MAX;
		lli oth=0;
		rep(j,0,n){
			if(i&(1<<j)){
				if(arr[1][j]&&arr[0][j])atmost=min(atmost,arr[0][j]);
				if(arr[0][j])oth+=arr[1][j];
			}
		}

		if(atmost!=LLONG_MAX)ans=min(ans,sum[0]-atmost+1+sum[1]-oth+1);
		break;
	}
	swap(sum[0],sum[1]);
	rep(i,0,n)swap(arr[0][i],arr[1][i]);
	rep(i,0,(1<<n)){
		lli atmost=LLONG_MAX;
		lli oth=0;
		rep(j,0,n){
			if(i&(1<<j)){
				if(arr[1][j]&&arr[0][j])atmost=min(atmost,arr[0][j]);
				if(arr[0][j])oth+=arr[1][j];
			}
		}
		if(atmost!=LLONG_MAX)ans=min(ans,sum[0]-atmost+1+sum[1]-oth+1);
	}
	rep(i,0,(1<<n)){
		lli atmost=LLONG_MAX;
		lli am=0;
		rep(j,0,n){
			if(arr[1][j]==0)am+=arr[0][j];
			else if(i&(1<<j)){
				am+=arr[0][j];
			}
		}
		rep(j,0,n){
			if(!(i&(1<<j))){
				if(arr[0][j]&&arr[1][j])atmost=min(atmost,arr[1][j]);
			}
		}
		if(atmost!=LLONG_MAX)ans=min(ans,am+1+sum[1]-atmost+1);
	}
	swap(sum[0],sum[1]);
	rep(i,0,n)swap(arr[0][i],arr[1][i]);
	rep(i,0,(1<<n)){
		lli atmost=LLONG_MAX;
		lli am=0;
		rep(j,0,n){
			if(arr[1][j]==0)am+=arr[0][j];
			else if(i&(1<<j)){
				am+=arr[0][j];
			}
		}
		rep(j,0,n){
			if(!(i&(1<<j))){
				if(arr[0][j]&&arr[1][j])atmost=min(atmost,arr[1][j]);
			}
		}
		if(atmost!=LLONG_MAX)ans=min(ans,am+1+sum[1]-atmost+1);
	}
	prl(ans);
    return 0;
}
/*
4
3 0 3 2
3 9 2 0
 */