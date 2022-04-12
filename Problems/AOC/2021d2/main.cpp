#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    string a;
    ll x = 0, y = 0;
    ll aim = 0;
    while (cin >> a) {
        int val;
        cin >> val;
        if (a == "forward") {
            x += val;
            y += aim * val;
        } else if (a == "down")
            aim += val;
        else
            aim -= val;
    }
    printf("%lli\n", x * y);
    return 0;
}