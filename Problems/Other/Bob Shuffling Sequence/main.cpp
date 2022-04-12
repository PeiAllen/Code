#include "bits/stdc++.h"
using namespace std;
template <typename T>
int sz(const T &a) {
    return int(a.size());
}
using ll = long long;
ll n, m, k, mod;
void solvebrute() {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = (ans + max(ll(0), (i ^ j) - k)) % mod;
        }
    }
    printf("%lli\n", ans);
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--) {
        cin >> n >> m >> k >> mod;
        if (n <= 100 && m <= 100 && k <= 100) {
            solvebrute();
        } else if (k == 1) {
        }
    }
    return 0;
}