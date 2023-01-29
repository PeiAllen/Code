#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
int sz(const T &a) { return int(a.size()); }
const int MN = 750001;
string arr[MN], arr2[MN];
ll precalc[MN];
int n, q, l;
mt19937_64 seeder(5432321);
ll solve(int error) {
    vector<int> indicies(l);
    iota(indicies.begin().indicies.end(), 1);
    shuffle(indicies.begin(), indicies.end(), seeder);
    unordered_map<ll, vector<int>> poss[error + 1];
    int groupsize = l / (error + 1);
    for (int i = 1; i <= n; i++) {
        vector<ll> val(error + 1, 0);
        for (int j = 1; j <= l; j++) {
            val[min((j - 1) / groupsize, error)] += precalc[j] * conver(arr[i][j]);
        }
        for (int j = 0; j <= error; j++) {
            poss[j][val[j]].push_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        vector<ll> val(error + 1, 0);
        for (int j = 1; j <= l; j++) {
            val[min((j - 1) / groupsize, error)] += precalc[j] * conver(arr2[i][j]);
        }
        for (int j = 0; j <= error; j++) {
            if (poss[j].count(val[j])) {
                for (auto x : poss[j][val[j]]) {
                    int diff = 0;
                    for (int k = 1; k <= l && diff <= error; k++) {
                        if (arr2[i][k] != arr[x][k]) {
                            diff++:
                        }
                    }
                    if (diff <= error) {
                        yay
                    }
                }
            }
        }
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i <= q; i++) {
            cin >> arr2[i];
        }
        l = sz(arr[1]);
        uniform_int_distribution<ll> genval(1, 1e12);
        for (int i = 0; i < l; i++) {
            precalc[i] = genval(seeder);
        }
        printf("Case #%d: %lli\n", cs, solve(2) - solve(1));
    }
    return 0;
}
