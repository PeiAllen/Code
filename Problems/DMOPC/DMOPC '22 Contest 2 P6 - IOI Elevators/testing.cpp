#include <stdio.h>

const int MN = 5e4;
const int ME = 500;
int n = MN, m = ME;
bool grid[MN + 5][ME];

int main() {
    for (int i = 0; i < n; i++) grid[i][0] = true;
    for (int i = 1; i < m; i++) {
        grid[n - i * 2][0] = false;
        grid[n - i * 2][i] = true;
        grid[n - i * 2 + 3][i] = true;
    }

    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) putchar(grid[i][j] ? '1' : '0');
        putchar('\n');
    }
}
