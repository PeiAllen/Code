#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int arr[5]={};
	for(int i=1;i<=4;i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	for(int i=0;i<=4;i++){
		for(int j=0;j<=4;j++){
			printf("%d ",abs(arr[i]-arr[j]));
		}
		printf("\n");
	}
	return 0;
}