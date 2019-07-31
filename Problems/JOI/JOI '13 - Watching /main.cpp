#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n,p,q;
int arr[2001];
int cango[2001][2];
int go(int cur,int a, int b){
	if(cur>n)return 0;
	return max(a>0?(go(cango[cur][0]+1,a-1,b)+cango[cur][0]-cur+1):0,b>0?(go(cango[cur][1]+1,a,b-1)+cango[cur][1]-cur+1):0);
}
int best(int w){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(arr[j]-arr[i]+1<=w){
				cango[i][0]=j;
			}
			if(arr[j]-arr[i]+1<=2*w){
				cango[i][1]=j;
			}
			else{
				break;
			}
		}
	}
	return go(1,min(n,p),min(n,q));
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin>>n>>p>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	int lo=1;
	int hi=1e9;
	while(lo!=hi){
		int mid=(lo+hi)/2;
		if(best(mid)>=n){
			hi=mid;
		}
		else{
			lo=mid+1;
		}
	}
	printf("%d\n",lo);
    return 0;
}