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
const int MAXN=2e5+1;
vector<int> matrix[MAXN];
lli peeps[MAXN];
lli subtreesize[MAXN];
lli dfssize(int loc, int parent){
	subtreesize[loc]=peeps[loc];
	for(int x:matrix[loc])if(x!=parent)subtreesize[loc]+=dfssize(x,loc);
	return subtreesize[loc];
}
vector<int> centroids;
void findcent(int loc, int parent, int siz){
	bool cent=true;
	for(int x:matrix[loc]){
		if(x!=parent)findcent(x,loc,siz);
		if(x!=parent&&subtreesize[x]>siz)cent=false;
	}
	if(subtreesize[1]-subtreesize[loc]>siz)cent=false;
	if(cent)centroids.push_back(loc);
}
lli ans;
lli dfspeeps(int loc, int parent){
	subtreesize[loc]=peeps[loc];
	for(int x:matrix[loc])if(x!=parent)subtreesize[loc]+=dfspeeps(x,loc);
	ans+=peeps[loc]*(subtreesize[loc]-1);
	return subtreesize[loc];
}
void tryuse(int cent){
	vector<lli> chs;
	lli tot=0;
	for(int x:matrix[cent]){
		chs.push_back(dfspeeps(x,cent));
		tot+=*chs.rbegin();
	}
	lli ha=tot/2;
	vector<lli> touse;
	int half=sz(chs)/2;
	rep(i,0,(1<<half)){
		lli am=0;
		rep(j,0,half){
			if(i&(1<<j)){
				am+=chs[j];
			}
		}
		touse.push_back(am);
	}
	sort(touse.begin(),touse.end());
	int oth=sz(chs)-half;
	lli best=0;
	rep(i,0,(1<<oth)){
		lli am=0;
		rep(j,0,oth){
			if(i&(1<<j)){
				am+=chs[half+j];
			}
		}
		if(am<=ha) {
			int loc = (upper_bound(touse.begin(),touse.end(),ha-am)-touse.begin())-1;
			best = max(best, am + touse[loc]);
		}
	}
	ans+=(tot-best+peeps[cent])*(best+peeps[cent])-peeps[cent];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    rep(i,1,n+1)sc(peeps[i]);
    int a;
    rep(i,2,n+1){
    	sc(a);
    	matrix[i].push_back(a);
    	matrix[a].push_back(i);
    }
    findcent(1,0,dfssize(1,0)/2);
    lli best=0;
	for(int x:centroids) {
		ans=0;
		tryuse(x);
		best=max(best,ans);
	}
	prl(best);
    return 0;
}