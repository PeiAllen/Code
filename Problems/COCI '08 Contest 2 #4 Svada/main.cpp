/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on May 4, 2019, 1:09 AM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pa {
    lli begin, llierval;

    pa(lli a = 0, lli b = 0) : begin(a), llierval(b) {
    }
};
vector<pa> arr[2];
lli amount(lli monkey, lli time){
    lli am=0;
    for(lli i=0;i<arr[monkey].size();i++){
        am+=max((lli)0,((time-arr[monkey][i].begin)/arr[monkey][i].llierval+(time>=arr[monkey][i].begin?1:0)));
    }
    return am;
}
lli time(lli monkey, lli coconuts) {
    lli l=0;
    lli r=1000000000;
    while(l!=r){
        lli mid=(l+r)/2;
        if(amount(monkey,mid)>=coconuts){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}

/*
 * 
 */
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli t, n, m;
    cin >> t>>n;
    lli a, b;
    for (lli i = 0; i < n; i++) {
        cin >> a>>b;
        arr[0].push_back(pa(a, b));
    }
    cin>>m;
    for (lli i = 0; i < m; i++) {
        cin >> a>>b;
        arr[1].push_back(pa(a, b));
    }
    lli l = 0, r = 1000000000;
    lli ans=-100;
    while (l != r) {
        lli mid = (l + r) / 2+1;
        lli te=time(0,mid);
        if (te + time(1, mid) <= t) {
            l = mid;
            ans=te;
        } else {
            r = mid - 1;
        }
    }
    printf("%lli\n", ans);
    //binarysearch the #of coconuts-> then for query, binary search for how much time the monkey1 and monkey 2 needsm as the amount of work a monkey does in time k is (k-ai+1)/bi

    return 0;
}

