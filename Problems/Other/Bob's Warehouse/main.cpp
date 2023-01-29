#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
int sz(const T &a) { return int(a.size()); }

const int MN = 1e6 + 2;
ll dp[MN];
tuple<ll, ll, ll> ware[MN];
ll prodsum[MN];
int deq[MN];
int l = 0, r = -1;
ll calc(int from, int at) {
    return dp[from] + get<2>(ware[from - 1]) + get<0>(ware[from - 1]) * (get<1>(ware[from - 1]) - get<1>(ware[at - 1])) - (prodsum[from - 1] - prodsum[at - 1]);
}
ll overcome(int a, int b) {
    return ((dp[b] + get<2>(ware[b - 1]) + get<0>(ware[b - 1]) * get<1>(ware[b - 1]) - prodsum[b - 1]) - (dp[a] + get<2>(ware[a - 1]) + get<0>(ware[a - 1]) * get<1>(ware[a - 1]) - prodsum[a - 1])) / (get<0>(ware[b - 1]) - get<0>(ware[a - 1]));
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> get<0>(ware[i]) >> get<1>(ware[i]) >> get<2>(ware[i]);
        prodsum[i] = prodsum[i - 1] + get<1>(ware[i]) * get<0>(ware[i]);
        get<1>(ware[i]) += get<1>(ware[i - 1]);
    }
    dp[n + 1] = 0;
    deq[++r] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (r - l + 1 >= 2 && calc(deq[l], i) >= calc(deq[l + 1], i)) {
            l++;
        }
        dp[i] = calc(deq[l], i);
        if (i != 1) {
            while (r - l + 1 >= 2 && overcome(deq[r], deq[r - 1]) <= overcome(i, deq[r])) {
                r--;
            }
            deq[++r] = i;
        }
    }
    printf("%lli\n", dp[1]);
    return 0;
}