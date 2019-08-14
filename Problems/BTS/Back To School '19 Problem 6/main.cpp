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
	int dp[n/2+1][2][2][2];
	for(int j=0;j<2;j++){
		for(int a=0;a<2;a++) {
			for (int b = 0; b < 2; b++) {
				dp[1][j][a][b]=1;
			}
		}
	}
	for(int i=2;i<=n/2;i++){
		for(int j=0;j<2;j++){
			for(int a=0;a<2;a++){
				for(int b=0;b<2;b++){
					dp[i][j][a][b]=n+2;
					for(int jp=0;jp<2;jp++){
						for(int ap=0;ap<2;ap++){
							for(int bp=0;bp<2;bp++){
								//take care of left
								int mid=arr[j?n-i+1:i]>arr[jp?n-i+2:i-1];
								int cnt=0;
								if(mid!=ap)cnt+=1;
								if(mid!=a)cnt+=1;
								//take care of right
								mid=arr[j?i:n-i+1]>arr[jp?i-1:n-i+2];
								if(mid!=bp)cnt+=1;
								if(mid!=b)cnt+=1;
								dp[i][j][a][b]=min(dp[i][j][a][b],dp[i-1][jp][ap][bp]+cnt);
							}
						}
					}
				}
			}
		}
	}
	if(n%2==0) {
		int ans = INT_MAX;
		for (int j = 0; j < 2; j++) {
			for (int a = 0; a < 2; a++) {
				for (int b = 0; b < 2; b++) {
					int mid = arr[j ? n - n / 2 + 1 : n / 2] < arr[j ? n / 2 : n - n / 2 + 1];
					int cnt = 0;
					if (mid != a)cnt++;
					if (mid == b)cnt++;
					ans = min(ans, dp[n / 2][j][a][b] + cnt);
				}
			}
		}
		printf("%d\n", ans);
	}
	else{
		if(n==1)printf("1\n");
		else{
			int ans = n+2;
			for (int j = 0; j < 2; j++) {
				for (int a = 0; a < 2; a++) {
					for (int b = 0; b < 2; b++) {
						int mid = arr[j ? n - n / 2 + 1 : n / 2] < arr[n/2+1];
						int cnt = 0;
						if (mid != a)cnt++;
						int mid2=arr[n/2+1] < arr[j ? n/2 : n - n / 2 + 1];
						if(mid2==b)cnt++;
						if(mid!=mid2)cnt++;
						ans = min(ans, dp[n / 2][j][a][b] + cnt);
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}