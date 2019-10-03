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
	freopen("mixmilk.in","r",stdin);
	freopen("mixmilk.out","w",stdout);
	lli arr[3][2];
    rep(i,0,3)rep(j,0,2)sc(arr[i][j]);
    int loc=0;
    rep(i,0,100){
    	int oth=(loc+1)%3;
    	lli torev=min(arr[loc][1],arr[oth][0]-arr[oth][1]);
    	arr[loc][1]-=torev;
    	arr[oth][1]+=torev;
    	loc=(loc+1)%3;
    }
    rep(i,0,3)prl(arr[i][1]);
    return 0;
}