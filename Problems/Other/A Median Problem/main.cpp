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
int arr[MAXN];
set<int> canuse;
vector<int> bads[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	rep(i,0,n)sc(arr[i]);
	rep(i,1,2*n)canuse.insert(i);
	for(int i=n-1;i>=1;i--){
		if(arr[i]==arr[i-1])continue;
		int l=arr[i];
		int r=arr[i-1];
		if(l>r)swap(l,r);
		auto it=canuse.upper_bound(l);
		auto end=canuse.lower_bound(r);
		for(auto j=it;j!=end;j++){
			bads[i].push_back(*j);
		}
		canuse.erase(it,end);
	}
	vector<int> ans;
	canuse.erase(arr[0]);
	ans.push_back(arr[0]);
	rep(i,1,n){
		for(int x:bads[i])canuse.insert(x);
		if(arr[i]>arr[i-1]){
			auto it=canuse.lower_bound(arr[i]);
			ans.push_back(*it);
			ans.push_back(*next(it,1));
			canuse.erase(it,next(it,2));
		}
		else if(arr[i]<arr[i-1]){
			auto it=canuse.upper_bound(arr[i]);
			it--;
			ans.push_back(*it);
			ans.push_back(*prev(it,1));
			canuse.erase(prev(it,1),next(it,1));
		}
		else{
			auto it=canuse.lower_bound(arr[i]);
			ans.push_back(*it);
			it--;
			ans.push_back(*it);
			canuse.erase(it,next(it,2));
		}
	}
	for(int x:ans){
		pr(x,"");
	}
    return 0;
}