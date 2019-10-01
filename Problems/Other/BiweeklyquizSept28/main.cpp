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
    int n,m;
    sc(n,m);
    map<int,pii> ma;
    int l,r,am;
    int arr[n+1];
    memset(arr,0,sizeof(arr));
    rep(i,1,m+1){
    	sc(l,r,am);
    	int cnt=0;
    	int oldl=INT_MAX;
    	int oldr=-1;
    	rep(j,l,r+1){
    		if(max(arr[j],am)==am){
    			oldl=min(oldl,j);
			    oldr=max(oldr,j);
    			cnt+=1;
    			arr[j]=am;
    		}
    	}
    	if(!cnt){
    		prl(i);
    		return 0;
    	}
    	if(ma.count(am)){
    		l=max(l,ma[am].first);
		    r=min(r,ma[am].second);
		    if(l>r){
		    	prl(i);
		    	return 0;
		    }
		    ma[am]={l,r};
    	}
    	else{
    		ma[am]={l,r};
    	}
    	for(auto x:ma) {
    		if(max(oldl,x.second.first)>min(oldr,x.second.second))continue;
		    cnt = 0;
		    rep(j, x.second.first, x.second.second + 1) {
			    if (max(arr[j], x.first) == x.first) {
				    cnt += 1;
				    arr[j] = x.first;
			    }
		    }
		    if (!cnt) {
			    prl(i);
			    return 0;
		    }
	    }
    }
    prl(0);
    return 0;
}