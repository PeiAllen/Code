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
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> t={1,5,7,11,13,17,19,23,25};
    int cnt=0;
    rep(i,1,(1<<sz(t))){
    	int sum=0;
    	rep(j,0,sz(t)){
    		if(i&(1<<j)){
    			sum+=t[j];
    		}
    	}
    	if(gcd(sum,24)==1)cnt++;
    }
    prl(cnt);
    return 0;
}