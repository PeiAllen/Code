#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
lli mod=998244853;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n,m;
	cin>>n>>m;
	lli maxam=n*m+1;
	lli ans=0;
	for(lli i=0;i<=min(m,n);i++){
		ans=(ans+((n-i)*(maxam-(n-i)*(m-i)-i)%mod))%mod;
	}
	printf("%lli\n",ans);
	return 0;
}