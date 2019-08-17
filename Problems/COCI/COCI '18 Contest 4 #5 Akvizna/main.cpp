#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
int n,k;
double dp[100001]={};
double interpoint(int a, int b){//a<b
	return (dp[b]-dp[a])/(1/(double)b-1/(double)a);
}
double run(double cnst){
	int cnt[n+1]={};
	int deq[n+1];
	int le=0,ri=-1;
	deq[++ri]=n;
	for(int i=n-1;i>=0;i--){
		while(ri-le>=1&&interpoint(deq[le+1],deq[le])>=(double)i)le++;
		dp[i]=dp[deq[le]]+(double)(deq[le]-i)/(double)deq[le]-cnst;
		cnt[i]=cnt[deq[le]]+1;
		while(ri-le>=1&&interpoint(deq[ri],deq[ri-1])<=interpoint(i,deq[ri]))ri--;
		deq[++ri]=i;
	}
	if(cnt[0]>k)return DBL_MIN;
	return dp[0]+cnst*cnt[0];
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	lli lo=0;
	lli hi=2e15;
	lli cnt=1e12;
	while(lo!=hi){
		lli mid=(lo+hi)/2;
		if(run((double)mid/cnt)!=DBL_MIN)hi=mid;
		else lo=mid+1;
	}
	printf("%.9f\n",run((double)lo/cnt));
	return 0;
}
//dp[a]+(a-i)/a-cnst>=dp[b]+(b-i)/b-cnst and a<b then a will be forever better
//dp[a]+(a-i)/a>=dp[b]+(b-i)/b
//(a-i)/a-(b-i)/b>=dp[b]-dp[a]
//1-i/a-1+i/b
//i/b-i/a
//i(1/b-1/a)>=dp[b]-dp[a]
//i<=(dp[b]-dp[a])/(1/b-1/a)