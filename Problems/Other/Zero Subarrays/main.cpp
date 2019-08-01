#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n;
	map<lli,lli> can;
	cin>>n;
	lli last=0;
	lli in;
	lli am=0;
	can[0]=1;
	for(lli i=0;i<n;i++){
		cin>>in;
		last+=in;
		am+=can[last];
		can[last]+=1;
	}
	printf("%lli\n",am);
	return 0;
}