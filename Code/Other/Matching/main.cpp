/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 19, 2019, 7:06 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
int mo=1000000007;
int mod(int a){
    while(a<0){
        a+=mo;
    }
    return a%mo;
}
int dp[2097153];
int match[21][21];
int women[21];
int n;
int go(int bitmask, int amount){
    if(bitmask==0){
        return 1;
    }
    if(dp[bitmask]!=-1){
        return dp[bitmask];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int currentmantried=amount;
        if(bitmask&(1<<i)&&match[currentmantried][i]){
            ans+=go(bitmask-(1<<i),amount-1);
            ans=mod(ans);
        }
    }
    return dp[bitmask]=ans;
}
/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>match[i][j];
            if(match[i][j]){
                women[j]+=1;
            }
        }
    }
    printf("%d\n",go((1<<n)-1,n-1));
    return 0;
}

