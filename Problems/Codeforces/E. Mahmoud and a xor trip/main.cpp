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
const int MAXN=1e5+1;
const int MAXB=3;
int n;
int arr[MAXN];
vector<int> matrix[MAXN];
lli subtreesize[MAXN];
lli dp[MAXN][MAXB];
lli get(int loc,int bit){//wrong
	if(dp[loc][bit]!=-1)return dp[loc][bit];
	int cur=(arr[loc]&(1<<bit)?1:0);
	lli cnt=cur;
	for(int x:matrix[loc]){
		if(x>loc){
			lli te=get(x,bit);
			cnt+=(cur?subtreesize[x]-te:te);
		}
	}
	return dp[loc][bit]=cnt;
}
lli dfs(int loc, int parent){
	subtreesize[loc]=1;
	for(int x:matrix[loc]){
		if(x!=parent){
			subtreesize[loc]+=dfs(x,loc);
		}
	}
	return subtreesize[loc];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n);
    int a,b;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)sc(arr[i]);
    for(int i=0;i<n-1;i++){
    	sc(a,b);
    	matrix[a].push_back(b);
    	matrix[b].push_back(a);
    }
    dfs(1,0);
    lli ans=0;
	for(int i=1;i<=n;i++){
		lli mut=1;
		for(int j=0;j<MAXB;j++){
			lli am=get(i,j);
			ans+=(am*mut);
			mut*=2;
		}
	}
	pr(ans);
    return 0;
}