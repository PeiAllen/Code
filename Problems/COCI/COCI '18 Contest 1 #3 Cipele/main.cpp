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
vector<lli> arr,arr2;
bool check(lli a){
	int l=0;
	for(lli x:arr){
		while(l<sz(arr2)&&abs(arr2[l]-x)>a)l++;
		if(l==sz(arr2))return false;
		l++;
	}
	return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    sc(n,m);
    arr.resize(n),arr2.resize(m);
    rep(i,0,n)sc(arr[i]);
    rep(i,0,m)sc(arr2[i]);
    if(n>m){
    	swap(n,m);
    	arr.swap(arr2);
    }
    sort(arr.begin(),arr.end());
    sort(arr2.begin(),arr2.end());
    lli lo=0,hi=1e9;
    while(lo!=hi){
    	lli mid=(lo+hi)/2;
    	if(check(mid))hi=mid;
    	else lo=mid+1;
    }
    prl(lo);
    return 0;
}