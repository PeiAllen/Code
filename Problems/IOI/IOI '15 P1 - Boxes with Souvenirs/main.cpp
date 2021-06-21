#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll delivery(int N, int K, int L, int *positions){
    int half=L/2;
    int mid=-1;
    while(mid+1<N&&positions[mid+1]<=half)mid++;
    vector<ll> dp(N);
    for(int i=0;i<=mid;i++){
        dp[i]=2*positions[i]+(i-K>=0?dp[i-K]:0);
    }
    for(int i=N-1;i>mid;i--){
        dp[i]=2*(L-positions[i])+(i+K<N?dp[i+K]:0);
    }
    ll best=(mid>=0?dp[mid]:0)+(mid+1<N?dp[mid+1]:0);
    for(int i=max(0,mid+1-K+1);i<=mid;i++){
        best=min(best,L+(i-1>=0?dp[i-1]:0)+(i+K<N?dp[i+K]:0));
    }
    return best;
}
