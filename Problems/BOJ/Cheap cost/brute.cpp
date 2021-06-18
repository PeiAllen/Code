#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9;
const int N = 9;
const int M = 9;
const int S = 2243;

int n, m;
int a[N][M];

int s;
vector<vector<int>> states;
vector<int> state;
int cnt;  // current number of connected components

bool compatible[S][S];
vector<int> g[2 * M];
int last[M];
int was[2 * M];
vector<int> que;

int dp[N + 1][S];

void FindStates(int i) {
    if (i == m) {
        states.push_back(state);
        return;
    }
    state[i] = -1;
    FindStates(i + 1);
    if (i == 0 || state[i - 1] == -1) {
        for (int j = 0; j < cnt; j++) {
            state[i] = j;
            FindStates(i + 1);
        }
        state[i] = cnt;
        cnt += 1;
        FindStates(i + 1);
        cnt -= 1;
    } else {
        state[i] = state[i - 1];
        FindStates(i + 1);
    }
}

bool AllConnected(int sid) {
    for (int comp : states[sid]) {
        if (comp != -1 && comp != 0) {
            return false;
        }
    }
    return true;
}

int Get(int row, int sid) {
    int res = 0;
    for (int j = 0; j < m; j++) {
        if (states[sid][j] >= 0) {
            res += a[row][j];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//#ifdef _DEBUG
//    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
//  freopen("debug_output.txt", "w", stderr);
//#endif

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cnt = 0;
    state.resize(m);
    FindStates(0);
    s = (int) states.size();
    for (int sid = 0; sid < s; sid++) {
        for (int tid = 0; tid < s; tid++) {
            for (int i = 0; i < 2 * m; i++) {
                g[i].clear();
            }
            auto Add = [&](int u, int v) {
                g[u].push_back(v);
                g[v].push_back(u);
            };

            // connections from previous row
            for (int j = 0; j < m; j++) {
                last[j] = -1;
            }
            for (int j = 0; j < m; j++) {
                int c = states[tid][j];
                if (c != -1) {
                    if (last[c] != -1) {
                        Add(last[c], j);
                    }
                    last[c] = j;
                }
            }
            // connections from this row
            for (int j = 0; j < m - 1; j++) {
                if (states[sid][j] != -1 && states[sid][j + 1] != -1) {
                    assert(states[sid][j] == states[sid][j + 1]);
                    Add(m + j, m + j + 1);
                }
            }
            // connections between the two rows
            for (int j = 0; j < m; j++) {
                if (states[sid][j] != -1 && states[tid][j] != -1) {
                    Add(j, m + j);
                }
            }

            // check if works
            for (int j = 0; j < 2 * m; j++) {
                was[j] = -1;
            }
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (states[sid][j] != -1 && was[m + j] == -1) {
                    que.assign(1, m + j);
                    was[m + j] = cnt++;
                    for (int b = 0; b < (int) que.size(); b++) {
                        int v = que[b];
                        for (int u : g[v]) {
                            if (was[u] != -1) {
                                continue;
                            }
                            was[u] = was[v];
                            que.push_back(u);
                        }
                    }
                }
            }
            bool res = true;
            for (int j = 0; j < m; j++) {
                if (states[tid][j] != -1 && was[j] == -1) {
                    res = false;
                }
            }
            for (int j = 0; j < m; j++) {
                if (states[sid][j] != -1 && was[m + j] != states[sid][j]) {
                    res = false;
                }
            }
            compatible[sid][tid] = res;
        }
    }

    for (int i = 0; i <= n; i++) {
        fill(dp[i], dp[i] + s, INF);
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = 0;
        for (int sid = 1; sid < s; sid++) {
            int add = Get(i, sid);
            for (int tid = 0; tid < s; tid++) {
                if (compatible[sid][tid]) {
                    dp[i + 1][sid] = min(dp[i + 1][sid], dp[i][tid] + add);
                }
            }
        }
    }

    int ans = INF;
    for (int sid = 0; sid < s; sid++) {
        if (AllConnected(sid)) {
            for (int i = 0; i <= n; i++) {
                ans = min(ans, dp[i][sid]);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}