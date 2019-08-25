#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n][n];
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",(i*n+j)^(j*(n/4)+i));
		}
		printf("\n");
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			printf("%d ",arr[i][i%(n/4)?((j+(n/4))%n):j]);
//		}
//		printf("\n");
//	}
//	for(int i=0;i<n;i++){
//		int x=0;
//		for(int j=0;j<n;j++){
//			x^=arr[j][j%(n/4)?(i+(n/4))%n:i];
//		}
//		printf("%d ",x);
//	}
	return 0;
}