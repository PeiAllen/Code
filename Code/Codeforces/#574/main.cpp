#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli bit[3001][3001];
lli n,m,a,b;
void update(lli x, lli y, lli val){
	for(int i=x;i<=n;i+=i&-i){
		for(int j=y;j<=m;j+=j&-j){
			bit[i][j]=min(bit[i][j],val);
		}
	}
}
lli query(lli x, lli y){
	lli ans=LLONG_MAX;
	for(int i=x;i>0;i-=i&-i){
		for(int j=y;j>0;j-=j&-j){
			ans=min(bit[i][j],ans);
		}
	}
	return ans;
}
int main() {
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
	if(a<b) {
		for (lli i = n; i > 0; i--) {
			for (lli j = m; j > 0; j--) {
				update(i, j, gvals[(i - 1) * m + j - 1]);
				if (i + a - 1 <= n && j + b - 1 <= m) {
					ans += query(i + a - 1, j + b - 1);
				}
			}
		}
	}
	else if(b<=a){
		for (lli i = m; i > 0; i--) {
			for (lli j = n; j > 0; j--) {
				update(j, i, gvals[(j - 1) * m + i - 1]);
				if (j + a - 1 <= n && i + b - 1 <= m) {
					ans += query(j + a - 1, i + b - 1);
				}
			}
		}
	}
//	else{
//		for(int i=m;i>0;i--){
//			for(int j=n;j>=n-a;j--){
//				update(j, i, gvals[(j - 1) * m + i - 1]);
//				if (j + a - 1 <= n && i + b - 1 <= m) {
//					ans += query(j + a - 1, i + b - 1);
//				}
//			}
//		}
//		for(int i=n-a;i>0;i--){
//			for(int j=m;j>0;j--){
//				update(i, j, gvals[(i - 1) * m + j - 1]);
//				if (i + a - 1 <= n && j + b - 1 <= m) {
//					ans += query(i + a - 1, j + b - 1);
//				}
//			}
//		}
//	}
	printf("%lli\n",ans);
	return 0;
}