#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
using frac=long double;
//struct frac {
//    ll n, d;
//
//    frac(ll num = 0, ll den = 1) {
//        n = num, d = den;
//        if (d < 0)d *= -1, n *= -1;
//         //reduce();
//    }
//
//    void reduce() {
//        if (d < 0)d *= -1, n *= -1;
//        if (n == 0)d = 1;
//        else if (d == 0)n = 0;
//        else {
//            ll gc = __gcd((n < 0 ? -n : n), d);
//            n /= gc, d /= gc;
//        }
//    }
//
//    ll toLL() const { return n / d; }
//
//    double toDouble() const { return double((long double) (n) / (long double) (d)); }
//
//    long double toLD() const { return (long double) (n) / (long double) (d); }
//
//    frac operator+(const frac &a) const { return frac(n * a.d + a.n * d, d * a.d); }
//
//    frac operator-(const frac &a) const { return frac(n * a.d - a.n * d, d * a.d); }
//
//    frac operator*(const frac &a) const { return frac(n * a.n, d * a.d); }
//
//    frac operator/(const frac &a) const { return frac(n * a.d, d * a.n); }
//
//    bool operator<(const frac &a) const { return __int128(n) * __int128(a.d) < __int128(a.n) * __int128(d); }
//
//    bool operator==(const frac &a) const { return !(*this < a) && !(a < *this); }
//
//    bool operator>=(const frac &a) const { return !(*this < a); }
//
//    bool operator<=(const frac &a) const { return !(a < *this); }
//
//    bool operator>(const frac &a) const { return a < *this; }
//
//    bool operator!=(const frac &a) const { return (*this < a) || (a < *this); }
//};
const int MN=2e5+1;
struct line{
    frac m,b;
    line(frac slope=frac(), frac inter=frac()){
        m=slope,b=inter;
    }
    frac inter(const line& a){
        return (a.b-b)/(m-a.m);
    }
};
pair<pll,int> point[MN];
long double dist[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    ll x,y,w,h,v;
    cin>>n>>v;
    for(int i=0;i<n;i++){
        cin>>x>>y>>w>>h;
        point[i]={{x,y},i};
    }
    sort(point,point+n);
    int bs=500;
    vector<pair<line,int>> val;
    for(int i=0;i<n;i++){
        if(i==0||point[i].first.first!=point[i-1].first.first)val.push_back({line(frac(ll(-2)*point[i].first.first),frac(point[i].first.first*point[i].first.first+point[i].first.second*point[i].first.second)),point[i].second});
    }
    for(int i=0;i<sz(val);i++){
        frac left(0),right(v);
        for(int j=max(0,i-bs);j<min(sz(val),i+bs);j++){
            frac inter = val[i].first.inter(val[j].first);
            if (val[i].first.m > val[j].first.m)right = min(right, inter);
            else left = max(left, inter);
        }
        if(right>=left)dist[val[i].second]=right-left;
    }
    double sum = 0;
    for (int i = 0; i < n; i++) {
        assert(double(dist[i]/(long double)(v)*(long double)(100))>=0);
        sum += double(dist[i] / (long double) (v) * (long double) (100));
        printf("%.11f\n", double(dist[i] / (long double) (v) * (long double) (100)));
    }
    assert(abs(sum-100)<=1e-8);
    return 0;
}