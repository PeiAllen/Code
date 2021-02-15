#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=4e5+1;
ll dp[MN],arr[MN],psa[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n+q;i++){
        cin>>arr[i],psa[i]=psa[i-1]+arr[i];
        dp[i]=max(dp[i-1],dp[i-2]+min(arr[i],arr[i-1]));//challenge previous two, or challenge these two(in two adjacent elements, if you want, you can always guarantee one(the minimal one, when A takes the larger one, you just take the smaller one)).
        if(i>=n)printf("%lli\n",psa[i]-dp[i]);
    }
    return 0;
}