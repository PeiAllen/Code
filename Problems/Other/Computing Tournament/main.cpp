#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    pair<int,pii> arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i].first>>arr[i].second.first;
    	arr[i].second.second=i;
    }
    sort(arr,arr+n,greater<pair<int,pii>>());
    int ma=-1,ind=-1;
    for(int i=0;i<k;i++){
    	if(arr[i].second.first>ma){
    		ma=arr[i].second.first;
    		ind=arr[i].second.second;
    	}
    }
    printf("%d\n",ind+1);
    return 0;
}