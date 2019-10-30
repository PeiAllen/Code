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
	int q;
	sc(q);
	while(q--){
		int n;
		sc(n);
		int arr[2];
		string a;
		int sizes[n];
		rep(i,0,n){
			sc(a);
			sizes[i]=sz(a);
			for(char x:a){
				arr[x-'0']+=1;
			}
		}
		int dp[n+1][arr[0]+1][arr[1]+1];
		rep(i,0,n){
			rep(i,0,)
		}
	}
    return 0;
}