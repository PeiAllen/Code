/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 19, 2019, 7:51 PM
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
    int n,k;
    cin>>k>>n;
    bool dp[n+1][2];
    int arr[k];
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n;i++){
        for(int player=0;player<=1;player++){
        bool win=!player;
        for(int j=0;j<k;j++){
            if(i-arr[j]>=0&&dp[i-arr[j]][!player]==(bool)player){
                win=player;
            }
        }
        dp[i][player]=win;
        }
    }
    if(dp[n][0]){
        printf("Second");
    }
    else{
        printf("First");
    }
    return 0;
}

