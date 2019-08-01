#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int arr[10001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int in;
    for(int i=0;i<n;i++){
		cin>>in;
		arr[in]+=1;
    }
    int am=0;
    int loc=0;
    for(int i=1;i<=10000;i++){
    	if(arr[i]>=am){
    		am=arr[i];
    		loc=i;
    	}
    }
    printf("%d\n",loc);
    return 0;
}