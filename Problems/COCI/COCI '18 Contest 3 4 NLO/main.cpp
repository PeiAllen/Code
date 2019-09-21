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

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m,k;
	sc(n,m,k);
	pair<pii,int> arr[k];
	rep(i,0,k){
		sc(arr[i].first.first,arr[i].first.second,arr[i].second);
	}
	lli ans=(lli)n*(lli)m*(lli)k;
	rep(i,1,n+1){
		vector<pii> vec;
		set<int> se;
		se.insert(0);
		rep(j,0,k){
			if(i<arr[j].first.first-arr[j].second||i>arr[j].first.first+arr[j].second)continue;
			int diff=(int)sqrt(pow((lli)arr[j].second,2)-pow((lli)i-(lli)arr[j].first.first,2));
			vec.push_back({max(1,arr[j].first.second-diff),j+1});
			vec.push_back({min(m+1,arr[j].first.second+diff+1),-(j+1)});
		}
		sort(vec.begin(),vec.end());
		int prev=1;
		for(auto x:vec){
			ans-=(lli)(x.first-prev)*(lli)*se.rbegin();
			prev=x.first;
			if(x.second<0){
				se.erase(abs(x.second));
			}
			else se.insert(x.second);
		}
	}
	prl(ans);
	return 0;
}