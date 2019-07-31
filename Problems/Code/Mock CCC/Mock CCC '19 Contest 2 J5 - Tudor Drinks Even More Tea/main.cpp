#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli a,b,c,d;
	cin>>a>>b>>c>>d;
	lli ans=(b-a+1)*(d-c+1);
	lli upto=min(b,d);
	lli nprime[upto+1]={ };
	bool sqr[upto+1]={};
	//inclusion exclusion if we have set f(a)+f(b)+f(c)-f(ab)-f(cb)-f(ac)+f(abc), alternates depending on number of unique prime factors
	//also means you exclude any numbers with two of the same prime factor, as they've already been counted for
	//number of intersection is number of elements divisble in range b/c,a/c
	for(lli i=2;i<=upto;i++){
		if(!nprime[i]){
			for(lli j=i;j<=upto;j+=i){
				nprime[j]+=1;
			}
			lli two=i*i;
			for(lli j=two;j<=upto;j+=two)sqr[j]=true;
		}
		if(sqr[i]) continue;
		if(nprime[i]%2)ans-=(d/i-(c-1)/i)*(b/i-(a-1)/i);
		else ans+=(d/i-(c-1)/i)*(b/i-(a-1)/i);
	}
	printf("%lli\n",ans);
	return 0;
}