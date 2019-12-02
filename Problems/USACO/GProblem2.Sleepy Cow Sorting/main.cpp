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
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e5+1;
int bit[MAXN];
int n;
void update(int loc){
	for(;loc<=n;loc+=loc&-loc)bit[loc]+=1;
}
int query(int loc){
	int sum=0;
	for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
	return sum;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("sleepy.in","r",stdin);
	freopen("sleepy.out","w",stdout);
	sc(n);
	int arr[n];
	rep(i,0,n)sc(arr[i]);
	int loc=2;
	update(arr[n-1]);
	while(loc<=n&&arr[n-loc]<arr[n-loc+1]){
		update(arr[n-loc]);
		loc++;
	}
	prl(n-loc+1);
	for(int i=0;i<n-loc;i++){
		pr(query(arr[i])+n-loc-i,"");
		update(arr[i]);
	}
	if(n-loc+1>0)prl(query(arr[n-loc])+n-loc-(n-loc));
	return 0;
}