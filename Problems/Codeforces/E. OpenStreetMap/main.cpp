#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int n,m,a,b;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin>>n>>m>>a>>b;
	lli g,x,y,z;
	cin>>g>>x>>y>>z;
	lli gvals[n*m];
	gvals[0]=g;
	for(lli i=1;i<=n;i++){
		for(lli j=1;j<=m;j++){
			bit[i][j]=LLONG_MAX;
		}
	}
	for(lli i=1;i<n*m;i++){
		gvals[i]=(gvals[i-1]*x+y)%z;
	}
	lli ans=0;
	if(a<=b) {
		for (lli i = n; i > 0; i--) {
			for (lli j = m; j > 0; j--) {
				update(i, j, gvals[(i - 1) * m + j - 1]);
				if (i + a - 1 <= n && j + b - 1 <= m) {
					ans += query(i + a - 1, j + b - 1);
				}
			}
		}
	}
    return 0;
}