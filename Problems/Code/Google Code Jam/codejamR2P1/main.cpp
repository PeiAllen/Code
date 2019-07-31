#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli mo=1000000007;
vector<lli> matrix[100001];
lli amount[100001];
bool gone[100001];
bool gone2[100001];
lli dp[100001];
lli m;
bool ca(lli loc){
	if(amount[loc])return true;
	gone2[loc]=true;
	for(lli x:matrix[loc]){
		if(!gone2[x]){
			if(ca(x)) {
				return true;
			}
		}
	}
//	gone2[loc]=false;
	return false;
}

lli dfs(lli loc){
	if(dp[loc]!=-2){
		return dp[loc];
	}
	if(gone[loc]){
		if(ca(loc)) {
			return dp[loc] = -1;
		}
		else{
			for(lli i=1;i<=m;i++){
				gone2[i]=false;
			}
			return dp[loc]=0;
		}
	}
	gone[loc]=true;
	lli ans=amount[loc];
	for(lli x:matrix[loc]){
		lli te=dfs(x);
		if(te==-1){
			gone[loc]=false;
			return dp[loc]=-1;
		}
		ans+=te;
		ans%=mo;
	}
	gone[loc]=false;
	return dp[loc]=ans;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli t;
	cin>>t;
	for(lli tests=1;tests<=t;tests++){
		cin>>m;
		lli a,b;
		for(lli i=0;i<=m;i++){
			dp[i]=-2;
			gone[i]=false;
			gone2[i]=false;
			matrix[i].clear();
			amount[i]=0;
		}
		for (lli i = 1; i <= m; i++) {
		    cin>>a>>b;
		    matrix[a].push_back(i);
		    matrix[b].push_back(i);
		}
		for(lli i=1;i<=m;i++){
			cin>>amount[i];
		}
		lli te=dfs(1);
		if(te==-1){
			printf("Case #%lli: UNBOUNDED\n",tests);
		}
		else {
			printf("Case #%lli: %lli\n",tests,te);
		}
	}
}
