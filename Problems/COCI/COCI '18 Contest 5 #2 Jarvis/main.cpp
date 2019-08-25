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
	map<int,int> inc;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int in;
	for(int i=0;i<n;i++){
		cin>>in;
		inc[in-arr[i]]+=1;
	}
	int ma=0;
	for(auto x:inc){
		ma=max(x.second,ma);
	}
	printf("%d\n",ma);
	return 0;
}