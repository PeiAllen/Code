#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int dp[2][20002];
    int premax[2][20002];
    int a,b;
    cin>>a;
    for(int i=0;i<=20001;i++){
		if(i<a)dp[0][i]=i;
		else dp[0][i]=-20001;
		premax[0][i]=max(dp[0][i],i>0?premax[0][i-1]:0);
    }
    int flip=1;
    int oth=0;
    for(int i=1;i<n;i++){
    	cin>>a>>b;
    	for(int j=0;j<=20001;j++){
    		if(j<b){
    			dp[flip][j]=max(premax[oth][a-1]+j,dp[oth][a+j]);
    		}
    		else if(j<a+b){
    			dp[flip][j]=dp[oth][j-b]+b;
    		}
    		else{
    			dp[flip][j]=dp[oth][j];
    		}
    		premax[flip][j]=max(dp[flip][j],j>0?premax[flip][j-1]:0);
    	}
    	int te=oth;
    	oth=flip;
    	flip=te;
    }
    printf("%d\n",premax[oth][20001]);
    return 0;
}