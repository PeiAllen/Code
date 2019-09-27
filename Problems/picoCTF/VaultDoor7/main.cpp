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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int given[8]={1096770097
                 ,1952395366
                 ,1600270708
                 ,1601398833
                 ,1716808014
                 ,1734292024
                 ,926443108
                 ,825569586};
    char ans[32];
    rep(i,0,8){
    	rep(j,0,4){
    		ans[i*4+(3-j)]=(char)given[i]%(1<<8);
    		given[i]>>=8;
    	}
    }
	rep(i,0,32)pr(ans[i]);
    return 0;
}

//F1AG5AND5TUFF