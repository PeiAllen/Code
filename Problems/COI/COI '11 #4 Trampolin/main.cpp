#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
int sz(const T &a) { return int(a.size()); }
const int MN = 3e5 + 1;
int arr[MN];
bool trampable[MN];
int le[MN],ri[MN];
string type;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> type;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (type[i] == 'T') {
            q.push(i);
            trampable[i] = true;
        }
    }
    while (sz(q)) {
        auto cur = q.front();
        q.pop();
        for(int i = -1; i <= 1; i+=2){
            int nxt = cur + i;
            if(nxt >= 0 && nxt < n && arr[nxt] >= arr[cur] && !trampable[nxt]){
                q.push(nxt);
                trampable[nxt]=true;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(i - 1 >= 0 && arr[i - 1] <= arr[i]){
            le[i] = le[i - 1] + 1;
        }
        else{
            le[i] = 1;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(i + 1 < n && arr[i + 1] <= arr[i]){
            ri[i] = ri[i + 1] + 1;
        }
        else{
            ri[i] = 1;
        }
    }
    k--;
    if(trampable[k]){
        int ans = 0;
        int best = 0;
        for(int i = 0; i < n; i++){
            if(trampable[i]){
                ans++;
            }
            else{
                best = max({best, le[i], ri[i]});
            }
        }
        printf("%d\n", ans + best);
    }
    else{
        int ans = 0;
        for(int i = k; i >= 0 && arr[i] == arr[k]; i--){
            ans = max(ans, ri[i]);
        }
        for(int i = k; i < n && arr[i] == arr[k]; i++){
            ans = max(ans, le[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}