#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli arr[16][16];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
    }
    lli precalc[(1<<n)]={};
    for(int i=1;i<(1<<n);i++){
	    vector<int> used;
	    lli am=0;
	    for(int k=0;k<n;k++){
		    if(i&(1<<k)){
			    for(int x:used){
				    am+=arr[x][k];
			    }
			    used.push_back(k);
		    }
	    }
	    precalc[i]=am;
    }
    lli dp[(1<<n)]={};
    for(int i=1;i<(1<<n);i++){
    	for(int j=i;j>0;j=(j-1)&i){
    		dp[i]=max(dp[i],dp[i-j]+precalc[j]);
    	}
    }
    printf("%lli\n",dp[(1<<n)-1]);
    return 0;
}