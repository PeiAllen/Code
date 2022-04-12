#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 2e5 + 1;
pii dsu[MN];
int lastsaw[MN];
ll endcnt[MN];
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
int main() {
    int n;
    cin >> n;
    vector<pair<int, pii>> edges(n - 1);
    for (int i = 1; i < n; i++) {
        cin >> edges[i - 1].second.first >> edges[i - 1].second.second >>
            edges[i - 1].first;
    }
    for (int i = 1; i <= n; i++)
        dsu[i] = {i, 1}, endcnt[i] = 1, lastsaw[i] = -1;
    sort(edges.begin(), edges.end());
    for (int ptr = 0; ptr < n - 1;) {
        int st = ptr;
        vector<int> nodes;
        auto addnode = [&](int a) {
            if (lastsaw[a] == st) return;
            nodes.push_back(a);
            lastsaw[a] = st;
        };
        for (; ptr < n - 1 && edges[ptr].first == edges[st].first; ptr++) {
            uni(edges[ptr].second.first, edges[ptr].second.second);
            addnode(edges[ptr].second.first);
            addnode(edges[ptr].second.second);
        }
        for (auto x : nodes) {
            if (find(x) != x) endcnt[find(x)] += endcnt[x];
        }
        for (auto x : nodes) {
            endcnt[x] = endcnt[find(x)];
        }
        for (auto x : nodes) {
            dsu[x] = {x, 1};
        }
    }
    printf("%lli\n", accumulate(endcnt + 1, endcnt + n + 1, ll(0)));
    return 0;
}