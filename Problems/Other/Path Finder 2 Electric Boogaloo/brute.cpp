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

struct seg {
    int l, r, id;
};

const int MN = 1000005;

int n, m, q, k, r, c, id = 1, par[MN];
vector<int> blk[MN];
vector<seg> segs[MN];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[x] = par[y];
    return true;
}

int get_id(int r, int c) {
    int lo = 0, hi = segs[r].size() - 1, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (segs[r][mid].r < c) lo = mid + 1;
        else hi = mid;
    }
    return segs[r][lo].id;
}

int main() {
    boost();

    for (int i = 0; i < MN; i++) par[i] = i;
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++) {
        cin >> r >> c;
        blk[r].push_back(c);
    }
    for (int i = 1; i <= n; i++) {
        sort(blk[i].begin(), blk[i].end());
        blk[i].push_back(m + 1);
        int l = 0;
        for (int p : blk[i]) {
            if (p > l + 1) segs[i].push_back({l + 1, p - 1, id++});
            l = p;
        }
    }
    for (int i = 1; i < n; i++) {
        int idx = 0;
        for (seg p : segs[i]) {
            while (idx < segs[i + 1].size() && p.l > segs[i + 1][idx].r) idx++;
            while (idx < segs[i + 1].size() && p.r >= segs[i + 1][idx].r) merge(p.id, segs[i + 1][idx].id), idx++;
            if (idx < segs[i + 1].size() && p.r >= segs[i + 1][idx].l) merge(p.id, segs[i + 1][idx].id);
        }
    }
    while (q--) {
        cin >> r >> c;
        int u = get_id(r, c);
        cin >> r >> c;
        int v = get_id(r, c);
        if (find(u) == find(v)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}