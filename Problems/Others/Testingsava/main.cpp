#include <iostream>
#include <cmath>
using namespace std;
int m, n, board[3001][3001], r = 1, c = 1, x = 1, r1 = 1, r2 = 1, c1 = 1, c2 = 1;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> m >> n;
    cin >> r >> c >> x;
    while(r != 0 && c != 0 && x != 0){
        board[r][c] = x;
        cin >> r >> c >> x;
    }
    for (int i = 1; i <= m; ++i) {
        board[i][1] -= board[i - 1][1];
    }
    for (int i = 1; i <= n; ++i) {
        board[1][i] -= board[1][i - 1];
    }
    for (int i = 2; i <= m; ++i) {
        for (int j = 2; j <= n; ++j) {
            board[i][j] = board[i][j] -board[i - 1][j] -board[i][j - 1] - board[i - 1][j - 1];
        }
    }

    cin >> r1 >> c1 >> r2 >> c2;

    while (r1 != 0 && r2 != 0 && c1 != 0 && c2 != 0){
        cout << -(board[r2][c2] - board[r1 - 1][c2] - board[r2][c1 - 1] - board[r1 - 1][c1 - 1]) << "\n";
        cin >> r1 >> c1 >> r2 >> c2;

    }

    /*
    cout << "\n\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    */
    return 0;
}