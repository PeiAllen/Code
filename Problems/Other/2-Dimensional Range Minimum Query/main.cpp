#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e3;
int sparse[MAXN][10][MAXN][10];
int n;
void init(std::vector<std::vector<int>> arr){
	n=sz(arr);
	rep(i,0,n)rep(j,0,n)sparse[i][0][j][0]=arr[i][j];
	for (int i = 0; i < n; i++) {
		for (int b = 1; b <= log2(n); b++) {
			for (int j = 0; j <= n - (1 << b); j++) {
				sparse[i][0][j][b]=min(sparse[i][0][j][b-1],sparse[i][0][j+(1<<(b-1))][b-1]);
			}
		}
	}
	for(int a=1;a<=log2(n);a++) {
		for (int i = 0; i <= n - (1 << a); i++) {
			for (int j = 0; j <n; j++) {
				sparse[i][a][j][0] = min(sparse[i][a-1][j][0], sparse[i+(1<<(a-1))][a-1][j][0]);
			}
		}
	}
	for(int a=1;a<=log2(n);a++) {
		for (int i = 0; i <= n - (1 << a); i++) {
			for(int b=1;b<=log2(n);b++){
				for(int j=0;j<=n-(1<<b);j++){
					sparse[i][a][j][b]=min(sparse[i][a-1][j][b-1],min(sparse[i+(1<<(a-1))][a-1][j][b-1],min(sparse[i][a-1][j+(1<<(b-1))][b-1],sparse[i+(1<<(a-1))][a-1][j+(1<<(b-1))][b-1])));
				}
			}
		}
	}
}
int query(int a, int b, int c, int d){
	int k1=log2(b-a+1);
	int k2=log2(d-c+1);
	return min(sparse[a][k1][c][k2],min(sparse[b-(1<<k1)+1][k1][c][k2],min(sparse[a][k1][d-(1<<k2)+1][k2],sparse[b-(1<<k1)+1][k1][d-(1<<k2)+1][k2])));
}
//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//	init({{1, 2}, {3, 4}});
//	prl(query(0, 1, 0, 1));
//	prl(query(1, 1, 0, 1));
//	prl(query(0, 0, 1, 1));
//    return 0;
//}