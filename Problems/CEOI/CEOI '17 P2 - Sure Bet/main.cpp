#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
double arr[100000];
double arr2[100000];
int n;
bool can(double a){
	double extra=0,extra2=0;
	int l=n-1;
	int r=n-1;
	while((l!=-1||extra>=a)&&(r!=-1||extra2>=a)){
		while(l>=0&&extra<a){
			extra+=(arr[l--]-1);
			extra2-=1;
		}
		while(r>=0&&extra2<a){
			extra2+=(arr2[r--]-1);
			extra-=1;
		}
		if(extra>=a&&extra2>=a)return true;
	}
	return false;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i]>>arr2[i];
	}
	sort(arr,arr+n);
	sort(arr2,arr2+n);
	double lo=0;
	double hi=100000000;
	while(hi-lo>=0.000001){
		double mid=(lo+hi)/2;
		if(can(mid))lo=mid;
		else hi=mid-0.0000001;
	}
	printf("%.4f\n",lo);
	return 0;
}