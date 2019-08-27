#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int n;
int arr[400001];
int findmax(){
	int ans=1;
	int cur=1;
	for(int i=1;i<n;i++){
		if(arr[i]>=arr[i-1])cur+=1;
		else cur=1;
		ans=max(ans,cur);
	}
	return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    printf("%d\n",findmax());
    while(q--){
    	int a,b;
    	cin>>a>>b;
    	arr[a-1]=b;
	    printf("%d\n",findmax());
    }
    return 0;
}