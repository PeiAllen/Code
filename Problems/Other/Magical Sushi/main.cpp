#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int arr[100000];
int n,f;
bool work(double avg){
	double arr2[n];
	double mi=0;
	for(int i=0;i<n;i++){
		arr2[i]=(double)arr[i]-avg;
		if(i>0)arr2[i]+=arr2[i-1];
		if(i>=f){
			mi=min(mi,arr2[i-f]);
			if(arr2[i]-mi>=0)return true;
		}
		else if(i==f-1){
			if(arr2[i]-mi>=0)return true;
		}
	}
	return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	cin>>n>>f;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	double lo=0;
	double hi=2000;
	double prec=0.00001;
	while(hi-lo>=prec){
		double mid=(lo+hi)/2;
		if(work(mid))lo=mid;
		else hi=mid-prec;
	}
	printf("%d\n",(int)floor((hi+prec)*1000));
    return 0;
}