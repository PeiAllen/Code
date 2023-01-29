#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
int sz(const T &a) { return int(a.size()); }
const int MN = 2e6 + 1;
vector<pii> adj[MN];
struct node {
    int cnt;
    int to[26];
    node() {
        for (int i = 0; i < 26; i++) to[i] = 0;
        cnt = 0;
    }
} tree[MN];
int nodecnt = 2;
void addnode(int cur, int curtree) {
    tree[cur].cnt++;
    for (auto x : adj[curtree]) {
        if (tree[cur].to[x.second] == 0) {
            tree[nodecnt] = node();
            tree[cur].to[x.second] = nodecnt++;
        }
        addnode(tree[cur].to[x.second], x.first);
    }
}
ll trip(ll a) {
    return a * (a - 1) * (a - 2) / 6;
}
ll solve(ll tot, ll atnode) {
    return trip(tot) - trip(tot - atnode);
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < MN; i++) tree[i] = node();
    nodecnt = 2;
    for (int cs = 1; cs <= t; cs++) {
        int n;
        cin >> n;
        int a;
        char c;
        for (int i = 1; i <= n; i++) {
            int m;
            cin >> m;
            for (int i = 1; i <= m; i++) adj[i] = vector<pii>();
            for (int j = 1; j < m; j++) {
                cin >> a >> c;
                adj[a].push_back({j + 1, c - 'a'});
            }
            addnode(1, 1);
        }
        ll ans = 0;
        for (int i = 1; i < nodecnt; i++) {
            ans += solve(n, tree[i].cnt);
        }
        printf("Case #%d: %lli\n", cs, ans);
        for (int i = 0; i < nodecnt; i++) tree[i] = node();
        nodecnt = 2;
    }
    return 0;
}
