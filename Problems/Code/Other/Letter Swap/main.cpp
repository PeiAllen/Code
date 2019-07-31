/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 19, 2019, 11:45 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli bit[1000001];
    int n;
void update(int loc){
    for(;loc<=n;loc+=(loc&-loc)){
        bit[loc]+=1;
    }
}
lli start(int loc){
    lli sum=0;
    for(;loc>0;loc-=(loc&-loc)){
        sum+=bit[loc];
    }
    return sum;
}
/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    string a,b;
    cin>>a>>b;
    int truloc[n];
    for(char let='A';let<='Z';let++){
        queue<int> loc;
        for(int i=0;i<n;i++){
            if(a[i]==let){
                loc.push(i);
            }
        }
        for(int i=0;i<n;i++){
            if(b[i]==let){
                int othloc=loc.front();
                loc.pop();
                truloc[i]=othloc;
            }
        }
    }
    lli ans=0;
    for(int i=0;i<n;i++){
        ans+=start(n)-start(truloc[i]+1);
        update(truloc[i]+1);
    }
    printf("%lli",ans);
    return 0;
}

