#include <bits/stdc++.h>
using namespace std;

const int N = 1234567;
int n;
int a[N];
int b[N];
int fen[N];

void upd(int p, int v) {
    p++;
    for (; p < N; p += p & -p) {
        fen[p] += v;
    }
}
int query(int p) {
    p++;
    int res = 0;
    for (; 0 < p; p -= p & -p) {
        res += fen[p];
    }
    return res;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        v.push_back(a[i] - b[i]);
        v.push_back(b[i] - a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int k = lower_bound(v.begin(), v.end(), a[i] - b[i]) - v.begin();
        res += query(k - 1);
        k = lower_bound(v.begin(), v.end(), b[i] - a[i]) - v.begin();
        upd(k, 1);
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}
