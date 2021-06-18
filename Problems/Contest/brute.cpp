// ./bobs-christmas-tree-lights.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

ostream& operator<<(ostream& out, const pii o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}

// template is 1-indexed
template <typename T> struct Ranks {
    vector<T> ranks;
    void init() {
        sort(ranks.begin(), ranks.end());
        ranks.resize(unique(ranks.begin(), ranks.end()) - ranks.begin());
    }
    template <typename It> void init(It st, It en) { ranks = vector<T>(st, en); init(); }
    void add(T v) { ranks.push_back(v); }
    int get(T v) { return lower_bound(ranks.begin(), ranks.end(), v) - ranks.begin() + 1; }
    int size() { return ranks.size(); }
};

const int MN = 1e5 + 1;
int N, Q,
        C[MN], seq[MN], sz;

// tree
vector<int> g[MN];
int in[MN], out[MN], ctr = 0;
void dfs(int c, int p) {
    in[c] = ++ctr;
    seq[ctr] = c;
    for (auto to : g[c]) {
        if (to != p) {
            dfs(to, c);
        }
    }
    out[c] = ctr;
}
bool ant(int upper, int downer) {
    return in[upper] <= in[downer] && out[downer] <= out[upper];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    {
        Ranks<int> rs;
        for (auto i = 1; i <= N; i++) {
            cin >> C[i];
            rs.add(C[i]);
        }
        rs.init();
        for (auto i = 1; i <= N; i++) C[i] = rs.get(C[i]);
        sz = SZ(rs);
    }
    for (auto i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    // dfs get in/out
    dfs(1, -1);
    // SQRT
    int r = 1;
    while (Q--) {
        int T; cin >> T;
        if (T == 1) {
            cin >> r;
            ctr = 0;
            dfs(r, -1);
        }
        else {
            int x, y; cin >> x >> y;

            vector<ll> f1(N+1), f2(N+1);
            for (auto i = 1; i <= N; i++) {
                if (ant(x, i)) f1[C[i]]++;
                if (ant(y, i)) f2[C[i]]++;
            }
            ll ans = 0;
            for (auto i = 1; i <= N; i++) ans += f1[i]*f2[i];
            cout << (ans) << '\n';
        }
    }

    return 0;
}
