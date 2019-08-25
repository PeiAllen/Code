#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,p;
	cin>>n>>p;
	pair<int,pii> arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].second.first>>arr[i].first;
		arr[i].second.second=i;
	}
	int cur=arr[p-1].second.first;
	int am=1;
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		if(arr[i].second.second!=p-1){
			if(arr[i].first<=cur&&arr[i].second.first>=arr[i].first){
				cur+=arr[i].second.first-arr[i].first;
				am+=1;
			}
		}
	}
	printf("%d\n%d\n",cur,am);
	return 0;
}