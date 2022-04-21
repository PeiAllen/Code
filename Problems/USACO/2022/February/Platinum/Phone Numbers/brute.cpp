#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005, MOD = 1e9 + 7;

int t, n, dp[MN], dp1[MN];
string s;
set<vector<char>> valid;

void add(char a, char b) {
    valid.insert({a, b});
    valid.insert({b, a});
}

void add(char a, char b, char c, char d) {
    vector<char> v = {a, b, c, d};
    sort(v.begin(), v.end());
    do valid.insert(v);
    while (next_permutation(v.begin(), v.end()));
}

int dp2(char a, char b, char c, char d) {
    vector<char> v = {a, b, c, d};
    dp1[0] = 1;
    for (int i = 1; i <= 4; i++) {
        dp1[i] = dp1[i - 1];
        if (i > 1 && valid.count({v[i - 2], v[i - 1]})) dp1[i] = (dp1[i] + dp1[i - 2]) % MOD;
    }
    return dp1[4];
}

bool eq(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int32_t main() {
    boost();

    add('1', '2');
    add('2', '3');
    add('4', '5');
    add('5', '6');
    add('7', '8');
    add('8', '9');
    add('1', '4');
    add('4', '7');
    add('2', '5');
    add('5', '8');
    add('3', '6');
    add('6', '9');
    add('1', '2', '4', '5');
    add('2', '3', '5', '6');
    add('4', '5', '7', '8');
    add('5', '6', '8', '9');
    cin >> t;
while (t--) {
        cin >> s;
        n = s.size();
        if (n <= 8) {
            string r = s;
            sort(r.begin(), r.end());
            int ans = 0;
            do {
                dp[0] = 1;
                for (int i = 1; i <= n; i++) {
                    dp[i] = 0;
                    if (s[i - 1] == r[i - 1]) dp[i] |= dp[i - 1];
                    if (i > 1 && valid.count({r[i - 2], r[i - 1]}) && eq(s.substr(i - 2, 2), r.substr(i - 2, 2))) dp[i] |= dp[i - 2];
                    if (i > 3 && valid.count({r[i - 4], r[i - 3], r[i - 2], r[i - 1]}) && eq(s.substr(i - 4, 4), r.substr(i - 4, 4))) dp[i] |= dp[i - 4];
                }
                ans += dp[n];
            } while (next_permutation(r.begin(), r.end()));
            printf("%lld\n", ans);
            continue;
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (i > 1 && valid.count({s[i - 2], s[i - 1]})) dp[i] = (dp[i] + dp[i - 2]) % MOD;
            if (i > 3 && valid.count({s[i - 4], s[i - 3], s[i - 2], s[i - 1]})) {
                int ways = 24 - dp2(s[i - 4], s[i - 3], s[i - 2], s[i - 1]);
                dp[i] = (dp[i] + dp[i - 4] * ways) % MOD;
            }
        }
        printf("%lld\n", dp[n]);
    }

    return 0;
}