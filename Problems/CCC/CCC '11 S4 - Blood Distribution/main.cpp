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
vector<int> arr[4]={{0},{2,0},{4,0},{0,2,4,6}};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli blood[8];
    rep(i,0,8)sc(blood[i]);
    lli in;
    lli ans=0;
    rep(i,0,8){
    	sc(in);
	    if(i%2) {
		    for (int x:arr[i / 2]) {
			    lli te = min(blood[x+1], in);
			    in -= te;
			    blood[x+1] -= te;
			    ans += te;
		    }
	    }
    	for(int x:arr[i/2]){
    		lli te=min(blood[x],in);
    		in-=te;
    		blood[x]-=te;
    		ans+=te;
    	}
    }
    prl(ans);
    return 0;
}