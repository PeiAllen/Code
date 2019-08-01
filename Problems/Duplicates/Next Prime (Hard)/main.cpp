#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int llu;
random_device rd;
mt19937_64 eng(rd());
llu fpow(llu a, llu b, llu mod){
	llu ret=1;
	for(llu i=0;i<=log2(b);i++){
		if(b&(1<<i)){
			ret*=a;
			ret%=mod;
		}
		a*=a;
		a%=mod;
	}
	return ret;
}
bool prime(llu a){
	uniform_int_distribution<llu> gen(2,a-1);
	for(int i=0;i<20;i++){
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