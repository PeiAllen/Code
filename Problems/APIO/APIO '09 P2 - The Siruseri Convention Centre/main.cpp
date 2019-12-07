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
const int MAXN=2e5+1;
map<int,vector<pair<pii,int>>> byfo;
map<int,vector<pair<pii,int>>> byen;
pii arr[MAXN];
int dpfo[2*MAXN];
int dpba[2*MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    vector<int> points;
    points.push_back(1e9+1);
    points.push_back(0);
    int a,b;
	rep(i,1,n+1){
		sc(a,b);
		points.push_back(a);
		points.push_back(b);
		arr[i]={a,b};
		byfo[a].push_back({{a,b},i});
		byen[b].push_back({{a,b},i});
	}
	sort(points.begin(),points.end());
	points.erase(unique(points.begin(),points.end()),points.end());
	for(int i=sz(points)-2;i>=0;i--){
		dpba[i]=dpba[i+1];
		for(auto x:byfo[points[i]]) {
			int oth = (lower_bound(points.begin(), points.end(), x.first.second) - points.begin()) + 1;
			dpba[i]=max(dpba[i],1+dpba[oth]);
		}
	}
	rep(i,1,sz(points)){
		dpfo[i]=dpfo[i-1];
		for(auto x:byen[points[i]]){
			int oth = (lower_bound(points.begin(), points.end(), x.first.first) - points.begin()) - 1;
			dpfo[i]=max(dpfo[i],1+dpfo[oth]);
		}
	}
	prl(dpba[0]);
    return 0;
}