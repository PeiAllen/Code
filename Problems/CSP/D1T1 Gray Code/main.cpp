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
lli get(lli sz, lli ind){
	if(sz==2)return ind;
	lli ne=sz>>1;
	lli te=get(ne,ind<ne?ind:sz-ind-1);
	return te+(ind<ne?0:ne);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,k;
    sc(n,k);
    prl(get(2<<n,k));
    return 0;
}