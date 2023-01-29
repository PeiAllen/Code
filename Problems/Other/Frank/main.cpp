#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector<pair<int, int>> arr[200001];
int par[200001];
long long dis[200001];
int s;
int e;
long long bfsdis[200001];
deque<int> q;
long long trip = 1e18 + 1;

void dfs(int cur) {
    for (pair<int, int> i : arr[cur]) {
        if (par[i.first] != cur) {
            if (par[i.first] == 0) {
                par[i.first] = cur;
                par[cur] = i.first;
                dis[i.first] += dis[cur] + i.second;
                dfs(i.first);
            } else {
                dis[i.first] = dis[cur] + i.second;
                if (bfsdis[i.first] != 0) trip = min(trip, dis[i.first] + bfsdis[i.first]);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a;
        int b;
        int t;
        cin >> a;
        cin >> b;
        cin >> t;
        arr[a].push_back({b, t});
        arr[b].push_back({a, t});
    }
    cin >> s;
    cin >> e;
    std::fill(bfsdis, bfsdis + n + 1, 1e18 + 1);
    bfsdis[e] = 0;
    q.push_back(e);
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        for (pair<int, int> i : arr[cur]) {
            if (bfsdis[cur] + i.second < bfsdis[i.first]) {
                bfsdis[i.first] = bfsdis[cur] + i.second;
                q.push_back(i.first);
            }
        }
    }

    par[s] = s;
    dfs(s);
    if (trip == 1e18 + 1)
        cout << -1 << endl;
    else
        cout << trip << endl;
    return 0;
}
