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
set<pair<pair<lli,int>,lli>> radi[501];
pll coords[501];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    assert(n==1);
    lli ax,ay,bx,by;
    sc(ax,ay,bx,by);
    if(ax==bx&&ay==by){
    	prl(0);
    	return 0;
    }
	lli x,y;
    int ans=n+1;
    rep(i,0,n){
		sc(x,y);
		coords[i]={x,y};
		radi[i].insert({{pow(ax-x,2)+pow(ay-y,2),0},pow(ax-x,2)+pow(ay-y,2)});
		rep(j,0,i){
			for(auto a:radi[j]){
				pair<pair<lli,int>,lli> cur;
				if(coords[j])
			}
		}
		lli len=pow(bx-x,2)+pow(by-y,2);
		auto te=radi[i].upper_bound({{len,n+1},len});
		if(te!=radi[i].begin()){
			te--;
			if(te->second>=len)ans=min(ans,te->first.second);
		}
    }
    prl(-1);
    return 0;
}