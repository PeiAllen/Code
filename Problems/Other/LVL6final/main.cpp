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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,l;
    sc(n,l);
    pii arr[n];
    int ma=0;
    int othma=0;
    int mi=0;
    rep(i,0,n){
        sc(arr[i].first,arr[i].second);
        int a=max(arr[i].first,arr[i].second);
        int b=min(arr[i].first,arr[i].second);
        if(arr[i].first>ma){
            othma=abs(arr[i].first-arr[i].second);
        }
        ma=max(a,ma);
        mi=min(a,min(mi,b));
    }
    sort(arr,arr+n);
    int ans=0;
    rep(i,0,n){
        ans+=2*abs(arr[i].first-arr[i].second);
        if(i!=n-1)ans-=abs(arr[i].first-arr[i+1].first);
    }
    ans-=othma;
    ans+=l-ma;
    ans+=mi;
    prl(ans);
    return 0;
}