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
int n, m;
mt19937_64 rnd;
int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rnd);
}
namespace Solution {
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
void sol() {
    printf("%d %d\n", n, m);
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            printf("%d", int(arr[i][j]));
        }
        printf("\n");
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
    fprintf(stderr, "%d\n", ans);
}
}  // namespace Solution

namespace randGen {
void gen(int freq) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = randint(1, m) <= freq;
        }
    }
    Solution::sol();
}
}  // namespace randGen

namespace pivotGen {
void gen(int freq, int nmin, int nmax, int pmin, int pmax) {
    for (int i = 1; i <= n; i++) {
        bool pivot = randint(1, n) <= freq;
        int am;
        if (pivot) {
            am = randint(pmin, pmax);
        } else {
            am = randint(nmin, nmax);
        }
        vector<int> perm(m);
        iota(perm.begin(), perm.end(), 1);
        shuffle(perm.begin(), perm.end(), rnd);
        for (int j = 0; j < am; j++) {
            arr[i][perm[j]] = 1;
        }
        for (int j = am; j < m; j++) {
            arr[i][perm[j]] = 0;
        }
    }
    Solution::sol();
}
}  // namespace pivotGen

namespace cheeseGen {
void gen(int type) {
    int bitamount, nam, otherbits;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = 0;
        }
    }
    if (type == 1) {
        bitamount = m / 2;
        nam = bitamount * 2;
        otherbits = m - bitamount;
        for (int i = 1; i <= n - nam; i++) {
            for (int j = 1; j <= otherbits; j++) {
                arr[i][j] = 1;
            }
        }
    } else {
        bitamount = m / 2;
        nam = bitamount * 2;
        otherbits = m - bitamount;
        pii residue = {1, 0};
        for (int i = 1; i <= otherbits; i++) {
            for (int j = 1; j <= n - nam; j++) {
                if ((j - 1) % residue.first == residue.second) {
                    arr[j][i] = 1;
                }
            }
            residue.second++;
            if (residue.second == residue.first) residue.first++, residue.second = 0;
        }
    }
    for (int ind = 1, i = n - nam + 1; ind <= bitamount; ind++, i += 2) {
        arr[i][otherbits + ind] = 1;
        for (int j = 1; j <= otherbits + ind - 1; j++) {
            arr[i + 1][j] = 1;
        }
    }
    Solution::sol();
}
}  // namespace cheeseGen

/*
yml paramters are
-----------
gentype
n
m
genparams
-----------
I made three types of generators
1. randgen (freq) -> generates each cell at freq/m probability
2. pivotgen (freq, nmin, nmax, pmin, pmax) -> generates pivot points with freq/n probability
        if point is a pivot point, generates [pmin, pmax] 1s in the column
        if point is not a pivot point, generates [nmin, nmax] 1s in the column
3. cheesegen (type) -> generate specific case to break check (l,r) then solve component solutions
        if type = 1, maximizes bits on nodes for solutions making edges on each node
        if type = 2, maximizes edges between nodes for solutions making edges between nodes
*/

int main(int argc, char **argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll base = 31, mod = 1e9 + 7;
    ll val = 0, plat = 1;
    for (int i = 1; i < argc; i++) {
        val = (val + plat * atoi(argv[i]) % mod) % mod;
        plat = plat * base % mod;
    }
    rnd.seed(val);
    n = atoi(argv[2]), m = atoi(argv[3]);
    if (atoi(argv[1]) == 1) {  // rand
        randGen::gen(atoi(argv[4]));
    } else if (atoi(argv[1]) == 2) {  // pivot
        pivotGen::gen(atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]));
    } else if (atoi(argv[1]) == 3) {  // cheese
        cheeseGen::gen(atoi(argv[4]));
    }
    return 0;
}