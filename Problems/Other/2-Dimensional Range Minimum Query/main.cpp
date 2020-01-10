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
int sparse[10][10][MAXN][MAXN];
int n;
void init(vector<vector<int>> arr){
    n=sz(arr);
    int lgn=31-__builtin_clz(n);
    rep(i,0,n)rep(j,0,n)sparse[0][0][i][j]=arr[i][j];
    for (int b = 1; b <= lgn; b++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n - (1 << b); j++) {
                sparse[0][b][i][j]=min(sparse[0][b-1][i][j],sparse[0][b-1][i][j+(1<<(b-1))]);
            }
        }
    }
    for(int a=1;a<=lgn;a++) {
        for (int i = 0; i <= n - (1 << a); i++) {
            for (int j = 0; j <n; j++) {
                sparse[a][0][i][j] = min(sparse[a-1][0][i][j], sparse[a-1][0][i+(1<<(a-1))][j]);
            }
        }
    }
    for(int a=1;a<=lgn;a++) {
        for(int b=1;b<=lgn;b++){
            for (int i = 0; i <= n - (1 << a); i++) {
                for(int j=0;j<=n-(1<<b);j++){
                    sparse[a][b][i][j]=min(sparse[a-1][b-1][i][j],min(sparse[a-1][b-1][i+(1<<(a-1))][j],min(sparse[a-1][b-1][i][j+(1<<(b-1))],sparse[a-1][b-1][i+(1<<(a-1))][j+(1<<(b-1))])));
                }
            }
        }
    }
}
int query(int a, int b, int c, int d){
    int k1=31-__builtin_clz(b-a+1);
    int k2=31-__builtin_clz(d-c+1);
    int k1s=(1<<k1),k2s=(1<<k2);
    return min(sparse[k1][k2][a][c],min(sparse[k1][k2][b-k1s+1][c],min(sparse[k1][k2][a][d-k2s+1],sparse[k1][k2][b-k1s+1][d-k2s+1])));
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