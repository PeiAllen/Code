#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int ccw(pii a, pii b, pii c){
    return (b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int test=0;test<5;test++) {
        int r, m;
        cin >> r >> m;
        vector<pii> arr(r);
        for (int i = 0; i < r; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(), arr.end());
        vector<pii> hull;
        vector<pii> te;
        for (auto x:arr) {
            while (sz(te) >= 2 && ccw(te[sz(te) - 2], te.back(), x) <= 0)te.pop_back();
            te.push_back(x);
        }
        hull.insert(hull.begin(), te.begin(), te.end());
        te = vector<pii>();
        reverse(arr.begin(), arr.end());
        for (auto x:arr) {
            while (sz(te) >= 2 && ccw(te[sz(te) - 2], te.back(), x) <= 0)te.pop_back();
            te.push_back(x);
        }
        te.erase(te.begin());
        if (sz(te))te.pop_back();
        hull.insert(hull.end(), te.begin(), te.end());
        int dist = 0;
        for (int i = 0; i < sz(hull); i++) {
            pii cur = hull[i], prev = hull[((i - 1) + sz(hull)) % sz(hull)];
            dist += ceil(sqrtl((cur.first - prev.first) * (cur.first - prev.first) + (cur.second - prev.second) * (cur.second - prev.second)));
        }
        printf("$%.2f\n", double(dist * m));
    }
    return 0;
}