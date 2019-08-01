#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli m=1e9+7;
lli fp(lli a, lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i)ans=(ans*a)%m;
		a=(a*a)%m;
	}
	return ans;
}
lli make(lli a){
	while(a>=m)a-=m;
	while(a<0)a+=m;
	return a;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n;
	cin >> n;
	n+=1;
	lli ans=1;
	for (lli i = 1; i <= n; i++) {// (2*n)!/(n!)^2-1
		ans=(ans*fp(i,m-2))%m;
	}
	for (lli i = n+1; i <= 2*n; i++) {// (2*n)!/(n!)^2-1
		ans=(ans*i)%m;
	}
	printf("%lli\n",make(ans-1));
	return 0;
}