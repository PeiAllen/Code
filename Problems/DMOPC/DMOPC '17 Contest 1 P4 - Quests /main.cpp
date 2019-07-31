#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct npc{
	lli totime,togold,qtime,qgold;
	npc(lli a=0, lli b=0, lli c=0, lli d=0):totime(a),togold(b),qtime(c),qgold(d){}
};
lli dp[2][5001][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,h;
    cin>>n>>h;
	npc arr[n+1];
	for(lli i=0;i<=1;i++){
		for(lli j=0;j<=h;j++){
			dp[i][j][0]=LLONG_MIN;
			dp[i][j][1]=LLONG_MIN;
		}
	}
	int cur=1;
    for(lli i=1;i<=n;i++){
    	dp[cur][0][0]=0;
		cin>>arr[cur].togold>>arr[cur].totime>>arr[cur].qgold>>arr[cur].qtime;
		for(lli j=1;j<=h;j++){
			dp[cur][j][0]=max(dp[(cur+1)%2][j][0],max(dp[cur][j-1][0],dp[(cur+1)%2][j][1]));
			dp[cur][j][1]=dp[cur][j-1][1];
			if(j>=arr[cur].totime)dp[cur][j][1]=max(dp[cur][j][1],dp[cur][j-arr[cur].totime][0]+arr[cur].togold);
			if(j>=arr[cur].qtime)dp[cur][j][1]=max(dp[cur][j][1],dp[cur][j-arr[cur].qtime][1]+arr[cur].qgold);
		}
		cur=(cur+1)%2;
    }
	printf("%lli\n",max(dp[(cur+1)%2][h][1],dp[(cur+1)%2][h][0]));
    return 0;
}