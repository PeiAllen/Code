#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
struct frac{
    ll n,d;
    frac(ll a,ll b){
        n=a,d=b;
        reduce();
    }
    void reduce(){
        if(d<0)d*=-1,n*=-1;
        ll gc=__gcd(abs(n),abs(d));
        n/=gc,d/=gc;
    }
    frac operator+(const frac &a) const{
        return frac(n*a.d+a.n*d,d*a.d);
    }
    bool operator<(const frac &a) const{
        return n*a.d<a.n*d;
    }
};
const int MN=1001;
string ans[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    frac slope(m,n);
    frac cur(0,1);
    for(int i=0;i<m;i++)ans[i]=string(n,'.');
    for(int i=0;i<n;i++){
        frac next=cur+slope;
        for(int j=0;j<m;j++){
            if(cur<frac(j+1,1)&&frac(j,1)<next){
                ans[m-j-1][i]='#';
            }
        }
        cur=next;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)printf("%c",ans[i][j]);
        printf("\n");
    }
    return 0;
}