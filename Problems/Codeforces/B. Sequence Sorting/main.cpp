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
const int MAXN=3e5+9;
int bit[MAXN];
int n;
void update(int loc, int am){
	for(;loc>0;loc-=loc&-loc)bit[loc]=min(bit[loc],am);
}
void reset(int loc){
	for(;loc>0;loc-=loc&-loc)bit[loc]=INT_MAX;
}
int query(int loc){
	int mi=INT_MAX;
	for(;loc<=n+3;loc+=loc&-loc){
		mi=min(mi,bit[loc]);
	}
	return mi;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    sc(q);
    rep(i,0,(int)MAXN)bit[i]=INT_MAX;
    while(q--) {
	    sc(n);
	    int arr[n+1];
	    vector<pii> nums;
	    pii ranges[n+1];
	    ranges[0]={0,0};
	    rep(i,1,n+1)ranges[i]={INT_MAX,0};
	    rep(i, 1, n+1){
	    	sc(arr[i]);
	    	ranges[arr[i]].first=min(ranges[arr[i]].first,i);
		    ranges[arr[i]].second=max(ranges[arr[i]].second,i);
	    }
	    rep(i,1,n+1){
	    	if(ranges[i].first!=INT_MAX){
	    		nums.push_back(ranges[i]);
	    	}
	    }
	    nums.push_back({INT_MAX,INT_MAX});
	    int dp[sz(nums)];
	    dp[sz(nums)-1]=0;
	    update(n+1,sz(nums)-1);
	    rep(i,sz(nums)-1,0){
	    	dp[i]=max(dp[i+1],1+dp[query(nums[i].second+1)]);
	    	update(nums[i].first,i);
	    }
	    reset(n+1);
	    rep(i,sz(nums)-1,0){
	    	reset(nums[i].first);
	    }
	    prl(sz(nums)-dp[0]-1);
    }
    return 0;
}