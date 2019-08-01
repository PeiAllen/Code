#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pa{
	int a,b;
	pa(int x=0, int y=0):a(x),b(y){}
};
int n,p,q;
int arr[2001];
int cango[2001][2];

bool best(int w){
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
	int dp[min(n,p)+1][min(n,q)+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	queue<pa> qu;
	qu.push({0,0});
	while(!qu.empty()){
		pa cur=qu.front();
		qu.pop();
		if(dp[cur.a][cur.b]>n)return 1;
		if(cur.a<min(n,p)){
			if(cango[dp[cur.a][cur.b]][0]+1>dp[cur.a+1][cur.b]){
				dp[cur.a+1][cur.b]=cango[dp[cur.a][cur.b]][0]+1;
				qu.push({cur.a+1,cur.b});
			}
		}
		if(cur.b<min(n,q)){
			if(cango[dp[cur.a][cur.b]][1]+1>dp[cur.a][cur.b+1]){
				dp[cur.a][cur.b+1]=cango[dp[cur.a][cur.b]][1]+1;
				qu.push({cur.a,cur.b+1});
			}
		}
	}
	return 0;
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
		if(best(mid)){
			hi=mid;
		}
		else{
			lo=mid+1;
		}
	}
	printf("%d\n",lo);
	return 0;
}