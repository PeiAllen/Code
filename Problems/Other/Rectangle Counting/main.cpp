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
const int MAXP=1e6+1;
int bit[2][MAXP];
void update(int ind,int loc, int am){
	for(;loc<MAXP;loc+=loc&-loc)bit[ind][loc]+=am;
}
int start(int ind, int loc){
	int sum=0;
	for(;loc>0;loc-=loc&-loc)sum+=bit[ind][loc];
	return sum;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	priority_queue<pair<int,pair<int,pii>>,vector<pair<int,pair<int,pii>>>,greater<pair<int,pair<int,pii>>>> q;
	int a,b,c,d;
	rep(i,0,n){
		sc(a,b,c,d);
		if(c<a)swap(a,c);
		if(d<b)swap(b,d);
		q.push({a,{1,{b,d}}});
		q.push({c,{0,{b,d}}});
	}
	lli cnt=0;
	while(sz(q)){
		auto cur=q.top();
		q.pop();
		if(!cur.second.first){
			update(1,cur.second.second.first,-1);
			update(0,cur.second.second.second,-1);
		}
		else{
			cnt+=start(1,cur.second.second.second-1)-start(0,cur.second.second.first);
			update(1,cur.second.second.first,1);
			update(0,cur.second.second.second,1);
		}
	}
	prl(cnt);
    return 0;
}