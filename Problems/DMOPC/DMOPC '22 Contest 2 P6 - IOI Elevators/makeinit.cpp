#include "bits/stdc++.h"
using namespace std;
template <typename T>
int sz(const T &a) { return int(a.size()); }
const int MB = 4;
int n[MB] = {300, int(5e4), int(5e4), int(5e4)};
int m[MB] = {300, 10, 50, 500};
int points[MB] = {10, 20, 30, 40};
vector<vector<int>> params[MB] =
    {
        {{1, 5},
         {1, 20},
         {1, 300},
         {1, 0},
         {2, 5, 1, 1, 50, 100},
         {2, 5, 1, 2, 25, 50},
         {2, 20, 1, 1, 20, 30},
         {2, 20, 1, 2, 5, 20}},
        {{1, 1},
         {1, 2},
         {1, 10},
         {1, 0},
         {2, 5, 1, 1, 2, 4},
         {2, 100, 1, 1, 2, 5},
         {2, int(1e4), 1, 1, 3, 5},
         {2, 100, 1, 2, 0, 1},
         {2, 500, 1, 3, 0, 1},
         {2, 1000, 1, 4, 0, 1},
         {2, 4000, 2, 3, 0, 1},
         {2, 5000, 1, 5, 0, 1}},
        {{1, 1},
         {1, 2},
         {1, 50},
         {1, 0},
         {2, 5, 1, 1, 2, 5},
         {2, 100, 1, 2, 2, 8},
         {2, int(1e4), 1, 2, 4, 20},
         {2, 100, 1, 3, 0, 1},
         {2, 500, 2, 4, 0, 1},
         {2, 1000, 2, 6, 0, 1},
         {2, 4000, 3, 10, 0, 1},
         {2, 5000, 2, 25, 0, 1}},
        {{1, 1},
         {1, 2},
         {1, 5},
         {1, 10},
         {1, 20},
         {1, 500},
         {1, 0},
         {2, 5, 1, 1, 10, 40},
         {2, 5, 1, 3, 5, 25},
         {2, 5, 2, 5, 3, 15},
         {2, 20, 1, 1, 8, 50},
         {2, 20, 1, 3, 4, 30},
         {2, 20, 2, 5, 2, 20},
         {2, 100, 1, 1, 5, 50},
         {2, 100, 1, 3, 3, 30},
         {2, 100, 2, 6, 2, 25},
         {2, int(1e4), 1, 1, 3, 75},
         {2, int(1e4), 1, 2, 3, 50},
         {2, int(1e4), 1, 8, 2, 30},
         {2, int(1e4), 2, 10, 2, 25},
         {2, 100, 1, 6, 0, 1},
         {2, 100, 2, 5, 0, 1},
         {2, 500, 5, 30, 0, 1},
         {2, 500, 10, 20, 0, 1},
         {2, 1000, 10, 50, 0, 1},
         {2, 1000, 20, 30, 0, 1},
         {2, 4000, 41, 100, 0, 1},
         {2, 5000, 50, 80, 0, 1}}};
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    printf("checker: standard\ngenerator: gen.cpp\ntest_cases:\n");
    for (int i = 0; i < MB; i++) {
        printf("- batched:\n");
        if (i <= 1) {
            printf("  - generator_args:\n");
            printf("    - %d\n", 1);
            printf("    - %d\n", 1);
            printf("    - %d\n", 1);
            printf("    - %d\n", 1);
            printf("  - generator_args:\n");
            printf("    - %d\n", 1);
            printf("    - %d\n", 1);
            printf("    - %d\n", 1);
            printf("    - %d\n", 0);
        }
        for (auto x : params[i]) {
            printf("  - generator_args:\n");
            printf("    - %d\n", x[0]);
            printf("    - %d\n", n[i]);
            printf("    - %d\n", m[i]);
            for (int j = 1; j < sz(x); j++) {
                printf("    - %d\n", x[j]);
            }
        }
        printf("  - generator_args:\n");
        printf("    - %d\n", 3);
        printf("    - %d\n", n[i]);
        printf("    - %d\n", m[i]);
        printf("    - %d\n", 1);
        printf("  - generator_args:\n");
        printf("    - %d\n", 3);
        printf("    - %d\n", n[i]);
        printf("    - %d\n", m[i]);
        printf("    - %d\n", 2);
        printf("  points: %d\n", points[i]);
        if (i == 2) {
            printf("  dependencies: [2]\n");
        } else if (i == 3) {
            printf("  dependencies: [1,2,3]\n");
        }
    }
    return 0;
}