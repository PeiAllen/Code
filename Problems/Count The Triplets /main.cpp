#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    set<int> count;
    set<pair<int,int>> count2;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	count.insert(arr[i]);
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<i;j++){
    		if(count.count(arr[i]+arr[j])){
    			count2.insert({min(arr[i],arr[j]),max(arr[i],arr[j])});
    		}
    	}
    }
    printf("%d\n",(count2.size()?count2.size():-1));
    return 0;
}