#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
vector<int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n];
	int cnt[n]={};
	int bests[n+1];
	for(int i=0;i<n;i++){
		bests[i+1]=INT_MAX;
		cin>>arr[i];
		for(int j=0;j<21;j++){
			if(arr[i]%primes[j]==0){
				cnt[i]+=(1<<j);
			}
		}
	}
	for(int i=0;i<(1<<21);i++){
		int can=0;
		for(int j=0;j<n;j++){
			if((cnt[j]|i)<=i){
				can+=1;
			}
		}
		int popcnt=__builtin_popcount(i);
		for(int j=1;j<=can;j++) {
			bests[j] = min(bests[j], popcnt);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",bests[i]);
	}
	return 0;
}