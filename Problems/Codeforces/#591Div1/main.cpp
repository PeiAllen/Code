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
const int MAXN=3e5+1;
int bit[2][MAXN];
int n;
void update(int loc,int am, int ind){
	for(;loc<=n;loc+=loc&-loc)bit[ind][loc]+=am;
}
int query(int loc, int ind){
	int ans=0;
	for(;loc>0;loc-=loc&-loc)ans+=bit[ind][loc];
	return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int q;
	sc(q);
	while(q--){
		sc(n);
		int ans=0;
		int in;
		set<int> cnt;
		int used[n];
		set<int> cnt2;
		rep(i,0,n){
			sc(in);
			used[i]=in;
			int am=query(n,0)-query(in,0);
			if(am){
				cnt.insert(in);
			}
			if(!cnt2.count(in))update(in,1);
			cnt2.insert(in);
		}
		ans=cnt.size();
		for(int x:used)update(x,-1);
		prl(ans);
	}
    return 0;
}