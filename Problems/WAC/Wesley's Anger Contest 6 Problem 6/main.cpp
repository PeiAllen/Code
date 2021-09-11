#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T>
int sz(const T &a) { return int(a.size()); }

const int MN = 2e5 + 1;

struct frac {
    ll n, d;

    frac(ll num = 0, ll den = 1) {
        n = num, d = den;
        // reduce();
    }

    void reduce() {
        if (d < 0)d *= -1, n *= -1;
        if (n == 0)d = 1;
        else if (d == 0)n = 0;
        else {
            ll gc = __gcd((n < 0 ? -n : n), d);
            n /= gc, d /= gc;
        }
    }

    ll toLL() const { return n / d; }

    double toDouble() const { return double((long double) (n) / (long double) (d)); }

    long double toLD() const { return (long double) (n) / (long double) (d); }

    frac operator+(const frac &a) const { return frac(n * a.d + a.n * d, d * a.d); }

    frac operator-(const frac &a) const { return frac(n * a.d - a.n * d, d * a.d); }

    frac operator*(const frac &a) const { return frac(n * a.n, d * a.d); }

    frac operator/(const frac &a) const { return frac(n * a.d, d * a.n); }

    bool operator<(const frac &a) const { return __int128(n) * __int128(a.d) < __int128(a.n) * __int128(d); }

    bool operator==(const frac &a) const { return !(*this < a) && !(a < *this); }

    bool operator>=(const frac &a) const { return !(*this < a); }

    bool operator<=(const frac &a) const { return !(a < *this); }

    bool operator>(const frac &a) const { return a < *this; }

    bool operator!=(const frac &a) const { return (*this < a) || (a < *this); }
};

struct line {
    frac m, b;

    line(frac slope = frac(), frac inter = frac()) {
        m = slope, b = inter;
    }

    frac inter(const line &a) {
        return (a.b - b) / (m - a.m);
    }

    frac at(const frac &x) {
        return m * x + b;
    }
};

