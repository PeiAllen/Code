#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int llu;
random_device rd;
mt19937_64 eng(rd());
llu fastmul(llu a, llu b, llu mod){
	llu ret=0;
	for(llu i=1;i<=b;i<<=1){
		if(b&i){
			ret+=a;
			ret%=mod;
		}
		a+=a;
		a%=mod;
	}
	return ret;
}
llu fpow(llu a, llu b, llu mod){
	llu ret=1;
	for(llu i=1;i<=b;i<<=1){
		if(b&i){
			ret=fastmul(ret,a,mod);
			ret%=mod;
		}
		a=fastmul(a,a,mod);
	}
	return ret;
}
bool prime(llu a){
	for(int i=0;i<1;i++){
		uniform_int_distribution<llu> gen(1,a-1);
		llu randnum=gen(eng);
		if(fpow(randnum,a-1,a)!=1){
			return false;
		}
	}
	return true;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	llu n;
	cin>>n;
	if(n<=2) printf("2\n");
	else {
		while (!prime(n))n++;
		printf("%llu\n", n);
	}
	return 0;
}