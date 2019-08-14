#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	string a;
	cin>>a;
	int ma=0,loc=0;
	for(int i=0;i<n;i++){
		if(arr[i].size()<=a.size()){
			if(arr[i].size()>ma){
				ma=arr[i].size();
				loc=i;
			}
		}
	}
	cout<<arr[loc]<<"\n";
	return 0;
}