pair<line, int> deq[2*MN];
long double ans[MN];
short state[MN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    ll v;
    cin >> n >> v;
    frac end(v);
    ll a, b, c, d;
    vector<pair<line, int>> arr;
    vector<pair<line, int>> tosort;
    vector<pair<int, pii>> toset;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        toset.push_back({min(a, v), {b, i}}), toset.push_back({min(a + c, v), {b, i}});
        arr.push_back({line(frac(ll(-2) * a), frac(a * a + b * b)), i});
        arr.push_back({line(frac(ll(-2) * (a + c)), frac((a + c) * (a + c) + b * b)), i});
    }
    for (int i = 0; i < sz(arr); i++)tosort.push_back(arr[i]);
    sort(tosort.begin(), tosort.end(), [&](const pair<line, int> &lhs, const pair<line, int> &rhs) {
        if(lhs.first.m.n == rhs.first.m.n){
            if(lhs.first.b.n == rhs.first.b.n){
                return lhs.second>rhs.second;
            }
            return lhs.first.b.n > rhs.first.b.n;
        }
        return lhs.first.m.n > rhs.first.m.n;
    });
    int r = -1;
    for (auto x:tosort) {
        while(r>=0&&deq[r].first.m.n==x.first.m.n)r--;
        while (r >= 1 && deq[r - 1].first.inter(deq[r].first) >= deq[r].first.inter(x.first))r--;
        while(r>=0&&deq[r].first.m.n==x.first.m.n)r--;
        deq[++r] = x;
    }
    frac last(0);
    vector<pair<frac, pair<pll, int>>> endpoints;
    for (int i = 0; i <= r; i++) {
        frac te = max(frac(0), min(end, (i + 1 <= r ? deq[i].first.inter(deq[i + 1].first) : end)));
        if (te != last)endpoints.push_back({te, {{deq[i].first.m.toLL(),deq[i].first.b.toLL()},deq[i].second}});
        last = te;
    }
    sort(toset.begin(), toset.end());
    priority_queue<pii,vector<pii>,greater<>> setblocks;
    vector<pair<frac, pii>> bendpoints;
    int telast = 0;
    for (auto x:toset) {
        if (x.first != telast) {
            while(sz(setblocks)&&state[setblocks.top().second]==2)setblocks.pop();
            if (sz(setblocks))bendpoints.push_back({x.first, setblocks.top()});
            else bendpoints.push_back({x.first, {-1, -1}});
        }
        telast = x.first;
        state[x.second.second]++;
        if(state[x.second.second]==1)setblocks.push(x.second);
    }
    int lft = 0;
    long double tlast=0;
    for (auto x:bendpoints) {
        long double xte=x.first.toLD();
        if (x.second.second != -1) {
            while (lft < sz(endpoints) && endpoints[lft].first <= x.first) {
                ll sqrte=endpoints[lft].second.first.first * endpoints[lft].second.first.first - (long double)(4) * (endpoints[lft].second.first.second - (long double)(ll(x.second.first) * ll(x.second.first)));
                if (sqrte < 0) {
                    ans[x.second.second] += endpoints[lft].first.toLD() - max(tlast,(lft==0?(long double)(0):endpoints[lft-1].first.toLD()));
                } else {
                    long double sqr = sqrtl(sqrte);
                    long double li = (-endpoints[lft].second.first.first - sqr) / ((long double) (2)), ri = li+sqr;
                    long double left = max(tlast,(lft==0?(long double)(0):endpoints[lft-1].first.toLD())), right = endpoints[lft].first.toLD();
                    ans[endpoints[lft].second.second] += max((long double) (0), min(ri, right) - max(li, left));
                    ans[x.second.second] += max((long double) (0), right - max(ri, left));
                    ans[x.second.second] += max((long double) (0), min(li, right) - left);
                }
                lft++;
            }
            if(lft<sz(endpoints)) {
                ll sqrte=endpoints[lft].second.first.first * endpoints[lft].second.first.first - (long double)(4) * (endpoints[lft].second.first.second - (long double)(ll(x.second.first) * ll(x.second.first)));
                if (sqrte < 0) {
                    ans[x.second.second] += xte - max(tlast,(lft==0?(long double)(0):endpoints[lft-1].first.toLD()));
                } else {
                    long double sqr = sqrtl(sqrte);
                    long double li = (-endpoints[lft].second.first.first - sqr) / ((long double) (2)), ri = li+sqr;
                    long double left = max(tlast,(lft==0?(long double)(0):endpoints[lft-1].first.toLD())), right = xte;
                    ans[endpoints[lft].second.second] += max((long double) (0), min(ri, right) - max(li, left));
                    ans[x.second.second] += max((long double) (0), right - max(ri, left));
                    ans[x.second.second] += max((long double) (0), min(li, right) - left);
                }
            }
        }
        else {
            while (lft < sz(endpoints) && endpoints[lft].first <= x.first)ans[endpoints[lft].second.second] += endpoints[lft].first.toLD() - max(tlast,(lft==0?(long double)(0):endpoints[lft-1].first.toLD())), lft++;
            if (lft < sz(endpoints))ans[endpoints[lft].second.second] += xte - max(tlast,(lft==0?(long double)(0):endpoints[lft-1].first.toLD()));
        }
        tlast = xte;
    }
    while (lft < sz(endpoints) && endpoints[lft].first <= end)ans[endpoints[lft].second.second] += endpoints[lft].first.toLD() - max(tlast,(lft==0?(long double)(0):endpoints[lft-1].first.toLD())), lft++;
    if (lft < sz(endpoints))ans[endpoints[lft].second.second] += v - max(tlast,(lft==0?(long double)(0):endpoints[lft-1].first.toLD()));
    //double sum = 0;
    for (int i = 0; i < n; i++) {
//        assert(double(ans[i]/(long double)(v)*(long double)(100))>=0);
//        sum += double(ans[i] / (long double) (v) * (long double) (100));
        printf("%.11f\n", double(ans[i] / (long double) (v) * (long double) (100)));
    }
    //assert(abs(sum-100)<=1e-8);
    return 0;
}