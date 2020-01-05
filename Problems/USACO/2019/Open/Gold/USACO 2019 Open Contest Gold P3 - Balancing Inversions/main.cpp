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
void prl(T a){cout<<a<<endl;}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e5+1;
lli lmn[MAXN];
lli rmn[MAXN];
lli lmninv[MAXN][2];
lli rmninv[MAXN][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    int in;
    int am[2]={};
    set<int> free[2];
    set<int> one[2];
    lli inv[2]={};
    rep(i,0,2*n){
        sc(in);
        if(in)one[i/n].insert(i),am[i/n]++;
        else inv[i/n]+=(lli)am[i/n],free[i/n].insert(i);
    }
    lmninv[0][0]=inv[0];
    lmninv[0][1]=inv[1];
    rmninv[0][0]=inv[0];
    rmninv[0][1]=inv[1];
    int cur=1;
    while(sz(free[0])&&sz(one[1])){
        lmninv[cur][0]=lmninv[cur-1][0]-(cur-1+am[0]-(n-*prev(free[0].end(),1)-1));
        lmninv[cur][1]=lmninv[cur-1][1]-(n-(am[1]-(cur-1))-(*one[1].begin()-n));
        lmn[cur]=lmn[cur-1]+n-*prev(free[0].end(),1)+*one[1].begin()-n;
        free[0].erase(prev(free[0].end(),1));
        one[1].erase(one[1].begin());
        cur++;
    }
    cur=1;
    while(sz(free[1])&&sz(one[0])){
        rmninv[cur][0]=rmninv[cur-1][0]-(n-*prev(one[0].end(),1)-1)+am[0]-cur;
        rmninv[cur][1]=rmninv[cur-1][1]-(*free[1].begin()-n)+n-(am[1]+(cur-1))-1;
        rmn[cur]=rmn[cur-1]+*free[1].begin()-n+1+n-*prev(one[0].end(),1)-1;
        free[1].erase(free[1].begin());
        one[0].erase(prev(one[0].end(),1));
        cur++;
    }
    lli ans=LLONG_MAX;
    int st=max(0,am[0]+am[1]-n);
    int en=min(n,am[0]+am[1])+1;
    rep(i,st,en){
        if(am[0]>i){
            ans=min(ans,rmn[am[0]-i]+abs(rmninv[am[0]-i][0]-rmninv[am[0]-i][1]));
        }
        else{
            ans=min(ans,lmn[i-am[0]]+abs(lmninv[i-am[0]][0]-lmninv[i-am[0]][1]));
        }
    }
    prl(ans);
    return 0;
}