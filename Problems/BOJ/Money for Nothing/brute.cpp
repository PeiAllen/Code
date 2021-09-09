#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 1000005, MD = 1e9 + 10;

struct line {
    int m, b, pos;
    int get(int x) {
        return m * x + b;
    }
    int get(int x, int cost) {
        int newm = m - cost, newb = -newm * (MD - pos);
        //return (m - cost) * x + (-m - cost) * st;
        return newm * x + newb;
    }
    int intersect(line l, int cost) {
        int newm = m - cost, newb = -newm * (MD - pos);
        int newm1 = l.m - cost, newb1 = -newm1 * (MD - l.pos);
        return (newb - newb1) / (newm1 - newm);
    }
};

int n, m, l = 1, r = 0;
vector<pii> a, b;
line deq[MN];

vector<pii> order_a(vector<pii> v) {
    vector<pii> ret;
    sort(v.begin(), v.end());
    int mn = 0x3f3f3f3f;
    for (pii p : v) {
        if (p.s >= mn) continue;
        mn = p.s;
        ret.push_back(p);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<pii> order_b(vector<pii> v) {
    vector<pii> ret;
    sort(v.begin(), v.end(), greater<>());
    int mx = -0x3f3f3f3f;
    for (pii p : v) {
        if (p.s <= mx) continue;
        mx = p.s;
        ret.push_back(p);
    }
    return ret;
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1, p, d; i <= n; i++) cin >> p >> d, a.push_back({d, p});
    for (int i = 1, p, d; i <= m; i++) cin >> p >> d, b.push_back({d, p});
    a = order_a(a);
    b = order_b(b);
    n = a.size(), m = b.size();
    int id = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (id < m && b[id].f >= a[i].f) {
            line cur = {b[id].s, -b[id].s * (MD - b[id].f), b[id].f};
            while (r - l >= 1 && cur.intersect(deq[r], a[i].s) < deq[r].intersect(deq[r - 1], a[i].s)) r--;
            deq[++r] = cur;
            id++;
        }
        while (r - l >= 1 && deq[l].get(MD - a[i].f, a[i].s) < deq[l + 1].get(MD - a[i].f, a[i].s)) l++;
        if (r - l >= 0) ans = max(ans, deq[l].get(MD - a[i].f, a[i].s));
    }
    printf("%lld\n", ans);

    return 0;
}
/*
6 6
1 9
2 8
3 5
4 4
5 3
6 1
2 10
4 8
5 7
6 4
9 2
12 1
 */
