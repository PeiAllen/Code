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
int n;
vector<int> tocheck;
bool check(int am){
    tocheck.clear();
    int cnt=am;
    for(int i=0;i<n-am;i++){
        tocheck.push_back(arr[i]);
    }
    sort(tocheck.begin(),tocheck.end());
    for(int i=0;i<sz(tocheck);i++){
        if(cnt<=tocheck[i])return true;
        cnt++;
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n);
    rep(i,0,n){
        sc(arr[i]);
    }
    int lo=0,hi=n-1;
    while(lo!=hi){
        int mid=(lo+hi)/2+1;
        if(check(mid))lo=mid;
        else hi=mid-1;
    }
    prl(lo);
    return 0;
}