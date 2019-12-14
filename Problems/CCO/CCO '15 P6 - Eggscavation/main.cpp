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
int MAXP=1e5;
int scoop[2502][2502];
int bit[(int)1e5+1];
set<int> ndone[2501];
void update(int loc, int am){
    for(;loc<=MAXP;loc+=loc&-loc)bit[loc]+=am;
}
int sum(int loc){
    int ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=bit[loc];
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,m;
    sc(n,k,m);
    int s;
    int coords[4][2];
    double tot=(n-k+1)*(n-k+1);
    rep(i,0,m){
        sc(s);
        rep(j,0,s){
            sc(coords[j][0],coords[j][1]);
        }
        rep(j,1,(1<<s)){
           int mi[2]={INT_MAX,INT_MAX},ma[2]={};
           rep(l,0,s){
               if(j&(1<<l)){
                   mi[0]=min(mi[0],coords[l][0]);
                   ma[0]=max(ma[0],coords[l][0]);
                   mi[1]=min(mi[1],coords[l][1]);
                   ma[1]=max(ma[1],coords[l][1]);
               }
           }
           int am=(__builtin_popcount(j)%2?1:-1);
           if(ma[0]-mi[0]+1<=k&&ma[1]-mi[1]+1<=k){
               scoop[max(1,ma[0]-k+1)][max(1,ma[1]-k+1)]+=am;
               scoop[max(1,ma[0]-k+1)][mi[1]+1]-=am;
               scoop[mi[0]+1][max(1,ma[1]-k+1)]-=am;
               scoop[mi[0]+1][mi[1]+1]+=am;
           }
        }
    }
    rep(i,1,n-k+2)rep(j,1,n-k+2){
        ndone[i].insert(j);
        scoop[i][j]+=scoop[i-1][j]+scoop[i][j-1]-scoop[i-1][j-1];
        if(scoop[i][j])update(scoop[i][j],1);
    }
    int t,a,b;
    sc(t);
    while(t--){
        sc(s);
        if(s==1){
            sc(a,b);
            for(int i=max(1,a-k+1);i<min(n-k+2,a+1);i++){
                auto st=ndone[i].lower_bound(max(1,b-k+1));
                auto en=ndone[i].lower_bound(b+1);
                for(auto j=st;j!=en;j++){
                    if(scoop[i][*j])update(scoop[i][*j],-1);
                }
                ndone[i].erase(st,en);
            }
        }
        else{
            sc(a);
            if(a-1>MAXP)printf("0\n");
            else printf("%.6f\n",(double)(sum(MAXP)-sum(a-1))/tot);
        }
    }
    return 0;
}