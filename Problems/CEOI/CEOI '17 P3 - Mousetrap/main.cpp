#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
const int MAXN=1e6+1;
vector<int> matrix[MAXN];
int dp[MAXN];
int par[MAXN];
int n,t,m;
int makedp(int cur, int parent){
	par[cur]=parent;
	int ma=0;
	int ma2=0;
	for(int x:matrix[cur]){
		if(x!=parent){
			int te=makedp(x,cur);
			if(te>=ma){
				ma2=ma;
				ma=te;
			}
			else if(te>ma2)ma2=te;
		}
	}
	return dp[cur]=ma2+(int)matrix[cur].size()-(parent?1:0);
}
int addtodp(int cur, int prev){
	if(cur==t)return 0;
	int aboveblock=addtodp(par[cur],cur);
	aboveblock+=max(0,(int)matrix[cur].size()-1-(prev?1:0));
	for(int x:matrix[cur]){
		dp[x]+=aboveblock;
	}
	return aboveblock;
}
bool work(int cur,int prev, int moves, int mustremoveabove,int used){
	if(cur==t){
		return used<=mustremoveabove;
	}
	int cnt=0;
	for(int x:matrix[cur]){
		if(x!=par[cur]&&x!=prev){
			if(dp[x]+used>mustremoveabove){
				cnt++;
			}
		}
	}
	used+=cnt;
	if(cnt>moves)return false;
	else{
		return work(par[cur],cur,moves+1-cnt,mustremoveabove,used);
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>t>>m;
	int a,b;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	makedp(t,0);
	addtodp(m,0);
	int lo=0;
	int hi=2*n;
	while(lo!=hi){
		int mid=(lo+hi)/2;
		if(work(m,-1,1,mid,0))hi=mid;
		else lo=mid+1;
	}
	printf("%d\n",lo);
	return 0;
}