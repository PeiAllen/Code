#include "bits/stdc++.h"
using namespace std;
template <typename T>
int sz(const T &a) {
    return int(a.size());
}
using ll = long long;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (ll(i) * ll(i - 1) / ll(2) == ll(n)) {
            printf("Yes\n");
            printf("%d\n", i);
            vector<vector<int>> has(i + 1);
            for (int j = 1; j <= i; j++) {
                for (int k = 1; k < j; k++) {
                    has[j].push_back(n);
                    has[k].push_back(n--);
                }
            }
            for (int j = 1; j <= i; j++) {
                printf("%d", sz(has[j]));
                for (auto x : has[j]) printf(" %d", x);
                printf("\n");
            }
            return 0;
        }
    }
    printf("No\n");
    return 0;
}