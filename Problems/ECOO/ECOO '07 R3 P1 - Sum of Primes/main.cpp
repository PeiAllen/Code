#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<int> primes;
bool nseive[(int)1e7+1];
pair<int,int> solveeven(int n){
	int loc = upper_bound(primes.begin(), primes.end(), n / 2)-primes.begin();
	loc-=1;
	for(;loc>=0;loc--){
		if(!nseive[n-primes[loc]]){
			return {primes[loc],n-primes[loc]};
		}
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for(int i=2;i<=1e7;i++){
		if(!nseive[i]){
			if(i!=2)primes.push_back(i);
			else nseive[i]=true;
			for(int j=i+i;j<=1e7;j+=i){
				nseive[j]=true;
			}
		}
	}
	for(int test=0;test<5;test++){
		int n;
		cin>>n;
		if(!nseive[n]){
			printf("%d = %d\n",n,n);
		}
		else if(!(n%2)) {
			pair<int,int> te=solveeven(n);
			printf("%d = %d + %d\n",n,te.first,te.second);
		}
		else{
			int loc=upper_bound(primes.begin(),primes.end(),n/3)-primes.begin();
			loc-=1;
			for(;loc>=0;loc--) {
				pair<int,int> te=solveeven(n-primes[loc]);
				if(te.first>=primes[loc]){
					printf("%d = %d + %d + %d\n",n,primes[loc],te.first,te.second);
					break;
				}
			}
		}
	}
	return 0;
}