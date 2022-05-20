#include <bits/stdc++.h>

using namespace std;

int n;
int k;
pair<int, int> height [1000001];
priority_queue<int> width;
long long total;
long long air = INT_MAX;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> k;
    for (int i = 1; i <= n; i++) {
        int a;
        int b;
        cin >> a;
        cin >> b;
        height[i].first = a;
        height[i].second = b;
    }
    sort(height+1, height + n + 1, [&](pair<int, int> l, pair<int, int> r) {
         return l.second < r.second;
    });
    for (int i = 1; i < k; i++) {
        width.push(height[i].first);
        total += height[i].first;
    }
    air = (total+height[k].first)*height[k].second;
    width.push(height[k].first);
    total += height[k].first;
    cout << width.size() << endl;
    for (int i = k+1; i <= n; i++) {
        total += height[i].first;
        width.push(height[i].first);
        total -= width.top();
        width.pop();
        air = min(air, height[i].second*total);
    }
    cout << air << endl;
    return 0;
}
