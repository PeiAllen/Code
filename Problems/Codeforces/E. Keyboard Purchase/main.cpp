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
lli dp[(1<<20)];
lli am[20][20];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,m;
	sc(n,m);
	string s;
	sc(s);
	rep(i,0,n-1){
		am[s[i]-'a'][s[i+1]-'a']+=1;
	}
	rep(i,0,(1<<m)){
		int cur=__builtin_popcount(i)-1;

	}
    return 0;
}