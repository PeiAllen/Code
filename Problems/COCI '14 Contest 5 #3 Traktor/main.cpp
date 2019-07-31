/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on May 4, 2019, 12:46 AM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
int columns[100001];
int rows[100001];
int diagonals[400002];

/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n>>k;
    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x>>y;
        rows[y] += 1;
        columns[x] += 1;
        if (rows[y] >= k || columns[x] >= k) {
            printf("%d\n", i);
            return 0;
        }
        diagonals[100000 + x - y] += 1;
        if (diagonals[100000 + x - y] >= k) {
            printf("%d\n", i);
            return 0;
        }
        diagonals[x+y-1 + 200000] += 1;
        if (diagonals[x+y-1 + 200000] >= k) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

