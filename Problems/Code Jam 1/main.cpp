/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 28, 2019, 11:46 AM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
//struct node{
//    int data,le,ri;
//    struct node* left;
//    struct node* right;
//    node(int a=0){
//        data=a;
//        le=0;
//        ri=0;
//        left=NULL;
//        right=NULL;
//    }
//    void maxin(int a,int loc){
//        
//    }
//};

/*
 * 
 */
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for (int test = 1; test <= t; test++) {
        int p, q;
        cin >> p>>q;
        int x, y;
        char in;
        int ma = 0;
        int arr[q + 2];
        int arrleft[q + 2];
        for (int i = 0; i <= q; i++) {
            arr[i] = 0;
            arrleft[i] = 0;
        }
        for (int i = 0; i < p; i++) {
            cin >> x >> y>>in;
            if (in == 'N') {
                arr[y + 1] += 1;
            } else if (in == 'S') {
                arr[0] += 1;
                arr[y] -= 1;
            } else if (in == 'E') {
                arrleft[x + 1] += 1;
            } else {
                arrleft[0] += 1;
                arrleft[x] -= 1;
            }
        }
        int yloc = 0;
        int xloc = 0;
        ma = arr[0];
        for (int i = 1; i <= q; i++) {
            arr[i] += arr[i - 1];
        }
        for (int i = 1; i <= q; i++) {
            if (arr[i] > ma) {
                xloc = i;
                ma = arr[i];
            }
        }
        int secma = arrleft[0];
        for (int i = 1; i <= q; i++) {
            arrleft[i] += arrleft[i - 1];
        }
        for (int i = 1; i <= q; i++) {
            if (arrleft[i] > secma) {
                yloc = i;
                secma = arrleft[i];
            }
        }
        printf("Case #%d: %d %d\n", test, yloc, xloc);
    }
    return 0;
}

