#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
int sz(const T &a) {
    return int(a.size());
}
const int MN = 1e5 + 1, MM = 501;
bitset<MM> arr[MN];
pii dsu[MM];
int last[MN];
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
    for (int i = 0; i <= n; i++) dsu[i] = {i, 1};
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string a;
    for (int i = n; i >= 1; i--) {
        cin >> a;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = a[j - 1] == '1';
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        reset(m);
        for (int j = i; j <= n; j++) {
            int recent = 0;
            for (int k = 1; k <= m; k++) {
                if (arr[j][k]) {
                    if (recent != 0) {
                        uni(recent, k);
                    }
                    recent = k;
                }
            }
            last[j] = recent;
            if (recent == 0) break;
            int curroot = 0;
            bool work = true;
            for (int k = i; k <= j; k++) {
                int newroot = find(last[k]);
                if (curroot == 0) {
                    curroot = newroot;
                } else if (curroot != newroot) {
                    work = false;
                }
            }
            if (work) ans = max(ans, j - i + 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}