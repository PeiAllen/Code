#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int arr[3001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    lli num=0;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	for(int j=i-1;j>=0;j--){
    		if(arr[j]>arr[i])num+=1;
    	}
    }
    printf("%lli\n",num);
    return 0;
}