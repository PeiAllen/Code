#include <bits/stdc++.h>
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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e6;
lli c[MAXN],r[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
	sc(n);
	rep(i,0,n)sc(c[i]);
	rep(i,0,n)sc(r[i]);
	sort(c,c+n),sort(r,r+n);
	if(c[n-1]!=r[n-1]){
		prl("-1");return 0;
	}
	int p=-1;
	lli pre=0,ans=0;
	rep(i,0,n){
		while(p+1<n&&r[p+1]<c[i])pre+=r[++p];
		ans+=pre+c[i]*(n-p-1);
	}
	prl(ans);
    return 0;
}