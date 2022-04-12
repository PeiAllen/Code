#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define A first
#define B second
template <typename T>
int sz(const T &a) {
    return int(a.size());
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    string a;
    ll x = 0, y = 0;
    while (cin >> a) {
        int am;
        cin >> am;
        if (a == "forward")
            x += am;
        else if (a == "down")
            y += am;
        else
            y -= am;
    }
    printf("%lli\n", x * y);
    return 0;
}