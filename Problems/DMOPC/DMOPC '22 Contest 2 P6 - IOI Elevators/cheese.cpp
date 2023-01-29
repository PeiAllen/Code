#include <bits/stdc++.h>
using namespace std;
const int DEBUG = 0;
typedef pair<int, int> pii;
#define F first
#define S second

int n, m;
char g[50005][505];

int up[50005];
char lv[50005];
int getup(int u) {
    if (up[u] == u) return u;
    return up[u] = getup(up[u]);
}

int ans = 1;
void rec(int lo, int hi, vector<pii> edge) {
    if (hi - lo + 1 <= ans) return;
    if (DEBUG) {
        printf("[%d %d]:", lo, hi);
        for (auto &p : edge) printf(" (%d %d)", p.F, p.S);
        printf("\n");
    }
    // try disjoint set
    for (int i = lo; i <= hi; i++) up[i] = i;
    for (int i = lo; i <= hi; i++) lv[i] = 0;
    for (auto &p : edge) {
        int x = getup(p.F), y = getup(p.S);
        if (x == y) continue;
        if (lv[x] < lv[y])
            up[x] = y;
        else if (lv[x] > lv[y])
            up[y] = x;
        else {
            up[x] = y;
            lv[y]++;
        }
    }
    for (int i = lo; i <= hi; i++) getup(i);
    // is there a chance?
    int ok = 1;
    for (int i = lo; i < hi; i++) {
        if (up[i] != up[hi]) ok = 0;
    }
    if (ok) {
        ans = max(ans, hi - lo + 1);
        return;
    }
    // find contiguous blocks
    sort(edge.begin(), edge.end());
    reverse(edge.begin(), edge.end());
    int s1 = lo;
    for (int s2 = lo; s2 <= hi; s2++) {
        if (!(s2 == hi || up[s1] != up[s2 + 1])) continue;
        vector<pii> edge2;
        while (!edge.empty() && edge.back().F <= s2) {
            auto e = edge.back();
            edge.pop_back();
            if (e.S <= s2) edge2.push_back(e);
        }
        rec(s1, s2, move(edge2));
        s1 = s2 + 1;
    }
}

int main() {
#ifdef NOT_DMOJ
    freopen("data.txt", "r", stdin);
#endif  // NOT_DMOJ
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf(" %s", &g[i][1]);
    set<pii> edge;
    for (int j = 1; j <= m; j++) {
        int prev = 0;
        for (int i = 1; i <= n; i++) {
            if (g[i][j] != '1') continue;
            if (prev != 0) edge.insert(pii{prev, i});
            prev = i;
        }
    }
    vector<pii> edge2;
    for (auto &p : edge) edge2.push_back(p);
    rec(1, n, move(edge2));
    printf("%d\n", ans);
    return 0;
}