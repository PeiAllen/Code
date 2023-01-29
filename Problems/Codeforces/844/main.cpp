#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
int sz(const T &a) { return int(a.size()); }
const int MN = 2e5 + 1;
int bit[3][3 * MN];
vector<int> xcoords;
void update(int ind, int loc, int val) {
    for (; loc < sz(xcoords); loc += loc & -loc) {
        bit[ind][loc] = max(bit[ind][loc], val);
    }
}
int query(int ind, int loc) {
    int best = 0;
    for (; loc > 0; loc -= loc & -loc) {
        best = max(best, bit[ind][loc]);
    }
    return best;
}
pair<pii, pii> arr[MN];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        xcoords = vector<int>();
        xcoords.push_back(0);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
            xcoords.push_back(arr[i].first.second);
            xcoords.push_back(arr[i].second.second);
        }
        sort(xcoords.begin(), xcoords.end());
        xcoords.erase(unique(xcoords.begin(), xcoords.end()), xcoords.end());
        for (int i = 0; i <= sz(xcoords); i++) bit[0][i] = bit[1][i] = bit[2][i] = 0;
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 1);
        sort(ord.begin(), ord.end(), [&](const auto &lhs, const auto &rhs) {
            return (arr[lhs].second.second - arr[lhs].first.second) > (arr[rhs].second.second - arr[rhs].first.second);
        });
        for (int i = 1; i <= n; i++) {
            int cur = ord[i - 1];
            int lloc = lower_bound(xcoords.begin(), xcoords.end(), arr[cur].first.second) - xcoords.begin();
            if (arr[cur].first.first != arr[cur].second.first) {
                bool top = query(arr[cur].first.first, lloc) >= arr[cur].second.second;
                bool bot = query(arr[cur].second.first, lloc) >= arr[cur].second.second;
                update(arr[cur].first.first, lloc, arr[cur].second.second);
                update(arr[cur].second.first, lloc, arr[cur].second.second);
                if (top && bot) {
                    arr[cur] = {{0, 0}, {0, 0}};
                } else if (top) {
                    arr[cur].first.first = 2;
                } else if (bot) {
                    arr[cur].second.first = 1;
                }
            } else {
                if (query(arr[cur].first.first, lloc) >= arr[cur].second.second) {
                    arr[cur] = {{0, 0}, {0, 0}};
                } else {
                    update(arr[cur].first.first, lloc, arr[cur].second.second);
                }
            }
        }
        sort(ord.begin(), ord.end(), [&](const auto &lhs, const auto &rhs) {
            return arr[lhs].first.second < arr[rhs].first.second;
        });
        int rightmost = 0;
        set<pii> filled[3];
        filled[0] = set<pii>();
        filled[1] = set<pii>();
        filled[2] = set<pii>();
        filled[1].insert({0, 0});
        filled[2].insert({0, 0});
        for (int i = 1; i <= n; i++) {
            int cur = ord[i - 1];
            if (arr[cur].first.first == 0) continue;
            if (arr[cur].first.first != arr[cur].second.first) {
                if (rightmost + 1 > arr[cur].second.second) {
                    arr[cur] = {{0, 0}, {0, 0}};
                } else {
                    arr[cur].first.second = max(arr[cur].first.second, rightmost + 1);
                    rightmost = arr[cur].second.second;
                    filled[1].insert({arr[cur].first.second, arr[cur].second.second});
                    filled[2].insert({arr[cur].first.second, arr[cur].second.second});
                }
            }
        }
        set<pii>::iterator it[3] = {filled[0].begin(), filled[1].begin(), filled[2].begin()};
        for (int i = 1; i <= n; i++) {
            int cur = ord[i - 1];
            if (arr[cur].first.first == 0) continue;
            if (arr[cur].first.first == arr[cur].second.first) {
                int h = arr[cur].first.first;
                while (next(it[h]) != filled[h].end() && next(it[h])->first <= arr[cur].second.second && (next(it[h])->first <= arr[cur].first.second || next(it[h])->first == it[h]->second + 1)) {
                    it[h]++;
                }
                int start = max(arr[cur].first.second, it[h]->second + 1);
                int endp = min(arr[cur].second.second, (next(it[h]) == filled[h].end() ? INT_MAX : next(it[h])->first - 1));
                if (start > endp) {
                    arr[cur] = {{0, 0}, {0, 0}};
                } else {
                    arr[cur].first.second = start;
                    arr[cur].second.second = endp;
                    filled[h].insert({arr[cur].first.second, arr[cur].second.second});
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i].first.first != 0) {
                ans += ll(arr[i].second.first - arr[i].first.first + 1) * ll(arr[i].second.second - arr[i].first.second + 1);
            }
        }
        printf("%lli\n", ans);
        for (int i = 1; i <= n; i++) {
            printf("%d %d %d %d\n", arr[i].first.first, arr[i].first.second, arr[i].second.first, arr[i].second.second);
        }
    }
    return 0;
}