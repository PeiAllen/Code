#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli mod=1e9+7;
lli make(lli a){
	while(a<0)a+=mod;
	return a%mod;
}
lli qpow(lli a, lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	lli am[m+1]={};
	lli totminus=0;
	for(lli i=1;i<=m;i++){
		totminus=(totminus+qpow(31,i))%mod;
	}
	map<lli,lli> store;
	store[0]=1;
	lli ans=0;
	lli in;
	lli cur=0;
	lli at=1;
	lli howmany[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>in;
		am[in]+=1;
		howmany[am[in]]+=1;
		if(howmany[at]==m){
			at+=1;
			cur=make(cur-totminus);
		}
		cur=(cur+qpow(31,in))%mod;
		ans+=store[cur];
		store[cur]+=1;
	}
	printf("%lli\n",ans);
	return 0;
}