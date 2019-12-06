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
bool work[(1<<22)+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    rep(i,0,(1<<12)+1){
	    rep(j,i,(1<<12)+1){
		    rep(k,j,(1<<12)+1){
			    if(i+j+k <= 1<<12 && i + j + k + i * j + j * k + k * i <= 1<<22) {
				    work[i + j + k + i * j + j * k + k * i] = true;
			    }
			    else break;
		    }
	    }
    }
    rep(i,1,(1<<22)+1){
    	if(!work[i])prl(i);
    }
    return 0;
}