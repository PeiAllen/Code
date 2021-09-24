#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;
#define A first
#define B second
template <typename T>
int SZ(const T &a) {
    return int(a.size());
}
const int MN = 3e5 + 1;
int dsu[MN], to[MN], ord[MN], n, q;
bool loop[MN];
int find(int a) {
    if (dsu[a] == a) {
        return a;
    }
    return dsu[a] = find(dsu[a]);
}
void uni(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
        loop[a] = true;
    } else {
        dsu[a] = b;
    }
}
pii query[MN];
vector<int> ans;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> to[i];
        ord[i] = INT_MAX;
        dsu[i] = i;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> query[i].A >> query[i].B;
        if (query[i].A == 2) ord[query[i].B] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (ord[i] == INT_MAX) {
            uni(i, to[i]);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        if (query[i].A == 1) {
            ans.push_back(find(query[i].B));
            if (loop[ans.back()]) {
                ans.back() = INT_MAX;
            }
        } else
            uni(query[i].B, to[query[i].B]);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) {
        if (x == INT_MAX)
            printf("CIKLUS\n");
        else
            printf("%d\n", x);
    }
    return 0;
}