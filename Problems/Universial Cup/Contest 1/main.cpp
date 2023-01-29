#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T>
int sz(const T &a) { return (int)a.size(); }
const ll mod = 998244353;
const int MN = 5010;
int depth[MN], ldepth[MN];
vector<pii> matrix[MN];
stack<int> st;
vector<vector<int>> comps;
int mycomp[MN];

int pc[MN * MN];

void dfs(int loc, int edgeind, int dep) {  // splits graph by bridges
    depth[loc] = dep, ldepth[loc] = dep;
    st.push(loc);
    for (auto x : matrix[loc]) {
        if (x.second != edgeind) {
            if (depth[x.first])
                ldepth[loc] = min(ldepth[loc], depth[x.first]);
            else {
                dfs(x.first, x.second, dep + 1);
                ldepth[loc] = min(ldepth[loc], ldepth[x.first]);
            }
        }
    }
    if (ldepth[loc] == depth[loc]) {
        comps.push_back({});
        while (true) {
            int cur = st.top();
            st.pop();
            comps.back().push_back(cur);
            if (cur == loc) break;
        }
    }
}

vector<int> adj[MN];
ll dp[MN][MN][2];
ll te[MN][2];
ll edgeways[MN];
ll intedge[MN];

int dfsdp(int loc, int par) {
    int sts = sz(comps[loc - 1]);
    dp[loc][sz(comps[loc - 1])][0] = 1;
    for (auto x : adj[loc]) {
        if (x != par) {
            int cts = dfsdp(x, loc);
            // printf("wat %d %d %d %d\n", loc, x, sts, cts);
            for (int i = 0; i <= sts + cts; i++) {
                for (int j = 0; j <= 1; j++) {
                    te[i][j] = 0;
                }
            }
            for (int rc = 1; rc <= sts; rc++) {
                for (int rp = 0; rp <= 1; rp++) {
                    for (int cc = 1; cc <= cts; cc++) {
                        for (int cp = 0; cp <= 1; cp++) {
                            te[rc][(rp + cp + 1) % 2] += dp[loc][rc][rp] * dp[x][cc][cp] % mod;
                            te[rc + cc][(rp + cp) % 2] += dp[loc][rc][rp] * dp[x][cc][cp] % mod * pc[rc * cc - 1] % mod;
                        }
                    }
                }
            }
            for (int i = 0; i <= sts + cts; i++) {
                for (int j = 0; j <= 1; j++) {
                    dp[loc][i][j] = te[i][j] % mod;
                }
            }
            sts += cts;
        }
    }
    return sts;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        matrix[a].push_back({b, i});
        matrix[b].push_back({a, i});
    }
    for (int i = 1; i <= n; i++) {
        if (!depth[i]) {
            dfs(i, 0, 1);
        }
    }
    for (int i = 0; i < sz(comps); i++) {
        for (auto x : comps[i]) {
            mycomp[x] = i + 1;
        }
    }
    pc[0] = 1;
    for (int i = 1; i < n * n; i++) {
        pc[i] = ll(pc[i - 1]) * 2 % mod;
    }
    for (int i = 1; i <= n; i++) {
        for (auto x : matrix[i]) {
            if (mycomp[i] == mycomp[x.first]) {
                intedge[mycomp[i]]++;
            } else {
                adj[mycomp[i]].push_back(mycomp[x.first]);
            }
        }
    }
    ll extra = 0;
    for (int i = 1; i <= sz(comps); i++) {
        ll nodecnt = sz(comps[i - 1]);
        extra += (nodecnt) * (nodecnt - 1) / 2 - intedge[i] / 2;
    }
    // edgeways[0] = 1;
    // for (int i = 1; i <= n; i++) {
    //     edgeways[i] = fp(2, i * (i - 1) / 2 - (i - 1));
    //     // printf("%lli ", edgeways[i]);
    // }
    // printf("\n");
    dfsdp(1, 0);
    // for (int i = 1; i <= n; i++) {
    //     printf("%d ", mycomp[i]);
    // }
    // printf("\n");
    // for (int i = 1; i <= sz(comps); i++) {
    //     for (int j = 0; j <= n; j++) {
    //         for (int k = 0; k <= 1; k++) {
    //             printf("%d %d %d: %lli\n", i, j, k, dp[i][j][k]);
    //         }
    //     }
    // }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[1][i][0] % mod) % mod;
        ans = (ans - (dp[1][i][1] % mod) + mod) % mod;
    }
    ans = ans * pc[extra] % mod;
    printf("%lli\n", ans);
    return 0;
}