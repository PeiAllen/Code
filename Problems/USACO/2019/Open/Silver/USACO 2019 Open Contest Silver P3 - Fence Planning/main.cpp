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
const int MAXN=1e5+1;
pii disjoint[MAXN];
int find(int a){
    if(disjoint[a].first==a)return a;
    return disjoint[a].first=find(disjoint[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return;
    if(disjoint[ap].second<disjoint[bp].second)swap(ap,bp);
    disjoint[ap].second+=disjoint[bp].second;
    disjoint[bp].first=ap;
}
pll arr[MAXN];
pll mi[MAXN];
pll ma[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    sc(n,m);
    int a,b;
    rep(i,1,n+1)sc(arr[i].first,arr[i].second),disjoint[i]={i,1},mi[i]={LLONG_MAX,LLONG_MAX};
    rep(i,0,m){
        sc(a,b);
        uni(a,b);
    }
    set<int> tocheck;
    rep(i,1,n+1){
        int p=find(i);
        tocheck.insert(p);
        mi[p].first=min(mi[p].first,arr[i].first);
        ma[p].first=max(ma[p].first,arr[i].first);
        mi[p].second=min(mi[p].second,arr[i].second);
        ma[p].second=max(ma[p].second,arr[i].second);
    }
    lli ans=LLONG_MAX;
    for(int x:tocheck){
        ans=min(ans,2*(ma[x].second-mi[x].second+ma[x].first-mi[x].first));
    }
    prl(ans);
    return 0;
}