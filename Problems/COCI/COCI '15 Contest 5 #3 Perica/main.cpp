/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 19, 2019, 8:57 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mo=1000000007;
lli mod(lli a){
    while(a<0){
        a+=mo;
    }
    return a%mo;
}
lli dp[100001][51];
lli choose(int n, int k){
    if(k==0){
        return 1;
    }
    if(n==k){
        return 1;
    }
    if(k==1){
        return n;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    return dp[n][k]=mod(choose(n-1,k)+choose(n-1,k-1));
}
/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    lli arr[n];
    for(lli i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    lli ans=0;
    for(lli i=k-1;i<n;i++){
        lli sum=mod(arr[i]);
        sum*=choose(i,k-1);
        ans+=mod(sum);
        ans=mod(ans);
    }
    printf("%lli\n",ans);
    return 0;
}