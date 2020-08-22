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

struct edge {
    int u = 0, v = 0, w = 0, i = 0, t = 0;
};

struct query {
    int t = 0, u = 0, v = 0, i = 0;
};

bool cmp(edge x, edge y) {
    return x.w > y.w;
}

bool cmp1(edge x, edge y) {
    return x.i < y.i;
}

bool cmq(query x, query y) {
    return x.u > y.u;
}

const int MN = 50005, MM = 100005, SQRT = 10005;

int n, m, q, par[MN], sz[MN], unst[MM], ans[MM];
edge e[MM], E[MM];
query Q[MM];
stack<pair<pii, int>> s;

int find(int x) {
    return x == par[x] ? x : find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {s.push({{x, y}, 0}); return false;}
    if (sz[x] > sz[y]) {
        par[y] = par[x];
        sz[x] += sz[y];
        s.push({{x, y}, 1});
    } else {
        par[x] = par[y];
        sz[y] += sz[x];
        s.push({{y, x}, 1});
    }
    return true;
}

void undo() {
    auto p = s.top(); s.pop();
    if (!p.s) return;
    par[p.f.s] = p.f.s;
    sz[p.f.f] -= sz[p.f.s];
}

int main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w; e[i].i = i;
        E[i] = e[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> Q[i].t >> Q[i].u >> Q[i].v; Q[i].i = i;
        if (Q[i].t == 2) swap(Q[i].u, Q[i].v);
    }
    memset(ans, -1, sizeof(ans));
    for (int I = 1; I <= q; I += SQRT) {
        int lft = I, rit = min(q, I + SQRT - 1); //range of currently processed block
        for (int i = 1; i <= m; i++) e[i] = E[i], unst[i] = 0;
        sort(e + 1, e + m + 1, cmp);
        vector<query> qs;
        vector<edge> edges;
        vector<int> chg;
        for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
        while (s.size()) s.pop();
        for (int i = lft; i <= rit; i++) {
            if (Q[i].t == 1) {
                unst[Q[i].u] = 1;
                chg.push_back(Q[i].u);
                edges.push_back({E[Q[i].u].u, E[Q[i].u].v, Q[i].v, i, Q[i].u});
            } else {
                qs.push_back(Q[i]);
            }
        }
        chg.erase(unique(chg.begin(), chg.end()), chg.end());
        sort(qs.begin(), qs.end(), cmq);
        int id = 1;
        for (query cur : qs) {
            while (id <= m && e[id].w >= cur.u) {
                if (!unst[e[id].i]) merge(e[id].u, e[id].v);
                id++;
            }
            int cnt = 0;
            for (edge ed : edges) {
                if (ed.i > cur.i) continue;
                unst[ed.t] = 0;
                if (ed.w >= cur.u) merge(ed.u, ed.v), cnt++;
            }
            for (int i : chg) {
                if (unst[i]) {
                    if (E[i].w >= cur.u) merge(E[i].u, E[i].v), cnt++;
                }
            }
            ans[cur.i] = sz[find(cur.v)];
            while (cnt--) undo();
            for (edge ed : edges) {
                if (ed.i > cur.i) continue;
                unst[ed.t] = 1;
            }
        }
        for (int i = lft; i <= rit; i++) {
            if (Q[i].t == 1) E[Q[i].u].w = Q[i].v;
            else printf("%d\n", ans[i]), assert(ans[i] > 0);
        }
    }

    return 0;
}