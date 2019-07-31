#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int sparse[n][(int)log2(n)+1];
    for(int i=0;i<n;i++){
    	cin>>sparse[i][0];
    }
    for(int i=1;i<=log2(n);i++){
    	for(int j=0;j<=n-(1<<i);j++){
    		sparse[j][i]=max(sparse[j][i-1],sparse[j+(1<<(i-1))][i-1]);
    	}
    }
    int a,b;
    while(m--){
    	cin>>a>>b;
    	a-=1;
    	b-=1;
    	int k=log2(b-a+1);
    	printf("%d\n",max(sparse[a][k],sparse[b-(1<<k)+1][k]));
    }
    return 0;
}