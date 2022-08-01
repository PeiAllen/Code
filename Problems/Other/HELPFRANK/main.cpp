#include <bits/stdc++.h>

using namespace std;

int n;
int sausage [100001];
vector<int> length [100001];
long long dp [100001][5];
int temp [100001];
long long total;
int wanted [5];
long long choose;

long long compute(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= 4; j++) {
            if (sausage[temp[i]] != wanted[j]) {
                dp[i][j] = dp[i-1][j];
            }
            if (sausage[temp[i]] == wanted[j]) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    return dp[x][4];
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) cin >> sausage[i];
    for (int i = 1; i <= n; i++) length[sausage[i]].push_back(i);
    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            if (a!=b) {
                wanted[1] = a;
                wanted[2] = b;
                wanted[3] = b;
                wanted[4] = a;;
                merge(length[a].begin(), length[a].end(), length[b].begin, length[b].end(), temp+1);
                total += compute(length[a].size() + length[b].size());
            }
        }
    }
    for (int i = 1; i <= 100; i++) {
        choose = (long)length[i].size()*((long)length[i].size()-1)/2;
        choose *= length[i].size()-2;
        choose /= 3;
        choose *= length[i].size()-3;
        choose /= 4;
        total += choose;
    }
    cout << total << endl;
    return 0;
}
