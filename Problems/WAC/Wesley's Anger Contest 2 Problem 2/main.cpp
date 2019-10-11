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
    lli n,m;
    int q;
    sc(n,m,q);
    map<lli,lli> prices;
    lli mdp=1000000,cdp=1000000;
    lli last=n;
    lli a,b;
    rep(i,0,q){
		sc(a,b);
		if(a==last){
			mdp=min(mdp,b);
			cdp=b;
		}
		else{
			prices[mdp]+=1;
			mdp=min(cdp,b);
			prices[cdp]+=last-a-1;
			cdp=b;
			last=a;
		}
    }
	prices[mdp]+=1;
	prices[cdp]+=last-1;
	lli ans=0;
	for(auto x:prices){
		lli tobuy=min(x.second,m);
		m-=tobuy;
		ans+=tobuy*x.first;
		if(m==0)break;
	}
	prl(ans);
    return 0;
}