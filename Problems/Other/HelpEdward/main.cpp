#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int r, c;
char a[2001][2001];

void findPath(int i, int j) {
  if (a[i][j] == 'N') {
    for (int k = i - 1; k >= 0; k--) {
      if (a[k][j] != '.') {
        findPath(k, j);
      }
    }
    printf("(%d,%d\n)", i, j);
  } else if (a[i][j] == 'S') {
    for (int k = i + 1; k < r; k++) {
      if (a[k][j] != '.') {
        findPath(k, j);
      }
    }
    printf("(%d,%d\n)", i, j);
  } else if (a[i][j] == 'W') {
    for (int k = i - 1; k >= 0; k--) {
      if (a[i][k] != '.') {
        findPath(i, k);
      }
    }
    printf("(%d,%d\n)", i, j);
  } else if (a[i][j] == 'E') {
    for (int k = i + 1; k < c; k++) {
      if (a[i][k] != '.') {
        findPath(i, k);
      }
    }
    printf("(%d,%d\n)", i, j);
  }
  a[i][j] = '.';
}

int main() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin>>a[i];
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (a[i][j] != '.') {
        findPath(i, j);
      }
    }
  }
  return 0;
}