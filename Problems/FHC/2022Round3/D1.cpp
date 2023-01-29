#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
int sz(const T &a) { return int(a.size()); }
const int MN = 6e5 + 1;
int n, m;
pii arr[MN];
pair<int, vector<int>> group[MN];  // which indicies are together
int cols[MN];                      // list of indices what have colour x.
pii subarray[MN];                  // which subarray of indicies are together
int findsubarray(int a) {
    if (subarray[a].first == a) return a;
    return subarray[a].first = findsubarray(subarray[a].first);
}
bool unisubarray(int a, int b) {
    int ap = findsubarray(a), bp = findsubarray(b);
    if (ap == bp) return false;
    if (subarray[ap].second < subarray[bp].second) swap(ap, bp);
    subarray[ap].second += subarray[bp].second;
    subarray[bp].first = ap;
    return true;
}
int findgroup(int a) {
    if (group[a].first == a) return a;
    return group[a].first = findgroup(group[a].first);
}
bool unigroup(int a, int b, int col) {
    int ap = findgroup(a), bp = findgroup(b);
    if (ap == bp) return false;
    if (sz(group[ap].second) < sz(group[bp].second)) swap(ap, bp);
    for (auto x : group[bp].second) {
        group[ap].second.push_back(x);
        if (x - 1 >= 1 && findgroup(x - 1) == ap) {
            unisubarray(x, x - 1);
        }
        if (x + 1 <= n && findgroup(x + 1) == ap) {
            unisubarray(x, x + 1);
        }
    }
    group[bp].second = vector<int>();
    group[bp].first = ap;
    cols[col] = ap;
    return true;
}
void reset(int n) {
    for (int i = 1; i <= n; i++) {
        cols[i] = i;
        subarray[i] = {i, 1};
        group[i].first = 1;
        group[i].second = vector<int>();
        group[i].second.push_back(i);
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        if (m < n / 2) {
            printf("Case #%d: %lli\n", cs, 0 + (-1) * ll(n - 1));
        }
        vector<int> nodes(n);
        iota(nodes.begin(), nodes.end(), 1);
        vector<pair<pii, vector<int>>> queries;
        queries.push_back({{0, m + 1}, nodes});
        ll ans = 0;
        while (1) {
            reset(n);
            int last = 0;
            vector<pair<pii, vector<int>>> nextqueries;
            for (auto x : queries) {
                int l = x.first.first, r = x.first.second;
                if (l == r) {
                    ll teans = (l == m + 1 ? -1 : l);
                    ans += teans * ll(sz(x.second));
                    continue;
                }
                int mid = (l + r) / 2;
                for (int i = last + 1; i <= mid; i++) {
                    int groupa = cols[arr[i].first], groupb = cols[arr[i].second];
                    if (groupa == 0) continue;
                    cols[arr[i].first] = cols[arr[i].second] = 0;
                    if (groupb == 0) {
                        cols[arr[i].second] = groupa;
                    } else {
                        unigroup(groupa, groupb, arr[i].second);
                    }
                }
                last = mid;
                vector<int> left, right;
                for (auto y : x.second) {
                    bool work = true;
                    for (int i = 1; i <= n && work; i += y) {
                        if (findsubarray(i) != findsubarray(min(n, i + y - 1))) {
                            work = false;
                        }
                    }
                    if (work) {
                        left.push_back(y);
                    } else {
                        right.push_back(y);
                    }
                }
                if (sz(left)) {
                    nextqueries.push_back({{l, mid}, left});
                }
                if (sz(right)) {
                    nextqueries.push_back({{mid + 1, r}, right});
                }
            }
            if (sz(nextqueries) == 0) break;
        }
        printf("Case #%d: %lli\n", cs, ans);
    }
    return 0;
}
