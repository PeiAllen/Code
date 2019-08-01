#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n;
    cin>>n;
    lli num=0;
    for(lli i=1;i<=sqrt(n);i++){
    	if(n%i==0)num+=2;
    	if(i*i==n)num-=1;
    }
    printf("%lli\n",num);
    return 0;
}