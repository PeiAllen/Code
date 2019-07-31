/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on March 14, 2019, 1:18 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    string in;
    string in2;
    cin >> n >> in>>in2;
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = INT_MAX;
        if (i < 2) {
            int amount = 0;
            for (int j = i; j >= 0; j--) {
                if (in[j] != in2[j]) {
                    amount += 1;
                }
            }
            if (amount) {
                int zerodiff = 0;
                int onediff = 0;
                int fill = 0;
                int land = 0;
                for (int j = i; j >= max(0, i - 3); j--) {
                    if (in[j] == '0' && in2[j] == '1') {
                        onediff += 1;
                    } else if (in[j] == '1' && in2[j] == '0') {
                        zerodiff += 1;
                    }
                    if (in[j] == '0') {
                        fill += 1;
                    }
                    if (in2[j] == '1') {
                        land += 1;
                    }
                    if (zerodiff == 0) {
                        dp[i] = min(dp[i], (j > 0 ? dp[j - 1] : 0) + onediff);
                    }
                }
                dp[i] = min(dp[i], fill + (in2[i + 1] == '0' ? 1 : 0) + land + (in2[i + 1] == '1' ? 1 : 0) + 1+(i==0?((in2[i + 2] == '1' ? 1 : 0)+(in2[i+2]=='0'?1:0)):0));
            } else {
                dp[i] = 0;
            }
        } else {
            int zerodiff = 0;
            int onediff = 0;
            int fill = 0;
            int land = 0;
            for (int j = i; j >= max(0, i - 3); j--) {
                if (in[j] == '0' && in2[j] == '1') {
                    onediff += 1;
                } else if (in[j] == '1' && in2[j] == '0') {
                    zerodiff += 1;
                }
                if (in[j] == '0') {
                    fill += 1;
                }
                if (in2[j] == '1') {
                    land += 1;
                }
                if (zerodiff == 0) {
                    dp[i] = min(dp[i], (j > 0 ? dp[j - 1] : 0) + onediff);
                }
            }
            if (i >= 3) {
                dp[i] = min(dp[i], fill + land + (i > 3 ? dp[i - 4] : 0) + 1);
                dp[i] = min(dp[i], fill - (in[i - 3] == '0' ? 1 : 0) + land - (in2[i - 3] == '1' ? 1 : 0) + dp[i - 3] + 1);
            }
            else {
                dp[i] = min(dp[i], fill + land + 1);
            }
        }

    }
    printf("%d", dp[n - 1]);
    return 0;
}