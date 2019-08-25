#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    string arr[n];
    string sorted[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	sorted[i]=arr[i];
    	sort(sorted[i].begin(),sorted[i].end());
    }
    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		if(sorted[i]==sorted[j]){
    			int le=INT_MAX;
    			int ri=-1;
    			for(int k=0;k<n;k++){
    				if(arr[i][k]!=arr[j][k]){
    					le=min(le,k);
    					ri=max(ri,k);
    				}
    			}
    			if(le>ri||ri-le+1<=k){
    				printf("DA\n");
    				return 0;
    			}
    		}
    	}
    }
    printf("NE\n");
    return 0;
}