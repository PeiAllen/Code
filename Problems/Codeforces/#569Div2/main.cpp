#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	lli in;
	lli arr[n];
	if(n%2) {
		lli ans=LLONG_MIN;
		int loc=-1;
		lli prod=1;
		for (int i = 0; i < n; i++) {
			cin>>in;
			if(in<0){
				prod*=abs(in);
				arr[i]=abs(in);
			}
			else{
				prod*=(in+1);
				arr[i]=in+1;
			}
		}
		for(int i=0;i<n;i++){
			if(prod/arr[i]*(arr[i]-1)>=ans){
				loc=i;
				ans=prod/arr[i]*(arr[i]-1);
			}
		}
			for (int i = 0; i < n; i++) {
				if (i == loc) {
					printf("%lli ", arr[i] - 1);
				} else {
					printf("%lli ", -1 * arr[i]);
				}
			}
	}
	else{
		lli prod=1;
		for (int i = 0; i < n; i++) {
			cin>>in;
			if(in<0){
				prod*=abs(in);
				arr[i]=abs(in);
			}
			else{
				prod*=(in+1);
				arr[i]=in+1;
			}
		}
		lli sec=1;
		for(int i=0;i<n;i++){
			sec*=(arr[i]-1);
		}
		if(sec>prod){
			for(int i=0;i<n;i++) {
				printf("%lli ", arr[i] - 1);
			}
		}
		else{
			for(int i=0;i<n;i++) {
				printf("%lli ", -1*arr[i]);
			}
		}
	}
	return 0;
}