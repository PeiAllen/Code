#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3001;
pll arr[MN];
ll dp[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    ll h;
    cin>>n>>h;
    arr[n+1]={h,0};
    for(int i=1;i<=n;i++)cin>>arr[i].first>>arr[i].second;
    n++;
    sort(arr+1,arr+n+1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        ll ma=0;
        dp[i]=LLONG_MAX;
        for(int j=i-1;j>=0;j--){
            ma=max(ma,arr[j+1].second);
            dp[i]=min(dp[i],dp[j]+max(arr[i].first-arr[j].first,ma-arr[j].first-arr[i].first+ll(2)*arr[j+1].first)+ll(2)*(arr[i].first-arr[j+1].first));
        }
    }
    printf("%lli\n",dp[n]);
    return 0;
}