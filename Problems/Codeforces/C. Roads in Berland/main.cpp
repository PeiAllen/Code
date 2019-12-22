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
const int MAXN=301;
vector<pii> matrix[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	int a,b,c;
	rep(i,1,n+1)rep(j,1,n+1){
		sc(a);
		if(a) {
			matrix[i].push_back({j, a});
			matrix[j].push_back({i, a});
		}
	}
	int m;
	sc(m);
	while(m--){
		sc(a,b,c);

	}
    return 0;
}