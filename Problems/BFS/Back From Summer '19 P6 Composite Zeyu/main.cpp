#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
vector<int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};
int dp[(1<<21)];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int in;
	int bests[n+1];
	for(int i=0;i<n;i++){
		bests[i+1]=INT_MAX;
		cin>>in;
		int cnt=0;
		for(int j=0;j<21;j++){
			if(in%primes[j]==0){
				cnt+=(1<<j);
			}
		}
		dp[cnt]+=1;
	}
	for(int i=0;i<21;i++){//first i bits are changed
		for(int j=0;j<(1<<21);j++){
			if(j&(1<<i))dp[j]+=dp[j^(1<<i)];//if this bit can be changed to 0, add the 0 possible value
		}
	}
	for(int i=0;i<(1<<21);i++)bests[dp[i]] = min(bests[dp[i]], __builtin_popcount(i));
	for(int i=n-1;i>=1;i--)bests[i]=min(bests[i],bests[i+1]);
	for(int i=1;i<=n;i++){
		printf("%d ",bests[i]);
	}
	return 0;
}