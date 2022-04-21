#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
int dp[(1<<16)][2];
int solve(int mask, int type){//0 is min, 1 is max
    if(dp[mask][type])return dp[mask][type];
    if(__builtin_popcount(mask)==2){
        int toret=0;
        for(int i=0;i<16;i++){
            if(mask&(1<<i)){
                if(toret==0){
                    toret-=(1<<i);
                }
                else toret+=(1<<i);
            }
        }
        return toret;
    }
    int highest=0;
    for(int i=0;i<16;i++){
        if(mask&(1<<i)){
            highest=i;
        }
    }
    if(type==0){
        int best=INT_MAX;
        for(int i=mask;i>0;i=(i-1)&mask){
            if((i&(1<<highest))&&__builtin_popcount(i)==__builtin_popcount(mask)/2){
                best=min(best,solve(i,0)-solve(mask-i,1));
            }
        }
        return best;
    }
    else{
        int best=INT_MIN;
        for(int i=mask;i>0;i=(i-1)&mask){
            if((i&(1<<highest))&&__builtin_popcount(i)==__builtin_popcount(mask)/2){
                best=max(best,solve(i,1)-solve(mask-i,0));
            }
        }
        return best;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    printf("%d\n",solve((1<<16)-1,0));
    return 0;
}