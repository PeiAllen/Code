#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

struct frac{
  ll n,d;
  frac(ll a=0, ll b=1){
      n=a,d=b;
      reduce();
  }
  void reduce(){
      if(n<0)n*=-1,d*=-1;
      ll gc=gcd(abs(n),abs(d));
      n/=gc,d/=gc;
  }
  frac operator+(const frac &a)const{
      return frac(n*a.d+a.n*d,d*a.d);
  }
  frac operator-(const frac &a) const{
      return (*this+frac(a.n,a.d*-1));
  }
  frac operator*(const frac &a)const{
      return frac(n*a.n,d*a.d);
  }
  frac operator/(const frac &a)const{
      return *this*frac(a.d,a.n);
  }
    bool operator<(const frac &a) const { return __int128(n) * __int128(a.d) < __int128(a.n) * __int128(d); }

    bool operator==(const frac &a) const { return !(*this < a) && !(a < *this); }

    bool operator>=(const frac &a) const { return !(*this < a); }

    bool operator<=(const frac &a) const { return !(a < *this); }

    bool operator>(const frac &a) const { return a < *this; }

    bool operator!=(const frac &a) const { return (*this < a) || (a < *this); }
};

map<vector<frac>,bool> memo;
bool solve(vector<frac> a){
    sort(a.begin(),a.end());
    if(memo.count(a))return memo[a];
    if(sz(a)==1)return false;
    for(int i=0;i<sz(a);i++){
        for(int j=0;j<sz(a);j++){
            if(i!=j){
                vector<frac> next;
                next.
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memo[{frac(24)}]=1;

    return 0;
}