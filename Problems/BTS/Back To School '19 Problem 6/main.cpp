#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	lli dp[n+1][2][2][2];
	memset(dp,INT_MAX,sizeof(dp));
	for(int i=1;i<=n/2;i++){
		for(int j=0;j<2;j++){
			for(int a=0;a<2;a++){
				for(int b=0;b<2;b++){
					for(int jp=0;jp<2;jp++){
						for(int ap=0;ap<2;ap++){
							for(int bp=0;bp<2;bp++){
								dp[i][j][a][b]=min(dp[i][j][a][b],dp[i-1][jp][ap][bp]+);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}