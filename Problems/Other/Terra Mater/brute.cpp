#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

struct range {
    int l, r, val; //left pt, right pt, whats the value we can get out of this?
};

const int MN = 1005, MH = 1e6+5;

int n, t, a[MN], st[6 * MH], lzy[6 * MH];

void push_down(int idx) {
    if (lzy[idx] == 0x3f3f3f3f) return;
    st[idx * 2] = min(st[idx * 2], lzy[idx]);
    st[idx * 2 + 1] = min(st[idx * 2 + 1], lzy[idx]);
    lzy[idx * 2] = min(lzy[idx * 2], lzy[idx]);
    lzy[idx * 2 + 1] = min(lzy[idx * 2 + 1], lzy[idx]);
    lzy[idx] = 0x3f3f3f3f;
}

void upd(int l, int r, int x, int y, int val, int idx) {
    if (r < x || l > y) return;
    if (r <= y && l >= x) {st[idx] = min(st[idx], val); lzy[idx] = min(lzy[idx],val); return;}
    push_down(idx);
    int mid = (l + r) >> 1;
    upd(l, mid, x, y, val, idx * 2);
    upd(mid + 1, r, x, y, val, idx * 2 + 1);
    st[idx] = min(st[idx * 2], st[idx * 2 + 1]);
}

int qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return 0x3f3f3f3f;
    if (r <= y && l >= x) return st[idx];
    push_down(idx);
    int mid = (l + r) >> 1;
    return min(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

bool check(int h) {
    memset(st, 0x3f, sizeof(st));
    memset(lzy, 0x3f, sizeof(lzy));
    vector<range> v;
    upd(1, MH, 1, MH, 0, 1);
    v.push_back({a[1], a[1], -1});
    for (int i = 2; i <= n; i++) {
        for (range &p : v) {
            p.l = max(1, p.l - h), p.r = min(MH, p.r + h);
            upd(1, MN, p.l, p.r, p.val, 1);
        }
        int val = qry(1, MN, a[i], a[i], 1);
        upd(1, MN, a[i], a[i], val - 1, 1);
        v.push_back({a[i], a[i], val - 1});
    }
    int tmp = qry(1, MN, 1, MN, 1) + n;
    return tmp <= t;
}

int main() {
    boost();

    cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int lo = 0, hi = MH, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    printf("%d\n", lo);

    return 0;
}