#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int arr[(int)1e7+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		arr[a]+=1;
		arr[b]-=1;
	}
	int ans=0;
	for(int i=1;i<=1e7;i++){
		arr[i]+=arr[i-1];
		ans=max(ans,arr[i]);
	}
	printf("%d\n",ans);
    return 0;
}