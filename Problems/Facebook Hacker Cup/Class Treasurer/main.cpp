#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mo=1000000007;
///for each b check if its part of a subarray thats starts at b, if it is, delete. cause the price of deleint b is larger then price of deleting all below him added u[
//babb 1
//and start from back. and do updates
int diff[1000001];
lli po2[1000001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	freopen("/Users/allen/CLionProjects/Class Treasurer/in.txt","r",stdin);
	freopen("/Users/allen/CLionProjects/Class Treasurer/out.txt","w",stdout);
	int t;
    cin>>t;
    for(int test=1;test<=t;test++){
    	int n,k;
    	cin>>n>>k;
    	string in;
    	cin>>in;
    	diff[0]=0;
    	po2[0]=1;
    	for(int i=1;i<=n;i++){
    		po2[i]=(po2[i-1]*2)%mo;
    		diff[i]=diff[i-1]+(in[i-1]=='A'?-1:1);
    	}
    	int ma=diff[n];
    	lli ans=0;
    	for(int i=n;i>0;i--){
    		if(diff[i]>ma)ma=diff[i];
    		if(ma-diff[i-1]>k){
    			ans=(ans+po2[i])%mo;
    			ma-=2;
    		}
    	}
    	printf("Case #%d: %lli\n",test,ans);
    }
    return 0;
}

min(s-max(0,((s+t)-n)),t-max(0,((s+t)-n)))+1

n=3,s=3,t=3 1