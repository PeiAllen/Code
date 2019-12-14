#include <bits/stdc++.h>
#include "testlib.h"
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
string arr[10000];
int main(int argc, char * argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	registerGen(argc, argv, 1);
	rnd.setSeed(time(0));
	for(int cases=1;cases<=20;cases++) {
		ofstream o("case"+to_string(cases)+".in");
		int n = rnd.next(1, 10000);
		if(cases>10)n=10000;
		o<<n<<"\n";
		int numstring = max(1, rnd.next(n / 2, n));
		rep(i, 0, numstring) {
			arr[i] = rnd.next("[a-zA-Z0-9]{1,100}");
		}
		set<string> used;
		set<string> ans;
		rep(i, 0, n) {
			int ind=rnd.next(0,numstring-1);
			if(used.count(arr[ind]))ans.insert(arr[ind]);
			else used.insert(arr[ind]);
			o<<arr[ind]<<"\n";
		}
		o.close();
		ofstream o2("case"+to_string(cases)+".out");
		for(string x:ans){
			o2<<x<<"\n";
		}
		o2.close();
	}
    return 0;
}