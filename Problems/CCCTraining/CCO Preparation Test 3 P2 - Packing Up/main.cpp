#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e6+1;
ll arr[MN],psa[MN],dp[MN];
int deq[MN];
ll c;
ll calc(int j, int i){
    return (psa[i]-psa[j]-c)*(psa[i]-psa[j]-c)+dp[j];
}
bool useless(int j1, int j2, int j3){
    ll m1=psa[j1]*-2,m2=psa[j2]*-2,m3=psa[j3]*-2;
    ll b1=2*c*psa[j1]+psa[j1]*psa[j1]+dp[j1];
    ll b2=2*c*psa[j2]+psa[j2]*psa[j2]+dp[j2];
    ll b3=2*c*psa[j3]+psa[j3]*psa[j3]+dp[j3];
    return __int128(b2-b1)*__int128(m2-m3)>=__int128(b3-b2)*__int128(m1-m2);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>c;
    c++;
    int l=0,r=-1;
    deq[++r]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]++;
        psa[i]=psa[i-1]+arr[i];
        while(r-l+1>=2&&calc(deq[l],i)>=calc(deq[l+1],i))l++;
        dp[i]=calc(deq[l],i);
        while(r-l+1>=2&&useless(deq[r-1],deq[r],i))r--;
        deq[++r]=i;
    }
    printf("%lli\n",dp[n]);
    return 0;
}