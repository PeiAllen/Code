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
string s;
bool done[10000][2];
set<string> dp[10000][2];
void run(int loc, int wh){
    string cur=(wh?s.substr(loc+1,3):s.substr(loc+1,2));
    if(loc-2>=4&&s.substr(loc-1,2)!=cur){
        dp[loc][wh].insert(s.substr(loc-1,2));
        run(loc-2,0);
        dp[loc][wh].insert(dp[loc-2][0].begin(),dp[loc-2][0].end());
    }
    if(loc-3>=4&&s.substr(loc-2,3)!=cur){
        dp[loc][wh].insert(s.substr(loc-2,3));
        run(loc-3,1);
        dp[loc][wh].insert(dp[loc-3][1].begin(),dp[loc-3][1].end());
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(s);
    s=s+"$$$";
    run(sz(s)-4,0);
    prl(sz(dp[sz(s)-4][0]));
    for(string x:dp[sz(s)-4][0])prl(x);
    return 0;
}