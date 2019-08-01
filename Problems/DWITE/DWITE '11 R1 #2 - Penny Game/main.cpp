#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int cas=0;cas<5;cas++){
		int n;
		cin>>n;
		int arr[n];
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		int ans=0;
		sum/=n;
		for(int i=0;i<n;i++){
			ans+=max(0,sum-arr[i]);
		}
		printf("%d\n",ans);
    }
    return 0;
}