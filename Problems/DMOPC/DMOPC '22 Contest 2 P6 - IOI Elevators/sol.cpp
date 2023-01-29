#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
int sz(const T &a) {
    return int(a.size());
}
const int MN = 5e4 + 1, MM = 501;
bitset<MM> arr[MN];
pii dsu[MM];
bool appear[MN];
int find(int a) {
    if (dsu[a].first == a) return a;
    return dsu[a].first = find(dsu[a].first);
}
bool uni(int a, int b) {
    int ap = find(a), bp = find(b);
    if (ap == bp) return false;
    if (dsu[ap].second < dsu[bp].second) swap(ap, bp);
    dsu[ap].second += dsu[bp].second;
    dsu[bp].first = ap;
    return true;
}
void reset(int n) {
    for (int i = 0; i <= n; i++) dsu[i] = {i, 1}, appear[i] = false;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string a;
    for (int i = n; i >= 1; i--) {
        cin >> a;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = a[j - 1] == '1';
        }
    }
    vector<pair<pii, int>> edges;
    int ans = 1;
    for (int i = n; i >= 1; i--) {
        vector<pair<pii, int>> newedges;
        reset(m);
        int cnt = 0, recent = 0;
        auto addnode = [&](int node) {
            if (!appear[node]) {
                appear[node] = true;
                cnt++;
                recent = node;
                return true;
            }
            return false;
        };
        for (int j = 1; j <= m; j++) {
            if (arr[i][j]) {
                if (recent != 0) {
                    uni(recent, j);
                    newedges.push_back({{recent, j}, i});
                }
                addnode(j);
            }
        }
        if (cnt == 0) {
            newedges.push_back({{0, 0}, i});
            addnode(0);
        } else if (cnt == 1) {
            newedges.push_back({{recent, recent}, i});
        }
        for (auto x : edges) {
            if (!appear[0] && cnt == dsu[find(recent)].second &&
                newedges.back().second < x.second) {
                ans = max(ans, x.second - i);
            }
            bool addededge = uni(x.first.first, x.first.second);
            bool addeda = addnode(x.first.first);
            bool addedb = addnode(x.first.second);
            if (addededge || addeda || addedb) {
                newedges.push_back(x);
            }
        }
        if (!appear[0] && cnt == dsu[find(recent)].second) {
            ans = max(ans, n - i + 1);
        }
        edges = newedges;
    }
    printf("%d\n", ans);
    return 0;
}