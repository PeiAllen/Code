#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	pair<long double,long double> arr[n];
	for(int i=0;i<n;i++){
		sc(arr[i].first,arr[i].second);
		arr[i].first*=10000;
		arr[i].second*=10000;
	}
	int best=0;
	for(long double i=0;i<=1000000;i+=1000){
		for(long double j=0;j<=1000000;j+=1000){
			int cnt=0;
			for(int k=0;k<n;k++){
					if(ceil((sqrt(pow(i/2-arr[k].first,2)+pow(j/2-arr[k].second,2))))<=25120){
					cnt+=1;
				}
			}
//			if(i==1)pr(i,j,"");
//			if(i==(double)1&&j==(double)22.5)pr(cnt,"");
			best=max(best,cnt);
		}
		//pr("\n");
	}
	pr(best);
	return 0;
}