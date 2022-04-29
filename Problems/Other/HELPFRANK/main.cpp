#include <bits/stdc++.h>

using namespace std;

int N;
int K;
int H [1000001][2];
int L [1000001];
bool centroid [1000001];
int sts [1000001];
long long ans = INT_MAX;
unordered_map<int, int> previousPath;
vector<pair<int, int>> currentPath;
vector<pair<int, long long>> adj [1000001];

int dfs(int loc, int parent) {
    sts[loc] = 1;
    for (auto x: adj[loc]) {
        if (x.first != parent) {
            sts[loc] += dfs(x.first, loc);
        }
    }
    return sts[loc];
}

int getCentroid(int cur, int parent, int treeSize) {
    for (auto x: adj[cur]) {
        if (x.first != parent && !centroid[x.first]) {
            if (sts[x.first] > treeSize) {
                return getCentroid(x.first, cur, treeSize);
            }
        }
    }
    return cur;
}

void dfspath(int cur, int parent, int depth, long long length) {
    currentPath.push_back({depth, length});
    for (auto x: adj[cur]) {
        if (x.first != parent && !centroid[x.first]) {
            dfspath(x.first, cur, depth+1, length + x.second);
        }
    }
}

void decomposeTree(int cur) {
    int cent = getCentroid(cur, -1, dfs(cur, -1)/2);
    centroid[cent] = true;
    previousPath[0] = 0;
    for (auto x :adj[cent]) {
        if (!centroid[x.first]) {
            currentPath.clear();
            dfspath(x.first, cent, 1, x.second);
            for (auto path: currentPath) {
                if (previousPath.count(K-path.second) > 0) ans = min(ans, (long long) path.first + previousPath[K-path.second]);
            }
            for (auto path: currentPath) {
                if (previousPath.count(path.second) > 0)
                    previousPath[path.second] = min(previousPath[path.second], path.first);
                else
                    previousPath[path.second] = path.first;
            }
        }
    }
    previousPath.clear();
    for (auto x: adj[cent]) {
        if (!centroid[x.first]) {
            decomposeTree(x.first);
        }
    }
}

int best_path(int n, int k, int h [][2], int l []) {
    for (int i = 0; i < n-1; i++) {
        adj[h[i][0]].push_back({h[i][1], l[i]});
        adj[h[i][1]].push_back({h[i][0], l[i]});
    }
    N = n;
    K = k;
    decomposeTree(1);

    if (ans != INT_MAX) return ans;
    return -1;
}