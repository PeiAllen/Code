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
bool dp[1000001][101];
bool gone[1000001][101];
int k;
bool go(int am, int last){
	if(am<0)return true;
	if(gone[am][last])return dp[am][last];
	gone[am][last]=true;
	for(int i=1;i<=k;i++){
		if(i!=last){
			if(!go(am-i,i)){
				dp[am][last]=true;
				return true;
			}
		}
	}
	dp[am][last]=false;
	return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //for(int i=1;i<=100;i+=2){
    	k=55;
    	memset(gone,false,sizeof(gone));
    	vector<int> ams;
		rep(j,1,1000000){
			int te=go(j,0);
			if(te) {
				if (!sz(ams) || !ams.back())ams.push_back(te);
				else ams[sz(ams) - 1] += 1;
			}
			else ams.push_back(te);
		}
		pr(55,": ");
		for(int x:ams)if(x)pr(x,"");
    	prl("");
  //  }
    return 0;
}