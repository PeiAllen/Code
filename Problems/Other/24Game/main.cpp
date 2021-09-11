#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

struct frac{
    ll n,d;
    frac(ll a=0, ll b=1){
        n=a,d=b;
        reduce();
    }
    void reduce(){
        if(n<0)n*=-1,d*=-1;
        ll gc=__gcd(abs(n),abs(d));
        n/=gc,d/=gc;
    }
    frac operator+(const frac &a)const{
        return frac(n*a.d+a.n*d,d*a.d);
    }
    frac operator-(const frac &a)const{
        return *this+frac(-a.n,a.d);
    }
    frac operator*(const frac &a)const{
        return frac(n*a.n,d*a.d);
    }
    frac operator/(const frac &a)const{
        return *this*frac(a.d,a.n);
    }
    bool operator<(const frac &a)const{
        return n*a.d<a.n*d;
    }
    bool operator==(const frac &a)const{
        return (!(*this<a))&&(!(a<*this));
    }
    bool operator!=(const frac &a)const{
        return *this<a||a<*this;
    }
    bool operator>(const frac &a)const{
        return a<*this;
    }
    bool operator>=(const frac &a)const{
        return !(*this<a);
    }
    bool operator<=(const frac &a)const{
        return !(a<*this);
    }
};

map<vector<frac>,int> memo;
int solve(vector<frac> a){
    sort(a.begin(),a.end());
    if(memo.count(a))return memo[a];
    if(sz(a)==1)return (a[0].n<=24?a[0].n:0);
    int best=0;
    for(int i=0;i<sz(a);i++){
        for(int j=0;j<sz(a);j++){
            if(i!=j){
                vector<frac> te;
                for(int k=0;k<sz(a);k++)if(k!=i&&k!=j)te.push_back(a[k]);
                te.push_back(a[i]+a[j]);
                best=max(best,solve(te));
                te.pop_back();
                te.push_back(a[i]-a[j]);
                best=max(best,solve(te));
                te.pop_back();
                te.push_back(a[i]*a[j]);
                best=max(best,solve(te));
                te.pop_back();
                if(a[j]!=frac(0)&&(a[i]/a[j]).d==1) {
                    te.push_back(a[i] / a[j]);
                    best = max(best,solve(te));
                    te.pop_back();
                }
            }
        }
    }
    return memo[a]=best;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b,c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        printf("%d\n",solve({frac(a),frac(b),frac(c),frac(d)}));
    }
    return 0;
}