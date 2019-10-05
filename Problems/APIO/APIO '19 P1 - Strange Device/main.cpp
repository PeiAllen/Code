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
lli gcd(lli a,lli b){
	if(a==0)return b;
	return gcd(b%a,a);
}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	lli n,a,b;
	sc(n,a,b);
	lli loop=a/gcd(b+1,a);
	if((lli)1e18/loop<b) loop=1e18+1;
	else loop*=b;
	lli l,r;
	priority_queue<pll,vector<pll>,greater<pll>> q;
	rep(i,0,n){
		sc(l,r);
		if(r-l>=loop){
			prl(loop);
			return 0;
		}
		l%=loop;
		r%=loop;
		if(r<l){
			q.push({0,r});
			q.push({l,loop-1});
		}
		else{
			q.push({l,r});
		}
	}
	r=-1;
	lli ans=0;
	while(!q.empty()){
		pll cur=q.top();
		q.pop();
		ans+=max((lli)0,cur.first-r-1);
		r=max(r,cur.second);
	}
	ans+=max((lli)0,loop-r-1);
	prl(loop-ans);
    return 0;
}