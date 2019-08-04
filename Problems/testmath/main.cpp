#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cnt=0;
    for(int i=1;i<=100;i++){
    	int sum=i%10+(i/10);
    	if(i%sum==0){
    		printf("%d\n",i);
    		cnt++;
    	}
    }
    printf("%d\n",cnt);
    return 0;
}