#include <bits/stdc++.h>
using namespace std;
int mo=1000000000;
vector<int> arr[10001];
int dp[10001];
bool gone[10001];
bool gone2[10001];
bool reee=false;
int mod(int a){
	if(a>=mo){
		reee=true;
	}
	return a%mo;
}
bool poss(int loc){
	bool work=false;
	gone2[loc]=true;
	if(loc==1){
		return true;
	}
	for(int i:arr[loc]){
		if(!gone2[i]){
			work|=poss(i);
		}
		if(work){
			return work;
		}
	}
	return work;
}

int dfs(int loc){
	int ans=loc==1?1:0;
	if(dp[loc]!=-2){
		return dp[loc];
	}
	if(gone[loc]){
		gone[loc]=true;
		if(poss(loc)){
			return dp[loc]=-1;
		}
		return dp[loc]=0;
	}
	gone[loc]=true;
	for(int i:arr[loc]){
		int te=dfs(i);
		if(te==-1){
			return dp[loc]=-1;
		}
		ans+=te;
		ans=mod(ans);
	}
	return dp[loc]=ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
	for (int i = 0; i <= n; i++) {
		dp[i]=-2;
	}
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        arr[b].push_back(a);
    }
    int te=dfs(2);
	if(te==-1){
		printf("inf\n");
	}
	else if(reee){
		printf("%09d\n",te);
	}
	else{
		printf("%d\n",te);
	}
    return 0;
}