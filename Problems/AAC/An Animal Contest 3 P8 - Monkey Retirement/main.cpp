#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T>
int sz(const T &a) { return int(a.size()); }

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m, q, l, r;
    cin >> n >> m >> q >> l >> r;
    if (q > n + m - 1 || r < q) {
        printf("-1\n");
        return 0;
    }
    if (q <= m) {
        printf("%d\n", q);
        for (int i = 1; i <= q; i++) {
            printf("%d %d\n", 1, i);
        }
    } else if (q <= n) {
        printf("%d\n", q);
        for (int i = 1; i <= q; i++) {
            printf("%d %d\n", i, 1);
        }
    } else {
        if (m * (q - m + 1) <= r && min(n, m - 1) >= q - m + 1) {
            printf("%d\n", m * (q - m + 1));
            for (int i = 1; i <= (q - m + 1); i++) {
                for (int j = 0; j < m - 1; j++) {
                    printf("%d %d\n", i, (j + (i - 1)) % (m - 1) + 1);
                }
                printf("%d %d\n", i, m);
            }
            return 0;
        }
        if (n * (q - n + 1) <= r && min(m, n - 1) >= q - n + 1) {
            printf("%d\n", n * (q - n + 1));
            for (int i = 1; i <= (q - n + 1); i++) {
                for (int j = 0; j < n - 1; j++) {
                    printf("%d %d\n", (j + (i - 1)) % (n - 1) + 1, i);
                }
                printf("%d %d\n", n, i);
            }
            return 0;
        }
        printf("-1\n");
    }
    return 0;
}