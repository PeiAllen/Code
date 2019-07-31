/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 28, 2019, 11:46 AM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for (int test = 1; test <= t; test++) {
        int n,k;
        cin>>n>>k;
        int spar[2][n][(int)log2((double)n)+1];
        for(int i=0;i<n;i++){
            cin>>spar[0][i][0];
        }
        for(int i=0;i<n;i++){
            cin>>spar[1][i][0];
        }
        for(int i=1;i<(int)log2((double)n)+1;i++){
            for(int j=0;j<n-(1<<i)+1;j++){
                spar[0][j][i]=max(spar[0][j][i-1],spar[0][j+(1<<(i-1))][i-1]);
                spar[1][j][i]=max(spar[1][j][i-1],spar[1][j+(1<<(i-1))][i-1]);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int ma[2]={0,0};
                int k=log2(j-i+1);
                ma[0]=max(spar[0][i][k],spar[0][j-(1<<k)+1][k]);
                ma[1]=max(spar[1][i][k],spar[1][j-(1<<k)+1][k]);
                if(abs(ma[0]-ma[1])<=k){
                    count+=1;
                }
            }
        }
        printf("Case #%d: %d\n", test, count);
    }
    return 0;
}

