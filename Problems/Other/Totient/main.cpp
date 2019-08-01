#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int m=1e9+7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n;
    cin>>n;
    bool power[n+1]={ };
    power[1]=true;
    for(lli i=2;i<=n;i++){
    	for(lli j=i*i;j<=n;j*=i)power[j]=true;
    }
    lli totient[n+1];
    iota(totient,totient+n+1,0);
    lli ans=0;
    for(lli i=2;i<=n;i++){
    	if(totient[i]==i){
			for(lli j=i;j<=n;j+=i){
				totient[j]=totient[j]/i*(i-1);
			}
    	}
    	ans=(ans+(power[totient[i]]?totient[i]:0))%m;
    }
    printf("%lli\n",(ans+(n>=1?1:0))%m);
    return 0;
}