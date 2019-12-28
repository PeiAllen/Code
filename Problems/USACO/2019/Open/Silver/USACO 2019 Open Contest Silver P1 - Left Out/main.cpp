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
bool arr[1001][1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	char in;
	rep(i,0,n){
		rep(j,0,n){
			sc(in);
			arr[i][j]=(in=='R');
		}
	}
	vector<int> flipped;
	rep(i,0,n) {
		if (arr[n - 1][i]) {
			flipped.push_back(i);
			rep(j, 0, n)arr[j][i] = !arr[j][i];
		}
	}
	vector<pii> badpoints;
	rep(i,0,n-1){
		vector<int> cnt[2];
		rep(j,0,n){
			cnt[arr[i][j]].push_back(j);
		}
		if(sz(cnt[0])==1){
			badpoints.push_back({i,cnt[0][0]});
		}
		else if(sz(cnt[1])==1){
			badpoints.push_back({i,cnt[1][0]});
		}
		else if(!(sz(cnt[0])==0||sz(cnt[1])==0)){
			badpoints.push_back({0,0});
			badpoints.push_back({0,0});
		}
	}
	if(sz(badpoints)==1) {
		prl(badpoints[0].first+1, badpoints[0].second+1);
		return 0;
	}
	if(n==1){
		prl(-1);
		return 0;
	}
	for(int x:flipped){
		rep(j, 0, n)arr[j][x] = !arr[j][x];
	}
	rep(i,0,n) {
		if (arr[n - 2][i]) {
			rep(j, 0, n)arr[j][i] = !arr[j][i];
		}
	}
	badpoints.clear();
	rep(i,0,n){
		vector<int> cnt[2];
		rep(j,0,n){
			cnt[arr[i][j]].push_back(j);
		}
		if(sz(cnt[0])==1){
			badpoints.push_back({i,cnt[0][0]});
		}
		else if(sz(cnt[1])==1){
			badpoints.push_back({i,cnt[1][0]});
		}
		else if(!(sz(cnt[0])==0||sz(cnt[1])==0)){
			badpoints.push_back({0,0});
			badpoints.push_back({0,0});
		}
	}
	if(sz(badpoints)==1) {
		prl(badpoints[0].first+1, badpoints[0].second+1);
		return 0;
	}
	prl(-1);
	return 0;
}