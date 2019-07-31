/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 20, 2019, 12:32 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pa{
    lli loc,mail;
    pa(lli a=0, lli b=0):loc(a),mail(b){}
    bool operator<(const pa& rhs){
        return loc>rhs.loc;
    }
};
/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,k;
    cin>>n>>k;
    lli time=0;
    vector<pa> locs[2];
    lli a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a<0){
        locs[0].push_back(pa(a,b));
        }
        else{
        locs[1].push_back(pa(a,b));
        }
    }
    sort(locs[0].begin(),locs[0].end());
    lli cur=0;
    lli furthest=0;
    for(int i=locs[0].size()-1;i>=0;i--){
        if(cur==0){
            furthest=locs[0][i].loc;
        }
        if(cur+locs[0][i].mail>=k){
            time-=furthest;
            locs[0][i].mail-=(k-cur);
            time-=locs[0][i].loc*(locs[0][i].mail/k);
            locs[0][i].mail%=k;
            cur=0;
            if(locs[0][i].mail!=0){
                furthest=locs[0][i].loc;
            }
        }
        cur+=locs[0][i].mail;
    }
    if(cur>0&&locs[0].size()){
        time-=furthest;
    }
    furthest=0;
    cur=0;
    sort(locs[1].begin(),locs[1].end());
    for(int i=0;i<locs[1].size();i++){
        if(cur==0){
            furthest=locs[1][i].loc;
        }
        if(cur+locs[1][i].mail>=k){
            time+=furthest;
            locs[1][i].mail-=(k-cur);
            time+=locs[1][i].loc*(locs[1][i].mail/k);
            locs[1][i].mail%=k;
            cur=0;
            if(locs[1][i].mail!=0){
                furthest=locs[1][i].loc;
            }
        }
        cur+=locs[1][i].mail;
    }
    if(cur>0&&locs[1].size()){
        time+=furthest;
        cur=0;
    }
    printf("%lli\n",time*2);
    return 0;
}

