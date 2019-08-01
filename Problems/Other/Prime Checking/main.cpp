#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
random_device rd;
mt19937_64 eng(rd());
lli fastmul(lli a, lli b, lli mod){
	lli ret=0;
	for(lli i=1;i<=b;i<<=1){
		if(b&i){
			ret+=a;
			ret%=mod;
		}
		a+=a;
		a%=mod;
	}
	return ret;
}
lli fpow(lli a, lli b, lli mod){
	lli ret=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i){
			ret=fastmul(ret,a,mod);
			ret%=mod;
		}
		a=fastmul(a,a,mod);
	}
	return ret;
}
bool prime(lli a){
	for(int i=0;i<1;i++){
		uniform_int_distribution<lli> gen(1,a-1);
		lli randnum=gen(eng);
		if(fpow(randnum,a-1,a)!=1){
			return false;
		}
	}
	return true;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n;
	cin>>n;
	if(!prime(n)||n==1)printf("NO\n");
	else printf("YES\n");
	return 0;
}