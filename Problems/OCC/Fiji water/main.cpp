#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN=60;
bool dp[MAXN+1];
bool gone[MAXN+1];
vector<int> jumps;
bool go(int n){
	if(n<=0)return 0;
	if(gone[n])return dp[n];
	gone[n]=true;
	for(int x:jumps){
		if(go(n-x)){
			return dp[n]=0;
		}
	}
	return dp[n]=1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int k;
	cin>>k;
	for(int i=1;i<=MAXN;i*=k){
		jumps.push_back(i);
	}
	for(int i=1;i<=MAXN;i++){
		printf("%d",go(i));
	}
    return 0;
}