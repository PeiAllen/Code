#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;
typedef long long int lli;
lli pt[10001];
lli f[10001];
lli s;
lli dp[2][10001];
int flip=1;
int deq[10001];
double val[10001];
int le, ri;
lli is;
inline double overcomepoint(int a, int b, lli i){
	return (double)(dp[(flip + 1) % 2][a] -is*f[a]-dp[(flip + 1) % 2][b] +is*f[b])/(double)(f[a]-f[b]);
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		dp[0][i]=INT_MAX;
		cin>>pt[i]>>f[i];
	}
	for(int i=1;i<=n;i++){
		pt[i]+=pt[i-1];
		f[i]+=f[i-1];
	}
	lli ans=LLONG_MAX;
	for(int i=1;i<=n;i++) {
		is=i*s;
		le=0;
		ri=-1;
		deq[++ri]=i-1;
		for (int j = i; j <= n; j++) {
			while((ri-le)>=1&&val[le]<=(double)pt[j])le++;
			dp[flip][j]=dp[(flip + 1) % 2][deq[le]] + ((lli)i*s + pt[j]) * (f[j] - f[deq[le]]);
			while((ri-le)>=1&&val[ri-1]>=(val[ri]=overcomepoint(j,deq[ri],i)))ri--;
			if((ri-le)<1)val[ri]=overcomepoint(j,deq[ri],i);
			deq[++ri]=j;
		}
		if(ans<dp[flip][n])break;
		ans=dp[flip][n];
		flip=(flip+1)%2;
	}
	printf("%lli\n",ans);
	return 0;
}
//dp[(flip + 1) % 2][a] + ((lli)i*s + pt[j]) * (f[j] - f[a])<=dp[(flip + 1) % 2][b] + ((lli)i*s + pt[j]) * (f[j] - f[b]); where a>b
//then a will always be better
//dp[(flip + 1) % 2][a] + ((lli)i*s + pt[j]) * (f[j] - f[a])<=dp[(flip + 1) % 2][b] + ((lli)i*s + pt[j]) * (f[j] - f[b])
//dp[(flip + 1) % 2][a] + (lli)i*s*f[j]-(lli)i*s*f[a]+pt[j]*f[j]-pt[j]*f[a]<=dp[(flip + 1) % 2][b] + (lli)i*s*f[j]-(lli)i*s*f[b]+pt[j]*f[j]-pt[j]*f[b]
//dp[(flip + 1) % 2][a] + (lli)i*s*f[j]-(lli)i*s*f[a]+pt[j]*f[j]-pt[j]*f[a]<=dp[(flip + 1) % 2][b] + (lli)i*s*f[j]-(lli)i*s*f[b]+pt[j]*f[j]-pt[j]*f[b]
//dp[(flip + 1) % 2][a] -(lli)i*s*f[a]-pt[j]*f[a]<=dp[(flip + 1) % 2][b] -(lli)i*s*f[b]-pt[j]*f[b]
//dp[(flip + 1) % 2][a] -(lli)i*s*f[a]-dp[(flip + 1) % 2][b] +(lli)i*s*f[b]<=pt[j](f[a]-f[b])
//pt[j]>=(dp[(flip + 1) % 2][a] -(lli)i*s*f[a]-dp[(flip + 1) % 2][b] +(lli)i*s*f[b])/(f[a]-f[b])