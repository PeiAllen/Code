#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli pre[300001];
lli pre2[300001];
lli n,m,k;
lli calc(lli l, lli r){
	return pre[r]-pre[l]-k*ceil((double)(r-l)/(double)m);
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	lli in;
	lli minu=ceil((double)(k)/(double)m);
	pre[0]=0;
	lli ans=0;
	lli mi=0;
	lli loc=0;
	for(lli i=1;i<=n;i++){
		cin>>in;
		lli te=in-minu;
		pre[i]=pre[i-1]+in;
		pre2[i]=pre2[i-1]+te;
		if(pre2[i]<mi){
			loc=i;
			mi=pre2[i];
		}
		for(int j=loc;j<=min(i,loc+m);j++) {
			ans = max(ans, calc(j, i));
		}
		for(int j=loc;j>=max((lli)0,loc-m);j--) {
			ans = max(ans, calc(j, i));
		}
	}
	mi=0;
	loc=0;
	memset(pre2,0,sizeof(pre2));
	minu=floor((double)(k)/(double)m);
	for(lli i=1;i<=n;i++){
		lli te=pre[i]-pre[i-1]-minu;
		pre2[i]=pre2[i-1]+te;
		if(pre2[i]<mi){
			loc=i;
			mi=pre2[i];
		}
		for(int j=loc;j<=min(i,loc+m);j++) {
			ans = max(ans, calc(j, i));
		}
		for(int j=loc;j>=max((lli)0,loc-m);j--) {
			ans = max(ans, calc(j, i));
		}
	}
	printf("%lli\n",ans);
	return 0;
}