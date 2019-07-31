/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 28, 2019, 11:46 AM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
/*
 * 
 */
int main() {
    setbuf(stdout,NULL);
    int t,w;
    cin>>t>>w;
    for (int test = 1; test <= t; test++) {
        lli arr[7];
        for(int i=0;i<7;i++){
            arr[i]=0;
        }
        lli in;
        printf("%d\n",14);
        cin>>in;
        if(in==-1){
            return 0;
        }
        arr[1]=in/(1<<14);
        printf("%d\n",1);
        cin>>in;
        if(in==-1){
            return 0;
        }
        lli temp1=in;
        temp1-=2*arr[1];
        printf("%d\n",2);
        cin>>in;
        if(in==-1){
            return 0;
        }
        lli temp2=in-4*arr[1];
        arr[2]=temp2-temp1;
        temp2-=arr[2]*2;
        printf("%d\n",4);
        cin>>in;
        if(in==-1){
            return 0;
        }
        lli temp4=in-arr[1]*(16)-arr[2]*(4);
        printf("%d\n",3);
        cin>>in;
        if(in==-1){
            return 0;
        }
        lli temp3=in-arr[1]*(8)-arr[2]*(2);
        arr[4]=temp4-temp3;
        arr[3]=temp3-temp2;
        printf("%d\n",5);
        cin>>in;
        if(in==-1){
            return 0;
        }
        lli temp5=in-arr[1]*(32)-arr[2]*(4);
        arr[5]=temp5-temp4;
        arr[6]=temp2-arr[3]-arr[4]-arr[5];
        for(int i=1;i<=5;i++){
            printf("%lli ",arr[i]);
        }
        printf("%lli\n",arr[6]);
        cin>>in;
        if(in==-1){
            return 0;
        }
    }
    
//    for(lli i=0;i<=500;i++){
//        if((1<<i)>(1<<(i/2))*100+(1<<(i/3))*100+(1<<(i/4))*100+(1<<(i/5))*100+(1<<(i/6))*100){
//            printf("1 %lli:",i);
//        }
//        if((1<<(i/2))>(1<<(i/3))*100+(1<<(i/4))*100+(1<<(i/5))*100+(1<<(i/6))*100){
//            printf("2 %lli:",i);
//        }
//        if((1<<(i/3))>(1<<(i/4))*100+(1<<(i/5))*100+(1<<(i/6))*100){
//            printf("3 %lli:",i);
//        }
//        if((1<<(i/4))>(1<<(i/5))*100+(1<<(i/6))*100){
//            printf("4 %lli:",i);
//        }
//        if((1<<(i/5))>(1<<(i/6))*100){
//            printf("5 %lli:",i);
//        }
//        if((1<<(i/6))>0){
//            printf("6 %lli:",i);
//        }
//        printf("\n");
//    }
    return 0;
}

