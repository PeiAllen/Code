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
int n,b;
int bit[MAXN];
int coms;
void update(int loc, int val){
    for(;loc<=coms;loc+=loc&-loc)bit[loc]=max(bit[loc],val);
}
int query(int loc){
    int ans=0;
    for(;loc>0;loc-=loc&-loc)ans=max(ans,bit[loc]);
    return ans;
}
int val[MAXN];
int deq[MAXN];
int le,ri;
int leftsm[MAXN],rightsm[MAXN];
vector<int> compress;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,b);
    rep(i,1,n+1)sc(val[i]),compress.push_back(val[i]);
    sort(compress.begin(),compress.end());
    compress.erase(unique(compress.begin(),compress.end()),compress.end());
    coms=sz(compress);
    le=0,ri=-1;
    deq[++ri]=1;
    rep(i,2,n){
        while(ri>=le&&val[deq[ri]]>=val[i])ri--;
        if(ri>=le)leftsm[i]=deq[ri];
        else leftsm[i]=-1;
        deq[++ri]=i;
    }
    le=0,ri=-1;
    deq[++ri]=n;
    for(int i=n-1;i>=2;i--){
        while(ri>=le&&val[deq[ri]]>=val[i])ri--;
        if(ri>=le)rightsm[i]=deq[ri];
        else rightsm[i]=-1;
        deq[++ri]=i;
    }
    rep(i,1,n){
        if(leftsm[i]!=-1){
            update(coms-((lower_bound(compress.begin(),compress.end(),val[i])-compress.begin())-1),rightsm[i]-leftsm[i]);
        }
    }
    int s,d;
    while(b--){
        sc(s,d);
        prl(query(coms-((upper_bound(compress.begin(),compress.end(),s)-compress.begin())-1))<=d);
    }
    return 0;
}